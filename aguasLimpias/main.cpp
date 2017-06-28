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

void tramosNavegables(Arbin<int> tramos, int &numTr, int &nivel){
	int tramoIz, tramoDr, nivelIz, nivelDr;
	if(tramos.esVacio()){
		numTr = 0;
		nivel = 0;
	}
	else if(tramos.hijoDr().esVacio() && tramos.hijoIz().esVacio()){
		numTr = 0;
		nivel = 1;
	}
	else{
		tramosNavegables(tramos.hijoDr(), tramoDr, nivelDr);
		tramosNavegables(tramos.hijoIz(), tramoIz, nivelIz);

		nivel = nivelDr + nivelIz - tramos.raiz(); // obtenemos el nivel del caudal
		// el tramos.raiz es el nivel que el embalse se queda

		if(nivel < 0)
			nivel = 0;

		numTr = tramoIz + tramoDr;

		if(nivelDr>=3)
			numTr++;

		if(nivelIz>=3)
			numTr++;
		
	}

}

void resuelveCaso(){
	Arbin<int> tramos;
	int numTr, nivel;
	tramos = leerArbol(-1);
	tramosNavegables(tramos, numTr, nivel);
	cout << numTr << endl;
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