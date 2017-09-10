#include <iostream>
#include "List.h"

using namespace std;

// FUNCIONA PERFECTAMENTE

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

// se supone siempre que l1 y l2 vienen ordenadas
List<int> uneOrdenaListas(List<int> *l1, List<int> *l2){
	List<int> *lista = new List<int>();
	List<int>::Iterator it1 = l1->begin();
	List<int>::Iterator it2 = l2->begin();

	while(it1 != l1->end() || it2 != l2->end()){
		// nunca entrarian aqui los dos vacios
		if(it1 == l1->end()){ // si es el final de l1, se mete lo de l2
			lista->push_back(it2.elem());
			it2.next();
		}
		else if(it2 == l2->end()){ // o viceversa
			lista->push_back(it1.elem());
			it1.next();
		}
		else if(!l1->empty() && !l2->empty()){ // comparacion
			if(it1.elem() <= it2.elem()){
				lista->push_back(it1.elem());
				it1.next();
			}
			else if(it2.elem() < it1.elem()){
				lista->push_back(it2.elem());
				it2.next();		
			}
		}
		
	}

	return *lista;

}

int main(){
	int n;
	cin >> n;
	cin.get();

	while(n > 0){
		List<int> *l1 = new List<int>();
		int elem;
		char c;

		c = cin.peek();
		while(c != '\n'){
			cin >> elem;
			l1->push_back(elem);
			c = cin.peek();			
		}
		cin.get();

		List<int> *l2 = new List<int>();
		c = cin.peek();
		while(c != '\n'){
			cin >> elem;
			l2->push_back(elem);
			c = cin.peek();			
		}		
		cin.get();

		List<int> *l = new List<int>();
		*l = uneOrdenaListas(l1, l2);
		mostrarLista(l);

		n--;
	}

	return 0;
}