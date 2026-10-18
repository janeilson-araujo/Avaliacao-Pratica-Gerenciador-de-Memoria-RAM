#include <stdlib.h>
#include <stdio.h>
#include "memoria.h"

typedef struct memoria{
    int id;
    int ocupado;
    size_t tamanho;
} memoria, *Pmemoria;

int tam_vet = 0;
memoria **vet_memoria = NULL;

void alocarMemoria(size_t tamanho){
    Pmemoria p;

    tam_vet = tam_vet + 1;

    vet_memoria = (Pmemoria) realloc(tam_vet ,sizeof(Pmemoria));

    vet_memoria[tam_vet-1] = (Pmemoria) calloc(1 ,sizeof(memoria));

    p->id = tam_vet;
    p->ocupado = 1;
    p->tamanho = tamanho;
}