#include <iostream>
#include "Arbin.h"
#include <algorithm>
#include <limits.h>

// FUNCIONA PERFECTAMENTE
/* ALGUNOS CASOS DE PRUEBA:
4
N X N O O N O O O
N X N O O N O O N O X O O
*/

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

int tiempoAyuda(const Arbin<char>& arbol, int level){
	if(arbol.esVacio()){ // si es vacio, nadie necesitara ayuda
		return 0;
	}
	else if(arbol.hijoDr().esVacio() && arbol.hijoIz().esVacio()){
		if(arbol.raiz() == 'X')
			return 2 * level;
		else
			return 0;
	}
	else{
		int tiempo = 0;
		if(arbol.raiz() == 'X')
			tiempo += level * 2;
		return tiempo + tiempoAyuda(arbol.hijoIz(), level + 1) + tiempoAyuda(arbol.hijoDr(), level + 1);
	}
}

int tiempoAyuda(const Arbin<char>& arbol){
	return tiempoAyuda(arbol, 0); // nivel en el que está la raiz -> suponemos 0
}

void resuelveCaso(){
	Arbin<char> rutas;
	int tiempo;
	rutas = leerArbol('O');
	tiempo = tiempoAyuda(rutas);
	cout << tiempo << endl;
}

int main(){
	int n;
	cin >> n; // casos de prueba
	
	while(n>0){
		resuelveCaso();
		n--;
	}
	
	return 0;
}