/*
 * Controller.c
 *
 *  Created on: Jun 23, 2021
 *      Author: caami
 */

#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "libro.h"




/** \brief Carga los datos en la likedlist desde el archivo
 *
 * \param path char*
 * \param pArray LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArray)
{
	int ret=-1;
	FILE* fp=NULL;

	if(path!=NULL && pArray!=NULL ){

		fp=fopen(path, "r");

		if(fp!=NULL){
			parser_LibroFromText(fp, pArray);
			fclose(fp);
			ret=0;
		}
	}
    return  ret;;
}



/** \brief Ordena pArray
 *
 * \param path char*
 * \param pArray LinkedList*
 * \return int
 *
 */
int controller_sortLibros(LinkedList* pArray){

	int ret=-1;
	if(pArray!=NULL){
		if(ll_len(pArray)==0){
			printf("Linkedlist vacia: nada para ordenar \n");
		}
		else{
			ll_sort(pArray, libro_criterioAutor, 1); // 1 ascendente
			ret=0;
		}
	}
	return ret;
}



/** \brief Listado de libros cargados en pArray
 *
 * \param pArray LinkedList*
 * \return int
 *
 */
int controller_ListLibros(LinkedList* pArray)
{
	int ret=-1;
	libro* pLibro=NULL;


	if(pArray!=NULL){

		if(ll_len(pArray)==0){
			printf("No hay libros ingresados al sistema \n");
		}
		else{
			ret=0;
			libro_printEncabezado();

			for(int i=0; i<ll_len(pArray); i++){
				pLibro=ll_get(pArray, i);
				libro_print(pLibro);
			}//cierro for

		}
	}
	return ret;

}



/** \brief Aplica descuentos
 *
 * \param pArray LinkedList*
 * \return int
 *
 */
int controller_Descuentos(LinkedList* pArray)
{
	int ret=-1;
	if(pArray!=NULL){
		if(ll_len(pArray)==0){
			printf("No hay libros ingresados al sistema \n");
		}
		else{
			ll_map(pArray, calculaPrecioFinal);
			ret=0;
		}
	}
	return ret;
}




/** \brief Guarda los datos de pArray en el archivo (modo texto).
 *
 * \param path char*
 * \param pArray LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArray){
	int ret=-1;
	FILE* fp;
	libro* pLibro;

	if(path!=NULL && pArray!=NULL){

		if(ll_len(pArray)==0){
			printf("No hay datos cargados \n");
		}
		else{
			fp=fopen(path, "w");
			if(fp!=NULL){
				fprintf(fp, "id,titulo,autor,precio,editorialId \n");

			for(int i=0; i<ll_len(pArray); i++){
					pLibro=ll_get(pArray, i);
					if(pLibro!=NULL){
						if(i==ll_len(pArray)-1){
							libro_printLastTxt(fp, pLibro);
						}
						else{
							libro_printTxt(fp, pLibro);
						}
						}
					}
				}

				fclose(fp);
				ret=0;
			}
		}

    return ret;
}

