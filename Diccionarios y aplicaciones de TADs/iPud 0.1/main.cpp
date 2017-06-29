#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Reproductor.h"

const string CENTINELA = "FIN";

void mostrarLista(List<Cancion> l){

	List<Cancion>::Iterator it = l.begin();
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

	string inst;
	Reproductor rep;
	Cancion cancion;
	Artista artista;
	Duracion duracion;

	cin >> inst;
	if(!cin) return false;

	while(inst != CENTINELA){
		try {
			if (inst == "addSong") {
				cin >> cancion >> artista >> duracion;
				rep.addSong(cancion, artista, duracion);
			}
			else if (inst == "addToPlaylist") {
				cin >> cancion;
				rep.addToPlaylist(cancion);
			}
			else if (inst == "current") {
				rep.current();
			}
			else if (inst == "play") {
				Cancion can = rep.play();
				cout << "Sonando " << can << endl;
			}
			else if (inst == "totalTime") {
				int time = rep.totalTime();
				cout << "Tiempo total " << time << endl;
			}
			else if (inst == "recent") {
				int n;
				cin >> n;
				List<Cancion> l = rep.recent(n);
				cout << "Las " << n << " mas recientes" << endl;
				mostrarLista(l);
				
			}
			else if (inst == "deleteSong") {
				cin >> cancion;
				rep.deleteSong(cancion);
			}
			else
				return false;
		}
		catch (ExcepcionTAD e) { cout << e.msg() << '\n'; }

		cin >> inst;
		if(!cin) return false;
	}
	cout << "----\n";

	return true;
}

int main() {
	while (resuelve()){}

	return 0;
}