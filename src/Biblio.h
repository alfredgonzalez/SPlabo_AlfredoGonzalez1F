/*
 * Biblio.h
 *
 *  Created on: 8 oct 2021
 *  Author: Alfredo Gonzalez
 */

#ifndef BIBLIO_H_
#define BIBLIO_H_

int ingresarString(char mensaje[], char dato[]);
int ingresarEntero(char mensaje[]);
float ingresarFlotante(char mensaje[]);
int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior);
int stringPrimeroLetraMayuscula(char string[]);
int validarLargoString(char string[], int min , int max);
int verificarSiContieneNumero(char list[]);
int menuOpcion();



#endif /* BIBLIO_H_ */
