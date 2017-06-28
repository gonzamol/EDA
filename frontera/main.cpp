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

int main(){
	int numCasos;
	cin >> numCasos;

	while(numCasos > 0){
		Arbin<int> arbol;
		int fr;
		arbol = leerArbol(-1);

		List<int> l;
		l = arbol.frontera();

		mostrarLista(l);
		
		numCasos--;
	}

	return 0;
}