#include <iostream>
#include "List.h"

using namespace std;

// GONZALO MOLINA
// PARCIAL JUNIO 2015 EJERCICIO 1
// FUNCIONA PERFECTAMENTE

template<class T>
void mostrarLista(List<T>* l){
	List<T>::ConstIterator it = l->cbegin();
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

	while(n>0){
		List<int> *l = new List<int>();;
		int num;
		cin >> num;

		while(num != -1){
			l->push_back(num);
			cin >> num;
		}

		l->intercala();

		mostrarLista(l);

		n--;
	}

	return 0;
}