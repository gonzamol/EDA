#include <iostream>
#include "Exceptions.h"
#include "List.h"

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


int buscaDuplicados(List<int>* l){
	List<int>::Iterator it = l->begin();
	int suma = 0, numRep=0;

	while (it != l->end()){
		if (suma == it.elem()){
			numRep++;
			l->insert(it.elem(), it);
		}

		suma += it.elem();
		it.next();
	}

	return numRep;
}

int main() {

	int  numCasos, n, numRep = 0;
	char c;
	cin >> numCasos;
	cin.get();
	for (int i = 0; i < numCasos; i++){
		List<int> *l = new List<int>();
		c = cin.peek();
		while (c != '\n'){
			cin >> n;
			l->push_back(n);		
			
			c = cin.peek();
		}
		cin.get();
		numRep=buscaDuplicados(l);
		cout << numRep << ": ";
		mostrarLista(l);

	}

	return 0;
}