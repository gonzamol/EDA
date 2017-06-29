#include <iostream>
#include "List.h"

using namespace std;

//EJERCICIO IDEADO POR GONZALO MOLINA
// IMPLEMENTA UNA FUNCION QUE DADA UNA LISTA, BORRE TODOS SUS ELEMENTOS PARES.
// La entrada comienza con el numero de casos prueba y la siguiente y unica linea constituye los elems de la lista (acabada en -1)
// La salida consiste en la lista sin los elemetos pares

void mostrarLista(List<int> *l){
	List<int>::ConstIterator it = l->cbegin();

	if(it != l->cend()){
		cout << it.elem();
		it.next();
	}

	while(it != l->cend()){
		cout << " " << it.elem();
		it.next();
	}
	cout << endl;
}

void eliminaPares(List<int> *l){
	List<int>::Iterator it = l->begin();

	while(it != l->end()){ // recorremos la lista dada
		if(it.elem()%2 == 0) // si es par
			it = l->erase(it); // borrar esa posicion
		else
			it.next();
	}

}

int main(){
	int n, elem;
	cin >> n;

	while(n > 0){
		List<int> *l = new List<int>();
		cin >> elem;

		while(elem != -1){
			l->push_back(elem);
			cin >> elem;
		}

		eliminaPares(l);
		mostrarLista(l);
	
		n--;
	}

	return 0;
}