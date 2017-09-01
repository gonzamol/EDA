// AUTOR: GONZALO MOLINA DÍAZ
// FECHA 01/09/2017
// FUNCIONA PERFECTAMENTE

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "List.h"
#include "espacioMatic.h"

template<class T>
void mostrarLista(List<T> l){

	List<T>::Iterator it = l.begin();
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
	EspacioMatic mat;
	Id id;
	Modulo mod;
	Nivel niv;

	for (int i = 0; i < numCasos; ++i) {
		try {
			cin >> inst;
			if (inst == "nuevaNave") {
				cin >> id;
				mat.nuevaNave(id);
				cout << "Insertada la nave con ID " << id << endl;
			}
			else if (inst == "equipaNave") {
				cin >> id >> mod >> niv;		
				mat.equipaNave(id, mod, niv);
				cout << "La nave con id " << id << " ha sido equipada con el modulo " << mod << " a nivel " << niv << endl;
			}
			else if (inst == "estropeaNave") {
				cin >> id >> mod;
				if(mat.estropeaNave(id, mod))
					cout << "El modulo " << mod << " de la nave de ID " << id << " ha restado 1 nivel" << endl;
				else
					cout << "El modulo " << mod << " de la nave de ID " << id << " o no existe o su nivel era 0" << endl;
			}
			else if (inst == "navesDefectuosas") {
				List<Id> lista;
				lista = mat.navesDefectuosas();
				mostrarLista(lista);
			}
			else if (inst == "modulosNave"){
				cin >> id;
				List<Modulo> lista;
				lista = mat.modulosNave(id);
				cout << " Modulos de la nave con ID " << id << endl;
				mostrarLista(lista);
			}
			else if(inst == "verNivelModuloNave"){
				cin >> id >> mod;
				cout << mat.verNivelModuloNave(id, mod) << endl;
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