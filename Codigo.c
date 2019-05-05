#include <stdio.h>
#include "lista.h"

int main(){

lista *L = CrearListaVacia(); 
CrearListaLlena(L);
BuscarNumero(L,5);
EliminarLista(L);

return (0);
}
