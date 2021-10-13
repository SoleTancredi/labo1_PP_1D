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

int menu()
{
	int option;

	printf("***** ESTADIAS DIARIAS *****");

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


int mostrarUnidadEstadia(EstadiaDiaria unaEstadia)
{
	int ok=-1;
	if(unaEstadia.isEmpty == 1)
	{
		ok=0;
		printf("\n**Datos del Perro**");
		printf("\nID: %d", unaEstadia.id);
		printf("\nNOMBRE DUENIO: %s ", unaEstadia.nombreDuenio);
		printf("\nTELEFONO CONTACTO: %s", unaEstadia.telefonoContacto);
		printf("\nID PERRO: %d", unaEstadia.idPerro);
		// IMPRIMIR FECHA
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
		if(mostrarUnidadPerro(arrayEstadias[i]) == 0)
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


int findEmpty(EstadiaDiaria* arrayEstadia, int tam)
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



int addEstadia(Perro* pUnidadPerrito, int len, int* id, char* name, char* race, int age)
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
}


int findById(Perro* arrayPerritos, int tam, int id, int* indice)
{
	int retorno = -1;

	if(arrayPerritos != NULL && indice != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayPerritos[i].isEmpty == 1 && arrayPerritos[i].id == id)
			{
				*indice = i;
				retorno = 0;
			}
		}
	}

	return retorno;

}



