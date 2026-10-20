#ifndef __MEMORIA_H__
#define __MEMORIA_H__

typedef void *endereco;

typedef struct memoria
{
    int id;
    endereco p;
    int ocupado;
    size_t tamanho;
} memoria, *Pmemoria;


void alocarMemoria(size_t tamanho);

void liberarMemoria(int id);

void exibirMemoria();

void resumoMemoria();

void liberarTodasMemorias();

#endif