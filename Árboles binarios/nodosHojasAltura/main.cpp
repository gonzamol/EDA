#include <iostream>
#include <algorithm>
#include <string>
#include "Arbin.h"

// COGIDO POR EL JUEZ

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


int main(){
	int n, numH, alt, numN; // casos de prueba
	char elem;

	cin >> n;
	while(n > 0){
		Arbin<char> arbol;
		arbol = leerArbol('.'); // -1 es la repr. de arbol vacio

		numN = arbol.numNodos();				
		numH = arbol.numHojas();
		alt = arbol.altura();
		cout << numN << " " << numH << " " << alt << endl;
		
		/*cout << " Numero de nodos: " << numN << endl;
		cout << " Numero de hojas: " << numH << endl; 
		cout << " Altura: " << alt << endl;*/

		n--;
	}

	return 0;
}