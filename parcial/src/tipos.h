/*
 * tipos.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef TIPOS_H_
#define TIPOS_H_

typedef struct
{
	int id; //comienza en 1000
	char descripcion[20];
} eTipo;

#endif /* TIPOS_H_ */

int mostrarTipos(eTipo tipos[], int tam);
