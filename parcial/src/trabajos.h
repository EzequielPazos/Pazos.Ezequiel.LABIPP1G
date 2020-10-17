/*
 * trabajos.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef TRABAJOS_H_
#define TRABAJOS_H_

typedef struct
{
	int id; //autoincremental
	int idMascota; //validar
	int idServicio; //validar
	eFecha fechaTrabajo; //validar dia mes anio
	int isEmpty;
} eTrabajo;

#endif /* TRABAJOS_H_ */

int buscarLibreTrabajo(eTrabajo trabajos[], int tam);

int altaTrabajo(eTrabajo trabajos[], eMascota mascotas[], eServicio servicios[], eTipo tipos[], eColor colores[], int tam, int tam_s, int tam_tc, int idTrabajo);

int mostrarTrabajos(eTrabajo trabajos[], int tam);
