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

int alta(eAlbum* Album , int tamAlbum , int lugarLibre, eGenero* Genero ,int tamGenero,  eTipoArtista* TipoArtista ,int tamTipoArtista, eArtista* Artista ,int tamArtista)
{
	int retorno = -1;
	//Album
	//char auxTituloAlbum[51];
	eAlbum auxAlbum ;
	eGenero auxGenero ;
	eTipoArtista auxTipoArtista ;
	eArtista auxArtista ;



	int estadoTitulo = -1;
	int estadoFecha = -1;
	int estadoImporte = -1;
	int i = 0;
	int flag = -1;
	int estadoCodigoTipoArtista = -1;//
	int estadoCodigoGenero = -1;//
	int  estadoCodigoArtitsa = -1;//

	if(Album != NULL && tamAlbum > 0)
	{
		if(Album[lugarLibre].isEmpty == VACIO)
		{
			//Titulo-----------------------------------------------
			estadoTitulo = utn_pedirChar(auxAlbum.titulo , "\nIngrese el nombre del Titulo :", "\nERROR ", 51, 2);
			while ( estadoTitulo == -1)
			{
				estadoTitulo = utn_pedirChar(auxAlbum.titulo , "\nIngrese el nombre del Titulo :", "\nERROR ", 51, 2);
			}
			//FECHA---------------------------------------------
			estadoFecha = utn_fecha(&auxAlbum.fecha.dia, &auxAlbum.fecha.mes, &auxAlbum.fecha.anio);
			while ( estadoFecha == -1)
			{
				estadoFecha = utn_fecha(&auxAlbum.fecha.dia, &auxAlbum.fecha.mes, &auxAlbum.fecha.anio);
			}
			//IMPORTE-------------------------------------------
			estadoImporte = utn_pedirInt(&auxAlbum.importe, "\nIngrese Importe del Album :", "\nERROR ", 1, 100000, 2);
			while ( estadoImporte == -1)
			{
				estadoImporte = utn_pedirInt(&auxAlbum.importe, "\nIngrese Importe del Album :", "\nERROR ", 1, 100000, 2);
			}
			//CODIGO ARTISTA---------------------------------------
			estadoCodigoArtitsa = utn_pedirInt(&auxAlbum.codigoArtista, "\nIngrese codigo del artista :", "\nERROR",0, 10000, 2);
			while ( estadoCodigoArtitsa == -1)
			{
				estadoCodigoArtitsa = utn_pedirInt(&auxAlbum.codigoArtista, "\nIngrese codigo del artista :", "\nERROR",0, 10000, 2);
			}
			estadoCodigoArtitsa = utn_pedirChar(auxArtista.nombreArtista, "\nIngrese nombre del Artista :", "\nERROR", 51, 2);
			while ( estadoCodigoArtitsa == -1)
			{
				estadoCodigoArtitsa = utn_pedirChar(auxArtista.nombreArtista, "\nIngrese nombre del Artista :", "\nERROR", 51, 2);
			}


			//CODIGO GENERO--------------------------------------
			estadoCodigoGenero = utn_pedirInt(&auxAlbum.codigoGenero, "\nIngrese codigo del Genero :", "\nERROR",0, 10000, 2);
			while ( estadoCodigoGenero == -1)
			{
				estadoCodigoGenero = utn_pedirInt(&auxAlbum.codigoGenero, "\nIngrese codigo del Genero :", "\nERROR",0, 10000, 2);
			}
			estadoCodigoGenero = utn_pedirChar(auxGenero.descripcion, "\nIngrese la descripcion del Genero :", "\nERROR", 51, 2);
			while ( estadoCodigoGenero == -1)
			{
				estadoCodigoGenero = utn_pedirChar(auxGenero.descripcion, "\nIngrese la descripcion del Genero :", "\nERROR", 51, 2);
			}


			//CODIGO TIPO ARTISTA --------------------------------------------------
			estadoCodigoTipoArtista = utn_pedirInt(&auxAlbum.codigoTipoArtista, "\nIngrese codigo del Tipo de artista :", "\nERROR",0, 10000, 2);
			while ( estadoCodigoTipoArtista == -1)
			{
				estadoCodigoTipoArtista = utn_pedirInt(&auxAlbum.codigoTipoArtista, "\nIngrese codigo del Tipo de artista :", "\nERROR",0, 10000, 2);
			}
			printf("\nTIPOS DE ARISTAS : \n 1) Solista \n2) Banda");
			estadoCodigoTipoArtista = utn_pedirInt(&auxTipoArtista.tipoArtista , "\nIngrese tipo Artista :", "\nERROR", 1, 2, 2);
			while ( estadoCodigoTipoArtista == -1)
			{
				printf("\nTIPOS DE ARISTAS : \n 1) Solista \n2) Banda");
				estadoCodigoTipoArtista = utn_pedirInt(&auxTipoArtista.tipoArtista , "\nIngrese tipo Artista :", "\nERROR", 1, 2, 2);
			}


//			strncpy(auxAlbum.titulo , auxTituloAlbum , sizeof(auxAlbum.titulo));
			int estadoId ;
			estadoId = nuevoId();

			while(flag != -1)
			{
				if(estadoId == Album[i].codigoAlbum)
				{
						printf("\nId : %d ocupado ", i);
					if(Album[i].isEmpty == VACIO)
					{
						auxAlbum.codigoAlbum = nuevoId();//revisar
						flag = 0;

					}
				}
				i++;
			}
			auxAlbum.codigoArtista = auxArtista.codigoArtista;
			auxAlbum.codigoGenero = auxGenero.codigoGenero ;
			auxAlbum.codigoTipoArtista = auxTipoArtista.codigoArtista ;

			Artista[lugarLibre] = auxArtista;
			Genero[lugarLibre] = auxGenero ;
			TipoArtista[lugarLibre] = auxTipoArtista;

			auxAlbum.isEmpty = OCUPADO;
			Album[lugarLibre] = auxAlbum;
			//ya lo pudimos agregar , ahora no  nos muestran los datos y el id se repite
			retorno = 1;

		}else{
			printf("\nEse espacio esta ocupado ");
		}


	}







//	if(Album != NULL && tamAlbum > 0)
//	{
//		if(Album[id].isEmpty == VACIO)
//		{
//			//Album
//			if(utn_pedirChar(auxTituloAlbum, "\nIngrese el nombre del Titulo :", "\nERROR ", 51, 2) == 0)
//			{
//				if(utn_fecha(&auxDiaAlbum, &auxMesAlbum, &auxAnioAlbum) == 1)
//				{
//					if(utn_pedirInt(&auxImporteAlbum, "\nIngrese Importe del Album :", "\nERROR ", 1, 100000, 2)== 0)
//					{
//						if(utn_pedirInt(&auxCodigoAlbum, "\nIngrese el codigo (solo puede tener 5 digitos):","\nERROR", 1, 99999, 2)== 0)
//						{
//							//Album
//							if(Album[id].codigoAlbum == auxCodigoAlbum)
//							{
//								printf("\nEl codigo : %d  esta libre y ya se le sido asignado ", auxCodigoAlbum);
//							}else{
//								printf("\n el codigo %d ya esta siendo ocupado ", auxCodigoAlbum);
//
//								for (i = 0; i < tamAlbum; ++i) {
//
//									if(Album[i].isEmpty == VACIO)
//									{
//										printf("\n el codigo libre es %d ", i);
//
//										break ;
//									}
//								}
//							}
//						retorno = 1;
//
//						}
//					}
//				}
//			}
//
//		}
//	}

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

void altaForzada(eAlbum* album , int tamAlbum , int id, char* titulo , int dia , int mes , int anio , int importe ,
		eGenero* genero , int tamGenero , int codigoGenero , char* descripcionGenero ,
		eTipoArtista* tipoArtista , int tamTipoArtista , int tiposDeArtistas , int codigoTipoArtista , char* descripcionTipoArtista,
		eArtista* artista , int tamArtista , int codigoArtista , char* nombreArtista )
{
	eAlbum auxAlbum ;
	eGenero auxGenero ;
	eTipoArtista auxTipoArtista ;
	eArtista auxArtista ;

	auxAlbum = album[id];

	strncpy(auxAlbum.titulo , titulo , sizeof(auxAlbum.titulo));
	auxAlbum.fecha.dia = dia ;
	auxAlbum.fecha.mes = mes ;
	auxAlbum.fecha.anio = anio ;
	auxAlbum.importe = importe ;
	auxAlbum.codigoAlbum = id ;
	auxAlbum.isEmpty = OCUPADO;
	album[id] = auxAlbum ;
	//cargar los datos de genero , tipo artista y artista
	//genero
	auxGenero.codigoGenero = codigoGenero ;
	strncpy(auxGenero.descripcion, descripcionGenero, sizeof(auxGenero.descripcion));
	genero[id] = auxGenero;

	//tipo artista
	auxTipoArtista.tipoArtista = tiposDeArtistas;
	auxTipoArtista.codigoArtista = codigoTipoArtista;
	strncpy(auxTipoArtista.descripcion, descripcionTipoArtista, sizeof(auxTipoArtista.descripcion));
	tipoArtista[id] = auxTipoArtista;

	//artista
	auxArtista.codigoArtista = codigoArtista;
	strncpy(auxArtista.nombreArtista, nombreArtista, sizeof(auxArtista.nombreArtista));
	artista[id] = auxArtista;

}

//INFORMAR---------------------------------------------------------------------------------------------------------------
int	calcularTotalPromedioCantidad(eAlbum* album , int tamAlbum , int* total , float* promedioImportesTotal , int* cantidadMayorPromedio)
{
	int estado = -1;
	int i, j;
	int contador = 0;
	int acumulador = 0;
	int contadorMayorPromedios = 0;

	if(album != NULL && tamAlbum > 0)
	{
		for (i = 0; i < tamAlbum; ++i) {

			if(album[i].isEmpty == OCUPADO)
			{
				if(album[i].importe > 0 )
				{
					contador++;
					acumulador += album[i].importe;
				}
			}
		}
		*promedioImportesTotal = acumulador /contador;
		*total = acumulador ;

		for (j = 0; j < tamAlbum; ++j) {

			if(album[j].isEmpty == OCUPADO)
			{
				if(*promedioImportesTotal < album[j].importe )
				{
					contadorMayorPromedios++;
				}
			}
		}
		*cantidadMayorPromedio = contadorMayorPromedios;

		if((*cantidadMayorPromedio > 0) && (*promedioImportesTotal > 0) && (*total > 0))
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
		printf("\n==========================================================================================");
		printf("\nTotal : %d || Promedio : %f || Superan el promedio : %d de albumes ", total , promedioImportes , cantidadMayorPromedio);
		printf("\n==========================================================================================");
	}
}

void informarTodoAlbum (eAlbum* album , int tamAlbum )
{

	int i;
	for (i = 0; i < tamAlbum; ++i) {

		if(album[i].isEmpty == OCUPADO)
		{
			printf("\nID : %d || TITULO : %s || FECHA %d/%d/%d  || IMPORTE : %d", album[i].codigoAlbum , album[i].titulo , album[i].fecha.dia , album[i].fecha.mes , album[i].fecha.anio , album[i].importe);
		}
	}
}

int cantidadAlbumesFecha(eAlbum* album , int tamAlbum , int* cantidad )
{
	int estado = -1;
	int i ;
	int contador = 0;

	if(album != NULL && tamAlbum > 0)
	{
		for (i = 0; i < tamAlbum; ++i)
		{

			if(album[i].isEmpty == OCUPADO)
			{
				estado = 1;
				if(album[i].fecha.anio < 2000)
				{
					contador ++;
				}


//				for (j = 0; j < tamAlbum; ++j) {
//
//					if(album[j].fecha.anio < 2000 )
//					{
//						contador ++;
//						break ;
//					}
//				}
			}
		}

		*cantidad = contador ;
	}

	return estado;
}

//Menu--------------
void menu( eAlbum* eAlbum , int tamAlbum ,eGenero* genero , int tamGenero , eTipoArtista* tipoArtista , int tamTipoArtista , eArtista* artista, int tamArtista )
{
	int opciones ;
	int auxLugarLibre ;
	int auxindice ;
	int auxCodigoBuscado;
	int auxCodigoBaja;
//1 solista // banda
	altaForzada(eAlbum, tamAlbum, 0, "Miguel", 10, 12, 2001, 200 , genero , tamGenero , 0 , "Jazz.", tipoArtista , tamTipoArtista , 1 , 0 , "fue un trompetista y compositor estadounidense de jazz", artista , tamArtista, 0 , "Miles Davis" );
	altaForzada(eAlbum, tamAlbum, 1, "Alexis", 8, 6, 2001, 1200 , genero , tamGenero , 1 , "Rock and Roll", tipoArtista , tamTipoArtista , 2 , 1 , " fue un cantante y compositor estadounidense", artista , tamArtista, 1, "Elvis Presley");
	altaForzada(eAlbum, tamAlbum, 2, "Oscar", 4, 4, 1999, 3200 , genero , tamGenero , 2 , "Soul", tipoArtista , tamTipoArtista , 2 , 2 , " fue un cantante de soul y funk estadounidense", artista , tamArtista, 2 , "James Brown");
	altaForzada(eAlbum, tamAlbum, 3, "Abel", 22, 3, 1996, 6200 , genero , tamGenero , 3 , "Heavy Metal.", tipoArtista , tamTipoArtista , 2 , 3 , "Iron Maiden es una banda brit??nica de heavy metal de Leyton en el East End de Londres", artista , tamArtista, 3 , "Iron Maiden");
	altaForzada(eAlbum, tamAlbum, 4, "Adrian", 18, 11, 1996, 5200 , genero , tamGenero , 4 , "Techno", tipoArtista , tamTipoArtista , 1 , 4 , "es un DJ, m??sico y productor brit??nico, naturalizado canadiense. ", artista , tamArtista, 4 , "Richie Hawtin");
	do {
		printf("\n1) ALTA \n2) MODIFICACION \n3) BAJA \n4) INFORMAR \n5) LISTAR \n6)SALIR");
		printf("\nIngrese algo : ");
		scanf("%d", &opciones);

		switch(opciones)
		{
			case 1:
				printf("\n-----------------Alta-------------------------------");

				if( altaSimplificada(eAlbum, tamAlbum, genero, tamGenero , tipoArtista , tamTipoArtista, artista , tamArtista, &auxLugarLibre, &auxindice) == 1)
				{
					printf("\nAlta finalizada");

				}else{
					printf("\nERROR ");
				}
				break;
			case 2:
				printf("\n-----------------------------MODIFICACION-----------------------------------");
				if(modificacionSimplificada(eAlbum, tamAlbum, &auxCodigoBuscado) == 1)
				{
					printf("\nModificaion finalizada");
				}
				break;
			case 3:
				printf("\nBAJA");

				if(bajaSimplificada(eAlbum, tamAlbum, &auxCodigoBaja) == 1)
				{
					printf("\nBaja finalizada");
				}
				break;
			case 4:
				printf("\n-------------------INFORMAR------------------------------------");

				subMenuInformar(eAlbum, tamAlbum);

				break;
			case 5:
				printf("\n---------------------------------LISTAR-------------------------------");
				subMenuListar(eAlbum, tamAlbum, genero, tamGenero, tipoArtista, tamTipoArtista, artista, tamArtista);
	//			informarTodoAlbum(eAlbum, tamAlbum);
				break;
			case 6 :
				printf("\nSalio del programa");
				break;
		}

	} while (opciones != 6);

}

//alta simplificado

int altaSimplificada(eAlbum* album , int tamAlbum ,eGenero* genero , int tamGenero, eTipoArtista* tipoArtista , int tamTipoArtista, eArtista* artista , int tamArtista,int* auxLugarLibre , int *auxIndice )
{
	int estado = -1;

	if(album != NULL && tamAlbum > 0)
	{
		if(buscarLugarLibre(album, tamAlbum, *&auxLugarLibre) == 1)
		{

			if(alta(album, tamAlbum, *auxLugarLibre, genero, tamGenero, tipoArtista , tamTipoArtista, artista, tamArtista) == 1)
			{
				estado = 1;
				printf("\nFin del Alta");
			}else{
				printf("\npaso algo ");
			}
		}else{
			printf("\nNo se encontro lugar libre ");
		}

	}else{
		printf("\nERROR");
	}

	return estado ;
}
//Modificacion simplificada

int modificacionSimplificada(eAlbum* album , int tamAlbum , int* auxCodigoBuscado  )
{
	int estado = -1;

	utn_pedirInt(*&auxCodigoBuscado, "\nIngrese el codigo (de 5 digitos) :","\nERROR", 1, 99999, 2);
	*auxCodigoBuscado = buscarCodigo(album, tamAlbum, *auxCodigoBuscado);
	if(*auxCodigoBuscado != -1)
	{
		printf("\nSe encontro el codigo ");
		printf("\nTitulo : %s || fecha : %d/%d/%d || importe : %d",
				album[*auxCodigoBuscado].titulo ,album[*auxCodigoBuscado].fecha.dia, album[*auxCodigoBuscado].fecha.mes , album[*auxCodigoBuscado].fecha.anio,album[*auxCodigoBuscado].importe);

		if(modificar(album, tamAlbum, *auxCodigoBuscado) == 1)
		{
			printf("\nFin de la modificacion ");
		}
	}else{
		printf("\nNo se encontro el codigo");
	}

	return estado ;
}

//Baja simplificada

int bajaSimplificada(eAlbum* album , int tamAlbum , int* auxCodigoBaja)
{
	int estado = -1;

	if(utn_pedirInt(*&auxCodigoBaja, "\nINgrese el Codigo del Album a bajar (entre 5 digitos):", "\nERROR", 1, 9999, 2)== 0)
	{
		*auxCodigoBaja = buscarCodigo(album, tamAlbum, *auxCodigoBaja);
		if(*auxCodigoBaja != -1)
		{
			printf("\nSE encontro : ");
			printf("\nTitulo : %s || fecha : %d/%d/%d || importe : %d",
			album[*auxCodigoBaja].titulo ,album[*auxCodigoBaja].fecha.dia, album[*auxCodigoBaja].fecha.mes , album[*auxCodigoBaja].fecha.anio,album[*auxCodigoBaja].importe);

			if(baja(album, tamAlbum, *&auxCodigoBaja) == 1)
			{
				estado = 1;
				printf("\nYa se hizo la baja ");
			}
		}
	}


	return estado ;
}

void subMenuInformar(eAlbum* eAlbum, int tamAlbum)
{
	int auxTotal ;
	float auxPromedio;
	int auxCantidad;
	int opcionInformar;
	int auxCantidadFecha;
	do {
		printf("\n1) Total y promedio de los importes, y cu??ntos ??lbumes superan ese promedio");
		printf("\n2) La cantidad de ??lbumes cuya fecha de publicaci??n es menor a 1/1/2000.");
		printf("\n3) Salir de Informar");
		utn_pedirInt(&opcionInformar, "\nIngrese una opcion :", "\nERROR", 1, 3, 2);
		switch(opcionInformar)
		{
			case 1://A. Total y promedio de los importes, y cu??ntos ??lbumes superan ese promedio.
				if(calcularTotalPromedioCantidad(eAlbum, tamAlbum, &auxTotal, &auxPromedio, &auxCantidad) == 1)
				{

					informar_Total_Promedio_Cuantos(eAlbum, tamAlbum, auxTotal, auxPromedio, auxCantidad);
				}

				break;
			case 2://B. Cantidad de ??lbumes cuya fecha de publicaci??n es anterior a 1/1/2000.
				if(cantidadAlbumesFecha(eAlbum, tamAlbum, &auxCantidadFecha)== 1)
				{
					printf("\n==========================================================================================");
					printf("\nLA Cantidad de ??lbumes cuya fecha de publicaci??n es anterior a 1/1/2000 es de : %d", auxCantidadFecha);
					printf("\n==========================================================================================");
				}

				break;
		}


	} while (opcionInformar != 3);
}

//Listar--------
void subMenuListar(eAlbum* eAlbum, int tamAlbum,eGenero* genero , int tamGenero, eTipoArtista* tipoArtista , int tamTipoArtista, eArtista* artista , int tamArtista)
{
	int opcionInformar;

	do {
printf(
"\n1) Todos los generos \n"
"2) Todos los tipos de artistas musicales\n "
"3) Todos los artistas. \n"
"4) Todos los ??lbumes.\nT??tulo (ascendentemente)\n"
"5) Realizar un solo listado de los ??lbumes ordenados por los siguientes criterios:\n"
"-Importe (descendentemente)\n-T??tulo (ascendentemente)"
"6) Todos los ??lbumes cuya fecha de publicaci??n es menor a 1/1/2000.\n"
"7)Todos los ??lbumes que superan el promedio de los importes\n"
"8)Todos los ??lbumes de cada artista.\n"
"9)Todos los ??lbumes de un a??o determinado.\n"
"10)El ??lbum o los ??lbumes m??s caros\n");

printf("\n11) Salir de Listar");
		utn_pedirInt(&opcionInformar, "\nIngrese una opcion :", "\nERROR", 1, 11, 2);
		switch(opcionInformar)
		{
			case 1://A) Todos los generos
				if(ListarGeneros(eAlbum, tamArtista, genero) == 0)
				{
					printf("\n---------------------Listar Todos los generos Finalizado----------------");
				}
				break;
			case 2://B) Todos los tipos de artistas musicales.
				if(ListarTiposArtistas(eAlbum, tamArtista, tipoArtista)== 0)
				{
					printf("\n---------------------Listar Todos los Tipos de Artistas Finalizado----------------");
				}
				break;
			case 3://C) Todos los artistas.

				if(ListarTodosLosArtistas(eAlbum, tamArtista, artista)== 0)
				{
					printf("\n---------------------Listar Todos los Artistas Finalizado----------------");
				}

				break;
			case 4://D) Todos los ??lbumes.

				if(ListarTodosLosAlbumes(eAlbum, tamArtista)==0)
				{
					printf("\n---------------------Listar Todos Albumes Finalizado----------------");
				}

				break;
			case 5:
				break;
			case 6://F) Todos los ??lbumes cuya fecha de publicaci??n es menor a 1/1/2000.//despues ingles

				if(ListarTodosLosAlbumesFechaPublicacion(eAlbum, tamArtista)== 0)
				{
					printf("\n---------------------Listar Todos Albumes cuya fecha de publicaci??n es menor a 1/1/2000 Finalizado----------------");

				}
				break;
			case 7://G)Todos los ??lbumes que superan el promedio de los importes

				if(listarAlbumesSuperanPromedioImportes(eAlbum, tamAlbum)== 0)
				{
					printf("\n---------------------Listar Todos los ??lbumes que superan el promedio de los importes Finalizado----------------");

				}
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
		}


	} while (opcionInformar != 11);
}
int ListarGeneros(eAlbum* listaAlbum, int tamListaAlbum, eGenero* listaGenero )
{
	int estado = -1;
	int i ;
	if(tamListaAlbum > 0 )
	{
		estado = 0;
		for (i = 0; i < tamListaAlbum; ++i)
		{

			if(listaAlbum[i].isEmpty == OCUPADO)
			{
				printf("\n Genero : %s ", listaGenero[i].descripcion);

			}
		}
	}

	return estado ;
}

int ListarTiposArtistas(eAlbum* listaAlbum, int tamListaAlbum, eTipoArtista* listaTiposArtista )
{
	int estado = -1;
	int i ;
	if(tamListaAlbum > 0 )
	{
		estado = 0;
		for (i = 0; i < tamListaAlbum; ++i)
		{

			if(listaAlbum[i].isEmpty == OCUPADO)
			{

				if(listaTiposArtista[i].tipoArtista == 1)
				{
					printf("\n tipo de artista :  solista");

				}else {
					printf("\n tipo de artista :  banda");

				}
			}
		}
	}

	return estado ;
}

int ListarTodosLosArtistas(eAlbum* listaAlbum, int tamListaAlbum, eArtista* listaArtistas )
{
	int estado = -1;
	int i ;
	if(tamListaAlbum > 0 )
	{
		estado = 0;
		for (i = 0; i < tamListaAlbum; ++i)
		{

			if(listaAlbum[i].isEmpty == OCUPADO)
			{

				printf("\n Artista :%s ", listaArtistas[i].nombreArtista);
			}
		}
	}

	return estado ;
}


int ListarTodosLosAlbumes(eAlbum* listaAlbum, int tamListaAlbum)
{
	int estado = -1;
	int i ;
	if(tamListaAlbum > 0 )
	{
		estado = 0;
		for (i = 0; i < tamListaAlbum; ++i)
		{

			if(listaAlbum[i].isEmpty == OCUPADO)
			{

				printf("\n Albumes :%s ", listaAlbum[i].titulo);
			}
		}
	}

	return estado ;
}
int ListarTodosLosAlbumesFechaPublicacion(eAlbum* listaAlbum, int tamListaAlbum)
{
	int estado = -1;
	int i ;
	if(tamListaAlbum > 0 )
	{
		estado = 0;
		for (i = 0; i < tamListaAlbum; ++i)
		{

			if(listaAlbum[i].isEmpty == OCUPADO)
			{
				if(listaAlbum[i].fecha.anio < 2000)
				{
					printf("\n Albumes :%s , fecha : %d/%d/%d", listaAlbum[i].titulo, listaAlbum[i].fecha.dia, listaAlbum[i].fecha.mes, listaAlbum[i].fecha.anio);

				}

			}
		}
	}

	return estado ;
}
//Todos los ??lbumes que superan el promedio de los importes.
int	listarAlbumesSuperanPromedioImportes(eAlbum* album , int tamAlbum )
{
	int estado = -1;
	int i, j;
	int contadorImporte = 0;
	int acumuladorImporte = 0;

	float promedioImportesTotal;

	if(album != NULL && tamAlbum > 0)
	{
		estado = 0;
		for (i = 0; i < tamAlbum; ++i) {

			if(album[i].isEmpty == OCUPADO)
			{
				if(album[i].importe > 0 )
				{
					contadorImporte++;
					acumuladorImporte += album[i].importe;
				}
			}
		}
		promedioImportesTotal = acumuladorImporte /contadorImporte;

		printf("\nPromedio de los importes Totales : %.2f", promedioImportesTotal);
		for (j = 0; j < tamAlbum; ++j) {

			if(album[j].isEmpty == OCUPADO)
			{
				if(promedioImportesTotal < album[j].importe )
				{
					printf("\nAlbum : %s || importe : %d ", album[j].titulo, album[j].importe);

				}
			}
		}

	}

	return estado;
}


