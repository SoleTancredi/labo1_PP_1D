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
