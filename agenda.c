#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "agenda.h"
#include "logger.h"

#define MAX 100

Pessoa agenda[MAX];
int total = 0;

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inserirOrdenado(Pessoa p) {
    int i = total - 1;
    while (i >= 0 && strcasecmp(agenda[i].nome, p.nome) > 0) {
        agenda[i + 1] = agenda[i];
        i--;
    }
    agenda[i + 1] = p;
    total++;
}

void inserirPessoa(void) {
    LOG_INFO("Inicio da insercao de pessoa");

    if (total >= MAX) {
        LOG_ERROR("Agenda cheia: total=%d", total);
        return;
    }

    Pessoa p;

    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    LOG_DEBUG("Nome digitado: %s", p.nome);

    printf("Email: ");
    fgets(p.email, 50, stdin);
    p.email[strcspn(p.email, "\n")] = '\0';
    LOG_DEBUG("Email digitado: %s", p.email);

    printf("Rua: ");
    fgets(p.endereco.rua, 50, stdin);
    p.endereco.rua[strcspn(p.endereco.rua, "\n")] = '\0';

    printf("Numero: ");
    scanf("%d", &p.endereco.numero);
    limparBuffer();

    printf("Complemento: ");
    fgets(p.endereco.complemento, 30, stdin);
    p.endereco.complemento[strcspn(p.endereco.complemento, "\n")] = '\0';

    printf("Bairro: ");
    fgets(p.endereco.bairro, 30, stdin);
    p.endereco.bairro[strcspn(p.endereco.bairro, "\n")] = '\0';

    printf("Cidade: ");
    fgets(p.endereco.cidade, 30, stdin);
    p.endereco.cidade[strcspn(p.endereco.cidade, "\n")] = '\0';

    printf("Estado: ");
    fgets(p.endereco.estado, 3, stdin);
    p.endereco.estado[strcspn(p.endereco.estado, "\n")] = '\0';
    limparBuffer();

    printf("Pais: ");
    fgets(p.endereco.pais, 30, stdin);
    p.endereco.pais[strcspn(p.endereco.pais, "\n")] = '\0';

    printf("CEP: ");
    fgets(p.endereco.cep, 15, stdin);
    p.endereco.cep[strcspn(p.endereco.cep, "\n")] = '\0';

    printf("Telefone (DDD): ");
    scanf("%d", &p.telefone.ddd);
    limparBuffer();

    printf("Numero: ");
    fgets(p.telefone.numero, 15, stdin);
    p.telefone.numero[strcspn(p.telefone.numero, "\n")] = '\0';

    printf("Data de aniversario (dd mm aaaa): ");
    scanf("%d %d %d", &p.aniversario.dia, &p.aniversario.mes, &p.aniversario.ano);
    limparBuffer();

    printf("Observacoes: ");
    fgets(p.observacao, 200, stdin);
    p.observacao[strcspn(p.observacao, "\n")] = '\0';

    inserirOrdenado(p);

    LOG_INFO("Pessoa inserida com sucesso: %s", p.nome);
    LOG_DEBUG("Total atual da agenda: %d", total);
}

void buscarPorNome(void) {
    LOG_INFO("Busca por nome iniciada");

    char nome[50];
    int encontrado = 0;

    printf("Digite o nome a ser buscado: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    LOG_DEBUG("Nome buscado: %s", nome);

    for (int i = 0; i < total; i++) {
        LOG_DEBUG("Comparando com agenda[%d]: %s", i, agenda[i].nome);

        if (strcasecmp(agenda[i].nome, nome) == 0) {
            encontrado = 1;
            LOG_INFO("Pessoa encontrada: %s", agenda[i].nome);

            printf("\n--- %s ---\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Telefone: (%d) %s\n",
                   agenda[i].telefone.ddd,
                   agenda[i].telefone.numero);
            printf("Aniversario: %02d/%02d/%04d\n",
                   agenda[i].aniversario.dia,
                   agenda[i].aniversario.mes,
                   agenda[i].aniversario.ano);
            printf("Endereco: %s, %d, %s, %s, %s-%s\n",
                   agenda[i].endereco.rua,
                   agenda[i].endereco.numero,
                   agenda[i].endereco.complemento,
                   agenda[i].endereco.bairro,
                   agenda[i].endereco.cidade,
                   agenda[i].endereco.estado);
            printf("CEP: %s | Pais: %s\n",
                   agenda[i].endereco.cep,
                   agenda[i].endereco.pais);
            printf("Observacao: %s\n",
                   agenda[i].observacao);
        }
    }

    if (!encontrado) {
        LOG_WARN("Nenhuma pessoa encontrada com o nome: %s", nome);
        printf("Nome nao encontrado.\n");
    }
}

void buscarPorMes(void) {
    LOG_INFO("Busca por mes iniciada");

    int mes;
    int encontrado = 0;

    printf("Digite o mes do aniversario (1-12): ");
    scanf("%d", &mes);
    limparBuffer();

    LOG_DEBUG("Mes buscado: %d", mes);

    for (int i = 0; i < total; i++) {
        if (agenda[i].aniversario.mes == mes) {
            encontrado = 1;
            printf("%s - %02d/%02d/%04d\n",
                   agenda[i].nome,
                   agenda[i].aniversario.dia,
                   agenda[i].aniversario.mes,
                   agenda[i].aniversario.ano);
        }
    }

    if (!encontrado) {
        LOG_WARN("Nenhum aniversario encontrado no mes %d", mes);
        printf("Nenhum aniversario encontrado neste mes.\n");
    }
}

void buscarPorDiaMes(void) {
    LOG_INFO("Busca por dia e mes iniciada");

    int dia, mes;
    int encontrado = 0;

    printf("Digite o dia e mes do aniversario (dd mm): ");
    scanf("%d %d", &dia, &mes);
    limparBuffer();

    LOG_DEBUG("Dia e mes buscados: %d/%d", dia, mes);

    for (int i = 0; i < total; i++) {
        if (agenda[i].aniversario.dia == dia &&
            agenda[i].aniversario.mes == mes) {

            encontrado = 1;
            printf("%s - %02d/%02d/%04d\n",
                   agenda[i].nome,
                   agenda[i].aniversario.dia,
                   agenda[i].aniversario.mes,
                   agenda[i].aniversario.ano);
        }
    }

    if (!encontrado) {
        LOG_WARN("Nenhum aniversario encontrado para %02d/%02d", dia, mes);
        printf("Nenhum aniversario encontrado nesta data.\n");
    }
}

void removerPessoa(void) {
    LOG_INFO("Remocao de pessoa iniciada");

    char nome[50];
    int removidos = 0;

    printf("Digite o nome da pessoa a remover: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    LOG_DEBUG("Nome para remocao: %s", nome);

    for (int i = 0; i < total; i++) {
        if (strcasecmp(agenda[i].nome, nome) == 0) {
            LOG_DEBUG("Removendo agenda[%d]: %s", i, agenda[i].nome);

            for (int j = i; j < total - 1; j++) {
                agenda[j] = agenda[j + 1];
            }

            total--;
            removidos++;
            i--;
        }
    }

    if (removidos > 0) {
        LOG_INFO("%d pessoa(s) removida(s): %s", removidos, nome);
        printf("%d registro(s) removido(s).\n", removidos);
    } else {
        LOG_WARN("Tentativa de remover pessoa inexistente: %s", nome);
        printf("Nenhuma pessoa encontrada.\n");
    }
}

void imprimirAgenda(void) {
    LOG_INFO("Impressao da agenda iniciada");

    int opcao;

    printf("1 - Nome, Telefone e Email\n");
    printf("2 - Todos os dados\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limparBuffer();

    LOG_DEBUG("Opcao de impressao escolhida: %d", opcao);

    for (int i = 0; i < total; i++) {
        LOG_DEBUG("Imprimindo agenda[%d]", i);

        printf("\n--- Contato %d ---\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: (%d) %s\n",
               agenda[i].telefone.ddd,
               agenda[i].telefone.numero);
        printf("Email: %s\n", agenda[i].email);

        if (opcao == 2) {
            printf("Endereco: %s, %d, %s, %s, %s-%s\n",
                   agenda[i].endereco.rua,
                   agenda[i].endereco.numero,
                   agenda[i].endereco.complemento,
                   agenda[i].endereco.bairro,
                   agenda[i].endereco.cidade,
                   agenda[i].endereco.estado);
            printf("CEP: %s | Pais: %s\n",
                   agenda[i].endereco.cep,
                   agenda[i].endereco.pais);
            printf("Aniversario: %02d/%02d/%04d\n",
                   agenda[i].aniversario.dia,
                   agenda[i].aniversario.mes,
                   agenda[i].aniversario.ano);
            printf("Observacao: %s\n",
                   agenda[i].observacao);
        }
    }
}

