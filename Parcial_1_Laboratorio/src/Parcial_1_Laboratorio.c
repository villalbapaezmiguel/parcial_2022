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
#include "Listar.h"

#define CANTIDAD 10
int main(void) {

	setbuf(stdout,NULL);
	eAlbum album[CANTIDAD];

	inicilizar(album, CANTIDAD);
	menu(album , CANTIDAD);

	return EXIT_SUCCESS;
}
