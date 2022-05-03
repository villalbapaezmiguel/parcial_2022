/*
 * Albumes.c
 *
 *  Created on: 30 abr. 2022
 *      Author: miguel
 */

#include "Albumes.h"
//static int nuevoId(void);

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
	int auxCodigoAlbum;

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
						if(utn_pedirInt(&auxCodigoAlbum, "\nIngrese el codigo (solo puede tener 5 digitos):","\nERROR", 1, 99999, 2)== 0)
						{
							//Album
						strncpy(eAlbum[id].titulo , auxTituloAlbum , sizeof(eAlbum[id].titulo));
						eAlbum[id].codigoAlbum = auxCodigoAlbum;
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
	}

	return retorno ;
}

//static int nuevoId(void)
//{
//	static int contador = 0;
//
//	return contador++;
//}


int modificar(eAlbum* eAlbum ,int tamAlbum , int codigo)
{
	int estado =-1;
	char auxTitulo [51];
	int auxDia ;
	int auxMes ;
	int auxAnio ;
	int auxImporte ;
	int i ;
	if((eAlbum != NULL && tamAlbum > 0))
	{
		for (i = 0; i < tamAlbum; ++i) {
			if(eAlbum[i].codigoAlbum == codigo)
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
							estado = 1;
							break;
						}
					}

				}
			}else{
				printf("\nNop");
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

int baja(eAlbum* eAlbum , int tamAlbum , int* codigo)
{
	int estado = -1;
	int i;

	if(eAlbum != NULL && tamAlbum > 0)
	{
		for (i = 0; i < tamAlbum; ++i) {

			if(eAlbum[i].codigoAlbum == *codigo)
			{
				eAlbum[i].isEmpty = VACIO;
				estado = 1;
				break;

			}
		}
	}

	return estado;
}

void altaForzada(eAlbum* album , int tamAlbum , int id, char* titulo , int dia , int mes , int anio , int importe)
{
	eAlbum auxAlbum ;

	strncpy(auxAlbum.titulo , titulo , sizeof(auxAlbum.titulo));
	auxAlbum.fecha.dia = dia ;
	auxAlbum.fecha.mes = mes ;
	auxAlbum.fecha.anio = anio ;
	auxAlbum.importe = importe ;
	auxAlbum.codigoAlbum = id ;
	auxAlbum.isEmpty = OCUPADO;
	album[id] = auxAlbum ;

}

//INFORMAR
int	calcularTotalPromedioCantidad(eAlbum* album , int tamAlbum , int* total , float* promedioImportes , int* cantidadMayorPromedio)
{
	int estado = -1;
	int i, j;
	int contador = 0;
	int acumulador = 0;
	int contadorMayorPromedios = 0;
	if(album != NULL && tamAlbum > 0)
	{
		for (i = 0; i < tamAlbum; ++i) {

			if(album[i].importe > 0)
			{
				contador++;
				acumulador += album[i].importe;
			}
		}
		*promedioImportes = acumulador /contador;
		*total = acumulador ;

		for (j = 0; j < tamAlbum; ++j) {

			if(*promedioImportes < album[j].importe)
			{
				contadorMayorPromedios++;
			}
		}
		*cantidadMayorPromedio = contadorMayorPromedios;

		if((*cantidadMayorPromedio > 0) && (*promedioImportes > 0) && (*total > 0))
		{
			estado = 1;
		}
	}

	return estado;
}

void informar_Total_Promedio_Cuantos(eAlbum* album , int tamAlbum , int total , float promedioImportes , int cantidadMayorPromedio)
{

	if(album != NULL && tamAlbum > 0)
	{

		printf("\nTotal : %d || Promedio : %f || Superan el promedio : %d de albumes ", total , promedioImportes , cantidadMayorPromedio);
	}
}

void informarTodoAlbum (eAlbum* album , int tamAlbum )
{

	int i;
	for (i = 0; i < tamAlbum; ++i) {

		if(album[i].isEmpty == OCUPADO)
		{
			printf("\nTITULO : %s || FECHA %d/%d/%d  || IMPORTE : %d", album[i].titulo , album[i].fecha.dia , album[i].fecha.mes , album[i].fecha.anio , album[i].importe);
		}
	}
}

int cantidadAlbumesFecha(eAlbum* album , int tamAlbum , int* cantidad )
{
	int estado = -1;
	int i , j;
	int contador = 0;

	if(album != NULL && tamAlbum > 0)
	{
		for (i = 0; i < tamAlbum; ++i) {

			if(album[i].isEmpty == OCUPADO)
			{
				estado = 1;
				for (j = 0; j < tamAlbum; ++j) {

					if(album[j].fecha.anio < 2000 )
					{
						contador ++;
						break ;
					}
				}
			}
		}

		*cantidad = contador ;
	}

	return estado;
}

//Menu--------------
void menu( eAlbum* eAlbum , int tamAlbum )
{
	int opciones ;
	int auxLugarLibre ;
	int auxCodigoBuscado;
	int auxCodigoBaja;

	int auxTotal ;
	float auxPromedio ;
	int auxCantidad;
	int auxCantidadFecha ;

	altaForzada(eAlbum, tamAlbum, 0, "Miguel", 10, 12, 2001, 200);
	altaForzada(eAlbum, tamAlbum, 1, "Alexis", 8, 6, 2001, 1200);
	altaForzada(eAlbum, tamAlbum, 2, "Oscar", 4, 4, 1999, 3200);
	altaForzada(eAlbum, tamAlbum, 3, "Adrian", 18, 11, 1996, 5200);
	do {
		printf("\n1) ALTA \n2) MODIFICACION \n3) BAJA \n4) INFORMAR \n5) LISTAR \n6)SALIR");
		printf("\nIngrese algo : ");
		scanf("%d", &opciones);

		switch(opciones)
		{
			case 1:
				printf("\nAlta");

				if(buscarLugarLibre(eAlbum, tamAlbum, &auxLugarLibre) == 1)
				{
					if(alta(eAlbum, tamAlbum, auxLugarLibre) == 1)
					{
						printf("\nFin del Alta");
					}
				}
				break;
			case 2:
				printf("\nMODIFICACION");
				utn_pedirInt(&auxCodigoBuscado, "\nIngrese el codigo (de 5 digitos) :","\nERROR", 1, 99999, 2);
				auxCodigoBuscado = buscarCodigo(eAlbum, tamAlbum, auxCodigoBuscado);
				if(auxCodigoBuscado != -1)
				{
					printf("\nSe encontro el codigo ");
					printf("\nTitulo : %s || fecha : %d/%d/%d || importe : %d",
							eAlbum[auxCodigoBuscado].titulo ,eAlbum[auxCodigoBuscado].fecha.dia, eAlbum[auxCodigoBuscado].fecha.mes , eAlbum[auxCodigoBuscado].fecha.anio,eAlbum[auxCodigoBuscado].importe);

					if(modificar(eAlbum, tamAlbum, auxCodigoBuscado) == 1)
					{
						printf("\nFin de la modificacion ");
					}
				}else{
					printf("\nNo se encontro el codigo");
				}

				break;
			case 3:
				printf("\nBAJA");
				if(utn_pedirInt(&auxCodigoBaja, "\nINgrese el Codigo del Album a bajar (entre 5 digitos):", "\nERROR", 1, 9999, 2)== 0)
				{
					auxCodigoBaja = buscarCodigo(eAlbum, tamAlbum, auxCodigoBaja);
					if(auxCodigoBaja != -1)
					{
						printf("\nSE encontro : ");
						printf("\nTitulo : %s || fecha : %d/%d/%d || importe : %d",
						eAlbum[auxCodigoBuscado].titulo ,eAlbum[auxCodigoBuscado].fecha.dia, eAlbum[auxCodigoBuscado].fecha.mes , eAlbum[auxCodigoBuscado].fecha.anio,eAlbum[auxCodigoBuscado].importe);

						if(baja(eAlbum, tamAlbum, &auxCodigoBaja) == 1)
						{
							printf("\nYa se hizo la baja ");
						}
					}
				}
				break;
			case 4:
				printf("\nINFORMAR");
					//crear un subMenu
					//A
					if(calcularTotalPromedioCantidad(eAlbum, tamAlbum, &auxTotal, &auxPromedio, &auxCantidad) == 1)
					{
						informar_Total_Promedio_Cuantos(eAlbum, tamAlbum, auxTotal, auxPromedio, auxCantidad);
					}
					//B
					if(cantidadAlbumesFecha(eAlbum, tamAlbum, &auxCantidadFecha)== 1)
					{
						printf("\nLA Cantidad de álbumes cuya fecha de publicación es anterior a 1/1/2000 es de : %d", auxCantidadFecha);
					}

				break;
			case 5:
				printf("\nLISTAR");
				informarTodoAlbum(eAlbum, tamAlbum);
				break;
			case 6 :
				printf("\nSalio del programa");
				break;
		}

	} while (opciones != 6);

}


