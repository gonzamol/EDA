// AUTOR: GONZALO MOLINA DÍAZ
// FECHA 01/09/2017
// FUNCIONA PERFECTAMENTE

#ifndef ESPACIOMATIC_H
#define ESPACIOMATIC_H

#include <iostream>
#include "HashMap.h"
#include "TreeMap.h"
#include "List.h"

using namespace std;

typedef int Id;
typedef string Modulo;
typedef int Nivel;

class EspacioMatic {
private:
	typedef TreeMap<Modulo, Nivel> TablaModulos;
	HashMap<Id, TablaModulos> tablaNaves;

public:
	EspacioMatic(){};

	void nuevaNave(Id id){
		if(tablaNaves.contains(id))
			throw ExcepcionTAD("Id ya existente");
		else{
			TablaModulos mod;
			tablaNaves.insert(id, mod);
		}
	}

	void equipaNave(Id id, Modulo mod, Nivel niv){
		if(!tablaNaves.at(id).contains(mod)) // si esa nave no tiene ese módulo
			tablaNaves[id].insert(mod, niv); // lo inserta con el nivel dado
		else{ // si esa nave ya tenía ese módulo
			tablaNaves[id][mod] += niv; // sumo el nivel que ya había la que me dan
		}
	}

	bool estropeaNave(Id id, Modulo mod){
		bool ok;
		if(tablaNaves.at(id).contains(mod) && tablaNaves.at(id).at(mod) > 0){ // el modulo existe y tiene un nivel > 0
			tablaNaves[id][mod]--;
			ok = true;
		}
		else // en cualquier otro caso solo devolvería false
			ok = false;

		return ok;
	}

	List<Id> navesDefectuosas(){
		List<Id> lista;

		// iteradores para recorrer todas las naves de la tablaNaves
		HashMap<Id, TablaModulos>::ConstIterator begin = tablaNaves.cbegin();
		HashMap<Id, TablaModulos>::ConstIterator end = tablaNaves.cend();

		while(begin != end){
			//iteradores para recorrer los modulos de cada nave
			TreeMap<Modulo, Nivel>::ConstIterator ini = begin.value().cbegin();
			TreeMap<Modulo, Nivel>::ConstIterator fin = begin.value().cend();
			while(ini != fin){
				if(ini.value() == 0) // si el nivel es 0
					lista.push_back(begin.key()); // se mete el id a la lista

				ini.next();
			}

			begin.next();
		}

		return lista;
	}

	List<Modulo> modulosNave(Id id){
		List<Modulo> lista;

		//iteradores para recorrer los modulos de la nave
		TreeMap<Modulo, Nivel>::ConstIterator ini = tablaNaves.at(id).cbegin();
		TreeMap<Modulo, Nivel>::ConstIterator fin = tablaNaves.at(id).cend();
		while(ini != fin){
			lista.push_back(ini.key()); // se mete el id a la lista
			ini.next();
		}

		return lista;
	}

	// Esta operación ha sido aniadida por el autor para la comprobaciçón del método estropeaNave
	int verNivelModuloNave(Id id, Modulo mod){
		return tablaNaves.at(id).at(mod);
	}

};

#endif