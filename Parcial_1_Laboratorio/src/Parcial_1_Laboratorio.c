/*
 ============================================================================
 Name        : Parcial_1_Laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "utn.h"
#include "Albumes.h"

int main(void) {

	char fecha[51];
	int dia ;
	int mes ;
	int anio ;
//tenemos que buscar la manera de pedir la fecha al usuario
	if(utn_pedirInt(&dia, "\nIngrese dia :", "\nERROR ", 1, 30, 2) == 0)
	{
		if(utn_pedirInt(&mes, "\nIngrese mes :", "\nERROR ", 1, 12, 2) == 0)
		{
			if(utn_pedirInt(&anio, "\nIngrese anio :", "\nERROR ", 1999,2022 , 2) == 0)
			{
				strncpy(fecha , dia , 51);
				strncpy(fecha , "/", 51);
			}
		}
	}

	if(utn_pedirChar(fecha, "\nIngrese fecha :", "\nERROR ",1, 51, 2)== 0)
	{
		printf("\nlisto :");
		printf("%s",fecha);
	}

	return EXIT_SUCCESS;
}