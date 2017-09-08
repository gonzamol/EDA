#include <iostream>
#include "Queue.h"

//  EJERCICIO 1 EXAMEN 27 DE JUNIO 2017. FUNCIONA PERFECTAMENTE

using namespace std;

int main(){
	int n;
	cin >> n;

	while(n > 0){
		try {
			Queue<int> *cola = new Queue<int>();
			int pos, dist;
			int elem;

			cin >> elem;
			while(elem != -1){
				cola->push_back(elem);
				cin >> elem;
			}

			cin >> pos >> dist;
			cola->desplaza(pos, dist);

			cout << *cola << endl;

			n--;
			delete cola;
		}
			catch (ExcepcionTAD e) { cout << e.msg() << '\n' << "---\n"; }
		}

		return 0;
	}