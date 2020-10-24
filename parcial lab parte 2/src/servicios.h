/*
 * servicios.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct
{
	int id; //comienza en 20000
	char descripcion[25];
	float precio;
} eServicio;

#endif /* SERVICIOS_H_ */

/**
 * @brief muestra una lista de servicios ya hardcodeados
 * @param servicios array de servicios
 * @param tam tamanio del array
 * @return 1 si hubo algun error al mostrar los servicios o devuelve 0 si no hubo ningun error
 */
int mostrarServicios(eServicio servicios[], int tam);
