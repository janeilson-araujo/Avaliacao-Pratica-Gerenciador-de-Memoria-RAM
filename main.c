#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "memoria.h"

int main()
{
    int opcao;

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
            printf("Digite sua opção: ");
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
            /* code */
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