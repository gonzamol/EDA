#include <iostream>
#include "List.h"

// PARCIAL JUNIO 2015 EJERCICIO 1
// FUNCIONA PERFECTAMENTE

using namespace std;

void mostrarLista(List<int>* l){
	List<int>::ConstIterator it = l->cbegin();
	if (it != l->cend()){
		cout << it.elem();
		it.next();
	}
	while (it != l->cend()){
		cout << " " << it.elem();
		it.next();
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;

	while(cin){
		List<int> *lista = new List<int>();

		while(n != -1){
			lista->push_back(n);
			cin >> n;
		}

		mostrarLista(lista);
		lista->intercala();
		mostrarLista(lista);

		cout << endl;
		cin >> n;
	}


	return 0;
}