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
#include "Duenio.h"
#define CANT_P 30
#define CANT_E 30
#define CANT_D 30

int main(void)
{
	EstadiaDiaria arrayEstadias[CANT_E];
	Perro arrayPerros[CANT_P];
	Duenio arrayDuenio[CANT_D];
	int idPerro = 7000;
	int idDuenio = 30000;
	int id = 100000;
	int flagReserva = 0;
	int opcion;
	float promedioEdadPerritos;

	inicializarEstadia(arrayEstadias, CANT_E);
	inicializarPerro( arrayPerros,CANT_P);
	inicializarDuenio(arrayDuenio, CANT_D);
	cargarPerrosHarcode(arrayPerros, &idPerro);
	cargarDuenioHarcode(arrayDuenio, &idDuenio);
	addEstadia(&arrayEstadias[0], &id, "ABEL", "0221596351203", 7001 ,30000,20,12,2020);
	addEstadia(&arrayEstadias[1], &id, "Carlos", "1123456789", 7002,31000,02,03,1998);
	addEstadia(&arrayEstadias[2], &id, "Pedro", "02248429672", 7000,32000,20,12,2020);
	addEstadia(&arrayEstadias[3], &id, "ZETA", "4545454545", 7001 ,33000,17,12,2020);
	addEstadia(&arrayEstadias[4], &id, "Ernesto","48425632", 7002, 34000, 02, 03, 1998);


	do
	{
		opcion = menuEstadia();

		switch(opcion)
		{
		case 1:

			if(altaEstadia(arrayEstadias, CANT_E, &id, arrayPerros, CANT_P, arrayDuenio, CANT_D) == 0)
			{
				flagReserva = 1;
			}
			else
			{
				printf("\nNo se pudo realizar la reserva.");
			}
			break;
		case 2:
			if(flagReserva == 1 && modificarEstadia(arrayEstadias, CANT_E, arrayPerros, arrayDuenio) == 0)
			{
				printf("\n//Los datos han sido modificados de manera exitosa.//");
				mostrarListaEstadias(arrayEstadias, CANT_E);
			}
			else
			{
				printf("\nNo se pudo realizar la modificacion de datos.");
			}
			break;
		case 3:
			if(flagReserva == 1 && darDeBajaEstadia(arrayEstadias, CANT_E) == 0)
			{
				printf("\nLa reserva se ha cancelado de manera correcta");
			}
			else
			{
				printf("\nNo se pudo realizar la cancelacion de la reserva.");
			}
			break;
		case 4:
			if(flagReserva == 1 && ordenarEstadia(arrayEstadias, CANT_E) == 0)
			{
				printf("\nLas estadias se han ordenado correctamente.");
				mostrarListaEstadias(arrayEstadias,CANT_E);
			}
			else
			{
				printf("\nAun no se ha reservado la estadia de ningun perrito. ");
			}

			break;
		case 5:
			if(flagReserva == 1)
			{
				mostrarListaPerros(arrayPerros, CANT_P);
			}
			else
			{
				printf("\nAun no se ha reservado la estadia de ningun perrito. ");
			}

			break;
		case 6:
			if(flagReserva == 1)
			{
				promedioEdadPerritos = promedioEdadPerros(arrayPerros, CANT_P);
				printf("\nEl promedio de edad de los perros es: %.2f",promedioEdadPerritos);
			}
			else
			{
				printf("\nAun no se ha reservado la estadia de ningun perrito. ");
			}
			break;
		case 7:
             //falta
			break;
		case 8:
			mostrarPerrosConSusEstadias(arrayPerros, CANT_P, arrayEstadias, CANT_E);
			break;
		case 9:
			printf("\nFIN DEL PROGRAMA");
			break;
		}

	}while(opcion != 9);


	return EXIT_SUCCESS;
}
