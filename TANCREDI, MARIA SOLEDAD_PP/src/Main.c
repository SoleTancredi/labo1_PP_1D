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
#define CANT_P 5
#define CANT_E 30


int main(void) {

   Perro arrayPerros[CANT_P];
   int id =7000;
  // EstadiaDiaria arrayEstadia[CANT_E];
  // int idPerro = 7000;
  // int idEstadia = 100000;

  // inicializarPerro(arrayPerros, CANT_P);
   cargarPerrosHarcode(arrayPerros, &id);
   mostrarListaPerros(arrayPerros, CANT_P);

   if(eliminarPerro(arrayPerros+2)==0)
   {

	   printf("\n %s", arrayPerros[2].nombre );
	   puts("\n ELIMINADOO POR PULGOSO");

   }

   mostrarListaPerros(arrayPerros, CANT_P);
   altaPerrito(arrayPerros, CANT_P);
   mostrarListaPerros(arrayPerros, CANT_P);

	return EXIT_SUCCESS;
}
