#include <iostream>
#include <algorithm>
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

void planificarRescate(Arbin<int> rutas, int &grupos, int &max){
	int gruIzq, maxIzq, gruDer, maxDer;

	if (rutas.esVacio()){
		grupos = 0;
		max = 0;
	}

	else {
		planificarRescate(rutas.hijoIz(), gruIzq, maxIzq);
		planificarRescate(rutas.hijoDr(), gruDer, maxDer);

		//si hay un nodo del arnol q no es 0 y se han usado 0 equpos d rescate por ambos lados hay q poner un equipo de rescate
		if (gruIzq == 0 && gruDer == 0 && rutas.raiz() != 0)
			grupos = 1;
		else
			grupos = gruDer + gruIzq;


		if (maxIzq > maxDer)
			max = maxIzq + rutas.raiz();
		else
			max = maxDer + rutas.raiz();
	}

}

void resuelveCaso(){
	Arbin<int> rutas;
	int grupos, max;
	rutas = leerArbol(-1); // -1 es la repr. de arbol vacio
	planificarRescate(rutas, grupos, max);
	cout << grupos << " " << max << endl;
}


int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

	return 0;
}