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

int mostrarServicios(eServicio servicios[], int tam);
