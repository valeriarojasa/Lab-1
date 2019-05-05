lista *temp;
temp = malloc(sizeof(lista));
temp->tamano = MAX;
temp->arreglo = malloc(sizeof(int)*temp->tamano);
return(temp);
}

lista *CrearListaLlena(lista *L){
srand(time(NULL));
lista *temp;
temp = L;
int i;

for (i=0; i < temp->tamano; i++){
temp->arreglo[i] = rand()%10;
temp -> datos++;
    }
return (temp);
}

int EliminarLista(lista *L){
lista *temp;
temp = L;

temp->datos = 0;
temp-> tamano = 0;
temp-> arreglo = malloc(sizeof(0));

printf("lista eliminada con exito");
}

int BuscarNumero(lista *L, int busca){
lista *temp;
temp = L;
int i;

for (i=0; i<temp->tamano; i++){
if (temp->arreglo[i] == busca){
return i;
}

}
return -1;
}
