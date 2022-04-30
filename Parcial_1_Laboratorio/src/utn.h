/*
 * utn.h
 *
 *  Created on: 29 abr. 2022
 *      Author: miguel
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int utn_pedirChar(char *pLetra , char *mensaje , char *mensajeError, char minimo , char maximo , int repeticiones);
int utn_pedirInt(int *pNumero , char *mensaje , char *mensajeError, int minimo , int maximo , int repeticiones);
int utn_pedirFloat(float *pNumero , char *mensaje , char *mensajeError, float minimo , float maximo , int repeticiones);


#endif /* UTN_H_ */
