#include <iostream>
#include "Stack.h"

using namespace std;

void sumaDig(Stack<int> pila);

int main(){
	Stack<int> pila;
	int elem;

	cin >> elem;

	while(elem != -1){
		int resto, c, suma;	

		if(elem < 10)
			pila.push(elem);

		while(elem >= 10){
			resto = elem%10;
			pila.push(resto);	
			
			c = elem/10;
			if(c < 10)
				pila.push(c);
			
			elem = elem/10;
		}

		sumaDig(pila);

		while(pila.size() > 0) // vaciamos la pila para la siguiente iteracion
			pila.pop();

		cin >> elem;
	}


	return 0;
}

void sumaDig(Stack<int> pila){
	int suma = 0;

	while(pila.size() > 0){
		suma += pila.top();
		cout << pila.top();
		if(pila.size() > 1)
			cout << " + ";
		pila.pop();
	}

	cout << " = " << suma << endl;
}