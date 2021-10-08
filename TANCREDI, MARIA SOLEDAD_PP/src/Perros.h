/*
 * Dogs.h
 *
 *  Created on: 7 oct. 2021
 *      Author: sole
 */

#ifndef PERROS_H_
#define PERROS_H_
#define TAM 21

struct
{
	int id;
	char nombre[TAM];
	char raza[TAM];
	int edad;
	int isEmpty;

}typedef Perro;

void inicializarPerro(Perro* array, int tam);


#endif /* PERROS_H_ */
