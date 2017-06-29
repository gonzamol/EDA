#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
	
	int n;
	cin >> n; // casos de prueba

	while(n > 0){
		Queue<int> *cola = new Queue<int>(); 
		// Introducir elementos en la cola
		int e, k;
		cin >> e;
		
		while(e != -1){
			cola->push_back(e);
			cin >> e;
		}

		cout << *cola; // cola introducida

		cin >> k; // elementos a invertir
		
		cola->invertirK(k);
		
		cout << *cola;
		n--;
		delete cola;
	}

	return 0;
}