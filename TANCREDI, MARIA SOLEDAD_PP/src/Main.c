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


int main(void) {

   Perro arrayPerros[CANT_P];
   int idPerro = 7000;
   int opcion;
   int flagCarga = 0;


   inicializarPerro(arrayPerros, CANT_P);


   do
   {
	   opcion = menuPerrito();

	     switch(opcion)
	     {
	  		case 1:
	  			cargarPerrosHarcode(arrayPerros, &idPerro);
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


   }while(opcion != 5);






	return EXIT_SUCCESS;
}
