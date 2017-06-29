#include <iostream>
#include <string>
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

int main(){

	while(cin){
		char eleccion;
		cin >> eleccion;

		if(eleccion == 'N'){
			Arbin<int> arbol;
			arbol = leerArbol(-1);
			
			int min = 0;
			min = arbol.minElem();
			cout << min << endl;
		}

		if(eleccion == 'P'){
			Arbin<char> arbol;
			arbol = leerArbol('#');
			// esta parte no la hace bien
			//no lee bien el string porque no deja arbol = leerArbol cuando es Arbin<string>
			string min = "c";
			cout << " aqui llega" ;
			min = arbol.minElem();
			cout << min << endl;
		}
	
	}


	return 0;
}