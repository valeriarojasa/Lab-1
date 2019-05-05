#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Lista{
int datos;
int tamano;
int *arreglo;
}lista;

lista *CrearListaVacia(int MAX){
	srand(time(NULL));
lista *temp;
temp = malloc(sizeof(lista));
temp->tamano = MAX;
temp->arreglo = malloc(sizeof(int)*temp->tamano);
return(temp);
}


lista *InsertarFinal(lista *L){
	
	srand(time(NULL));
    lista *temp;
    temp = L;
    int i;

    for (i = 0; i < temp->tamano; i++) {
        temp->arreglo[i] = rand()%10000 + rand()%100000;
        temp->datos++;
    }

    return(temp);
}

lista *InsertarOrden(lista *L){
		srand(time(NULL));
lista *temp;
temp = L;
int i;
int aux;

for (i=0; i< temp->tamano; i++){
	
		temp->arreglo[i] = rand()%10000 + rand()%100000;
		temp -> datos++;


		if(temp->arreglo[i]>temp->arreglo[i-1]){
			aux = temp->arreglo[i-1];
			temp->arreglo[i-1] = temp->arreglo[i];
			temp->arreglo[i] = aux;
			
		}
	}
	return (temp);
}

int CompararParaQuicksort(const void *p, const void *q){
	int x, y;
	x = *(int *) p;
	y = *(int *) q;
	if(x < y){
		return -1;
	}
	if(x == y ){
		return 0;
	}
	return 1;
}
lista *InsertarQuicksort(lista *L){
		srand(time(NULL));
    lista *temp;
    temp = L;
    int i,aux;
    for (i = 0; i < temp->tamano; i++){
        temp->arreglo[i] = rand()%10000 + rand()%100000;
        aux = i + 1;
        qsort(temp->arreglo,aux,sizeof(int),&CompararParaQuicksort);
    }

    temp->datos = temp->tamano;

}

int BusquedaSecuencial(lista *L,int num){
    lista *temp;
    temp = L;
    int i;

    for(i = 0; i < temp->tamano; i++){
      if(temp->arreglo[i] == num){
        return i;
      }
    }

    return -1;
}
int BusquedaBinaria(lista *L, int num){
  lista *temp;
  temp = L;
	int inf,sup,mitad;

	inf = 0;
	sup = temp->tamano - 1;
	mitad = (sup + 1)/2;

	while(temp->arreglo[mitad] != num && inf<sup){
		if(temp->arreglo[mitad] > num){
			sup = mitad -1;
		}else{
			inf = mitad + 1;
		}
		mitad = (inf+sup)/2;
	}

	if(temp->arreglo[mitad] == num){
		return 1;
	}
	return 0;
}
