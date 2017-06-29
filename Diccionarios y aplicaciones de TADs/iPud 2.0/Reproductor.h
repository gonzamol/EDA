#ifndef __REPRODUCTOR_H
#define __REPRODUCTOR_H

using namespace std;

#include <iostream>
#include "HashMap.h"
#include "List.h"
#include "AvlTreeMap.h"

typedef string Cancion;
typedef string Artista;
typedef int Duracion;
typedef string Nom;

class Reproductor {
private:
	typedef struct {
		Artista artista;
		Duracion duracion;
		bool marcadaReproduccion;
		bool marcadaReproducidas; // false es no marcada y true marcada
		List<Cancion>::Iterator itReproduccion;
		List<Cancion>::Iterator itReproducidas;
	} InfoCancion;

	HashMap <Cancion, InfoCancion> tablaCanciones;

	AvlTreeMap<Nom, List<Cancion>> listas;  // para el saveCurrentList

	List<Cancion> listaReproduccion;
	List<Cancion> listaReproducidas;
	int tiempoTotal;

public:

	Reproductor(){
		this->tablaCanciones = *new HashMap <Cancion, InfoCancion>;
		this->listaReproduccion = *new List<Cancion>;
		this->listaReproducidas = *new List<Cancion>;
		this->tiempoTotal = 0;
	}

	void addSong(Cancion c, Artista a, Duracion d){

		//Informacion de la cancion
		InfoCancion info;
		info.artista = a;
		info.duracion = d;
		info.marcadaReproduccion = false;
		info.marcadaReproducidas = false;

		if (tablaCanciones.contains(c))
			throw ExcepcionTAD("ERROR addSong");

		else{
			tablaCanciones.insert(c, info);
		}
	}


	void addToPlaylist(Cancion c){
		
		if (!tablaCanciones.contains(c))
			throw ExcepcionTAD("ERROR addToPlaylist");

		else{

			if (!tablaCanciones.at(c).marcadaReproduccion){
				listaReproduccion.push_front(c); // lo metemos al final de la lista
				tablaCanciones[c].itReproduccion = listaReproduccion.begin();
				tiempoTotal += tablaCanciones.at(c).duracion;
				tablaCanciones[c].marcadaReproduccion = true; // se marca la cancion de la lista de reproduccion
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
			Cancion primeraCancion = listaReproduccion.back(); //guardamos la ultima cancion de listaReproduccion

			if (!tablaCanciones.at(primeraCancion).marcadaReproducidas){
				listaReproducidas.push_front(primeraCancion);
				tablaCanciones[primeraCancion].marcadaReproducidas = true;
				tablaCanciones[primeraCancion].itReproducidas = listaReproducidas.begin();
			}

			else{			
				listaReproducidas.erase(tablaCanciones[primeraCancion].itReproducidas);

				listaReproducidas.push_front(primeraCancion);
				tablaCanciones[primeraCancion].itReproducidas = listaReproducidas.begin();
			}

			listaReproduccion.pop_back(); //sacamos dicha cancion de lista reproduccion
			tiempoTotal -= tablaCanciones.at(primeraCancion).duracion;
			tablaCanciones[primeraCancion].marcadaReproduccion = false;

			return primeraCancion;
		}

		else
			throw ExcepcionTAD("No hay canciones en la lista");

	}

	int totalTime(){
		return tiempoTotal;
	}

	void deleteSong(Cancion c){

		if (tablaCanciones.contains(c)){
			InfoCancion info = tablaCanciones.at(c); // la informacion de la cancion dada
			tablaCanciones.erase(c);
			

			if (info.marcadaReproduccion){
				tiempoTotal -= info.duracion;
				listaReproduccion.erase(info.itReproduccion);
			}

			if (info.marcadaReproducidas)
				listaReproducidas.erase(info.itReproducidas);
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