#ifndef __MEMORIA_H__
#define __MEMORIA_H__

#include <stddef.h>

void alocarMemoria(size_t tamanho);

void liberarMemoria(int id);

void exibirMemoria();

void resumoMemoria();

void liberarTodasMemorias();

#endif