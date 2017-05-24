#include <iostream>
#include "Arbin.h"
using namespace std;

Arbin<int> reconstruir(List<int> post, List<int> in);

void mostrarArbol(List<int> *niveles) { // Usando un iterador recorremos el arbol
	List<int>::ConstIterator it = niveles->cbegin();
	while (it != niveles->cend()) {
		cout << it.elem() << " ";
		it.next();
	}
	cout << endl;
}

int main(){

	List<int> post, in;
	
	int Px,Py,x,y;
	bool postSalir, inSalir, continuar = true;

	while (continuar){
		postSalir = false, inSalir = false;
		post = List<int>();
		in = List<int>();

		cin >> x;
		Px = x;

		while (!postSalir && x != -1){ // primera l�nea
			post.push_back(x);

			cin >> x;

			if (x == -1)
				postSalir = true;
		}

		cin >> y;
		Py = y;

		while (!inSalir && y != -1){ // segunda l�nea
			in.push_back(y);

			cin >> y;

			if (y == -1)
				inSalir = true;
		}

		if (Px == -1 && Py == -1) //eval�a si los dos primeros de cada l�nea han sido uno, de ser as�, sale del while mas externo y acaba
			continuar = false;

		Arbin<int> arbol = reconstruir(post, in);
		mostrarArbol(arbol.niveles());
	}

	return 0;
}

Arbin<int> reconstruir(List<int> post, List<int> in){
	List<int> postIz, postDr, inIz, inDr;
	Arbin<int> arbolIz, arbolDr;

	if (post.empty() && in.empty()){ // si ambas listas est�n vac�as, devuelve un �rbol vac�o
		return Arbin<int>();		// no vale con size() == 1 porque el -1 no lo mete dentro de la lista, por lo que no hay nada
	}								// no he probado con size() == 0, pero es mejor aprovechar la funci�n empty 

	else {
		int raiz = post.back(), posIz = 0;
		int elem = in.at(posIz);
		int numElemsIzq = 0;

		while (elem != raiz){ //sublista inIz
			numElemsIzq++;
			inIz.push_back(elem);
			posIz++;
			elem = in.at(posIz);
		}

		int posDr = posIz+1;

		while (posDr <= in.size() - 1){ //sublista inDr o elem!=NULL
			elem = in.at(posDr);
			inDr.push_back(elem);
			posDr++;	
		}

		int dondeEmpiezo = numElemsIzq; // debe ser igual porque en el caso de postorden la raiz se encuentra al final
										//hay que tener en cuenta tambi�n que comienza en la posici�n 0
		int x = numElemsIzq - 1;

		while (x >= 0){ //sublista postIz
			postIz.push_front(post.at(x));
			x--;
		}

		while (post.at(dondeEmpiezo) != raiz){ //sublista postDr
			postDr.push_back(post.at(dondeEmpiezo));
			dondeEmpiezo++;
		}

		arbolIz = reconstruir(postIz, inIz);
		arbolDr = reconstruir(postDr, inDr);

		return Arbin<int>(arbolIz, raiz, arbolDr);
	}

}