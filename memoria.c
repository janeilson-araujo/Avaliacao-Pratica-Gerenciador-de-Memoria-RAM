#include <stdlib.h>
#include <stdio.h>
#include "memoria.h"

size_t tam_vet = 0;
Pmemoria *vet_memoria = NULL;

void alocarMemoria(size_t tamanho)
{
    Pmemoria *novo_vetor;

    if (tamanho == 0)
    {
        printf("O tamanho deve ser maior que zero.\n");
        return;
    }

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

    vet_memoria[tam_vet]->p = calloc(1, tamanho);
    if (vet_memoria[tam_vet]->p == NULL)
    {
        printf("Erro ao alocar bloco de memoria.\n");
        free(vet_memoria[tam_vet]);
        vet_memoria[tam_vet] = NULL;
        return;
    }

    printf("Bloco alocado com sucesso!\n");

    vet_memoria[tam_vet]->id = tam_vet + 1;
    vet_memoria[tam_vet]->ocupado = 1;
    vet_memoria[tam_vet]->tamanho = tamanho;

    printf("Identificador: %d\n", vet_memoria[tam_vet]->id);
    printf("Endereço: %p\n", vet_memoria[tam_vet]->p);
    printf("Tamanho: %zu bytes\n", vet_memoria[tam_vet]->tamanho);
    printf("Estado: ");
    if (vet_memoria[tam_vet]->ocupado == 1)
    {
        printf("OCUPADO\n");
    }
    else
    {
        printf("LIVRE\n");
    }
    printf("\n");

    tam_vet++;
}

void liberarMemoria(int id)
{
    if (id <= 0 || (size_t)id > tam_vet || vet_memoria[id - 1] == NULL)
    {
        printf("Erro ao acessar memoria.\n");
        return;
    }

    if (vet_memoria[id - 1]->ocupado == 0)
    {
        printf("Bloco de memoria já liberado\n");
        return;
    }

    free(vet_memoria[id - 1]->p);
    vet_memoria[id - 1]->p = NULL;
    vet_memoria[id - 1]->ocupado = 0;

    printf("bloco %d liberado com sucesso\n", id);
}

void exibirMemoria()
{
    printf("ID    ENDERECO    TAMANHO    ESTADO\n");
    for (size_t i = 0; i < tam_vet; i++)
    {
        printf("%d  ", vet_memoria[i]->id);
        printf("%p  ", vet_memoria[i]->p);
        printf("%zu  ", vet_memoria[i]->tamanho);
        if (vet_memoria[i]->ocupado == 1)
        {
            printf("OCUPADO\n");
        }
        else
        {
            printf("LIVRE\n");
        }
    }
}

void resumoMemoria()
{
    size_t blocosRegistros = tam_vet;
    size_t blocosOcupados = 0;
    size_t blocosLivres = 0;
    size_t totalBytes = 0;

    for (size_t i = 0; i < tam_vet; i++)
    {
        if (vet_memoria[i]->ocupado == 1)
        {
            blocosOcupados = blocosOcupados + 1;
            totalBytes = totalBytes + vet_memoria[i]->tamanho;
        }
        else
        {
            blocosLivres = blocosLivres + 1;
        }
    }

    printf("Total de registros: %zu\n", blocosRegistros);
    printf("Blocos ocupados: %zu\n", blocosOcupados);
    printf("Blocos livres: %zu\n", blocosLivres);
    printf("Bytes atualmente alocados: %zu\n", totalBytes);
}

void liberarTodasMemorias()
{
    for (size_t i = 0; i < tam_vet; i++)
    {
        if (vet_memoria[i] != NULL)
        {
            free(vet_memoria[i]->p);
            free(vet_memoria[i]);
        }
    }

    free(vet_memoria);
    vet_memoria = NULL;
    tam_vet = 0;
}

void limparEntrada()
{
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF){}
}
