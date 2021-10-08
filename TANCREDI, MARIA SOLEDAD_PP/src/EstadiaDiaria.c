/*
 * DailyStay.c
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
	int opcion;

	printf("***** ESTADIAS DIARIAS *****");

	if(utn_getNumber(&opcion, "Ingrese la opcion que desee realizar: ", "Error. Reingrese la opcion. "
			, 1, 6, 1) == 0)
	{
		switch(opcion)
		{
			case 1:
				//reservar estadia
				break;
			case 2:
				//modificar estadia
				break;
			case 3:
				//cancelarestadia
				break;
			case 4:
				//listar estadia
				break;
			case 5:
				//listar perros
				break;
			case 6:
				//promedio de edad de lo perros
				break;

		}
	}


return opcion;


}
