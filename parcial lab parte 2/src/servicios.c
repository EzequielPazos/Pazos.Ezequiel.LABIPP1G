/*
 * servicios.c
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fecha.h"
#include "tipos.h"
#include "colores.h"
#include "mascotas.h"
#include "servicios.h"
#include "trabajos.h"
#include "validaciones.h"
#include "cliente.h"

int mostrarServicios(eServicio servicios[], int tam)
{
	int error = 1; //falla

	if(servicios !=NULL && tam>0) //verificacion de nulos y tamanios
	{
		system("cls");
		printf("========== LISTADO SERVICIOS ==========\n");
		printf("-------------------------------------\n");
		printf("  ID        DESCRIPCION        PRECIO  \n");
		for(int i=0; i<tam; i++)
		{
			printf("  %d    %s         %2.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio); //muestro los servicios
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}
