#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// FUNCIONA PERFECTAMENTE

#include "List.h"
#include "faltas.h"
#include <io.h>
#include <fcntl.h>

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
	faltas faltas;
	IdAlumno a;
	IdAsig s;

	for (int i = 0; i < numCasos; ++i) {
		try {
			cin >> inst;
			if(inst == "anadirAlumno"){
				cin >> a;
				faltas.anadirAlumno(a);
				cout << " Alumno anadido: " << a << endl;
			}
			else if (inst == "anadirFalta") {
				cin >> a >> s;
				faltas.anadirFalta(a, s);
				cout << " Anadida falta al alumno: " << a << " en la asignatura " << s << endl;
			}
			else if (inst == "anadirAsignatura") {
				cin >> s;		
				faltas.anadirAsignatura(s);
				cout << " Asignatura anadida: " << s << endl;
			}
			else if (inst == "noFaltas") {	
				List<IdAlumno> lista;
				lista = faltas.noFaltas();
				cout << " Los alumnos con 0 faltas en todas las asignaturas son: " << endl;
				mostrarLista(lista);
				cout << "---\n";
			}
			else if (inst == "totalFaltas") {
				cin >> a;
				int total = faltas.totalFaltas(a);
				cout << " Faltas del alumno " << a << " = " << total << endl;
			}
			else if (inst == "maxFaltas") {
				IdAsig s = faltas.maxFaltas();
				cout << " Asignatura con mayor numero de faltas: " << s << endl;
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