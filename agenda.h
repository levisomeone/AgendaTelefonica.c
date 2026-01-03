#ifndef AGENDA_H
#define AGENDA_H

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char rua[50];
    int numero;
    char complemento[30];
    char bairro[30];
    char cidade[30];
    char estado[3];
    char cep[15];
    char pais[30];
} Endereco;

typedef struct {
    int ddd;
    char numero[15];
} Telefone;

typedef struct {
    char nome[50];
    char email[50];
    Endereco endereco;
    Telefone telefone;
    Data aniversario;
    char observacao[200];
} Pessoa;

void limparBuffer(void);
void inserirPessoa(void);
void buscarPorNome(void);
void buscarPorMes(void);
void buscarPorDiaMes(void);
void removerPessoa(void);
void imprimirAgenda(void);

#endif
