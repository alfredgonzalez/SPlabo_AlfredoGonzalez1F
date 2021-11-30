/*
 * Editorial.h
 *
 *  Created on: 29 nov 2021
 *      Author: alfre
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include "LinkedList.h"
#include "Books.h"

typedef struct
{
	int idEditorial;
	char nombre[50];
}eEditorial;

eEditorial* Editorial_new();
eEditorial* Editorial_newParametros(char* idEditorialStr,char* nombre);
void Editorial_delete(eEditorial* this);

int Editorial_setIdEditorial(eEditorial* this, int idEditorial);
int Editorial_getIdEditorial(eEditorial* this,int* idEditorial);

int Editorial_setNombre(eEditorial* this,char* nombre);
int Editorial_getNombre(eEditorial* this,char* nombre);

int cargarDescripcionEditorial(LinkedList* pArrayEditoriales, eEditorial* pEditorial, int tamEditoriales, int id, char descripcion[]);


#endif /* EDITORIAL_H_ */
