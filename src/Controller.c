/*
 * Controller.c
 *
 *  Created on: 28 nov 2021
 *      Author: alfre
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "Editorial.h"
#include "Books.h"
#include "LinkedList.h"



int controller_loadFromTextBook(char* path , LinkedList* pArrayListBook)
{
	int todoOk = 0;
	FILE* pFile;

	if ( path != NULL && pArrayListBook != NULL )
	{
	     system("cls");
	     printf("Cargar los datos de los libros desde el archivo data.csv (modo texto).\n");

	     pFile = fopen( path, "r");
	     if ( pFile == NULL )
	     {
	         printf("No se pudo abrir el archivo\n");
	     }
	     else
	     {
	         if (parser_BookFromText(pFile, pArrayListBook))
	         {
	             printf( "Carga de archivo de texto exitosa\n" );
	             todoOk = 1;
	         }
	     }
	 }
	 fclose(pFile);
	 return todoOk;
}
int controller_loadFromTextEditorial(char* path , LinkedList* pArrayListEditorial)
{
	int todoOk = 0;
	FILE* pFile;

	if ( path != NULL && pArrayListEditorial != NULL )
	{
	     system("cls");
	     printf("Cargar los datos de las editoriales desde el archivo data.csv (modo texto).\n");

	     pFile = fopen( path, "r");
	     if ( pFile == NULL )
	     {
	         printf("No se pudo abrir el archivo\n");
	     }
	     else
	     {
	         if (parser_EditorialFromText(pFile, pArrayListEditorial))
	         {
	             printf( "Carga de archivo de texto exitosa\n" );
	             todoOk = 1;
	         }
	     }
	 }
	 fclose(pFile);
	 return todoOk;
}

int controller_saveAsText(char* path, LinkedList* pArrayBook)
{
    int todoOk = 0;
    FILE* pFile;
    int idBook;
    char titulo[50];
    char autor[50];
    float precio;
    int idEditorialUno;
    eBook* auxBook = NULL;
    int tam;
    if (path != NULL && pArrayBook != NULL)
    {
        pFile = fopen(path, "w");
        if (pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }

        fprintf(pFile, "id_libro,titulo,autor,precio,id_editorial\n");
        tam =  ll_len(pArrayBook);
        for (int i = 0; i < tam ; i++)
        {
        	auxBook = ll_get(pArrayBook, i);
            if (
            		Book_getIdBook(auxBook,&idBook)
                && Book_getTitulo(auxBook,titulo)
                && Book_getAutor(auxBook,autor)
                && Book_getPrecio(auxBook,&precio)
				&& Book_getIdEditorial(auxBook, &idEditorialUno)
               )
            {
                   fprintf(pFile, "%d,%s,%s,%.2f,%d\n", idBook, titulo, autor, precio, idEditorialUno);
                   todoOk = 1;
            }

        }
    }
    fclose(pFile);
    return todoOk;
}

int controller_ListBook(LinkedList* pArrayListBook, LinkedList* pArrayEditorial)
{

	eBook* pBookAux = NULL;
	eEditorial* pEditorialAux = NULL;
	int todoOk = 0;


	if(pArrayListBook != NULL)
	{
		system("cls");
        printf("                                  Lista de libros  \n");
        printf("------------------------------------------------------------------------------------------\n");
        printf(" ID         TITULO               AUTOR                PRECIO                EDITORIAL\n");
        printf("------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < ll_len(pArrayListBook); i++)
		{
			pBookAux = ll_get(pArrayListBook,i);
			controller_showBook(pBookAux, pEditorialAux, pArrayEditorial, pArrayListBook);

		}
		todoOk =1;
	}
	return todoOk;
}


int controller_showBook(eBook* pBook, eEditorial* pEditorial, LinkedList* pArrayEditoriales, LinkedList* pArrayBook)
{
    int idBook;
    char titulo[40];
    char autor[40];
    float precio;
    int todoOk = 0;
    int idEditorial;
    char descripcion[50];
    int tamEditoriales;

    tamEditoriales = ll_len(pArrayEditoriales);

    if(pBook != NULL &&
        Book_getIdBook(pBook, &idBook) &&
        Book_getTitulo(pBook, titulo) &&
        Book_getAutor(pBook, autor) &&
        Book_getPrecio(pBook, &precio) &&
		Book_getIdEditorial(pBook, &idEditorial) &&
		cargarDescripcionEditorial(pArrayEditoriales, pEditorial, tamEditoriales,idEditorial,  descripcion))
    {
    	printf(" %-10d %-20s %-20s $%-20.2f %-20s\n",idBook,titulo,autor,precio,descripcion);
        todoOk = 1;
    }
    return todoOk;
}

int controller_sortBook(LinkedList* pArrayBooks)
{
	int todoOk = 0;
	int criterio = 0;

	if(pArrayBooks != NULL)
	{
		if(ll_isEmpty(pArrayBooks)==0)
		{
			ll_sort(pArrayBooks, Book_sortBookAutor, criterio);
			todoOk = 1;
		}
	}

	return todoOk;
}

int controller_filtroMinotauro(LinkedList* pArrayBook, LinkedList* pArrayEditoriales)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayBook != NULL)
    {
        listaFiltrada = ll_filter(pArrayBook, Book_FiltrarMinotauro);
        if(controller_ListBook(listaFiltrada, pArrayEditoriales))
        {
        	controller_saveAsText("editorialMinotauro.csv", listaFiltrada);
            printf("Archivo generado exitosamente \n");
        }

        todoOk = 1;
    }
    return todoOk;
}

void* controller_aplicarDescuentoPlaneta(void* pElement)
{
	eBook* aux = NULL;
	int descuento = 20;
	float calcularDescuento;
	if(pElement != NULL)
	{
		aux = (eBook*) pElement;
		if(aux->idEditorial == 1 && aux->precio >= 1500)
		{
			calcularDescuento = aux->precio *descuento/100;
			aux->precio = aux->precio - calcularDescuento;
		}
	}
	return aux;
}

void* controller_aplicarDescuentoSigloXXI(void* pElement)
{
	eBook* aux = NULL;
	int descuento = 10;
	float calcularDescuento;
	if(pElement != NULL)
	{
		aux = (eBook*) pElement;
		if(aux->idEditorial == 2 && aux->precio <= 1200)
		{
			calcularDescuento = aux->precio *descuento/100;
			aux->precio = aux->precio - calcularDescuento;
		}
	}
	return aux;
}
