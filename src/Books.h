/*
 * Books.h
 *
 *  Created on: 28 nov 2021
 *      Author: alfre
 */

#ifndef BOOKS_H_
#define BOOKS_H_
typedef struct
{
	int idBook;
	char titulo[50];
	char autor[50];
	float precio;
	int idEditorial;
}eBook;

eBook* book_new();
eBook* Book_newParametros(char* idBookStr,char* titulo,char* autor, char* precioStr, char* idEditorialStr);
void Book_delete(eBook* this);

int Book_setIdBook(eBook* this, int idBook);
int Book_getIdBook(eBook* this,int* idBook);

int Book_setTitulo(eBook* this,char* titulo);
int Book_getTitulo(eBook* this,char* titulo);

int Book_setAutor(eBook* this,char* autor);
int Book_getAutor(eBook* this,char* autor);

int Book_setPrecio(eBook* this,float precio);
int Book_getPrecio(eBook* this,float* precio);

int Book_SetIdEditorial(eBook* this, int idEditorial);
int Book_getIdEditorial(eBook* this,int* idEditorial);

int Book_sortBookAutor(void* pElementUno, void* pElementDos);
int Book_FiltrarMinotauro(void* pEditorial);
#endif /* BOOKS_H_ */
