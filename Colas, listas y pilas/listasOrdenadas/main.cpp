#include <iostream>
#include "List.h"

// CORRECT EN EL JUEZ 8-08

using namespace std;

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


List<int> uneListas(const List<int> *l1, const List<int> *l2);
List<int> ordenaLista(List<int> *lista);

int main(){
	int n, elem;
	char c;
	cin >> n; // casos de prueba
	cin.get();

	while (n > 0){
		//Creacion de la primera lista e insercion de los elementos
		List<int> *l1 = new List<int>();
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

		//cout << " Lista 1: ";
		//mostrarLista(l1);
		//cout << " Lista 2: ";
		//mostrarLista(l2);

		List<int> *lista = new List<int>();
		if(!l1->empty() && !l2->empty())
			*lista = uneListas(l1, l2);
		else if(l1->empty())
			*lista = *l2;
		else if(l2->empty())
			*lista = *l1;
		//cout << " Lista unida: ";
		//mostrarLista(lista);

		List<int> *listaOrd = new List<int>();
		if(!lista->empty())
			*listaOrd = ordenaLista(lista);
		//cout << " Lista ordenada: ";
		mostrarLista(listaOrd);

		delete l1;
		delete l2;
		delete lista;
		delete listaOrd;

		n--;
	}

	return 0;
}


List<int> uneListas(const List<int> *l1, const List<int> *l2){
	List<int>::ConstIterator it1 = l1->cbegin();
	List<int>::ConstIterator it2 = l2->cbegin();

	//Lista nueva donde irán unidas las dos
	List<int> *lista = new List<int>();
	
	while(it1 != l1->cend()){
		lista->push_back(it1.elem());
		it1.next();
	}

	while(it2 != l2->cend()){
		lista->push_back(it2.elem());
		it2.next();
	}

	return *lista;
}


List<int> ordenaLista(List<int> *lista){
	List<int>::Iterator it = lista->begin();
	List<int> *lis = new List<int>();
	List<int>::Iterator itNew = lis->begin();
	lis->insert(it.elem(), itNew);
	it.next();

	while(it != lista->end() && !lista->empty()){
		if(it.elem() >= lis->back())
			lis->push_back(it.elem());
		else if(it.elem() <= lis->front())
			lis->push_front(it.elem());
		else{
			List<int>::Iterator itNew = lis->begin();
			bool introducido = false;
			while(itNew != lis->end() && !introducido){
				if(it.elem() < itNew.elem()){
					lis->insert(it.elem(), itNew);
					introducido = true;
				}
				itNew.next();
			}
		}
		
		it.next(); // la lista original siempre avanza
	}

	return *lis;
}