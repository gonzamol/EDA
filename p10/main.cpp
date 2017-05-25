#include <iostream>
#include <list>
#include "TreeMap.h"
#include <string>

using namespace std;

void printLista(const list<int>& l, ostream& sout){
	list<int>::const_iterator it = l.cbegin();
	if (it != l.cend()){
		sout << *it;
		++it;
	}
	while (it != l.end()){
		sout << " " << *it;
		++it;
	}
	sout << endl;
}

void aMinusculas(std::string& palabra) {
	for (char& c : palabra) {
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
	}
}

void resuelveCaso(int numLineas){
	char c;
	string palabra;

	TreeMap<string, list<int>> refs;

	for (int linea = 1; linea <= numLineas; linea++){
		cin.get(c); // para orden alfabetico
		while (c != '\n'){
			cin.unget();
			cin >> palabra;
			aMinusculas(palabra);
			if (palabra.size() > 2){
				if (!refs.contains(palabra)){ // si la palabra no esta en el arbol
					list<int> lista;
					lista.push_back(linea);
					refs.insert(palabra, lista); //insertamos en el arbol la palabra y su valor				
				}
				else // si NO esta la palabra en el arbol
					if (refs[palabra].back() != linea)
						refs[palabra].push_back(linea); //añadimos a la lista de la palabra la nueva linea. at es solo observadora
			}
			cin.get(c);
		}

	}

	TreeMap<string, list<int>>::ConstIterator it = refs.cbegin();

	while (it != refs.cend())
	{
		cout << it.key() << " ";
		printLista(refs.at(it.key()), cout);//mostramos la lista de enteros de una palabra concreta
		it.next();
	}
}

int main(){
	int numLineas;
	char c;
	cin >> numLineas;
	cin.get(c);
	while (numLineas != 0){
		resuelveCaso(numLineas);
		cout << "----" << endl;
		cin >> numLineas;
		cin.get(c);
	}
}