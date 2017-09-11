#include <iostream>
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

void busca(Arbin<char> &rutas, int &nodos, int &hojas, int &altura){
	int nodosIz, nodosDr, hojasIz, hojasDr, alturaIz, alturaDr;
	if(rutas.esVacio()){
		nodos = 0;
		hojas = 0;
		altura = 0;
	}
	else if(rutas.hijoDr().esVacio() && rutas.hijoIz().esVacio()){
		nodos = 1;
		hojas = 1;
		altura = 1;
	}
	else {		
		busca(rutas.hijoIz(), nodosIz, hojasIz, alturaIz);
		busca(rutas.hijoDr(), nodosDr, hojasDr, alturaDr);

		nodos = nodosDr + nodosIz + 1;
		hojas = hojasDr + hojasIz;
		altura = max(alturaIz, alturaDr) + 1;
		
	}
}

void resuelveCaso(){
	Arbin<char> rutas;
	rutas = leerArbol('.');
	int nodos, hojas, altura;
	busca(rutas, nodos, hojas, altura);
	cout << nodos << " " << hojas << " " << altura << endl;
}

int main(){
	int numCasos;
	cin >> numCasos;

	for(int i = 0; i < numCasos; i++)
		resuelveCaso();

	return 0;
}