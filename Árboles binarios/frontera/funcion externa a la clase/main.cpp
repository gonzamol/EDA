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

void mostrarLista(List<int> l){
	List<int>::ConstIterator it = l.cbegin();
	if (it != l.cend()){
		cout << it.elem();
		it.next();
	}
	while (it != l.cend()){
		cout << " " << it.elem();
		it.next();
	}
	cout << endl;
}

void buscaFronteras(Arbin<int> &rutas, List<int> &front){
	if(!rutas.esVacio()){
		if(rutas.hijoDr().esVacio() && rutas.hijoIz().esVacio()){
			front.push_back(rutas.raiz());
		}
		else{
			buscaFronteras(rutas.hijoIz(), front);
			buscaFronteras(rutas.hijoDr(), front);

			// ¿unir las dos listas?
		}
	}

}

void resuelveCaso(){
	Arbin<int> rutas;
	List<int> frontera;
	rutas = leerArbol(-1);
	buscaFronteras(rutas, frontera);
	mostrarLista(frontera);
}

int main(){
	int numCasos;
	cin >> numCasos;

	for(int i = 0; i < numCasos; i++)
		resuelveCaso();
	
	return 0;
}