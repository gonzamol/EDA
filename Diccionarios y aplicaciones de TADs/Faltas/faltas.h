#ifndef FALTAS_H
#define FALTAS_H

#include <iostream>
#include "HashMap.h"
#include "TreeMap.h"
#include "List.h"

using namespace std;

typedef string IdAsig;
typedef string IdAlumno;
typedef int numFaltas;

class faltas {
private:
	typedef struct {
		HashMap<IdAlumno, numFaltas> tablaAlumnos;
		numFaltas num;
	} InfoAsignatura;
	HashMap<IdAsig, InfoAsignatura> lista_faltas;
	TreeMap<IdAlumno, numFaltas> alumnos;

public:

	// LINEAL RESPECTO AL NUMERO DE ASIGNATURAS EN lista_faltas
	void anadirAlumno(const IdAlumno &a){
		//se añade el alumno a la tabla general de 'alumnos'
		if(!alumnos.contains(a)) // siempre y cuando no estuviera ya
			alumnos.insert(a, 0);
		else
			throw ExcepcionTAD("Ese alumno ya existe en el sistema");

		// se añade el alumno a lista_faltas
		HashMap<IdAsig, InfoAsignatura>::Iterator it = lista_faltas.begin();
		while(it != lista_faltas.end()){
			it.value().tablaAlumnos.insert(a, 0);
			it.next();
		}

	}

	// O(log(A)) siendo A el numero de alumnos dadas de alta
	void anadirFalta(const IdAlumno &a, const IdAsig &s){
		if(lista_faltas.contains(s)){
			if(lista_faltas.at(s).tablaAlumnos.contains(a)) {
				if(alumnos.contains(a)){
					lista_faltas[s].tablaAlumnos[a]++; // aumento 1 el numero de faltas del alumno 'a' en la asignatura 's'
					lista_faltas[s].num++; // aumento el numero de faltas totales de todos los alumnos en esa asignatura
					alumnos[a]++; // le aumento una falta a ese alumno 'a'
				}
				else
					throw ExcepcionTAD("No esta en la tabla alumnos");
			}
			else
				throw ExcepcionTAD("No esta en la lista_faltas");
		}
		else
			throw ExcepcionTAD("Esa asignatura no existe");
	}

	// lineal respecto al numero de alumnos dados de alta en 'alumnos'
	void anadirAsignatura(const IdAsig &s){
		if(!lista_faltas.contains(s)){
			InfoAsignatura info;
			TreeMap<IdAlumno, numFaltas>::ConstIterator it = alumnos.cbegin(); // iterador para coger todos los alumnos disponibles			
			
			while(it != alumnos.cend()){
				info.tablaAlumnos.insert(it.key(), 0); // meto al alumno con 0 faltas
				it.next();
			}
			info.num = 0;
			lista_faltas.insert(s, info); 
		}
		else
			throw ExcepcionTAD("Esa asignatura ya esta en el sistema");
	}

	// lineal respecto al numero de alumnos dados de alta en 'alumnos'
	List<IdAlumno> noFaltas(){
		List<IdAlumno> lista;
		TreeMap<IdAlumno, numFaltas>::Iterator it = alumnos.begin();

		while(it != alumnos.end()){
			if(it.value() == 0)
				lista.push_back(it.key());
			it.next();
		}
		
		return lista;
	}

	// O(log(A)) siendo a el numero de alumnos en 'alumnos'
	int totalFaltas(const IdAlumno &a){
		if(alumnos.contains(a))
			return alumnos[a];
		else
			throw ExcepcionTAD("Ese alumno no existe");
	}

	// lineal respecto al numero de asignaturas en lista_faltas
	IdAsig maxFaltas(){
		HashMap<IdAsig, InfoAsignatura>::Iterator it = lista_faltas.begin();
		int max = 0;
		IdAsig id;

		while(it != lista_faltas.end()){
			if(it.value().num >= max){
				id = it.key();
				max = it.value().num;
			}
			it.next();
		}

		return id;
	}

};

#endif