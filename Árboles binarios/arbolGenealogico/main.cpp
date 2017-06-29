#include <iostream>
#include "Arbin.h"

using namespace std;

//FUNCIONA EXCEPTO CUANDO PONES UN HIJO MAYOR QUE SU PADRE EN ALGUNA HOJA

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


bool genealogico(Arbin<int> arbol, int &numGen){
	if(arbol.esVacio()){
		return false;
		numGen = 0;
	}
	else if(arbol.hijoDr().esVacio() && arbol.hijoIz().esVacio()){
		numGen = 1;
		return true;
	}

	else {
		int numGenDr, numGenIz;
		bool esIz, esDr;

		esIz = genealogico(arbol.hijoIz(), numGenIz);
		esDr = genealogico(arbol.hijoDr(), numGenDr);

		if(esIz || esDr){

			if(!arbol.hijoDr().esVacio()){ // compara el padre con el hijo derecho
				if(arbol.raiz() >= arbol.hijoDr().raiz() + 18)
					esDr = true;
				else
					esDr = false;
			}
			else if(arbol.hijoDr().esVacio())
				esDr = true;

			if(!arbol.hijoIz().esVacio()){ // compara el padre con el hijo izquierdo
				if(arbol.raiz() >= arbol.hijoIz().raiz() + 18)
					esIz = true;
				else
					esIz = false;
			}	
			else if(arbol.hijoIz().esVacio())
				esIz = true;


			if(numGenDr > numGenIz)
				numGen = numGenDr + 1;
			else
				numGen = numGenIz + 1;

			if(esIz == true && esDr == true){ // si ambas son true hasta el momento
				if(!arbol.hijoDr().esVacio() && !arbol.hijoIz().esVacio()){ // y ningun hijo es vacio
					if(arbol.hijoIz().raiz() >= arbol.hijoDr().raiz() + 2){ // entonces comprueba que la diferencia entre hijos es la exigida
						return true;
					}
					else{
						return false;
					}
				}

			}

			if(esIz == false || esDr == false)
				return false;
		}
		else
			return false;
	}
	return true;
}

void resolverCaso(){
	Arbin<int> arbol;
	int numGen;
	bool es;
	arbol = leerArbol(-1);
	es = genealogico(arbol, numGen);

	if(es){
		cout << "YES" << " " << numGen << endl;
	}
	else
		cout << "NO" << endl;
}

int main(){
	int n;
	cin >> n; // casos de prueba

	while(n>0){
		resolverCaso();
		n--;
	}

	return 0;
}