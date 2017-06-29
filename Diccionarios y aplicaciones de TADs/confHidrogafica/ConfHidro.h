#ifndef CONFHIDRO_H
#define CONFHIDRO_H

#include <iostream>
#include "TreeMap.h"
#include "HashMap.h"

using namespace std;

typedef string Rio;
typedef string Pantano;

class ConfHidro{
private:
	typedef struct {
		int capacidad;
		int litros_emb;
	} InfoPantano;
	typedef HashMap<Pantano, InfoPantano> InfoRio;
	HashMap<Rio, InfoRio> tablaRios;

public:
	//Constructores
	ConfHidro(){
		this->tablaRios = *new HashMap<Rio, InfoRio>;
	}

	void an_rio(Rio r){
		if(tablaRios.contains(r))
			throw ExcepcionTAD("Rio ya existente");
		else{
			InfoRio info;
			tablaRios.insert(r, info);
		}
	}

	void an_pantano(Rio r, Pantano p, int n1, int n2){
		if(tablaRios.contains(r) && !tablaRios[r].contains(p)){ // el rio existe y el pantano aun no
			InfoPantano infoP;
			infoP.capacidad = n1;
			if(n2 > n1) // si le quiere meter mas de lo que hay (algo q es imposible), lo llena
				n2 = n1;
			infoP.litros_emb = n2;
			tablaRios[r].insert(p, infoP);
		}
		else
			throw ExcepcionTAD("El rio no existe o el pantano ya existe");

	}

	void embalsar(Rio r, Pantano p, int n){
		if(tablaRios.contains(r) && tablaRios[r].contains(p)){ // el rio está y el pantano de ese rio también
			InfoPantano infoP;
			infoP.capacidad = tablaRios[r][p].capacidad;
			infoP.litros_emb = tablaRios[r][p].litros_emb;

			if(n > infoP.capacidad)
				infoP.litros_emb = infoP.capacidad;
			else
				infoP.litros_emb += n;

			tablaRios[r].insert(p, infoP);
		}
		else
			throw ExcepcionTAD("El rio no existe o el pantano no existe");
	}

	int embalsado_pantano(Rio r, Pantano p){
		int cant = -1;
		
		if(tablaRios.contains(r) && tablaRios[r].contains(p)) // el rio está y el pantano de ese rio también
			cant = tablaRios[r][p].litros_emb;
		
		return cant;
	}

	int reserva_cuenca(Rio r){
		int cant = 0;
		if(tablaRios.contains(r)){ // si el rio existe
			HashMap<Rio, InfoRio>::Iterator itR = tablaRios.find(r);

			if(itR != tablaRios.end()){
				InfoRio::Iterator itP = itR.value().begin();
				while(itP != itR.value().end()){
					cant += itP.value().litros_emb;
					itP.next();
				}
			}

		}
		else
			cant = -1;

		return cant;
	}

	void transvase(Rio r1, Pantano p1, Rio r2, Pantano p2, int n){
		//comprobar que todo existe primero
		if(tablaRios.contains(r1) && tablaRios.contains(r2) && tablaRios[r1].contains(p1) && tablaRios[r2].contains(p2)) {
			// n es menor que los litros que hay en p1(esta en la cantidad a transvasar) y n menor que la capacidad de p2(el destino)
			if(n < tablaRios[r1][p1].litros_emb && n < tablaRios[r2][p2].capacidad){
				tablaRios[r1][p1].litros_emb -= n;
				tablaRios[r2][p2].litros_emb += n;
			}
		}

	}

};

#endif