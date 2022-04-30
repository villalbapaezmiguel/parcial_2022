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
//tipo artista
#define SOLISTA 1
#define BANDA 2
typedef struct{

	//Genero
	int codigoGenero ;
	char descripicion [DESCRIPCION];
	//Artista
	int codigoArtista ;
	char nombreArtista [NOMBRE];
	//tipo artista
	int codigoTipoArtista ;
	char descripcion [DESCRIPCION];
	//Album
	int codigoAlbum ;
	char titulo [DESCRIPCION];


}eAlbumes;


#endif /* ALBUMES_H_ */
