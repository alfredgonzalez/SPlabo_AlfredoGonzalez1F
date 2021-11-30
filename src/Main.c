/*
 ============================================================================
 Name        : Parcial_Labo2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Books.h"
#include "Controller.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Biblio.h"
#include "Editorial.h"

int main(void) {
	setbuf(stdout,NULL);
	int option = 0;
	char archivoCargarBook[20];
	char archivoCargarEditoriales[20];

	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();
	LinkedList* listaMapeada = ll_newLinkedList();
	do{
		option =  menuOpcion();
		switch(option)
		{
		case 1:
			ingresarString("Ingresa el nombre del archivo csv a cargar para libros (libros.csv)\n", archivoCargarBook);
			controller_loadFromTextBook(archivoCargarBook,listaLibros);
			break;
		case 2:
			ingresarString("Ingresar el nombre del archivo csv a cargar para editoriales (editoriales.csv)\n", archivoCargarEditoriales);
			controller_loadFromTextEditorial(archivoCargarEditoriales, listaEditoriales);
			break;
		case 3:
			if(!ll_isEmpty(listaLibros)&& !ll_isEmpty(listaEditoriales))
			{
				if(listaLibros != NULL)
				{
					printf("Lista ordenada correctamente\n");
					controller_sortBook(listaLibros);
				}
			}
			else
			{
				printf("debe cargar el archivo (libros.csv) y el archivo (editoriales.csv) para poder ordenar la lista de libros\n");
			}
			break;
		case 4:
			if(!ll_isEmpty(listaLibros) && !ll_isEmpty(listaEditoriales))
			{
				if(listaLibros != NULL && listaEditoriales != NULL)
				{
					{
						controller_ListBook(listaLibros, listaEditoriales);
						printf("Imprimiendo lista de libros\n");
					}
				}
			}
			else
			{
				printf("debe cargar el archivo (libros.csv) y el archivo (editoriales.csv) para poder ordenar la lista de libros\n");
			}
			break;
		case 5:
			if(!ll_isEmpty(listaLibros) && !ll_isEmpty(listaEditoriales))
			{
				if(listaLibros != NULL && listaEditoriales != NULL)
				{
					{
						printf("Filtrando lista \n");
						controller_filtroMinotauro(listaLibros, listaEditoriales);
					}
				}
			}
			else
			{
				printf("debe cargar el archivo (libros.csv) y el archivo (editoriales.csv) para poder ordenar la lista de libros\n");
			}

			break;
		case 6:
			if(!ll_isEmpty(listaLibros) && !ll_isEmpty(listaEditoriales))
			{
				controller_ListBook(listaLibros, listaEditoriales);
				listaMapeada = ll_map(listaLibros, controller_aplicarDescuentoPlaneta);
				listaMapeada = ll_map(listaMapeada, controller_aplicarDescuentoSigloXXI);
				controller_ListBook(listaMapeada, listaEditoriales);
				if(controller_saveAsText("mapeado.csv", listaMapeada))
				{
					printf("Archivo guardado con exito\n");
					printf("Descuento del 20%% aplicado a mayores de 1500 y editorial PLANETA\n");
					printf("Descuento del 10%% aplicado a menores de 1200 y editorial SIGLO XXI EDITORES\n");
					//EL ID 100 ES UN EJEMPLO DEL DESCUENTO DE PLANETA
					//EL ID 68 ES UN EJEMPLO DEL DESCUENTO DE SIGLO XXI EDITORES
				}
				else
				{
					printf("No fue posible guardar el archivo\n");
				}
			}
			else
			{
				printf("debe cargar el archivo (libros.csv) y el archivo (editoriales.csv) para poder ordenar la lista de libros\n");
			}
			break;
		case 7:
			printf("Gracias por elegirnos\n");

			break;
		default:
			printf("Opcion invalida \n");
			break;
		}
		system("pause");
	}while(option != 7);
	ll_deleteLinkedList(listaLibros);
	return 0;
}
