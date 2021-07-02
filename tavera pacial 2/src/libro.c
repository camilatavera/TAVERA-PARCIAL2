#include "libro.h"



//---------------SETTERS--------------------------------
int libro_setId(libro* this,int id){

	int ret=-1;
	if(this!=NULL && id>0){
		this->id=id;
		ret=0;
	}
	return ret;
}

int libro_setIdTxt(libro* this,char* id){

	int ret=-1;
	if(this!=NULL && id!=NULL){
		if(esNumero(id, 10)){
			this->id=atoi(id);
			ret=0;
		}
	}
	return ret;

}

int libro_setTitulo(libro* this,char* titulo){
	int ret=-1;
	if(this!=NULL && titulo!=NULL){

		//if(isValidNombre(titulo, LEN_STR)){
			strncpy(this->titulo, titulo, LEN_STR);
			ret=0;
		//}
	}
		return ret;
}


int libro_setAutor(libro* this,char* autor){
	int ret=-1;
	if(this!=NULL && autor!=NULL){

		//if(isValidNombre(autor, LEN_STR)){
			strncpy(this->autor, autor, LEN_STR);
			ret=0;
		//}
	}
		return ret;
}


int libro_setPrecio(libro* this, int precio){

	int ret=-1;
	if(this!=NULL && precio>0){
		this->precio=precio;
		ret=0;
	}
	return ret;
}

int libro_setPrecioTxt(libro* this,char* precio){

	int ret=-1;
	if(this!=NULL && precio!=NULL){
			this->precio=atoi(precio);
			ret=0;
		}
	return ret;
}

int libro_setIdEditorialTxt(libro* this,char* editorial){

	int ret=-1;
	if(this!=NULL && editorial!=NULL){

		if(stricmp(editorial, "planeta")==0){
			this->editorialId=1;
			ret=0;
		}
		else if(stricmp(editorial, "siglo xxi editores")==0){
			this->editorialId=2;
			ret=0;
		}
		else if(stricmp(editorial, "pearson")==0){
			this->editorialId=3;
			ret=0;
		}
		else if(stricmp(editorial, "minotauro")==0){
			this->editorialId=4;
			ret=0;
		}
		else if(stricmp(editorial, "salamandra")==0){
			this->editorialId=5;
			ret=0;
		}
		else if(stricmp(editorial, "penguin books")==0){
			this->editorialId=6;
			ret=0;
		}


		}
	return ret;
}


int libro_setIdEditorial(libro* this, int idEditorial){

	int ret=-1;
	if(this!=NULL && idEditorial>=1 && idEditorial<=6){
		this->editorialId=idEditorial;
		ret=0;
	}
	return ret;
}

//*************************************************************************************************************

int libro_delete(libro* this){
	int ret=-1;
	if(this!=NULL){
		free(this);
		this=NULL;
		ret=0;
	}
	return ret;
}



libro* libro_new(){
	libro* nuevoLibro=NULL;
	nuevoLibro=(libro*)malloc(sizeof(libro));
	return nuevoLibro;
}




libro* libro_newParametrosTxt(char* id, char* titulo, char* autor, char* precio, char* nombreEditorial){

	libro* pLibro=libro_new();


	if(id!=NULL && titulo!=NULL && autor!=NULL && precio!=NULL && nombreEditorial!=NULL){

			if(libro_setIdTxt(pLibro, id)==-1 ||
					libro_setTitulo(pLibro, titulo)==-1 ||
					libro_setAutor(pLibro, autor)==-1 ||
					libro_setPrecioTxt(pLibro, precio)==-1 ||
					libro_setIdEditorialTxt(pLibro, nombreEditorial)==-1){

					libro_delete(pLibro);
				}
	}

	return pLibro;
}




////////////GETTERS----------------------------------------


int libro_getId(libro* this,int* id){

	int ret=-1;

	if(this!=NULL && id!=NULL){
		*id=this->id;
		ret=0;
	}
	return ret;
}

int libro_getTitulo(libro* this,char* titulo){
	int ret=-1;
		if(this!=NULL && titulo!=NULL){
			strcpy(titulo, this->titulo);
			ret=0;
		}

		return ret;
}


int libro_getAutor(libro* this,char* autor){
	int ret=-1;
		if(this!=NULL && autor!=NULL){
			strcpy(autor, this->autor);
			ret=0;
		}

	return ret;
}



int libro_getPrecio(libro* this,int* precio){

	int ret=-1;

	if(this!=NULL && precio!=NULL){
		*precio=this->precio;
		ret=0;
	}
	return ret;
}


int libro_getEditorialId(libro* this,int* idEditorial){

	int ret=-1;

	if(this!=NULL && idEditorial!=NULL){
		*idEditorial=this->editorialId;
		ret=0;
	}
	return ret;
}


int getEditorialStr(int idEditorial, char* editorial){
	int ret=-1;
	if(idEditorial>=1 && idEditorial<=6 && editorial!=NULL){
		ret=0;
		switch(idEditorial){
		case 1:
			strcpy(editorial, "PLANETA");
			break;
		case 2:
			strcpy(editorial, "SIGLO XXI EDITORES");
			break;
		case 3:
			strcpy(editorial, "PEARSON");
			break;
		case 4:
			strcpy(editorial, "MINOTAURO");
			break;
		case 5:
			strcpy(editorial, "SALAMANDRA");
			break;
		case 6:
			strcpy(editorial, "PENGUIN BOOKS");
			break;
		}
	}
	return ret;
}



/////////////////////PRINTS/////////////////////////////////

int libro_print(libro* this){
	int ret=-1;
	int id;
	char titulo[128];
	char autor[128];
	int precio;
	int editorialId;
	char editorialStr[128];

	if(this!=NULL){
		ret=0;

		if(libro_getId(this, &id)==0 && libro_getTitulo(this, titulo)==0 && libro_getAutor(this, autor)==0 &&
			libro_getPrecio(this, &precio)==0 && libro_getEditorialId(this, &editorialId)==0 &&
			getEditorialStr(editorialId, editorialStr)==0){


			printf("%-5d %-55s %-20s %-8d %s  \n", id, titulo, autor, precio, editorialStr);

			}
	}

	return ret;
}


void libro_printEncabezado(void){
	printf("Id    Titulo                                                  Autor                Precio   Editorial \n");

}




////////ORDENAMIENTO/////////////////////////////



/** \brief  Compara dos elementos.
 * \param void* item1
 * \param void* item1
 * \return int (0) si item1 o item2 es NULL
 * 			   (1) si item1 es mayor a item2
 * 			   (-1) si item1 es menor a item2
*/
int libro_criterioAutor(void* item1, void* item2){
	int ret=0;
	libro* e1;
	libro* e2;

	char autor1[LEN_STR];
	char autor2[LEN_STR];
	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(libro*)item1;
		e2=(libro*)item2;

		libro_getAutor(e1, autor1);
		if(libro_getAutor(e1, autor1)==0 && libro_getAutor(e2, autor2)==0){
				if(strcmp(autor1, autor2)>0){
					ret=1;
				}
				else if(strcmp(autor1, autor2)<0){
					ret=-1;
				}
				else{
					if(libro_getId(e1, &id1)==0 && libro_getId(e2, &id2)==0){
						if(id1>id2){
							ret=1;
						}
						else{
							ret=-1;
						}
					}
				}

		}
	}
	return ret;
}



//////////////////DESCUENTOS. (funcion criterio de  ll_map)//////////////////


/** \brief  Aplica descuentos si corresponde.
 *
 * \param pElement void* Puntero del elemento a procesar.
 * \return void Retorna
*/
void calculaPrecioFinal(void* pElement){

	int editorialId;
	int precio;

	if(pElement!=NULL && libro_getEditorialId(pElement, &editorialId)==0 && libro_getPrecio(pElement, &precio)==0){


		if(editorialId==1 && precio>=300){
			precio=precio*80/100;
			libro_setPrecio(pElement, precio);
		}
		else if(editorialId==2 && precio<=200){
			precio=precio*90/100;
			libro_setPrecio(pElement, precio);
		}

	}
}



///////////SAVE AS TEXT///////////////////////////////

int libro_printTxt(FILE* fp, libro* this){
	int ret=-1;

		int id;
		char titulo[128];
		char autor[128];
		int precio;
		int editorialId;
		char editorialStr[128];

		if(this!=NULL && fp!=NULL){
			ret=0;

			if(libro_getId(this, &id)==0 && libro_getTitulo(this, titulo)==0 && libro_getAutor(this, autor)==0 &&
				libro_getPrecio(this, &precio)==0 && libro_getEditorialId(this, &editorialId)==0 &&
				getEditorialStr(editorialId, editorialStr)==0){

				fprintf(fp,"%d,%s,%s,%d,%s\n", id, titulo, autor, precio, editorialStr);
			}
	}
	return ret;
}


int libro_printLastTxt(FILE* fp, libro* this){
	int ret=-1;

		int id;
		char titulo[128];
		char autor[128];
		int precio;
		int editorialId;
		char editorialStr[128];

		if(this!=NULL && fp!=NULL){
			ret=0;

			if(libro_getId(this, &id)==0 && libro_getTitulo(this, titulo)==0 && libro_getAutor(this, autor)==0 &&
				libro_getPrecio(this, &precio)==0 && libro_getEditorialId(this, &editorialId)==0 &&
				getEditorialStr(editorialId, editorialStr)==0){

				fprintf(fp,"%d,%s,%s,%d,%s", id, titulo, autor, precio, editorialStr);
			}
	}
	return ret;
}

















