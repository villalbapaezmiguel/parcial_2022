/*
 * Menu.c
 *
 *  Created on: 29 abr. 2022
 *      Author: miguel
 */

#include "Menu.h"

void menu( eAlbum* eAlbum , int tamAlbum )
{
	int opciones ;
	int auxLugarLibre ;
	int auxCodigoBuscado;
	inicilizar(eAlbum, tamAlbum);

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
				auxCodigoBuscado = buscarCodigo(eAlbum, tamAlbum, auxCodigoBuscado);
				if(auxCodigoBuscado != -1)
				{
					printf("\nSe encontro el codigo ");
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
				break;
			case 4:
				printf("\nINFORMAR");
				break;
			case 5:
				printf("\nLISTAR");
				break;
			case 6 :
				printf("\nSalio del programa");
				break;
		}

	} while (opciones != 6);

}

