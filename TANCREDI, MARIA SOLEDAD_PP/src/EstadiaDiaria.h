/*
 * EstadiaDiaria.h
 *
 *  Created on: 7 oct. 2021
 *      Author: sole
 */

#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_
#define TAM_NOMBRE 20
#define TAM_TEL 15
#include "Duenio.h"
#include "Perros.h"


struct
{
	int dia;
	int mes;
	int anio;

}typedef Fecha;

struct
{
	int id;
	char nombreDuenio[TAM_NOMBRE];
	char telefonoContacto[TAM_TEL];
	int idPerro;
	int idDuenio;
	int isEmpty;
	Fecha fechaEstadia;

}typedef EstadiaDiaria;



int menuEstadia();
void inicializarEstadia(EstadiaDiaria* array, int tam);
int mostrarUnidadEstadia(EstadiaDiaria unaEstadia);
void mostrarListaEstadias(EstadiaDiaria* arrayEstadias, int tam);
int eliminarEstadia(EstadiaDiaria* unidadEstadia);
int findEmptyEstadia(EstadiaDiaria* arrayEstadia, int tam);
int findByIdEstadia(EstadiaDiaria* arrayEstadia, int tam, int id, int* indice);
int addEstadia(EstadiaDiaria* unidadEstadia,int* id, char* nombreDuenio, char* telefono, int idPerro, int idDuenio, int dia, int mes, int anio);
int altaEstadia(EstadiaDiaria* arrayEstadia, int tam, int* id, Perro* arrayPerro, int tamP, Duenio* arrayDuenio, int tamD);
int subMenuModifEstadia(EstadiaDiaria* arrayEstadia, int tam,int* option);
int modificarEstadia(EstadiaDiaria* arrayEstadia, int tam, Perro* arrayPerritos, Duenio* arrayDuenio);
int validIdEstadia(EstadiaDiaria* arrayEstadia, int tam, int id);
int ordenarEstadia(EstadiaDiaria* arrayEstadia,int tam);
int darDeBajaEstadia(EstadiaDiaria* arrayEstadia, int tam);
void mostrarPerrosConSusEstadias(Perro* arrayPerro, int tamPerro, EstadiaDiaria* arrayEstadia, int tamEstadia);

#endif /* ESTADIADIARIA_H_ */
