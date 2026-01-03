#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"
#include "logger.h"

int main(void)
{
    Agenda agenda;
    int opcao;

    LOG_INFO("Sistema iniciado");

    inicializarAgenda(&agenda);

    do {
        printf("\n===== AGENDA TELEFONICA =====\n");
        printf("1 - Inserir contato\n");
        printf("2 - Buscar por nome\n");
        printf("3 - Buscar aniversarios por mes\n");
        printf("4 - Buscar aniversarios por dia e mes\n");
        printf("5 - Remover contato\n");
        printf("6 - Imprimir agenda\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        LOG_DEBUG("Opcao escolhida: %d", opcao);

        switch (opcao) {
            case 1:
                LOG_INFO("Inserindo novo contato");
                inserirContato(&agenda);
                break;

            case 2:
                LOG_INFO("Busca por nome iniciada");
                buscarPorNome(&agenda);
                break;

            case 3:
                LOG_INFO("Busca de aniversarios por mes");
                buscarAniversariosPorMes(&agenda);
                break;

            case 4:
                LOG_INFO("Busca de aniversarios por dia e mes");
                buscarAniversariosPorDiaMes(&agenda);
                break;

            case 5:
                LOG_INFO("Remocao de contato iniciada");
                removerContato(&agenda);
                break;

            case 6:
                LOG_INFO("Impressao da agenda");
                imprimirAgenda(&agenda);
                break;

            case 0:
                LOG_INFO("Sistema encerrado pelo usuario");
                break;

            default:
                LOG_WARN("Opcao invalida selecionada");
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
