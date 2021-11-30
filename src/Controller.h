
#include "LinkedList.h"
#include "Parser.h"
#include "Books.h"
#include "Editorial.h"

int controller_loadFromTextBook(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromTextEditorial(char* path , LinkedList* pArrayListEditorial);
int controller_showBook(eBook* pBook, eEditorial* pEditorial, LinkedList* pArrayEditoriales, LinkedList* pArrayBook);
int controller_saveAsText(char* path, LinkedList* pArrayBook);
int controller_ListBook(LinkedList* pArrayListBook, LinkedList* pArrayEditorial);
int controller_sortBook(LinkedList* pArrayBooks);
int controller_filtroMinotauro(LinkedList* pArrayBook, LinkedList* pArrayEditoriales);
void* controller_aplicarDescuentoPlaneta(void* pElement);
void* controller_aplicarDescuentoSigloXXI(void* pElement);
