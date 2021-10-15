/*
 * EstadiaDiaria.c
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
#include "Perros.h"
#include "EstadiaDiaria.h"
#include "Duenio.h"

/**
 * @fn int menuEstadia()
 * @brief muestra el cartel Menu de opciones
 *
 * @return
 */

int menuEstadia()
{
	int option;

	printf("\n########## ESTADIAS DIARIAS ##########\n\n");

	if(utn_getNumber(&option, "Ingrese la opcion que desee realizar: "
			"\n1.RESERVAR ESTADIA. "
			"\n2.MODIFICAR ESTADIA. "
			"\n3.CANCELAR ESTADIA. "
			"\n4.LISTAR ESTADIAS. "
			"\n5.LISTAR PERROS. "
			"\n6.PROMEDIO DE EDAD DE LOS PERROS. "
			"\n7.FINALIZAR."
			, "Error. Reingrese la opcion. "
			, 1, 7, 1) == 0)
	{
		printf("Usted ha ingresado la opcion nº %d", option);

	}

return option;

}
/**
 * @fn void inicializarEstadia(EstadiaDiaria*, int)
 * @brief inicializa el array
 *
 * @param array
 * @param tam
 */
void inicializarEstadia(EstadiaDiaria* array, int tam)
{
	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam ; i++)
		{
			array[i].isEmpty = 0;
		}
	}
}

/**
 * @fn int mostrarUnidadEstadia(EstadiaDiaria)
 * @brief imprime un solo elemento de la estadia
 *
 * @param unaEstadia
 * @return
 */
int mostrarUnidadEstadia(EstadiaDiaria unaEstadia)
{
	int ok=-1;

	if(unaEstadia.isEmpty == 1)
	{
		ok=0;
		printf("\n****DATOS DE LA ESTADIA****");
		printf("\nID: %d", unaEstadia.id);
		printf("\nNOMBRE DUEÑO: %s ", unaEstadia.nombreDuenio);
		printf("\nTELEFONO CONTACTO: %s", unaEstadia.telefonoContacto);
		printf("\nID PERRO: %d", unaEstadia.idPerro);
		printf("\nID DUEÑO: %d", unaEstadia.idDuenio);
		printf("\nFECHA: %d / %d / %d", (unaEstadia).fechaEstadia.dia,
				(unaEstadia).fechaEstadia.mes, (unaEstadia).fechaEstadia.anio);
		printf("\n------------------------------");
	}
	return ok;
}

/**
 * @fn void mostrarListaEstadias(EstadiaDiaria*, int)
 * @brief imprime el array completo de elementos
 *
 * @param arrayEstadias
 * @param tam
 */
void mostrarListaEstadias(EstadiaDiaria* arrayEstadias, int tam)
{
	int conteoEstadias=0;
	for(int i =0; i < tam; i++)
	{
		//printf("\nmostrar I valor: %d\n", i);
		if(mostrarUnidadEstadia(arrayEstadias[i]) == 0)
		{
			conteoEstadias++;
		}
	}

	printf("\n Cantidad de estadias :%d \n", conteoEstadias);
}


/**
 * @fn int eliminarEstadia(EstadiaDiaria*)
 * @brief da la baja logica de un elemento del array
 *
 * @param unidadEstadia
 * @return
 */
int eliminarEstadia(EstadiaDiaria* unidadEstadia)
{
	int retorno=-1;

	if(unidadEstadia!=NULL)
	{
		(*unidadEstadia).isEmpty=0;
		retorno =0 ;
	}
	return retorno;
}

/**
 * @fn int findEmptyEstadia(EstadiaDiaria*, int)
 * @brief encuntra un lugar vacio dentro del array
 *
 * @param arrayEstadia
 * @param tam
 * @return
 */
int findEmptyEstadia(EstadiaDiaria* arrayEstadia, int tam)
{
	int indice = -1;

	if(arrayEstadia != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayEstadia[i].isEmpty == 0)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

/**
 * @fn int findByIdEstadia(EstadiaDiaria*, int, int, int*)
 * @brief realiza la busqueda de un elemento mediante el Id y devuelve por referencia su ubicacion
 *
 * @param arrayEstadia
 * @param tam
 * @param id
 * @param indice
 * @return
 */
int findByIdEstadia(EstadiaDiaria* arrayEstadia, int tam, int id, int* indice)
{
	int retorno = -1;

	if(arrayEstadia != NULL && indice != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayEstadia[i].isEmpty == 1 && arrayEstadia[i].id == id)
			{
				*indice = i;
				retorno = 0;
			}
		}
	}

	return retorno;

}
/**
 * @fn int addEstadia(EstadiaDiaria*, int*, char*, char*, int, int, int, int)
 * @brief toma por parametro los datos y los ubica en cada campo correspondiente en el elemento del array
 *
 * @param unidadEstadia
 * @param id
 * @param nombreDuenio
 * @param telefono
 * @param idPerro
 * @param dia
 * @param mes
 * @param anio
 * @return
 */
int addEstadia(EstadiaDiaria* unidadEstadia,int* id, char* nombreDuenio, char* telefono, int idPerro,int idDuenio, int dia, int mes, int anio)
{
	int retorno = -1;

	if(unidadEstadia != NULL && nombreDuenio != NULL && telefono != NULL)
	{
		(*unidadEstadia).isEmpty = 1;
		(*unidadEstadia).id = *id;
		strcpy((*unidadEstadia).nombreDuenio, nombreDuenio);
		strcpy((*unidadEstadia).telefonoContacto,telefono);
		(*unidadEstadia).idPerro = idPerro;
		(*unidadEstadia).idDuenio = idDuenio;
		(*unidadEstadia).fechaEstadia.dia = dia;
		(*unidadEstadia).fechaEstadia.mes = mes;
		(*unidadEstadia).fechaEstadia.anio = anio;
		(*id)++;
		retorno = 0;

	}

	return retorno;
}
/**
 * @fn int altaEstadia(EstadiaDiaria*, int, int*, Perro*, int)
 * @brief pide lo datos al usuario para que de de alta un nuevo elemento
 *
 * @param arrayEstadia
 * @param tam
 * @param id
 * @param arrayPerro
 * @param tamP
 * @return
 */
int altaEstadia(EstadiaDiaria* arrayEstadia, int tam, int* id, Perro* arrayPerro, int tamP, Duenio* arrayDuenio, int tamD)
{
	int retorno = -1;
	int i;
	int iDuenio;
	EstadiaDiaria bufferE;

	if(arrayEstadia != NULL && id != NULL)
	{
		i = findEmptyEstadia(arrayEstadia, tam);
		mostrarListaDuenios(arrayDuenio, tam);
		//pregunto por el cliente de la estadia
		if(utn_getNumber(&bufferE.idDuenio, "\nIngrese el ID del DUEÑO:", "\nError.Reingrese.", 30000, 60000, 1) == 0)
		{
			if(validIdDuenio(arrayDuenio, tamD, bufferE.idDuenio) == 0)
			{
				if(indexByIdDuenio(arrayDuenio, tamD, bufferE.idDuenio,&iDuenio) == 0)
				{
					strcpy(bufferE.nombreDuenio, arrayDuenio[iDuenio].nombre);
					strcpy(bufferE.telefonoContacto, arrayDuenio[iDuenio].telefono);
				}
			}
			else
			{
				printf("\nEl ID ingresado no existe.");
			}

		}

		if(i != -1 && utn_getNumber(&bufferE.fechaEstadia.dia, "\nIngrese la fecha: \nDia: ","\nError. Reintente."
			,1, 31, 1) == 0 && utn_getNumber(&bufferE.fechaEstadia.mes, "\nMes: ","\nError. Reintente."
			, 1, 12,1) == 0 && utn_getNumber(&bufferE.fechaEstadia.anio, "\nAño: ", "\nError. Reintente.", 1990, 2021, 1)  == 0)
		{
			mostrarListaPerros(arrayPerro, tamP);
			if(utn_getNumber(&bufferE.idPerro, "\nIngrese el ID del perro:", "\nError.Reingrese.", 7000, 10000, 1) == 0)
			{
				if(validIdPerro(arrayPerro, tamP, bufferE.idPerro) == 0)
				{
					if(addEstadia(&arrayEstadia[i], id,bufferE.nombreDuenio ,bufferE.telefonoContacto , bufferE.idPerro,bufferE.idDuenio, bufferE.fechaEstadia.dia, bufferE.fechaEstadia.mes, bufferE.fechaEstadia.anio) == 0)
					{
						printf("perfecto");
						retorno = 0;
					}

				}
				else
				{
					printf("\nEl ID ingresado no existe.");
				}

			}

		}

	}

	return retorno;
}

/**
 * @fn int subMenuModifEstadia(EstadiaDiaria*, int, int*)
 * @brief muestra el cartel de un subMenu de opciones para realizar modificaciones
 *
 * @param arrayEstadia
 * @param tam
 * @param option
 * @return
 */
int subMenuModifEstadia(EstadiaDiaria* arrayEstadia, int tam,int* option)
{
	int retorno = -1;
	if(arrayEstadia != NULL)
	{
		printf("\n########## MODIFICAR DATOS ##########\n");

		if(utn_getNumber(option, "\nIngrese la opcion del dato que desea modificar:"
						"\n1. TELEFONO DE CONTACTO."
						"\n2. PERRO segun su Identificador."
						"\n3. SALIR. "
						, "Error. Reingrese la opcion", 1, 3, 1) == 0)
		{
			printf("\nUsted ha ingresado la opcion nº %d", *option);
			retorno = 0;
		}

	}

	return retorno;
}
/**
 * @fn int modificarEstadia(EstadiaDiaria*, int, Perro*)
 * @brief modifica algunos datos de la estadia segun eleccion del usuario
 *
 * @param arrayEstadia
 * @param tam
 * @param arrayPerritos
 * @return
 */
int modificarEstadia(EstadiaDiaria* arrayEstadia, int tam, Perro* arrayPerritos, Duenio* arrayDuenio)
{
	int retorno = -1;
	int option;
	int indice;
	int bufferId;
	EstadiaDiaria bufferE;

	if(arrayEstadia != NULL )
	{
		mostrarListaEstadias(arrayEstadia, tam);
		if(utn_getNumber(&bufferId, "\nIngrese el ID de la ESTADIA que desea modificar:  "
				,"\nError. Reingrese.",100000,150000, 1) == 0 &&
		findByIdEstadia(arrayEstadia, tam, bufferId,&indice) == 0)
		{
			do
			{
				if(subMenuModifEstadia(arrayEstadia, tam,&option) == 0)
			{
				switch(option)
				{
					case 1:
						if(utn_telephoneNumber(bufferE.telefonoContacto,"\nIngrese el nuevo telefono de contacto:"
								,"\nError. Reingrese el numero.", tam, 1) == 0)
						{
							printf("\nEl telefono de contacto ingresado es: %s", bufferE.telefonoContacto);
							strcpy(arrayEstadia[indice].telefonoContacto, bufferE.telefonoContacto);
						}
						else
						{
							printf("\nNo se ha podido realizar la modificacion de manera correcta");
						}
						break;
					case 2:
						mostrarListaPerros(arrayPerritos, tam);
						if(utn_getNumber(&bufferE.idPerro, "\nIngrese el nuevo Id del perro."
						, "\nError. Reingrese el id.", 7000, 10000, 1) == 0
						&& validIdPerro(arrayPerritos, tam, bufferE.idPerro) == 0
						)
						{
							printf("\nEl ID ingreado es: %d",bufferE.idPerro);
							arrayEstadia[indice].idPerro = bufferE.idPerro;
						}
						break;
					case 3:
						printf(" Salir de modificaciones.");
						break;
				}
				retorno = 0;
			}

			}while(option != 3);
		}


	}

	return retorno;
}

/**
 * @fn int validIdEstadia(EstadiaDiaria*, int, int)
 * @brief valida la existencia de un Id
 *
 * @param arrayEstadia
 * @param tam
 * @param id
 * @return
 */
int validIdEstadia(EstadiaDiaria* arrayEstadia, int tam, int id)
{
	int retorno = -1;

	if(arrayEstadia != NULL)
		{
			for(int i = 0; i < tam; i++)
			{
				if(arrayEstadia[i].isEmpty == 1 && arrayEstadia[i].id == id)
				{
					retorno = 0;
				}
			}
		}

	return retorno;
}

/**
 * @fn int ordenarEstadia(EstadiaDiaria*, int)
 * @brief ordena por fecha cada elemento del array, en caso de tener igualdad de fechas ordena
 * por orden alfabetico el nombre de los dueños
 *
 * @param arrayEstadia
 * @param tam
 * @return
 */
int ordenarEstadia(EstadiaDiaria* arrayEstadia,int tam)
{
	int retorno=-1;
	int flag = 1;
	int newTam;
	EstadiaDiaria aux;

	if(arrayEstadia != NULL)
	{
		newTam = tam -1;

		do
		{
			flag = 1;

			for(int i = 0; i < newTam; i++)
			{
				if(arrayEstadia[i].fechaEstadia.anio < arrayEstadia[i+1].fechaEstadia.anio)
				{
					flag = 0;
					aux = arrayEstadia[i];
					arrayEstadia[i]=arrayEstadia[i+1];
					arrayEstadia[i+1]=aux;
					retorno = 0;
				}
				else
				{
					if(arrayEstadia[i].fechaEstadia.anio == arrayEstadia[i+1].fechaEstadia.anio)
					{
						if(arrayEstadia[i].fechaEstadia.mes < arrayEstadia[i+1].fechaEstadia.mes)
						{
							flag = 0;
							aux = arrayEstadia[i];
							arrayEstadia[i]=arrayEstadia[i+1];
							arrayEstadia[i+1]=aux;
							retorno = 0;
						}
						else
						{
							if(arrayEstadia[i].fechaEstadia.mes == arrayEstadia[i+1].fechaEstadia.mes)
							{
								if(arrayEstadia[i].fechaEstadia.dia < arrayEstadia[i+1].fechaEstadia.dia)
								{
									flag = 0;
									aux = arrayEstadia[i];
									arrayEstadia[i]=arrayEstadia[i+1];
									arrayEstadia[i+1]=aux;
									retorno = 0;
								}
								else
								{
									if(arrayEstadia[i].fechaEstadia.dia == arrayEstadia[i+1].fechaEstadia.dia)
									{
										if(strcmp(arrayEstadia[i].nombreDuenio, arrayEstadia[i+1].nombreDuenio) > 0)
										{
											flag = 0;
											aux = arrayEstadia[i];
											arrayEstadia[i]=arrayEstadia[i+1];
											arrayEstadia[i+1]=aux;
											retorno = 0;
										}
									}
								}
							}
						}
					}
				}
				newTam--;
			}

		}while(flag == 0);
	}




	return retorno;
}

/**
 * @fn int darDeBajaEstadia(EstadiaDiaria*, int)
 * @brief elimina un elemento del array, segun el Id que ingrese el usuario
 *
 * @param arrayEstadia
 * @param tam
 * @return
 */
int darDeBajaEstadia(EstadiaDiaria* arrayEstadia, int tam)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayEstadia!= NULL)
	{
		printf("\n***** DAR DE BAJA UN PERRITO *****\n");

		mostrarListaEstadias(arrayEstadia, tam);

		if( utn_getNumber(&id, "\nIngrese el ID de la ESTADIA que desea cancelar: ","\nError. Reingrese el ID."
					, 100000, 150000, 1) == 0 && findByIdEstadia(arrayEstadia, tam, id, &indice) == 0)

		{
			if(eliminarEstadia(&arrayEstadia[indice]) == 0)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}






