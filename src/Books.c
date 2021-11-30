/*
 * Books.c
 *
 *  Created on: 28 nov 2021
 *      Author: alfre
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Books.h"


eBook* book_new()
{
	eBook* nuevoLibro;
	nuevoLibro = (eBook*) malloc(sizeof(eBook));

	if(nuevoLibro != NULL)
	{
		nuevoLibro->precio = 0;
		nuevoLibro->idBook = 0;
		strcpy(nuevoLibro->titulo, "indefinido");
		strcpy(nuevoLibro->autor, "NN");
		nuevoLibro->idEditorial = 0;
	}
	return nuevoLibro;
}

eBook* Book_newParametros(char* idBookStr,char* titulo,char* autor, char* precioStr, char* idEditorialStr)
{
	eBook* nuevoLibro;
	nuevoLibro = book_new();

	if(nuevoLibro != NULL)
	{
		if(!( Book_setIdBook(nuevoLibro,atoi(idBookStr) )
			&& Book_setTitulo(nuevoLibro, titulo)
			&& Book_setAutor(nuevoLibro, autor)
			&& Book_setPrecio(nuevoLibro,atof(precioStr))
			&& Book_SetIdEditorial(nuevoLibro,atoi(idEditorialStr))))
			{
				free(nuevoLibro);
				nuevoLibro = NULL;
			}
	}
	return nuevoLibro;
}

void Book_delete(eBook* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Book_setIdBook(eBook* this, int idBook)
{
	int todoOk = 0;
		if(this != NULL && idBook > 0)
		{
			this->idBook = idBook;
			todoOk = 1;
		}

	return todoOk;
}

int Book_getIdBook(eBook* this,int* idBook)
{
	int todoOk = 0;
	if(this != NULL && idBook != NULL)
	{
		*idBook = this->idBook;
		todoOk = 1;
	}
	return todoOk;
}


int Book_setTitulo(eBook* this,char* titulo)
{
	int todoOk = 0;
	if(this != NULL && titulo != NULL && strlen(titulo) > 3 && strlen(titulo) < 50)
	{
		strcpy(this->titulo,titulo);
		todoOk = 1;
	}
	return todoOk;
}

int Book_getTitulo(eBook* this,char* titulo)
{
	int todoOk = 0;
	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);
		todoOk = 1;
	}
	return todoOk;
}

int Book_setAutor(eBook* this,char* autor)
{
	int todoOk = 0;
	if(this != NULL && autor != NULL && strlen(autor) > 3 && strlen(autor) < 40)
	{
		strcpy(this->autor,autor);
		todoOk = 1;
	}
	return todoOk;
}

int Book_getAutor(eBook* this,char* autor)
{
	int todoOk = 0;
	if(this != NULL && autor != NULL)
	{
		strcpy(autor,this->autor);
		todoOk = 1;
	}
	return todoOk;
}

int Book_setPrecio(eBook* this,float precio)
{
	int todoOk = 0;
	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		todoOk = 1;
	}
	return todoOk;
}

int Book_getPrecio(eBook* this,float* precio)
{
	int todoOk = 0;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		todoOk = 1;
	}

	return todoOk;
}

int Book_SetIdEditorial(eBook* this, int idEditorial)
{
	int todoOk = 0;
		if(this != NULL && idEditorial > 0)
		{
			this->idEditorial = idEditorial;
			todoOk = 1;
		}

	return todoOk;
}

int Book_getIdEditorial(eBook* this,int* idEditorial)
{
	int todoOk = 0;
	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		todoOk = 1;
	}
	return todoOk;
}

int Book_sortBookAutor(void* pElementUno, void* pElementDos)
{
	int todoOk = 0;
	eBook* libroUno = NULL;
	eBook* libroDos = NULL;
	char autorUno[50];
	char autorDos[50];
	libroUno = (eBook*) pElementUno;
	libroDos = (eBook*) pElementDos;
	if(pElementUno != NULL && pElementDos != NULL)
	{
		Book_getAutor(libroUno, autorUno);
		Book_getAutor(libroDos, autorDos);
		if(strcmp(autorUno, autorDos) < 0)
		{
			todoOk = 1;
		}
		else
		{
			if(strcmp(autorUno, autorDos) > 0)
			{
				todoOk = -1;
			}
		}
	}

	return todoOk;
}

int Book_FiltrarMinotauro(void* pEditorial)
{
    int todoOk = 0;
    eBook* aux = NULL;
    aux = (eBook*)pEditorial;
   	int idEditorial = 4;
    if(aux != NULL)
    {
        if (aux->idEditorial == idEditorial)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
