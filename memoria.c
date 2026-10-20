#include <stdlib.h>
#include <stdio.h>
#include "memoria.h"

typedef struct memoria
{
    int id;
    int ocupado;
    size_t tamanho;
} memoria, *Pmemoria;

size_t tam_vet = 0;
Pmemoria *vet_memoria = NULL;

void alocarMemoria(size_t tamanho)
{
    Pmemoria *novo_vetor;

    novo_vetor = realloc(vet_memoria, (tam_vet + 1) * sizeof(*vet_memoria));
    if (novo_vetor == NULL)
    {
        printf("Erro ao aumentar vetor.\n");
        return;
    }

    vet_memoria = novo_vetor;
    vet_memoria[tam_vet] = calloc(1, sizeof(*vet_memoria[tam_vet]));
    if (vet_memoria[tam_vet] == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        vet_memoria[tam_vet] = NULL;
        return;
    }

    vet_memoria[tam_vet]->id = tam_vet + 1;
    vet_memoria[tam_vet]->ocupado = 1;
    vet_memoria[tam_vet]->tamanho = tamanho;
    tam_vet++;
}

void liberarMemoria(int id)
{
    if (vet_memoria[id - 1] == NULL || id <= 0 || id > tam_vet)
    {
        printf("Erro ao acessar memoria.\n");
        return;
    }

    if (vet_memoria[id - 1]->ocupado == 0)
    {
        printf("Bloco de memoria já liberado\n");
        return;
    }

    vet_memoria[id - 1]->ocupado = 0;

    printf("Memoria Liberada\n");
}