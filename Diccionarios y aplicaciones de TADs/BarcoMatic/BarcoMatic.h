#ifndef ESPACIOMATIC_H
#define ESPACIOMATIC_H

#include <iostream>
#include <utility>
#include <string>
#include "HashMap.h"
#include "TreeMap.h"
#include "List.h"

using namespace std;

typedef int Bodega;
typedef string Especie;
typedef int Peso;
typedef string Nombre;

class BarcoMatic {
private:
	Bodega bodega;
	typedef HashMap<Especie, Peso> Captura;
	HashMap<Nombre, Captura> tablaPescadores;

public:
	void nuevo(Bodega bodega){
		this->bodega = bodega;
		this->tablaPescadores = *new HashMap<Nombre,Captura>;
	}

	// O(N) siendo N el nº de pescadores
	void altaPescador(Nombre nom){
		Captura cap;
		tablaPescadores.insert(nom, cap);
	}

	// O(N) siendo N el nº de pescadores
	void nuevaCaptura(Nombre nom, Especie esp, Peso peso){
		if(tablaPescadores.contains(nom))
			if(bodega - peso >= 0){ // si a la bodega le restas lo que pesa el pez y sigue siendo >= 0 es que caben aun cosas
				tablaPescadores[nom].insert(esp, peso);
				bodega -= peso;
			}
	}

	// O(N) siendo N el numero de capturas del pescador
	List<pair<Especie, Peso>> capturasPescador(Nombre nom){
		List<pair<Especie, Peso>> lista;

		if(!tablaPescadores.contains(nom))
			throw ExcepcionTAD("Este pescador no esta registrado");
		else{
			Captura cap = tablaPescadores.at(nom);

			HashMap<Especie, Peso>::ConstIterator begin = cap.cbegin();
			HashMap<Especie, Peso>::ConstIterator end = cap.cend();

			while(begin != end){
				if(tablaPescadores.at(nom).contains(begin.key())){
					pair<Especie, Peso> par = pair<Especie, Peso>(begin.key(), begin.value());
					lista.push_back(par);
				}
				begin.next();
			}
		}
		return lista;
	}

	// O(N) siendo N el numero de pescadores 
	int kilosEspecie(Especie esp){
		int total = 0;

		auto it = tablaPescadores.cbegin();

		while(it != tablaPescadores.cend()){
			total += it.value().find(esp).value();
			it.next();
		}

		return total;
	}
	
	// O(N) siendo N el numero de pescadores
	int kilosPescador(Nombre nom){
		int total = 0;

		auto it = tablaPescadores.at(nom).cbegin();

		while(it != tablaPescadores.at(nom).cend()){
			total += it.value();
			it.next();
		} 

		return total;
	}

	// constante
	int bodegaRestante() {
		return bodega;
	}

};

#endif