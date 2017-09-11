#ifndef CIUDADMATIC_H
#define CIUDADMATIC_H

#include <iostream>
#include "HashMap.h"
#include "TreeMap.h"
#include "List.h"

using namespace std;

typedef int Presupuesto;
typedef string Nombre;
typedef string Id;

class ciudadMatic {
private:
	Presupuesto pres;
	typedef struct {
		Id id;
		int coste;
		int impuesto;
		int calidad;
	} InfoEdificio;
	HashMap<Nombre, InfoEdificio> tablaEdificios;
	HashMap<Id, InfoEdificio> tablaTipos;	

public:
	ciudadMatic(){}

	void crea(Presupuesto pres){
		this->pres = pres;
		this->tablaTipos = *new HashMap<Id, InfoEdificio>();
		this->tablaEdificios = *new HashMap<Nombre, InfoEdificio>();
	}

	// constante
	void nuevoTipo(string id, int cos, int imp, int cal){
		if(!tablaTipos.contains(id)){
			InfoEdificio info;
			info.id = id;
			info.coste = cos;
			info.impuesto = imp;
			info.calidad = cal;
			tablaTipos.insert(id, info); 
		}
		else
			throw ExcepcionTAD("Ya existe un edificio con ese id");
	}

	// constante
	void insertaEdificio(Nombre nom, Id id){
		if(tablaTipos.at(id).coste < pres){ // si el coste del tipo de edificio es <= que el presupuesto total, se puede construir
			InfoEdificio info;
			info.id = id;
			info.coste = tablaTipos.at(id).coste;
			info.impuesto = tablaTipos.at(id).impuesto;
			info.calidad = tablaTipos.at(id).calidad;
			tablaEdificios.insert(nom, info); // se crea un nuevo edificio con todas sus caracteristicas 'recien costruidas'
			pres -= tablaTipos.at(id).coste; // se resta el coste de la construccion al presupuesto total
		}
		else
			throw ExcepcionTAD("Presupuesto insuficiente");

	}

	// constante
	void reparaEdificio(Nombre nom){
		Id id = tablaEdificios.at(nom).id; // cojo el id de ese edificio
		HashMap<Id, InfoEdificio>::Iterator it = tablaTipos.find(id); // lo busco en la tabla de tipos

		if(it != tablaTipos.end()){ // si lo ha encontrado
			// lo deja todo como recien construido
			tablaEdificios[nom].calidad = it.value().calidad;
			tablaEdificios[nom].coste = it.value().coste;
			tablaEdificios[nom].impuesto = 0; // cuando se crea no tiene ningun impuesto aun

			int coste = it.value().coste * 0.1; // el coste de la reparacion es el 10% de la construccion
			pres -= coste; // se resta al pres total
		}
		else
			throw ExcepcionTAD("Edificio con ese nombre inexistente");
	}

	// lineal respecto al numero de edificios de la tablaEdificios
	int finTurno(){
		HashMap<Nombre, InfoEdificio>::Iterator itE = tablaEdificios.begin(); // iterador para recorrer todos los edificios
		int impuestosTotales = 0;

		while(itE != tablaEdificios.end()){
			HashMap<Id, InfoEdificio>::Iterator itT = tablaTipos.find(itE.value().id); // busca el id de ese edificio
			if(itT != tablaTipos.end()){ // si lo ha encontrado
				itE.value().impuesto += itT.value().impuesto; // se le suma el impuesto de su tipo 
				impuestosTotales = itE.value().impuesto; // se guarda en una variable local porque si lo pones en el return te devuelve el del next
				itE.value().calidad--; // se le desciende un punto la calidad
				if(itE.value().calidad == 0) // si su calidad llega a 0
					tablaEdificios.erase(itE.key()); // se elimina de la ciudad
			}
			itE.next();
		}
		
		return impuestosTotales + pres;
	}

	// lineal respecto al numero de edificios de la tablaEdificios
	List<Id> listaEdificios(Id id){
		List<Id> lista;
		HashMap<Nombre, InfoEdificio>::Iterator it = tablaEdificios.begin();

		// debe listarlos por orden de antigüedad (primero los mas antiguos)
		while(it != tablaEdificios.end()){
			if(it.value().id == id)
				lista.push_back(it.key());
			
			it.next();
		}

		return lista;
	}

};

#endif