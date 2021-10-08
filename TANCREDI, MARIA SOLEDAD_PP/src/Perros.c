/*
 * Dogs.c
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
#include "Perros.h"

/**
 * @fn void inicializarPerro(Perro*, int)
 * @brief se inicializa el isEmpty solamente ya que despues guiandome por ese dato, si esta vacio directamente
 * no muestro el dato y si sucede lo contrario si.
 *
 * @param array
 * @param tam
 */
void inicializarPerro(Perro* array, int tam)
{
	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam ; i++)
		{
			array[i].isEmpty = 0;
		}
	}
}

/**
 * @fn void mostrarUnidadPerro(Perro)
 * @brief muestra el contenido de la variable de tipo perro
 *
 * @param unPerro
 */
int mostrarUnidadPerro(Perro unPerro)
{
	int ok=-1;
	if(unPerro.isEmpty == 1)
	{
		ok=0;
		printf("\n**Datos del Perro**");
		printf("\nID: %d", unPerro.id);
		printf("\nNOMBRE: %s ", unPerro.nombre);
		printf("\nRAZA: %s", unPerro.raza);
		printf("\nEDAD: %d", unPerro.edad);
		printf("\n------------------------------");
	}
	return ok;
}

void mostrarListaPerros(Perro* arrayPerros, int tam)
{
	int conteoPerros=0;
	for(int i = 0; i < tam; i++)
	{
		//+mostrarUnidadPerro(arrayPerros[i]);//notacion vectorial
		//mostrarUnidadPerro(*(arrayPerros + i));//notacion de pùntero
		if(mostrarUnidadPerro(*(arrayPerros + i))==0){
			conteoPerros++;
		}
	}

	printf("\n Cantidad de perros :%d \n",conteoPerros );
}

void cargarPerrosHarcode(Perro* arrayPerros, int* id)
{
		Perro bufferPerrito[] =
		{
			{7000, "Lobo", "Sharpei", 2,1},
			{7001, "Sheila", "Golden", 12,1},
			{7002, "Reina", "Galgo",13,1}
		};

		for(int i = 0; i < 3; i++)
		{
			arrayPerros[i] = bufferPerrito[i];
		}
}


int eliminarPerro(Perro* unidadPerro)
{
	int retorno=-1;
	if(unidadPerro!=NULL)
	{
		unidadPerro->isEmpty=0;
		retorno =0 ;
	}
	return retorno;
}
