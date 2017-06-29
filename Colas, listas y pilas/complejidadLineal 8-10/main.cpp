#include <iostream>
#include "List.h"

using namespace std;

// CORRECT EN EL JUEZ

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

void eliminaMenor(List<int> *lista){
	List<int>::Iterator it = lista->begin();
	int m;

	if(it != lista->end()){
		m = it.elem();
		it.next();
	}

	while(it != lista->end()){
		if(it.elem() < m){
			it = lista->erase(it);
		}
		else{
			m = it.elem();
			it.next();
		}
	}

}

int main(){
	int n;
	cin >> n; // casos de prueba
	
	while(n>0){
		int elem;
		List<int> *l = new List<int>(); 
		cin >> elem;

		while(elem != -1){
			l->push_back(elem);
			cin >> elem;
		}

		eliminaMenor(l);
		mostrarLista(l);

		n--;
	}
	
	return 0;
}

