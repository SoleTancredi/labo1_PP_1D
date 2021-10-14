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
#define CANT_P 30
#define CANT_E 30



int main(void)
{
	EstadiaDiaria arrayEstadias[CANT_E];
	Perro arrayPerros[CANT_P];
	int idPerro = 7000;
	int id = 100000;
	int flagReserva = 0;
	int opcion;
	float promedioEdadPerritos;

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
			addEstadia(&arrayEstadias[0], &id, "ABEL", "4545454545", 7001 ,20,12,2020);
			addEstadia(&arrayEstadias[1], &id, "Carlos", "1123456789", 7002,02,03,1998);
			addEstadia(&arrayEstadias[2], &id, "Pedro", "1123456711", 7000,20,12,2020);
			addEstadia(&arrayEstadias[3], &id, "ZETA", "4545454545", 7001 ,17,12,2020);


		//	if(altaEstadia(arrayEstadias, CANT_E, &id, arrayPerros, CANT_P) == 0)
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
			if(flagReserva == 1 && darDeBajaEstadia(arrayEstadias, CANT_E) == 0)
			{
				printf("\nLa reserva se ha cancelado de manera correcta");
			}
			break;
		case 4:
			if(flagReserva == 1 && ordenarEstadia(arrayEstadias, CANT_E) == 0)
			{
				printf("\nLas estadias se han ordenado correctamente.");
				mostrarListaEstadias(arrayEstadias,CANT_E);
			}

			break;
		case 5:
			mostrarListaPerros(arrayPerros, CANT_P);
			break;
		case 6:
			if(flagReserva == 1)
			{
				promedioEdadPerritos = promedioEdadPerros(arrayPerros, CANT_P);
				printf("\nEl promedio de edad de los perros es: %.2f",promedioEdadPerritos);
			}
			break;
		case 7:
			printf("FIN DEL PROGRAMA");
			break;

		}

	}while(opcion != 7);


	return EXIT_SUCCESS;
}
