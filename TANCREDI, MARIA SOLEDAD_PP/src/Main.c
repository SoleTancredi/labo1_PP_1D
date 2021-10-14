/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : Sole Tancredi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "BibliotecaUtn2021.h"
#include "Perros.h"
#include "EstadiaDiaria.h"
#define CANT_P 10
#define CANT_E 30
#define CANT_F 30


int main(void)
{
	EstadiaDiaria arrayEstadias[CANT_E];
	Perro arrayPerros[CANT_P];
	int idPerro = 7000;
	int id = 100000;
	int flagReserva = 0;
	int opcion;

	inicializarEstadia(arrayEstadias, CANT_E);
	inicializarPerro( arrayPerros,CANT_P);
	cargarPerrosHarcode(arrayPerros, &idPerro);

	do
	{
		opcion = menuEstadia();

		switch(opcion)
		{
		case 1:
			// HARDCODE
			addEstadia(&arrayEstadias[1], &id, "ABEL", "4545454545", 7001 ,20,12,2020);
			addEstadia(&arrayEstadias[0], &id, "Carlos", "1123456789", 7002,02,03,1998);
			addEstadia(&arrayEstadias[2], &id, "Pedro", "1123456711", 7000,20,12,2020);
			addEstadia(&arrayEstadias[3], &id, "ZETA", "4545454545", 7001 ,17,12,2020);


		//	if(registrarEstadia(arrayEstadias, CANT_E, &id, arrayPerros, CANT_P) == 0)
			//{
				flagReserva = 1;
			//}
			break;
		case 2:
			if(flagReserva == 1 && modificarEstadia(arrayEstadias, CANT_E, arrayPerros) == 0)
			{
				printf("\n//Los datos han sido modificados de manera exitosa.//");
				mostrarListaEstadias(arrayEstadias, CANT_E);
			}
			break;
		case 3:

			break;
		case 4:
			mostrarListaEstadias(arrayEstadias, CANT_E);
			break;
		case 5:
			ordenar(arrayEstadias, CANT_E);
			mostrarListaEstadias(arrayEstadias,CANT_E);
			break;
		case 6:
			break;
		case 7:
			printf("FIN DEL PROGRAMA");
			break;

		}

	}while(opcion != 7);


	return EXIT_SUCCESS;
}
