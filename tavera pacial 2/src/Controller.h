

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#include "LinkedList.h"
#include "parser.h"
#include "libro.h"


int controller_loadFromText(char* path , LinkedList* pArray);

int controller_sortLibros(LinkedList* pArray);


int controller_ListLibros(LinkedList* pArray);
int controller_Descuentos(LinkedList* pArray);
int controller_saveAsText(char* path , LinkedList* pArray);


//int controller_Informes(LinkedList* pArray);



#endif /* CONTROLLER_H_ */
