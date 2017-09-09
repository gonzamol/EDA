#include <iostream>
#include "Stack.h"

using namespace std;

int sumaDigitos(Stack<int> pila){
	int suma = 0;

	while(!pila.empty()){
		suma += pila.top();
		pila.pop();
	}

	return suma;
}

int main(){
	int elem;
	cin >> elem;

	while(elem != -1){
		Stack<int> pila;
		int coc = elem;
		int res = elem%10;

		while(coc >= 10){
			pila.push(res);
			coc = coc/10;
			res = coc%10;			
		}

		pila.push(coc);

		int suma = sumaDigitos(pila);

		while(!pila.empty()){
			cout << pila.top();
			
			if(pila.size() > 1)
				cout << " + ";
			
			pila.pop();
		}

		cout << " = " << suma << endl;
	
		cin >> elem;
	}

	return 0;
}