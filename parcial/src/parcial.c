/*
 ============================================================================
 Name        : parcial.c
 Author      : Pazos Ezequiel
 Version     : 1.0.0
 Curso       : 1ro G
 Description : PP Laboratorio 1
 ============================================================================
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

#define TAM 100
#define TAM_TC 5
#define TAM_S 3
#define ASC 1
#define DESC 0

char menuVeterinaria();

int main(void) {

	setbuf(stdout, NULL);

	char seguir = 's';
	char opcionDeseada;
	char confirmacion;
	int proximoIdMascota = 1;
	int proximoIdTrabajo = 1;
	int flagPrimerAlta = 0;
	int flagPrimerTrabajo = 0;
	int rta;
	eMascota listaMascotas[TAM];
	eTipo listaTipos[TAM_TC] =
	{
			{1000, "Ave"},
			{1001, "Perro"},
			{1002, "Gato"},
			{1003, "Roedor"},
			{1004, "Pez"},
	};
	eColor listaColores[TAM_TC] =
	{
			{5000, "Negro"},
			{5001, "Blanco"},
			{5002, "Gris"},
			{5003, "Rojo"},
			{5004, "Azul"},
	};
	eServicio listaServicios[TAM_S] =
	{
			{20000, "Corte", 250},
			{20001, "Desparasitado", 300},
			{20002, "Castrado", 400},
	};
	eTrabajo listaTrabajos[TAM];

	do{
		opcionDeseada = menuVeterinaria(); //Muestra menu de opciones

		switch(opcionDeseada)
		{
			case 'a': //alta mascota
	        	if(altaMascota(listaMascotas, listaTipos, listaColores, TAM, TAM_TC, proximoIdMascota))
				{
					proximoIdMascota++;
					printf("\n >>>Alta exitosa!<<<\n\n");
					flagPrimerAlta = 1;
				}else
				{
					printf("\n>>>Problemas para realizar el alta\n\n");
				}
				break;
			case 'b': //modificacion de mascotas
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede modificar nada ya que todavia no se ha dado ningun alta!<<<\n\n");
				}else if(modificarMascota(listaMascotas, listaTipos, listaColores, TAM, TAM_TC))
				{
					printf("\n >>>Modificacion exitosa!<<<\n\n");
				}else
				{
					printf("\n >>>Se ha producido un error en la modificacion<<<\n\n");
				}
				break;
			case 'c': //baja mascota
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede dar de baja ninguna mascota ya que todavia no se ha dado ninguna de alta!<<<\n\n");
				}else
				{
					rta = bajaMascota(listaMascotas, listaTipos, listaColores, TAM, TAM_TC);
					if(rta == 0)
					{
						printf("\n >>>Baja exitosa!<<<\n\n");
					}else if(rta == 2)
					{
						printf("\n >>>La baja se ha cancelado por el usuario<<< \n\n");
					}else
					{
						printf("\n >>>Se ha producido un error en la baja<<<\n\n");
					}
				}
				break;
			case 'd': //listar mascotas
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se pueden listar las mascotas ya que todavia no se ha dado ninguna de alta!<<<\n\n");
				}else if(ordenarMascotasTipoNombre(listaMascotas, TAM, ASC, ASC)) //falta elegir asc o desc
				{
					printf("\n>>> Error al intentar ordenar los autos <<<\n\n");
				}else
				{
					printf("\n>>> Personas ordenadas con exito! <<<\n\n");
				}
				mostrarMascotas(listaMascotas, listaTipos, listaColores, TAM, TAM_TC);
				break;
			case 'e': //listar tipos
				if(mostrarTipos(listaTipos, TAM_TC))
				{
					printf("\n>>> Error al intentar mostrar las marcas <<<\n\n");
				}else
				{
					printf("\n>>> Marcas mostradas con exito! <<<\n\n");
				}
				break;
			case 'f': //listar colores
				if(mostrarColores(listaColores, TAM_TC))
				{
					printf("\n>>> Error al intentar mostrar los colores <<<\n\n");
				}else
				{
					printf("\n>>> Colores mostrados con exito! <<<\n\n");
				}
				break;
			case 'g': //listar servicios
				if(mostrarServicios(listaServicios, TAM_S))
				{
					printf("\n>>> Error al intentar mostrar los servicios <<<\n\n");
				}else
				{
					printf("\n>>> Servicios mostrados con exito! <<<\n\n");
				}
				break;
			case 'h': //alta trabajo
				if(altaTrabajo(listaTrabajos, listaMascotas, listaServicios, listaTipos, listaColores, TAM, TAM_TC, TAM_S, proximoIdTrabajo))
				{
					proximoIdTrabajo++;
					printf("\n >>>Alta exitosa!<<<\n\n");
					flagPrimerTrabajo = 1;
				}else
				{
					printf("\n>>>Problemas para realizar el alta<<<\n\n");
				}
				break;
			case 'i': //listar trabajos
				if(flagPrimerTrabajo == 0)
				{
					printf("\n\n>>>No se pueden listar los trabajos ya que todavia no se ha dado ninguno de alta!<<<\n\n");
				}else if(mostrarTrabajos(listaTrabajos, TAM))
				{
					printf("\n>>> Error al intentar mostrar los trabajos <<<\n\n");
				}else
				{
					printf("\n>>> Trabajos mostrados con exito! <<<\n\n");
				}
				break;
			case 'z': //salir
				printf("Confirma que quiere salir? Ingrese s/n\n"); //falta validar que lo que ingresa sea una letra
				fflush(stdin);
				scanf("%c", &confirmacion);
				confirmacion = tolower(confirmacion);
				while(confirmacion != 's' && confirmacion != 'n')
				{
					printf("La respuesta ingresada no es valida. Ingrese s/n\n");
					fflush(stdin);
					scanf("%c", &confirmacion);
					confirmacion = tolower(confirmacion);
				}
				if(confirmacion == 's')
				{
					seguir = 'n';
				}
				break;
			default: //validacion de las otra letras elegidas
				printf("\n>>> La opcion elegida es invalida! <<<\n");
				break;
		}

		system("pause");

	}while(seguir == 's');

	return EXIT_SUCCESS;
}

char menuVeterinaria()
{
	char opcion;

	system("cls");

	printf("========== VETERINARIA ==========\n\n");
	printf("A. ALTA MASCOTA\n");
	printf("B. MODIFICAR MASCOTA\n");
	printf("C. BAJA MASCOTA\n");
	printf("D. LISTAR MASCOTAS\n");
	printf("E. LISTAR TIPOS\n");
	printf("F. LISTAR COLORES\n");
	printf("G. LISTAR SERVICIOS\n");
	printf("H. ALTA TRABAJO\n");
	printf("I. LISTAR TRABAJOS\n");
	printf("Z. SALIR\n\n");
	printf("Ingrese la opcion deseada: "); //falta validar que lo que se ingrese sea una letra
	fflush(stdin);
	opcion = tolower(getchar());

	return opcion;
}

