#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
	int elem;
	cin >> elem;

	while(cin){
		Queue<int> *cola = new Queue<int>();
		
		while(elem != 0){
			cola->push_back(elem);
			cin >> elem;
		}
	
		cola->duplica();
		cola->muestra();
		cout << endl;

		cin >> elem;		
	}

}