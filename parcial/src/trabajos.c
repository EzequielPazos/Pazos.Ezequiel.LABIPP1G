/*
 * trabajos.c
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

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(trabajos[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int altaTrabajo(eTrabajo trabajos[], eMascota mascotas[], eServicio servicios[], eTipo tipos[], eColor colores[], int tam, int tam_s, int tam_tc, int idTrabajo)
{
	int error = 1; //falla en el alta
	int indice;
	eTrabajo nuevoTrabajo;

	if(trabajos !=NULL && tam>0 && idTrabajo>0)
	{
		system("cls");
		printf("========== ALTA DE TRABAJOS ==========\n\n");
		indice = buscarLibreTrabajo(trabajos, tam);

		if(indice==-1) //error
		{
			printf("     >>> El sistema esta completo <<<");
		}else
		{
			nuevoTrabajo.id = idTrabajo;
			nuevoTrabajo.isEmpty = 0;

			mostrarMascotas(mascotas, tipos, colores, tam, tam_tc);

			printf("\nIngrese el ID de la mascota deseada: ");
			scanf("%d", &nuevoTrabajo.idMascota); //falta validar

			mostrarServicios(servicios, tam_s);

			printf("\nIngrese el ID del servicio deseado: ");
			scanf("%d", &nuevoTrabajo.idServicio); //falta validar

			printf("Se ha ingresado el trabajo al sistema con exito!");
		}
	}

	return error;
}

int mostrarTrabajos(eTrabajo trabajos[], int tam)
{
	int error = 1;

	if(trabajos !=NULL && tam>0)
	{
		system("cls");
		printf("========== LISTADO TRABAJOS ==========\n");
		printf("-------------------------------------\n");
		printf("  ID  ID-MASCOTA  SERVICIO  FECHA  \n");
		for(int i=0; i<tam; i++)
		{
			printf("  %d  %d  %d %02d/%02d/%d\n", trabajos[i].id, trabajos[i].idMascota, trabajos[i].idServicio, trabajos[i].fechaTrabajo.dia, trabajos[i].fechaTrabajo.mes, trabajos[i].fechaTrabajo.anio);
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}
