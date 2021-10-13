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


	//distinto harcode
	inicializarEstadia(arrayEstadias, CANT_E);
	cargarPerrosHarcode(arrayPerros, &idPerro);
	addEstadia(&arrayEstadias[0], &id, "Carlos", "1123456789", 7002,02,03,1998);
	addEstadia(&arrayEstadias[1], &id, "Pedro", "1123456711", 7003,20,12,2020);
	//mostrarListaEstadias(arrayEstadias, CANT_E);

	registrarEstadia(arrayEstadias, CANT_E, &id, arrayPerros, CANT_P);
	mostrarListaEstadias(arrayEstadias, CANT_E);














   /*Perro arrayPerros[CANT_P];
   int idPerro = 7000;
   int opcion;
   int flagCarga = 0;
   inicializarPerro(arrayPerros, CANT_P);
   cargarPerrosHarcode(arrayPerros, &idPerro);
   do
   {
	   opcion = menuPerrito();

	     switch(opcion)
	     {
	  		case 1:

	  			if(altaPerrito(arrayPerros, CANT_P, &idPerro) == 0)
	  			{
	  				flagCarga = 1;
	  				printf("\n// El nuevo perrito se ha dado de alta correctamente. //");
	  			}
	  			else
	  			{
	  				printf("\nNo se han podido cargar correctamente los datos. Vuelva a intentarlo.");
	  			}
	  		   break;
	  		case 2:
	  			if(flagCarga == 1 && darDeBajaPerrito(arrayPerros, CANT_P) == 0)
	  			{
	  				printf("\nEl perrito se ha eliminado de la lista.");

	  			}
	  			else
	  			{
	  				printf("\nNo hay elementos cargados. ");
	  			}
	  		   break;
	  		case 3:
	  			if(flagCarga == 1 && modificarPerrito(arrayPerros, CANT_P) == 0)
	  			{

	  			}
	  			else
				{
	  				printf("\nNo hay elementos cargados. ");
				}

	  		   break;
	  		case 4:
	  			if(flagCarga == 1 )
	  			{
	  				 mostrarListaPerros(arrayPerros, CANT_P);
	  			}
	  			else
	  			{
	  				printf("\nNo hay elementos cargados. ");
	  			}
	  		   break;
	  		case 5:
	  			printf("FIN DEL PROGRAMA.");
	  		   break;
	     }
   }while(opcion != 5);*/






	return EXIT_SUCCESS;
}
