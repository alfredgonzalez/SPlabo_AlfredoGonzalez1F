/*
 * Parser.h
 *
 *  Created on: 28 nov 2021
 *      Author: alfre
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Books.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Editorial.h"

int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBooks);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);;

#endif /* PARSER_H_ */
