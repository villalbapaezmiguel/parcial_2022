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
#include "Listar.h"

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
	int codigoArtista ;
	int codigoTipoArtista ;
	int codigoGenero;
	int isEmpty ;
}eAlbum;
//abm
int inicilizar(eAlbum* eAlbum,int tamAlbum);
int buscarLugarLibre(eAlbum* album , int tamAlbum , int* lugarLibre);
int alta(eAlbum* Album , int tamAlbum , int lugarLibre, eGenero* Genero ,int tamGenero,  eTipoArtista* TipoArtista ,int tamTipoArtista, eArtista* Artista ,int tamArtista);
int modificar(eAlbum* eAlbum ,int tamAlbum , int codigo);
int buscarCodigo(eAlbum* eAlbum , int tamAlbum , int valorBuscardo);
int baja(eAlbum* eAlbum , int tamAlbum , int* codigo);
void altaForzada(eAlbum* album , int tamAlbum , int id, char* titulo , int dia , int mes , int anio , int importe ,
		eGenero* genero , int tamGenero , int codigoGenero , char* descripcionGenero ,
		eTipoArtista* tipoArtista , int tamTipoArtista , int tiposDeArtistas , int codigoTipoArtista , char* descripcionTipoArtista,
		eArtista* artista , int tamArtista , int codigoArtista , char* nombreArtista );
//Informar
void informarTodoAlbum (eAlbum* album , int tamAlbum );
int	calcularTotalPromedioCantidad(eAlbum* album , int tamAlbum , int* total , float* promedioImportes , int* cantidadMayorPromedio);
void informar_Total_Promedio_Cuantos(eAlbum* album , int tamAlbum , int total , float promedioImportes , int cantidadMayorPromedio);
int cantidadAlbumesFecha(eAlbum* album , int tamAlbum , int* cantidad );
//menu
void menu( eAlbum* eAlbum , int tamAlbum ,eGenero* genero , int tamGenero , eTipoArtista* tipoArtista , int tamTipoArtista , eArtista* artista, int tamArtista );

void subMenuInformar(eAlbum* eAlbum, int tamAlbum);
//Simplificacion ABM
int altaSimplificada(eAlbum* album , int tamAlbum ,eGenero* genero , int tamGenero, eTipoArtista* tipoArtista , int tamTipoArtista, eArtista* artista , int tamArtista,int* auxLugarLibre , int *auxIndice );
int modificacionSimplificada(eAlbum* album , int tamAlbum , int* auxCodigoBuscado  );
int bajaSimplificada (eAlbum* album , int tamAlbum , int* auxCodigoBaja );


//listar
void subMenuListar(eAlbum* eAlbum, int tamAlbum,eGenero* genero , int tamGenero, eTipoArtista* tipoArtista , int tamTipoArtista, eArtista* artista , int tamArtista);

int ListarGeneros(eAlbum* listaAlbum, int tamListaAlbum, eGenero* listaGenero );
int ListarTiposArtistas(eAlbum* listaAlbum, int tamListaAlbum, eTipoArtista* listaTiposArtista );
int ListarTodosLosArtistas(eAlbum* listaAlbum, int tamListaAlbum, eArtista* listaArtistas );
int ListarTodosLosAlbumes(eAlbum* listaAlbum, int tamListaAlbum);
int ListarTodosLosAlbumesFechaPublicacion(eAlbum* listaAlbum, int tamListaAlbum);
int	listarAlbumesSuperanPromedioImportes(eAlbum* album , int tamAlbum );
#endif /* ALBUMES_H_ */
