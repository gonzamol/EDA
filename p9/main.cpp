#include <iostream>
#include <algorithm>
#include <limits.h>
#include "Arbin.h"

using namespace std;

template <class T>
Arbin<T> leerArbol(const T& repVacio){
	T elem;
	cin >> elem;
	if (elem == repVacio)
		return Arbin<T>();
	else{
		Arbin<T> hi = leerArbol(repVacio);
		Arbin<T> hd = leerArbol(repVacio);
		return Arbin<T>(hi, elem, hd);
	}
}


void buscaRutas(Arbin<int> rutas, int &puerta, int &dragones){
	int puertaIzq, puertaDer,dragonesIzq,dragonesDer;

	if (rutas.esVacio()){
		puerta = 0;
		dragones = INT_MAX;
	}

	else if (rutas.hijoDr().esVacio() && rutas.hijoIz().esVacio()){
		puerta = rutas.raiz();
		dragones = 0;
	}

	else{
		buscaRutas(rutas.hijoIz(), puertaIzq, dragonesIzq);
		buscaRutas(rutas.hijoDr(), puertaDer, dragonesDer);

		if (dragonesIzq <= dragonesDer){
			puerta = puertaIzq;
			dragones = dragonesIzq;
		}

		else{
			puerta = puertaDer;
			dragones = dragonesDer;
		}

		if (rutas.raiz() == 1)
			dragones++;
	}

}

void resuelveCaso(){
	Arbin<int> rutas;
	int puerta, dragones = 0;
	rutas = leerArbol(-1); // -1 es la repr. de arbol vacio
	buscaRutas(rutas, puerta, dragones);
	cout << puerta << endl;
}


int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

	return 0;
}