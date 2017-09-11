#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "List.h"
#include "BarcoMatic.h"
#include <io.h>
#include <fcntl.h>

// FUNCIONA OK

bool resuelve() {
	int numCasos;
	cin >> numCasos;
	if (!cin) return false;

	string inst;
	BarcoMatic barco;
	Nombre nom;
	Bodega bod;
	Especie esp;
	Peso peso;


	for (int i = 0; i < numCasos; ++i) {
		try {
			cin >> inst;
			if(inst == "nuevo"){
				cin >> bod;
				barco.nuevo(bod);
				cout << " ***Barco creado\n";
			}
			else if (inst == "altaPescador") {
				cin >> nom;
				barco.altaPescador(nom);
				cout << " ***Insertado el pescador " << nom << endl;
			}
			else if (inst == "nuevaCaptura") {
				cin >> nom >> esp >> peso;		
				barco.nuevaCaptura(nom, esp, peso);
				cout << " ***El pescador " << nom << " ha conseguido un ejemplar de " << esp << " con un pesaje de " << peso << " kg"<< endl;
			}
			else if (inst == "capturasPescador") {	
				cin >> nom;
				List<pair<Especie, Peso>> lista;
				lista = barco.capturasPescador(nom);
				cout << " El pescador " << nom << " ha recolectado: " << endl;
				for (auto p : lista) {					
					cout << " " << p.first << " a " << p.second << " kg" << endl;					
				}
				cout << "---\n";
			}
			else if (inst == "kilosEspecie") {
				cin >> esp;
				int total = barco.kilosEspecie(esp);
				cout << " Kg total de la especie " << esp << " = " << total << endl;
			}
			else if (inst == "kilosPescador") {
				cin >> nom;
				int total = barco.kilosPescador(nom);
				cout << " Kg total pescados por " << nom << " = " << total << endl;
			}
			else if(inst == "bodegaRestante"){
				int total = barco.bodegaRestante();
				cout << " A la bodega le quedan (en kg): " << total << endl;
			}
		}
		catch (ExcepcionTAD e) { cout << e.msg() << '\n' << "---\n"; }

	}
	cout << "------\n";


	return true;
}

int main() {
	while (resuelve()){}
	return 0;
}