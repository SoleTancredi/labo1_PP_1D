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
