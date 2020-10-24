/*
 * colores.c
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

int mostrarColores(eColor colores[], int tam)
{
	int error = 1; //falla

	if(colores !=NULL && tam>0) //verificacion de nulos y tamanios
	{
		system("cls");
		printf("========== LISTADO COLORES ==========\n");
		printf("-------------------------------------\n");
		printf("  ID         COLOR\n");
		for(int i=0; i<tam; i++)
		{
			printf("  %d  %20s  \n", colores[i].id, colores[i].nombreColor);
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}

int obtenerDescripcionColor(eColor colores[], int tam, int idMascota, char descripcion[])
{
	int error = 1; //falla

	if(colores != NULL && tam > 0 && idMascota>0 && descripcion !=NULL) //verificacion de nulos y tamanios
	{
		for(int i=0; i<tam; i++)
		{
			if(colores[i].id == idMascota) //recorro el array de colores en la seccion de id buscando coincidencias con mi id mascota
			{
				strcpy(descripcion, colores[i].nombreColor); //copio los datos en descripcion en caso de coincidir
				error = 0;
				break;
			}
		}
	}
	return error;
}
