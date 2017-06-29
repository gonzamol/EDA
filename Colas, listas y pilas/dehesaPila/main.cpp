#include <iostream>
#include "Stack.h"

//EL JUEZ NO LO COGE PORQUE LO PIDE DE OTRA MANERA PERO ESTO FUNCIONA PERFECTAMENTE


using namespace std;

const int MAX_WAGONS = 100000;

int main(){
	int nVagones;
	Stack<int> pila;
	
	cin >> nVagones; // numero de vagones que entran

	while(nVagones != 0 && 1 <= nVagones && nVagones <= MAX_WAGONS){
		int nPasados = 0, vagonSalida, siguienteVagon = 1, vagonesTomados = 0;
		bool posible = true;

		while(nPasados < nVagones){
			cin >> vagonSalida; // indicar el vagon que sale
			if(vagonSalida >= siguienteVagon){
				for(int i = siguienteVagon; i <= vagonSalida; i++){ // mete el/los vagon/es que haya en siguienteVagon
					pila.push(i);
					cout << "Wagon " << i << " in\n";
				}
				cout << "Wagon " << pila.top() << " out\n";
				pila.pop();
				siguienteVagon = vagonSalida + 1;
				nPasados++; // ha salido uno, se suma al ya pasados
			}

			else{
				if(vagonSalida == pila.top()){
					cout << "Wagon " << pila.top() << " out\n";
					pila.pop();
					nPasados++;
				}
				else
					posible = false;	
			}

			vagonesTomados++; // vagones evaluados
		}

		if(posible == false)
			cout << "IMPOSSIBLE\n";
	
		else
			cout << "POSSIBLE\n";

		//Vaciamos la pila para la siguiente iteraccion
		while(pila.size() > 0)
			pila.pop();

		if(posible == false){ // Para desechar los posibles cin que se han escrito pero que ya no sirven porque se ha llegado a false
			while(vagonesTomados < nVagones){
				cin >> vagonSalida;
				vagonesTomados++;
			}
		}
		
		cin >> nVagones;
	}

	return 0;
}