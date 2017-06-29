#ifndef __CONSULTORIO_H
#define __CONSULTORIO_H
using namespace std;

#include <iostream>
#include <utility>
#include <string>
#include "Fecha.h"
#include "List.h"
#include "TreeMap.h"
#include "HashMap.h"

typedef string Medico;
typedef string Paciente;

class Consultorio{

private:
	typedef TreeMap<Fecha, Paciente> TablaCitas; // TreeMap para que respete el orden
	HashMap<Medico, TablaCitas> tablaMedicos; //esto es el consultorio

public:
	// constructores

	Consultorio(){
		this->tablaMedicos = *new HashMap<Medico, TablaCitas>;
	}

	Consultorio(HashMap <Medico, TablaCitas> tablaMedicos){
		this->tablaMedicos = tablaMedicos;
	}

	// Métodos de la clase

	void nuevoMedico(Medico med){
		TablaCitas citasIniciales;

		if (!tablaMedicos.contains(med)){
			tablaMedicos.insert(med, citasIniciales);
			// cout << "Insertado el medico " << tablaMedicos.cbegin().key(); lo puse para comprobar si lo insertaba bien
		}
	}

	void pideConsulta(Paciente p, Medico m, Fecha f){
		if (!tablaMedicos.contains(m)){
			throw ExcepcionTAD("Medico no existente");	
		}
		else{

			if (tablaMedicos.at(m).contains(f)) //miramos si en la tablaCitas de ese medico esta la fecha
				throw ExcepcionTAD("Fecha ocupada");

			else{
				tablaMedicos[m].insert(f, p); //insertamos el paciente con su fecha en la tablaCitas del medico de tablaMedicos
				// TreeMap<Fecha, Paciente>::ConstIterator it = tablaMedicos.at(m).cbegin();
				// cout << "Pide consulta el paciente " <<  it.value() << endl; //// COMPROBACIONES DE GONZA 
			}
		}
	}

	Paciente siguientePaciente(Medico m){

		if (!tablaMedicos.contains(m))
			throw ExcepcionTAD("Medico no existente");
		else{

			if (tablaMedicos.at(m).empty())
				throw ExcepcionTAD("No hay pacientes");

			else{
				TreeMap<Fecha, Paciente>::ConstIterator it = tablaMedicos.at(m).cbegin();
				return it.value(); //Devuelve el paciente al que apunta el iterador que sera el primero
			}
		}

		return "";
	}

	void atiendeConsulta(Medico m){

		if (!tablaMedicos.contains(m))
			throw ExcepcionTAD("Medico no existente");
		else{

			if (tablaMedicos.at(m).empty())
				throw ExcepcionTAD("No hay pacientes");
			else{
				TreeMap<Fecha, Paciente>::ConstIterator it = tablaMedicos.at(m).cbegin();
				tablaMedicos[m].erase(it.key());
			}

		}

	}

	List<pair<Fecha,Paciente>> listaPacientes(Medico m, Fecha f){

		List<pair<Fecha,Paciente>> listaDePares; //Creamos una lista de Pares	

		Fecha fechaFinalizar = Fecha(f.getDia(),23,59); //Acabaremos ese dia en el ultimo minuto.

		if (!tablaMedicos.contains(m))
			throw ExcepcionTAD("Medico no existente");

		else{
			TablaCitas citas = tablaMedicos.at(m); 
			//Iterador begin, apunta donde empiezan los pacientes 
			TreeMap<Fecha, Paciente>::ConstIterator begin = citas.cbegin(); 

			//Iterador end, apunta al final
			TreeMap<Fecha, Paciente>::ConstIterator end = citas.cend();

			while(begin != end && begin.key() < f )  //Avanzamos el iterador hasta que demos con nuestra fecha
				begin.next();

			while ( begin != end && begin.key() < fechaFinalizar){ //Mientras que la fecha sea menor y no apunten al mismo lado distinto

				pair<Fecha,Paciente> par = pair<Fecha,Paciente>(begin.key(),begin.value()); //Creamos un par con la fecha y el paciente
				listaDePares.push_back(par); //Añadimos el par a la listaDePares
				begin.next(); //avanzamos el iterador
			}		
		}


		return listaDePares;
	}
};
#endif