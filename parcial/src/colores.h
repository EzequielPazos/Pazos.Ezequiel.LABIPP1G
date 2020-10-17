/*
 * colores.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef COLORES_H_
#define COLORES_H_

typedef struct
{
	int id; //comienza en 5000
	char nombreColor[20];
} eColor;

#endif /* COLORES_H_ */

int mostrarColores(eColor colores[], int tam);
