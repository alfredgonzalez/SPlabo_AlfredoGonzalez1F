/*
 * Editorial.c
 *
 *  Created on: 29 nov 2021
 *      Author: alfre
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Editorial.h"
#include "LinkedList.h"


eEditorial* Editorial_new()
{
	eEditorial* nuevaEditorial;
	nuevaEditorial = (eEditorial*) malloc(sizeof(eEditorial));

	if(nuevaEditorial != NULL)
	{
		nuevaEditorial->idEditorial = 0;
		strcpy(nuevaEditorial->nombre, "indefinido");
	}
	return nuevaEditorial;
}

eEditorial* Editorial_newParametros(char* idEditorialStr,char* nombre)
{
	eEditorial* nuevaEditorial;
	nuevaEditorial = Editorial_new();

	if(nuevaEditorial != NULL)
	{
		if(!( Editorial_setIdEditorial(nuevaEditorial,atoi(idEditorialStr) )
			&& Editorial_setNombre(nuevaEditorial, nombre)))
			{
				free(nuevaEditorial);
				nuevaEditorial = NULL;
			}
	}
	return nuevaEditorial;
}

void Editorial_delete(eEditorial* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Editorial_setIdEditorial(eEditorial* this, int idEditorial)
{
	int todoOk = 0;
		if(this != NULL && idEditorial > 0)
		{
			this->idEditorial = idEditorial;
			todoOk = 1;
		}

	return todoOk;
}

int Editorial_getIdEditorial(eEditorial* this,int* idEditorial)
{
	int todoOk = 0;
	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		todoOk = 1;
	}
	return todoOk;
}

int Editorial_setNombre(eEditorial* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && this != NULL && strlen(nombre) > 3 && strlen(nombre) < 20)
	{
		strcpy(this->nombre,nombre);
		todoOk = 1;
	}
	return todoOk;
}

int Editorial_getNombre(eEditorial* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk = 1;
	}
	return todoOk;
}


int cargarDescripcionEditorial(LinkedList* pArrayEditoriales, eEditorial* pEditorial, int tamEditoriales, int id, char descripcion[])
{
    int todoOk = 0;

    if (pArrayEditoriales != NULL && tamEditoriales > 0 && descripcion != NULL)
    {
    	todoOk = 1;
        for(int i=0; i<tamEditoriales;i++)
        {
        	pEditorial = ll_get(pArrayEditoriales, i);
        	if (pEditorial->idEditorial == id)
        	{
        		strcpy(descripcion, pEditorial->nombre);
        		break;
        	}

        }
    }
    return todoOk;
}

