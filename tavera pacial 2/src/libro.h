
#ifndef LIBRO_H_
#define LIBRO_H_

#define LEN_STR 256
#include "getsDatos.h"

typedef struct
{
    int id;
    char titulo [LEN_STR];
    char autor [LEN_STR];
    int precio;
    int editorialId;
}libro;

//setters
int libro_setId(libro* this,int id);
int libro_setIdTxt(libro* this,char* id);

int libro_setTitulo(libro* this,char* titulo);

int libro_setAutor(libro* this,char* autor);

int libro_setPrecio(libro* this, int precio);
int libro_setPrecioTxt(libro* this,char* precio);

int libro_setIdEditorialTxt(libro* this,char* editorial);
int libro_setIdEditorial(libro* this, int idEditorial);


//getters
int libro_getId(libro* this,int* id);
int libro_getTitulo(libro* this,char* titulo);
int libro_getAutor(libro* this,char* autor);
int libro_getPrecio(libro* this,int* precio);
int libro_getEditorialId(libro* this,int* idEditorial);
int getEditorialStr(int idEditorial, char* editorial);



////////////////////////
int libro_delete(libro* this);
libro* libro_new();
libro* libro_newParametrosTxt(char* id, char* titulo, char* autor, char* precio, char* nombreEditorial);



int libro_print(libro* this);
void libro_printEncabezado(void);



int libro_criterioAutor(void* item1, void* item2);


/////descuentos
void calculaPrecioFinal(void* pElement);\

//print en text
int libro_printTxt(FILE* fp, libro* this);
int libro_printLastTxt(FILE* fp, libro* this);





#endif /* LIBRO_H_ */
