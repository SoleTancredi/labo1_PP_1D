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
int addEstadia(EstadiaDiaria* unidadEstadia,int* id, char* nombreDuenio, char* telefono, int idPerro, int dia, int mes, int anio);
int registrarEstadia(EstadiaDiaria* arrayEstadia, int tam, int* id, Perro* arrayPerro, int tamP);

#endif /* ESTADIADIARIA_H_ */
