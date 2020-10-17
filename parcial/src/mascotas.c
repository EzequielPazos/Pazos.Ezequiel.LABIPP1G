/*
 * mascotas.c
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

int buscarLibreMascotas(eMascota mascotas[], int tam)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(mascotas[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

void mostrarMascota(eMascota unaMascota, eTipo tipos[], eColor colores[], int tam_tc)
{
	char descripcionTipo[20];
	char nombreColor[20];

	for(int i=0; i<tam_tc; i++)
	{
		if(tipos[i].id == unaMascota.idTipo)
		{
			strcpy(descripcionTipo, tipos[i].descripcion);
			break;
		}else if(colores[i].id == unaMascota.idColor)
		{
			strcpy(nombreColor, colores[i].nombreColor);
			break;
		}
	}

	printf("%4d %s %s %s %d\n", unaMascota.id, unaMascota.nombre, descripcionTipo, nombreColor, unaMascota.edad);
}

int mostrarMascotas(eMascota mascotas[], eTipo tipos[], eColor colores[], int tam, int tam_tc)
{
	int error = 1;
	int flag = 0;

	if(mascotas !=NULL && tam>0)
	{
		printf("  ID  NOMBRE  TIPO  COLOR  EDAD\n");
		printf("-------------------------------------\n");

		for(int i=0; i<tam; i++)
		{
			if(mascotas[i].isEmpty == 0)
			{
				mostrarMascota(mascotas[i], tipos, colores, tam_tc);
				flag = 1;
			}
		}

		if(flag == 0)
		{
			printf("  No hay ninguna mascota en la lista!");
		}
		printf("\n\n");

		error = 0;
	}
	return error;
}

int altaMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], int tam, int tam_tc, int idMascota)
{
	int error = 1; //falla en el alta
	int indice;
	eMascota nuevaMascota;

	if(mascotas !=NULL && tam>0 && idMascota>0)
	{
		system("cls");
		printf("========== ALTA DE MASCOTAS ==========\n\n");
		indice = buscarLibreMascotas(mascotas, tam);

		if(indice==-1) //error sistema completo
		{
			printf("     >>> El sistema esta completo <<<");
		}else
		{
			nuevaMascota.id = idMascota;
			nuevaMascota.isEmpty = 0;
			printf("Ingrese el nombre: "); //ingreso del nombre
			fflush(stdin);
			gets(nuevaMascota.nombre);

			mostrarTipos(tipos, tam_tc);

			printf("Ingrese el ID del tipo: "); //ingreso del tipo y validacion
			scanf("%d", &nuevaMascota.idTipo);
			while(nuevaMascota.idTipo !=1000 && nuevaMascota.idTipo !=1001 && nuevaMascota.idTipo !=1002 && nuevaMascota.idTipo !=1003 && nuevaMascota.idTipo !=1004)
			{
				printf("La ID ingresada no coincide con ningun tipo existente.\n");
				printf("Ingrese nuevamente el ID del tipo: ");
				scanf("%d", &nuevaMascota.idTipo);
			}

			mostrarColores(colores, tam_tc);

			printf("Ingrese el ID del color: "); //ingreso del color y validacion
			scanf("%d", &nuevaMascota.idColor);
			while(nuevaMascota.idColor !=5000 && nuevaMascota.idColor !=5001 && nuevaMascota.idColor !=5002 && nuevaMascota.idColor !=5003 && nuevaMascota.idColor !=5004)
			{
				printf("La ID ingresada no coincide con ningun tipo existente.\n");
				printf("Ingrese nuevamente el ID del tipo: ");
				scanf("%d", &nuevaMascota.idTipo);
			}

			printf("Ingrese la edad: ");  //ingreso de la edad y validacion
			scanf("%d", &nuevaMascota.edad);
			while(nuevaMascota.edad > 30 || nuevaMascota.edad < 1)
			{
				printf("La edad ingresada no es valida. Ingrese nuevamente la edad: ");
				scanf("%d", &nuevaMascota.edad);
			}

			printf("Se ha ingresado la mascota al sistema con exito!");
		}
	}
	return error;
}

int buscarMascota(eMascota mascotas[], int tam, int idMascota)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(mascotas[i].id == idMascota)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int modificarMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], int tam, int tam_tc)
{
	int error = 1;
	int idMascota;
	int indice;
	char opcion;
	char seguir = 's';

	if(mascotas != NULL && tam > 0)
	{
		system("cls");
		printf("========== MODIFICACION MASCOTAS ==========\n\n");
		mostrarMascotas(mascotas, tipos, colores, tam, tam_tc);
		printf("Ingrese el ID de la mascota que desea modificar: ");
		scanf("%d", &idMascota);

		indice = buscarMascota(mascotas, tam, idMascota);

		if(indice == -1)
		{
			printf(">>> No existe una mascota con esa ID! <<<\n\n");
		}else
		{
			mostrarMascota(mascotas[indice], tipos, colores, tam_tc);

			do{
				printf("Que desea modificar?\n\n");
				printf("A ---> TIPO\n");
				printf("B ---> EDAD\n\n");
				printf("Z ---> Volver atras\n\n");
				scanf("%c", &opcion); //FALTA VALIDAR QUE SEA UNA LETRA
				fflush(stdin);
				opcion = tolower(getchar());

				switch(opcion)
				{
					case 'a':
						mostrarTipos(tipos, tam_tc);
						printf("Ingrese la ID del tipo deseado: ");
						scanf("%d", &mascotas[indice].idTipo);
						printf("\n\nEl cambio de tipo ha sido realizado con exito!");
						system("pause");
						break;
					case 'b':
						printf("Ingrese la edad: \n\n");
						scanf("%d", &mascotas[indice].edad);
						printf("\n\nEl cambio de edad ha sido realizado con exito!");
						system("pause");
						break;
					case 'z':
						seguir = 'n';
						break;
					default:
						printf("\nLa opcion ingresada no existe!\n\n"); //validacion de las opciones disponibles
						system("pause");
						break;
				}
				error = 0;
			}while(seguir == 's');
		}
	}
	return error;
}

int bajaMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], int tam, int tam_tc)
{
	int error = 1; //error en la baja
	int idMascota;
	int indice;
	char confirma;

	if(mascotas != NULL && tam > 0)
	{
		system("cls");
		printf("========== BAJA DE MASCOTA ==========\n\n");
		mostrarMascotas(mascotas, tipos, colores, tam, tam_tc);
		printf("Ingrese el ID de la mascota: ");
		scanf("%d", &idMascota);

		indice = buscarMascota(mascotas, tam, idMascota);

		if(indice == -1)
		{
			printf(">>> No existe una mascota con esa ID! <<<\n\n");
		}else
		{
			mostrarMascota(mascotas[indice], tipos, colores, tam_tc);
			printf("Confirma el borrado?: Ingrese s/n"); //falta validacion
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);

			if(confirma =='s')
			{
				mascotas[indice].isEmpty = 1;
				error = 0; //borrado correctamente
			}else
			{
				error = 2; //no confirma el borrado
			}
		}
	}
	return error;
}

int ordenarMascotasTipoNombre(eMascota mascotas[], int tam, int criterioTipo, int criterioNombre)
{
	int error = 1;
	eMascota auxMascota;

	if(mascotas !=NULL && tam>0 && criterioTipo >= 0 && criterioTipo <= 1 && criterioNombre >= 0 && criterioNombre <= 1)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if(mascotas[i].idTipo > mascotas[j].idTipo && criterioTipo == 1)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
				else if(mascotas[i].idTipo < mascotas[j].idTipo && criterioTipo == 0)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
				else if(mascotas[i].idTipo == mascotas[j].idTipo && mascotas[i].nombre > mascotas[j].nombre && criterioNombre == 1)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
				else if(mascotas[i].idTipo == mascotas[j].idTipo && mascotas[i].nombre < mascotas[j].nombre && criterioNombre == 0)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
			}
		}
		error = 0;
	}
	return error;
}
