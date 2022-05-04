/*
 * Albumes.h
 *
 *  Created on: 29 abr. 2022
 *      Author: miguel
 */

#ifndef ALBUMES_H_
#define ALBUMES_H_

#define DESCRIPCION 51
#define NOMBRE 51
#define VACIO 0
#define OCUPADO 1
//bibliotecas
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "utn.h"

//tipo artista
#define SOLISTA 1
#define BANDA 2


typedef struct{
	int dia ;
	int mes ;
	int anio ;

}eFecha;

typedef struct{
	int codigoGenero ;
	char descripcion[51];

}eGenero;

typedef struct{
	int codigoArtista ;
	char nombreArtista [51];

}eArtista;

typedef struct{
	int tipoArtista ;
	int codigoArtista ;
	char descripcion [51];

}eTipoArtista;

typedef struct{
	int codigoAlbum ;
	char titulo [51];
	eFecha fecha ;
	int importe ;
	int idArtista ;
	int idTipoArtista ;
	int idGenero;
	int isEmpty ;
}eAlbum;
//abm
int inicilizar(eAlbum* eAlbum,int tamAlbum);
int buscarLugarLibre(eAlbum* album , int tamAlbum , int* lugarLibre);
int alta(eAlbum* Album , int tamAlbum , int lugarLibre);
int modificar(eAlbum* eAlbum ,int tamAlbum , int codigo);
int buscarCodigo(eAlbum* eAlbum , int tamAlbum , int valorBuscardo);
int baja(eAlbum* eAlbum , int tamAlbum , int* codigo);
void altaForzada(eAlbum* album , int tamAlbum , int id, char* titulo , int dia , int mes , int anio , int importe);
//Informar
void informarTodoAlbum (eAlbum* album , int tamAlbum );
int	calcularTotalPromedioCantidad(eAlbum* album , int tamAlbum , int* total , float* promedioImportes , int* cantidadMayorPromedio);
void informar_Total_Promedio_Cuantos(eAlbum* album , int tamAlbum , int total , float promedioImportes , int cantidadMayorPromedio);
int cantidadAlbumesFecha(eAlbum* album , int tamAlbum , int* cantidad );
//menu
void menu( eAlbum* eAlbum , int tamAlbum );
//Simplificacion ABM
int altaSimplificada(eAlbum* album , int tamAlbum ,int* auxLugarLibre , int* auxIndice);
int modificacionSimplificada(eAlbum* album , int tamAlbum , int* auxCodigoBuscado  );
int bajaSimplificada (eAlbum* album , int tamAlbum , int* auxCodigoBaja );

#endif /* ALBUMES_H_ */
