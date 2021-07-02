
#include "controller.h"
#include "menu.h"

int main(void) {

	setbuf(stdout, NULL);

	    int option;
	    char nombreArchivo[LEN_STR];
	    int flag=1;
	    int flagArchivo=1;

	    LinkedList* listaLibros = ll_newLinkedList();


	    do{
	    	printMenu();
	    	getNumero(&option, "Ingrese opcion de menu\n", "Error. ", 1, 6, 25);


	        switch(option)
	        {
	            case 1:
	            	if(flagArchivo==0){
	            		printf("Ya tiene un archivo cargado \n");
	            	}
	            	else if(validarString(nombreArchivo, LEN_STR, "Ingrese el nombre del archivo (datos.csv) \n",
	            			"Error. ", "datos.csv", 25)==0 && controller_loadFromText(nombreArchivo, listaLibros)==0){
	            		flagArchivo=0;
	                	printf("Operacion realizada con exito \n");
	                }
	                break;
	            case 2:
	            	if(controller_sortLibros(listaLibros)==0){
	            		printf("Ordenamiento exitoso \n");
	            	}
	            	break;
	            case 3:
	            	controller_ListLibros(listaLibros);
	            	break;
	            case 4:
	            	if(controller_Descuentos(listaLibros)==0){
	            		printf("Descuentos realizados con exito \n");
	            		flag=0;
	            	}
	            	break;
	            case 5:
	            	if(flag){
	            		printf("Primero debe realizar los decuentos \n");
	            	}
	            	else{
	            	controller_saveAsText("mapeado.csv", listaLibros);
	            	}
	            	break;
	        }
	    }while(option!=6);
	    return 0;
}
