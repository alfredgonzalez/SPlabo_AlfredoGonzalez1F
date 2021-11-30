/*
 * Parser.c
 *
 *  Created on: 28 nov 2021
 *      Author: alfre
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Parser.h"
#include "LinkedList.h"


int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBooks)
{
	eBook* pBooksAux = NULL;
	int cant;
	char buffer[5][128];
	int todoOk = 0;
	if(pFile != NULL)
	{
		todoOk = 1;
	    cant = fscanf(pFile,"%[^,],%[^,],%[^,], %[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3], buffer[4]);
	    do
	    {
	         cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3], buffer[4]);

	         if(cant < 5)
	         {
	             break;
	         }

	         pBooksAux =  Book_newParametros(buffer[0],buffer[1],buffer[2], buffer[3], buffer[4]);

	         if(pBooksAux != NULL)
	         {
	               ll_add(pArrayListBooks,pBooksAux);

	         }
	    }while(!feof(pFile));
	}
	else
	{
	   printf("Error abriendo el archivo\n");
	}
	fclose(pFile);
	return todoOk;
}

int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{
	eEditorial* pEditorialAux = NULL;
	int cant;
	char buffer[2][128];
	int todoOk = 0;
	if(pFile != NULL)
	{
		todoOk = 1;
	    cant = fscanf(pFile,"%[^,],%[^\n]\n",buffer[0],buffer[1]);
	    do
	    {
	         cant = fscanf(pFile,"%[^,],%[^\n]\n",buffer[0],buffer[1]);

	         if(cant < 2)
	         {
	             break;
	         }

	         pEditorialAux =  Editorial_newParametros(buffer[0],buffer[1]);

	         if(pEditorialAux != NULL)
	         {
	               ll_add(pArrayListEditorial,pEditorialAux);

	         }
	    }while(!feof(pFile));
	 }
	 else
	 {
	     printf("Error abriendo el archivo\n");
	 }
	fclose(pFile);
	return todoOk;
}
