/*
 * Albumes.c
 *
 *  Created on: 30 abr. 2022
 *      Author: miguel
 */

#include "Albumes.h"
static int nuevoId(void);

int inicilizar(eAlbum* eAlbum,int tamAlbum)
{
	int respuesta = -1;
	int i ;
	if(eAlbum != NULL && tamAlbum > 0)
	{
		for ( i = 0; i < tamAlbum; i ++) {

			respuesta = 1;
			eAlbum[i].isEmpty = VACIO ;
		}
	}

	return respuesta ;
}

/*busca la primera posicion libre
 * retorna 1 si la encontro , -1 si no la encontro*/
int buscarLugarLibre(eAlbum* album , int tamAlbum , int* lugarLibre)
{
	int retorno = -1;
	int i ;

	if(album != NULL && tamAlbum > 0)
	{
		for (i = 0; i < tamAlbum; ++i) {

			if(album[i].isEmpty == VACIO)
			{
				*lugarLibre = i;
				retorno = 1;
				break ;
			}
		}

	}

	return retorno;
}

int alta(eAlbum* eAlbum , int tamAlbum , int id)
{
	int retorno = -1;
	//Album
	char auxTituloAlbum[51];
	int auxDiaAlbum ;
	int auxMesAlbum;
	int auxAnioAlbum ;
	int auxImporteAlbum ;

	if((eAlbum != NULL && tamAlbum > 0))
	{
		if(eAlbum[id].isEmpty == VACIO)
		{
			//Album
			if(utn_pedirChar(auxTituloAlbum, "\nIngrese el nombre del Titulo :", "\nERROR ", 51, 2) == 0)
			{
				if(utn_fecha(&auxDiaAlbum, &auxMesAlbum, &auxAnioAlbum) == 1)
				{
					if(utn_pedirInt(&auxImporteAlbum, "\nIngrese Importe del Album :", "\nERROR ", 1, 100000, 2)== 0)
					{
							//Album
						strncpy(eAlbum[id].titulo , auxTituloAlbum , sizeof(eAlbum[id].titulo));
						eAlbum[id].codigoAlbum = nuevoId();
						eAlbum[id].fecha.dia = auxDiaAlbum;
						eAlbum[id].fecha.mes = auxMesAlbum;
						eAlbum[id].fecha.anio = auxAnioAlbum;
						eAlbum[id].importe = auxImporteAlbum;
						retorno = 1;

					}
				}
			}

		}
	}

	return retorno ;
}

static int nuevoId(void)
{
	static int contador = 0;

	return contador++;
}


int modificar(eAlbum* eAlbum ,int tamAlbum , int codigo)
{
	int estado =-1;
	char auxTitulo [51];
	int auxDia ;
	int auxMes ;
	int auxAnio ;
	int auxImporte ;
	if((eAlbum != NULL && tamAlbum > 0))
	{
		if(eAlbum[codigo].codigoAlbum == codigo)
		{
			if(utn_pedirChar(auxTitulo, "\nIngrese el nuevo Titulo : ", "\nERROR ", 51, 2) == 0)
			{
				if(utn_fecha(&auxDia, &auxMes, &auxAnio) == 1)
				{
					if(utn_pedirInt(&auxImporte, "\nIngrese el nuevo importe : ", "\nERROR", 1, 10000, 2) == 0)
					{
						strncpy(eAlbum[codigo].titulo , auxTitulo , sizeof(eAlbum[codigo].titulo));
						eAlbum[codigo].fecha.dia = auxDia;
						eAlbum[codigo].fecha.mes = auxMes;
						eAlbum[codigo].fecha.anio = auxAnio;
						eAlbum[codigo].importe = auxImporte;

					}
				}

			}
		}

	}

	return estado ;
}

int buscarCodigo(eAlbum* eAlbum , int tamAlbum , int valorBuscardo)
{
	int retorno = -1;
	int i;

	if((eAlbum != NULL && tamAlbum > 0)&& valorBuscardo > 0 )
	{
		for (i = 0; i < tamAlbum; ++i) {

			if(eAlbum[i].codigoAlbum == valorBuscardo)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

