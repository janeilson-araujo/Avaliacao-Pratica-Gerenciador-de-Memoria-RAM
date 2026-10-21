#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "memoria.h"

int main()
{
    int opcao;
    int id;
    size_t quant_bytes;
    int tamanho_temp;
    char term;

    printf("========== GERENCIADOR DE MEMÓRIA ==========\n");
    printf("1 - Alocar bloco de memória\n");
    printf("2 - Liberar bloco de memória\n");
    printf("3 - Exibir estado da memória\n");
    printf("4 - Exibir resumo da memória\n");
    printf("0 - Encerrar\n");

    while (true)
    {
        do
        {
            printf("\nEscolha uma opção: ");
            
            if (scanf("%d%c", &opcao, &term) != 2 || term != '\n')
            {
                limparEntrada();
                opcao = -1;
            }
            
            if (opcao < 0 || opcao > 4)
            {
                printf("Opção inválida. Por favor, digite um número entre 0 e 4.\n");
            }
        } while (opcao < 0 || opcao > 4);

        switch (opcao)
        {
        case 1:
            printf("\nInforme o tamanho do bloco em bytes: ");
            
            if (scanf("%d%c", &tamanho_temp, &term) != 2 || term != '\n')
            {
                limparEntrada();
                printf("Erro: Entrada inválida. Digite apenas números inteiros.\n");
                break;
            }
            
            if (tamanho_temp <= 0)
            {
                printf("Erro: O tamanho deve ser maior que zero.\n");
                break;
            }
            
            quant_bytes = (size_t)tamanho_temp;
            alocarMemoria(quant_bytes);

            break;

        case 2:
            printf("\nInforme o identificador do bloco: ");
            
            if (scanf("%d%c", &id, &term) != 2 || term != '\n')
            {
                limparEntrada();
                printf("Erro: Entrada inválida. Digite apenas números inteiros.\n");
                break;
            }

            liberarMemoria(id);

            break;

        case 3:
            exibirMemoria();
            break;
            
        case 4:
            resumoMemoria();
            break;
            
        case 0:
            printf("\nLiberando blocos restantes...\n");
            liberarTodasMemorias();
            printf("Todos os recursos foram liberados.\n");
            printf("Programa encerrado.\n");
            return 0;
        }
    }
}