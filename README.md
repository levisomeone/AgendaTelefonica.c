<h1 align="center">📘 Agenda Telefônica — Linguagem C</h1>

<p align="center">
Agenda telefônica com vdiversas funções, incluindo arquivo log para salvamento de etapas.
</p>

<br>

---


## 📞 Projeto: Agenda Telefônica em C (com Logs)

<p>
Projeto de uma <strong>Agenda Telefônica em C</strong>, desenvolvida com foco em:
</p>

<ul>
  <li>Estruturas (<code>struct</code>)</li>
  <li>Organização em múltiplos arquivos (<code>.h</code> / <code>.c</code>)</li>
  <li>Manipulação de strings</li>
  <li>Ordenação alfabética</li>
  <li>Boas práticas de entrada de dados</li>
  <li><strong>Sistema de logs profissional</strong></li>
</ul>

---

## ✨ Funcionalidades

<ul>
  <li>Inserir contatos</li>
  <li>Buscar contato por nome</li>
  <li>Buscar aniversários por mês</li>
  <li>Buscar aniversários por dia e mês</li>
  <li>Remover contatos</li>
  <li>Imprimir agenda (resumida ou completa)</li>
</ul>

---

## 🧠 Sistema de Logs

<p>
O projeto conta com um <strong>sistema de logs próprio</strong>, inspirado em aplicações reais.
Ele registra eventos importantes do sistema em um arquivo <code>.log</code>.
</p>

### 🔹 Níveis de log utilizados

<ul>
  <li><strong>DEBUG</strong> — Informações detalhadas para depuração</li>
  <li><strong>INFO</strong> — Eventos normais do sistema</li>
  <li><strong>WARN</strong> — Situações inesperadas, mas não críticas</li>
  <li><strong>ERROR</strong> — Erros que impedem alguma ação</li>
</ul>

### 📄 Exemplo de saída do log

```txt
[03/01/2026 09:45:12] [INFO] Iniciando sistema...
[03/01/2026 09:45:20] [DEBUG] Opcao escolhida pelo usuario: 1
[03/01/2026 09:45:45] [INFO] Pessoa inserida com sucesso: João
[03/01/2026 09:46:10] [WARN] Nenhum aniversario encontrado neste mes
[03/01/2026 09:46:30] [INFO] Sistema encerrado

## 📁 Organização dos Arquivos

```txt
📂 agenda-telefonica/
│
├── agenda.h        # Definições das estruturas e protótipos
├── agenda.c        # Implementação das funções da agenda
│
├── logger.h        # Interface do sistema de logs
├── logger.c        # Implementação do logger
│
├── main.c          # Função principal e menu
├── app.log         # Arquivo de logs gerado em execução
└── README.md

