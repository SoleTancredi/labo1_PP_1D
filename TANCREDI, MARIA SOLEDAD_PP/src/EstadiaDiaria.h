/*
 * DailyStay.h
 *
 *  Created on: 7 oct. 2021
 *      Author: sole
 */

#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_
#define TAM_NOMBRE 20
#define TAM_TEL 15

struct
{
	int id;
	char nombreDuenio[TAM_NOMBRE];
	char telefonoContacto[TAM_TEL];
	int idPerro;
	int fecha;
	int isEmpty;


}typedef EstadiaDiaria;

int menu();


#endif /* ESTADIADIARIA_H_ */
