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
            scanf("%d", &opcao);
            getchar();
            if (opcao < 0 || opcao > 4)
            {
                printf("Opção inválida. Por favor, digite um número entre 0 e 7.\n");
            }
        } while (opcao < 0 || opcao > 4);

        switch (opcao)
        {
        case 1:
            printf("\nInforme o tamanho do bloco em bytes: ");
            scanf("%zu",&quant_bytes);

            alocarMemoria(quant_bytes);

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 0:

            void liberarTodasMemorias();
            return 0;
        }
    }
}