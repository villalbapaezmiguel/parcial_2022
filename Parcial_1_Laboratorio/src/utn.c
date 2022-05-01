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

/*
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Arrary con la cadena a ser analizada
 *  \return 1 si contiene solo espacios letras y  numeros , 0 si no lo es
 */
int esAlfaNumerico(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && (str[i] == '/'))
		{
			return 0;
		}
		i++;
	}
	return 1;

}


int utn_fecha(int* dia , int* mes , int* anio , char* mensaje , char* mensajeERROR , int repeticiones )
{
	int retorno = -1;
	int estado ;

	if(dia != NULL && mes != NULL && anio != NULL )
	{


		printf("\n%s",mensaje);
		__fpurge(stdin);
		estado = scanf("%d%d%d",*&dia , *&mes , *&anio);

		while((estado != 3) && (*dia <= 1 && *dia >= 31)&& (*mes <= 1 && *mes >= 12) && (*anio <= 1990 && *anio >= 2022) )
		{

			system("cls");
			printf("\n%s",mensajeERROR);
			printf("\n%s",mensaje);
			__fpurge(stdin);
			estado = scanf("%d%d%d",dia , mes , anio);

		}

		retorno = 0;
	}

	return retorno;
}
