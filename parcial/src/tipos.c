/*
 * tipos.c
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

int mostrarTipos(eTipo tipos[], int tam)
{
	int error = 1;

	if(tipos !=NULL && tam>0)
	{
		system("cls");
		printf("========== LISTADO TIPOS ==========\n");
		printf("-------------------------------------\n");
		printf("     ID         DESCRIPCION\n");
		for(int i=0; i<tam; i++)
		{
			printf("  %d  %20s  \n", tipos[i].id, tipos[i].descripcion);
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}
