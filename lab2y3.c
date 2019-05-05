#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lan2y3.h"

int main(){
    int opcion,MAX = 10000,numero;
    struct timespec start, finish;

    lista *L = CrearListaVacia(MAX);

    do{
    printf("\n\t\t\t\t\tMenu\n\n1. Insertar al final y buscar Secuencialmente\n\n2. Insertar en orden y buscar Binariamente\n\n3. Insertar al final, usar quicksort y buscar Binariamente\n\nR: ");
    scanf("%i",&opcion);
    system("cls");
    }while(opcion != 1 && opcion != 2 && opcion != 3);

    switch (opcion){
      case 1:
          clock_gettime(CLOCK_REALTIME, &start);

          InsertarFinal(L);
          BusquedaSecuencial(L,rand()%10000);

          clock_gettime(CLOCK_REALTIME, &finish);

          BusquedaSecuencial(L,rand()%10000);

          printf("\nTiempo en nano segundos al insertar %i datos en el arreglo: %ld",MAX,(finish.tv_nsec-start.tv_nsec));
          break;

      case 2:
        clock_gettime(CLOCK_REALTIME, &start);

        InsertarOrden(L);
        BusquedaBinaria(L,rand()%10000);

        clock_gettime(CLOCK_REALTIME, &finish);

        printf("\nTiempo en nano segundos al insertar %i datos en el arreglo: %ld",MAX,(finish.tv_nsec-start.tv_nsec));
        break;
      case 3:

        clock_gettime(CLOCK_REALTIME, &start);
        InsertarQuicksort(L);
        BusquedaBinaria(L,rand()%10000);
        clock_gettime(CLOCK_REALTIME, &finish);

        printf("\nTiempo en nano segundos al insertar %i datos en el arreglo: %ld",MAX,(finish.tv_nsec-start.tv_nsec));
      break;
    }

  return 0;
}
