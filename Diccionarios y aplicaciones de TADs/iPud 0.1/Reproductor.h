#ifndef __REPRODUCTOR_H
#define __REPRODUCTOR_H

using namespace std;

#include <iostream>
#include "HashMap.h"
#include "List.h"

typedef string Cancion;
typedef string Artista;
typedef int Duracion;

class Reproductor {
private:
	typedef struct {
		Artista artista;
		Duracion duracion;
		bool marcada; // false es no marcada y true marcada
	} InfoCancion;

	HashMap <Cancion, InfoCancion> tablaCanciones;

	List<Cancion> listaReproduccion;
	List<Cancion> listaReproducidas;

public:

	Reproductor(){
		this->tablaCanciones = *new HashMap <Cancion, InfoCancion>;
		this->listaReproduccion = *new List<Cancion>;
		this->listaReproducidas = *new List<Cancion>;
	}

	void addSong(Cancion c, Artista a, Duracion d){

		//Informacion de la cancion
		InfoCancion info;
		info.artista = a;
		info.duracion = d;
		info.marcada = false;

		if (tablaCanciones.contains(c))
			throw ExcepcionTAD("ERROR addSong");

		else{
			tablaCanciones.insert(c, info);
		}
	}

	void addToPlaylist(Cancion c){
		bool encontrada = false;
		if (!tablaCanciones.contains(c))
			throw ExcepcionTAD("ERROR addToPlaylist");

		else{

			List<Cancion>::ConstIterator it = listaReproduccion.cbegin();
			List<Cancion>::ConstIterator end = listaReproduccion.cend();

			if(listaReproduccion.empty())
				listaReproduccion.push_back(c);

			else{
				while (it != end && !encontrada){
					if (it.elem() == c)
						encontrada = true;
					else	
						it.next();
				}

				if(!encontrada)
					listaReproduccion.push_back(c);

			}
		}
	}

	Cancion current(){
		if (listaReproduccion.empty())
			throw ExcepcionTAD("ERROR current");
		else
			return listaReproduccion.front();
	}

	Cancion play(){

		if (!listaReproduccion.empty()){
			Cancion primeraCancion = listaReproduccion.front(); //guardamos la primera cancion de listaReproduccion
			listaReproduccion.pop_front(); //eliminamos dicha cancion

			if(tablaCanciones.at(primeraCancion).marcada){
				//Si la cancion esta marcada, buscamos en reproducidas para borrarla, porque solo queremos que se quede la reciente
				List<Cancion>::Iterator it = listaReproducidas.begin();
				while(it.elem() != primeraCancion)
					//Buscamos la cancion antigua para borrarla de listaReproducidas, ya que solo queremos la reciente
					it.next();
					listaReproducidas.erase(it);
			}

			else //Marcamos la cancion
				tablaCanciones[primeraCancion].marcada = true;
			
			listaReproducidas.push_front(primeraCancion); //añadimos la cancion mas reciente a la lista de reproduccion

			return primeraCancion;
		}

		else
			throw ExcepcionTAD("No hay canciones en la lista");

	}

	int totalTime(){

		int total = 0;

		if (!listaReproduccion.empty()){

			List<Cancion>::ConstIterator it = listaReproduccion.cbegin();
			List<Cancion>::ConstIterator end = listaReproduccion.cend();

			while (it != end){

				Cancion cancionActual = it.elem();

				InfoCancion info = tablaCanciones.at(cancionActual);
				total += info.duracion;

				it.next();
			}
		}

		return total;

	}

	void deleteSong(Cancion c){
		bool encontrada = false;

		if (tablaCanciones.contains(c)){ //borramos de la tablaCanciones
			tablaCanciones.erase(c);

			//Buscamos en la lista de reproduccion la cancion c
			List<Cancion>::Iterator it = listaReproduccion.begin();
			List<Cancion>::Iterator end = listaReproduccion.end();

			while (it != end && !encontrada){
				if (it.elem() == c){
					encontrada = true;
					listaReproduccion.erase(it);
				}
				it.next();
			}

			encontrada = false;
			//Buscamos en la lista de reproduccidas la cancion c
			List<Cancion>::Iterator itReproducidas = listaReproducidas.begin();
			List<Cancion>::Iterator endReproducidas = listaReproducidas.end();

			while (itReproducidas != endReproducidas && !encontrada){
				if (itReproducidas.elem() == c){
					encontrada = true;
					listaReproducidas.erase(itReproducidas);
				}
				itReproducidas.next();
			}

			encontrada = false;
		}
	}

	List<Cancion> recent(int N){
		
		List<Cancion> listaRecientes;

		if(listaReproducidas.empty() || N <= 0)
			throw ExcepcionTAD("No hay canciones recientes");

		if(N>0) {

			int cont = 0;
			List<Cancion>::ConstIterator it = listaReproducidas.cbegin();

			while(it != listaReproducidas.cend() && cont < N){
				listaRecientes.push_back(it.elem());
				it.next();
				cont++;
			}
		}

		return listaRecientes;
	}

};


#endif