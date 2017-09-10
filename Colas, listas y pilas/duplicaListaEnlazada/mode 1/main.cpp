#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
	int n;
	cin >> n;

	while(cin){
		Queue<int> *cola = new Queue<int>();

		while(n != 0){
			cola->push_back(n);
			cin >> n;
		}

		cola->duplica();
		cola->muestraLista();

		delete cola;
		cout << endl;
		cin >> n;
	}


	return 0;
}