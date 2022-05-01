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
//bibliotecas
#include "utn.h"
#include "Menu.h"

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
	char descripcion;

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
}eAlbum;




#endif /* ALBUMES_H_ */
