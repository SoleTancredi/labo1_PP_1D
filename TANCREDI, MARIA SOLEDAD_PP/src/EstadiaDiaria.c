/*
 * EstadiaDiaria.c
 *
 *  Created on: 7 oct. 2021
 *      Author: sole
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "BibliotecaUtn2021.h"
#include "EstadiaDiaria.h"
#include "Perros.h"

int menuEstadia()
{
	int option;

	printf("\n***** ESTADIAS DIARIAS *****\n");

	if(utn_getNumber(&option, "Ingrese la opcion que desee realizar: "
			"\n1.Reservar estadia: "
			"\n2.Modificar estadia: "
			"\n3.Cancelar estadia: "
			"\n4.Listar estadias: "
			"\n5.Listar perros: "
			"\n6.Promedio de edad de los perros: "
			, "Error. Reingrese la opcion. "
			, 1, 6, 1) == 0)
	{
		printf("Usted ha ingresado la opcion nº %d", option);

	}

return option;

}

void inicializarEstadia(EstadiaDiaria* array, int tam)
{
	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam ; i++)
		{
			array[i].isEmpty = 0;
		}
	}
}

void cargarEstadiaHarcode(EstadiaDiaria* unidadEstadia, int* id)
{

		(*id)++;
}


int mostrarUnidadEstadia(EstadiaDiaria unaEstadia)
{
	int ok=-1;

	if(unaEstadia.isEmpty == 1)
	{
		ok=0;
		printf("\n****DATOS DE LA ESTADIA****");
		printf("\nID: %d", unaEstadia.id);
		printf("\nNOMBRE DUEÑO: %s ", unaEstadia.nombreDuenio);
		printf("\nTELEFONO CONTACTO: %s", unaEstadia.telefonoContacto);
		printf("\nID PERRO: %d", unaEstadia.idPerro);
		printf("\nFECHA: %d / %d / %d", (unaEstadia).fechaEstadia.dia,
				(unaEstadia).fechaEstadia.mes, (unaEstadia).fechaEstadia.anio);
		printf("\n------------------------------");
	}
	return ok;
}

void mostrarListaEstadias(EstadiaDiaria* arrayEstadias, int tam)
{
	int conteoEstadias=0;
	for(int i =0; i < tam; i++)
	{
		//printf("\nmostrar I valor: %d\n", i);
		if(mostrarUnidadEstadia(arrayEstadias[i]) == 0)
		{
			conteoEstadias++;
		}
	}

	printf("\n Cantidad de perros :%d \n", conteoEstadias);
}



int eliminarEstadia(EstadiaDiaria* unidadEstadia)
{
	int retorno=-1;

	if(unidadEstadia!=NULL)
	{
		(*unidadEstadia).isEmpty=0;
		retorno =0 ;
	}
	return retorno;
}


int findEmptyEstadia(EstadiaDiaria* arrayEstadia, int tam)
{
	int indice = -1;

	if(arrayEstadia != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayEstadia[i].isEmpty == 0)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int addEstadia(EstadiaDiaria* unidadEstadia,int* id, char* nombreDuenio, char* telefono, int idPerro, int dia, int mes, int anio)
{
	int retorno = -1;

	if(unidadEstadia != NULL && nombreDuenio != NULL && telefono != NULL)
	{
		(*unidadEstadia).isEmpty = 1;
		(*unidadEstadia).id = *id;
		strcpy((*unidadEstadia).nombreDuenio, nombreDuenio);
		strcpy((*unidadEstadia).telefonoContacto,telefono);
		(*unidadEstadia).idPerro = idPerro;
		(*unidadEstadia).fechaEstadia.dia = dia;
		(*unidadEstadia).fechaEstadia.mes = mes;
		(*unidadEstadia).fechaEstadia.anio = anio;
		(*id)++;
		retorno = 0;

	}

	return retorno;
}


/*int addEstadia(Perro* pUnidadPerrito, int len, int* id, char* name, char* race, int age)
{
	int retorno = -1;

	if(pUnidadPerrito != NULL && id != NULL && name != NULL && race != NULL)
	{

		(*pUnidadPerrito).isEmpty = 1;
		strcpy((*pUnidadPerrito).nombre, name);
		strcpy((*pUnidadPerrito).raza, race);
		(*pUnidadPerrito).edad = age;
		(*pUnidadPerrito).id = (*id)++;
		retorno = 0;
	}

	return retorno;
}*/


int findByIdEstadia(EstadiaDiaria* arrayEstadia, int tam, int id, int* indice)
{
	int retorno = -1;

	if(arrayEstadia != NULL && indice != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayEstadia[i].isEmpty == 1 && arrayEstadia[i].id == id)
			{
				*indice = i;
				retorno = 0;
			}
		}
	}

	return retorno;

}



