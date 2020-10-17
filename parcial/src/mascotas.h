/*
 * mascotas.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef MASCOTAS_H_
#define MASCOTAS_H_

typedef struct
{
	int id;
	char nombre[20];
	int idTipo; //validar
	int idColor; //validar
	int edad; //año fabricacion
	int isEmpty; // 1 vacia 0 llena
} eMascota;

#endif /* MASCOTAS_H_ */

int buscarLibreMascotas(eMascota mascotas[], int tam);

int altaMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], int tam, int tam_tc, int idMascota);

void mostrarMascota(eMascota unaMascota, eTipo tipos[], eColor colores[], int tam_tc);

int mostrarMascotas(eMascota mascotas[], eTipo tipos[], eColor colores[], int tam, int tam_tc);

int buscarMascota(eMascota mascotas[], int tam, int idMascota);

int modificarMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], int tam, int tam_tc);

int bajaMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], int tam, int tam_tc);

int ordenarMascotasTipoNombre(eMascota mascotas[], int tam, int criterioTipo, int criterioNombre);
