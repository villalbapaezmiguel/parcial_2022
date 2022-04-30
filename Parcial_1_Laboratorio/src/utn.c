/*
 * utn.c
 *
 *  Created on: 29 abr. 2022
 *      Author: miguel
 */

#include "utn.h"

/*\brief Solicita un numero al usuario , lo valida , verifica y devuelve el resultado
 *\param pLetra Puntero al resultado alli se dejara el char ingresado por el usuario
 *\param mensaje es El mensaje a ser mostrado
 *\param mensajeError Es el mensaje a ser mostrado en caso de error
 *\param minimo Valor minimo aceptado
 *\param maximo Valor maximo aceptado
 *\param reintentos Cantidad de reintentos en el caso de error
 *\return En caso de exito (0) , en caso de error (-1)
 */
int utn_pedirChar(char *pLetra , char *mensaje , char *mensajeError, char minimo , char maximo , int repeticiones)
{
	char bufferChar ;
	int respuesta = -1;

	while(repeticiones >= 0)
	{
		if(pLetra != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && repeticiones >= 0)
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			scanf("%c",&bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*pLetra = bufferChar;
				respuesta = 0;
				break;
			}else{
				printf("%s",mensajeError);
			}

		}
	}
	return respuesta;

}
/*\brief Solicita un numero al usuario , lo valida , verifica y devuelve el resultado
 *\param pNumero Puntero al resultado alli se dejara el int ingresado por el usuario
 *\param mensaje es El mensaje a ser mostrado
 *\param mensajeError Es el mensaje a ser mostrado en caso de error
 *\param minimo Valor minimo aceptado
 *\param maximo Valor maximo aceptado
 *\param reintentos Cantidad de reintentos en el caso de error
 *\return En caso de exito (0) , en caso de error (-1)
 */
int utn_pedirInt(int *pNumero , char *mensaje , char *mensajeError, int minimo , int maximo , int repeticiones)
{
	int bufferInt;
	int respuesta =-1;

	while(repeticiones >= 0)
	{
		if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && repeticiones >= 0)
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pNumero = bufferInt ;
				respuesta = 0;
				break ;

			}else{
				printf("%s",mensajeError);
			}

		}
	}
	return respuesta;
}
/*\brief Solicita un numero al usuario , lo valida , verifica y devuelve el resultado
 *\param pNumero Puntero al resultado alli se dejara el float ingresado por el usuario
 *\param mensaje es El mensaje a ser mostrado
 *\param mensajeError Es el mensaje a ser mostrado en caso de error
 *\param minimo Valor minimo aceptado
 *\param maximo Valor maximo aceptado
 *\param reintentos Cantidad de reintentos en el caso de error
 *\return En caso de exito (0) , en caso de error (-1)
 */
int utn_pedirFloat(float *pNumero , char *mensaje , char *mensajeError, float minimo , float maximo , int repeticiones)
{
	int bufferFloat;
	int respuesta = -1;

	while(repeticiones >= 0)
	{
		if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && repeticiones >=0)
		{
			printf("%s",mensaje);
			scanf("%d",&bufferFloat);

			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pNumero = bufferFloat;
				respuesta = 0;
				break ;
			}else{
				printf("%s",mensajeError);
			}
		}
	}

	return respuesta;

}