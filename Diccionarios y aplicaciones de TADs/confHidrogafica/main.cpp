#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

//FUNCIONA PERFECTO

#include "List.h"
#include "ConfHidro.h"

void mostrarLista(List<Rio> l){

	List<Rio>::Iterator it = l.begin();
	if (it != l.end()){
		cout << "    " << it.elem() << endl;
		it.next();
	}
	while (it != l.end()){
		cout << "    " << it.elem() << endl;	
		it.next();
	}

}

bool resuelve() {

	int numCasos;
	cin >> numCasos;
	if (!cin) return false;

	string inst;
	Rio r; 
	Pantano p;
	ConfHidro conf;
	int cap, lit;

	for (int i = 0; i < numCasos; ++i) {
		try {
			cin >> inst;
			if (inst == "an_rio") {
				cin >> r;
				conf.an_rio(r);
				cout << "Insertado el rio " << r << endl;
			}
			else if (inst == "an_pantano") {
				cin >> r >> p >> cap >> lit;		
				conf.an_pantano(r, p, cap, lit);
				cout << "El pantano " << p << " ha sido insertado en el rio " << r << " con una capacidad de " << cap << " y "  << lit <<" litros insertados\n";
			}
			else if (inst == "embalsar") {
				cin >> r >> p >> lit;
				conf.embalsar(r, p ,lit);
				cout << "El pantano " << p << " del rio " << r << " ha recibido " << lit << " litros mas\n";
			}
			else if (inst == "embalsado_pantano") {
				cin >> r >> p;
				int m = conf.embalsado_pantano(r, p);
				if(m == -1)
					cout << "El pantano o el rio no existen\n";
				else
					cout << "El pantano " << p << " del rio " << r << " tiene " << m << " litros \n";
			}
			else if (inst == "reserva_cuenca"){
				cin >> r;
				int m = conf.reserva_cuenca(r);
				if(m != -1)
					cout << "La cuenca del rio " << r << " es " << m << endl;
				else
					cout << "No existe el rio " << r << " en la confederacion\n";
				cout << "---\n";
			}

			else if (inst == "transvase") {
				Rio r2;
				Pantano p2;
				cin >> r >> p >> r2 >> p2 >> lit; 
				conf.transvase(r, p, r2, p2, lit);
				cout << " Se han pasado " << lit << " litros desde el pantano " << p << " al pantano " << p2 << endl;
				cout << "---\n";
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