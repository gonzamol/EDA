#include <iostream>
#include <string>
#include "Set.h"
#include "Error.h"

using namespace std;

const int MAX = 2000;

template <class T>
void kDistintos(Set<T> &s, int k, T v[], int cont);

int main(){
	int k, cont;
	char c;
	int V[MAX];
	string palabras[MAX];

	//cout << "Pon cuantos cuantos numeros menores distintos quieres (0 para acabar): ";

	cin >> c; //LEEMOS SI ES UNA N O UNA P

	while (!cin.fail()){
		cont = 0;

		cin >> k;

		if (c == 'N'){
			Set<int> num;
			int j = 0;
			cin >> V[j];

			while (V[j] != -1){ //while de final de la serie
				j++;
				cin >> V[j];
				cont = j; //Numero de elementos del vector
			}

			kDistintos(num, k, V, cont);
			cout << num << endl;
		}

		else if (c == 'P'){
			Set<string> pal;
			int j = 0;
			cin >> palabras[j];

			while (palabras[j] != "FIN"){ //while de final de la serie
				j++;
				cin >> palabras[j];
				cont = j; //Numero de elementos del vector
			}

			kDistintos(pal, k, palabras, cont);
			cout << pal << endl;
		}

		cin >> c;

	}

	cout << endl;

	return 0;
}


//COMPLEJIDAD : theta(k^2 + n logk)
template <class T>
void kDistintos(Set <T> &s, int k, T v[], int cont){
	int cont2 = 0;
	int i = 0, j = 0;

	while (i < k){ //Añade los k primeros distintos a s
		if (!s.contains(v[j])){
			s.add(v[j]);
			i++; //Contador para ver el numero de elementos distintos
		}
		j++; //Contador del array para evaluar todos los elementos
	}

	while (k <= cont){ //Cont es size del array

		if (s.getMin() < v[k] && !s.contains(v[k])){
			s.removeMin();
			s.add(v[k]);
			cont2++;
		}
		k++;
	}

}