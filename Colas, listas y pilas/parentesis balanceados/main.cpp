#include <iostream>
#include "Stack.h"

//GONZALO MOLINA D�AZ & D�MASO S�NCHEZ ARENAS
//C38

using namespace std;

bool popNext(char esperado, Stack<char> &x);

int main() {

	// pila vacia, 0 errores: listos para empezar
	Stack<char> pila;
	int errors = 0;
	bool anterior = true;

	string c;
	getline(cin, c);

	while (c != ".") {
		for (int i = 0; i < c.size(); i++){
			if (c[i] == '(' || c[i] == '{' || c[i] == '<' || c[i] == '[')
				pila.push(c[i]);

			else if (c[i] == ')'){
				if (!popNext('(', pila))
					errors++;
			}

			else if (c[i] == '}'){
				if (!popNext('{', pila))
					errors++;
			}

			else if (c[i] == '>'){
				if (!popNext('<', pila))
					errors++;
			}

			else if (c[i] == ']'){
				if (!popNext('[', pila))
					errors++;
			}

		}
		if (pila.empty() && errors == 0)
			cout << "YES" << endl;

		else
			cout << "NO" << endl;

		while (pila.size() > 0)
			pila.pop();

		errors = 0;
		getline(cin, c);
	}

	return 0;
}

bool popNext(char esperado, Stack<char> &pila){
	bool ok = false;
	if (!pila.empty() && pila.top() == esperado){
		pila.pop();
		ok = true;
	}
	return ok;
}



// si c es 
//    - un par�ntesis, llave, mayor-que o corchete de apertura, lo apila
//    - un par�ntesis, llave, menor-que o corchete de cierre, 
//         si cierra bien con el �ltimo apilado, desapila el �ltimo
//         y si no, apunta 1 error
//    - un fin-de-l�nea, y 
//         si la pila est� vac�a y hay 0 errores, muestra YES
//         y si no, muestra NO
//         (y en ambos casos vac�a la pila y hace errores=0, para la siguiente vuelta)
//    - todo lo dem�s, lo ignora
// en los casos de prueba, siempre hay un '\n' como �ltimo caracter