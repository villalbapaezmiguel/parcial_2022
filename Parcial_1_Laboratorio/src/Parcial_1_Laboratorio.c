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

	int dia ;
	int mes ;
	int anio ;
//tenemos que buscar la manera de pedir la fecha al usuario

	int estado ;
	estado = utn_fecha(&dia, &mes, &anio, "\nIngrese una fecha (dia/mes/ anio)", "\nERROR ", 2);

	if(estado == 0)
	{
		printf("\nsalio todo bien ");
		printf("\n %d /%d / %d ", dia , mes , anio);
	}else{
		printf("\nF");
	}



	return EXIT_SUCCESS;
}
