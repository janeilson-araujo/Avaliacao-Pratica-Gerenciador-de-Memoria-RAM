#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "memoria.h"

int main()
{
    int opcao;
    int id;
    size_t quant_bytes;

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
            printf("Escolha uma opção: ");
            if (scanf("%d", &opcao) != 1)
            {
                limparEntrada();
                opcao = -1;
            }
            else
            {
                limparEntrada();
            }
            if (opcao < 0 || opcao > 4)
            {
                printf("Opção inválida. Por favor, digite um número entre 0 e 7.\n");
            }
        } while (opcao < 0 || opcao > 4);

        switch (opcao)
        {
        case 1:
            printf("\nInforme o tamanho do bloco em bytes: ");
            if (scanf("%zu", &quant_bytes) != 1)
            {
                limparEntrada();
                printf("Entrada inválida.\n");
                break;
            }
            limparEntrada();

            alocarMemoria(quant_bytes);

            break;
        case 2:
            printf("\nInforme o identificador do bloco: ");
            if (scanf("%d", &id) != 1)
            {
                limparEntrada();
                printf("Entrada inválida.\n");
                break;
            }
            limparEntrada();

            liberarMemoria(id);

            break;
        case 3:

            exibirMemoria();

            break;
        case 4:
            resumoMemoria();

            break;
        case 0:

            liberarTodasMemorias();
            return 0;
        }
    }
}