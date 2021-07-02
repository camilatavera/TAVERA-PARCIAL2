#include "parser.h"





int parser_LibroFromText(FILE* pFile , LinkedList* pArray)
{

	int ret=-1;
	char id[LEN_STR], titulo[LEN_STR], autor[LEN_STR], precio[LEN_STR], nombreEditorial[LEN_STR];
	int flag=0; //lectura fantasma

	if(pFile!=NULL && pArray!=NULL){
		ret=0;


		do{

			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor,
					precio, nombreEditorial)==5 && flag){

				libro* pLibro=NULL;
				pLibro=libro_newParametrosTxt(id, titulo, autor, precio, nombreEditorial);

				if(pLibro!=NULL){
					libro_print(pLibro);
					ll_add(pArray, pLibro);
				}
			}
				flag=1;



		}while(feof(pFile)==0);

	}

    return ret;
}











