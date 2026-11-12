# PSE em Ação — Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola

## Sobre o projeto

O **PSE em Ação** é um projeto acadêmico desenvolvido no contexto da **Atividade de Estudo Programado (AEP)** do curso de **Análise e Desenvolvimento de Sistemas** da Universidade Cesumar (Unicesumar).

O projeto consiste em uma aplicação desenvolvida em linguagem **C**, executada em terminal, com o objetivo de auxiliar uma equipe escolar e de saúde no **planejamento, registro e acompanhamento de ações coletivas do Programa Saúde na Escola (PSE)**.

A aplicação permite organizar informações como código identificador, escola, tema da ação, data planejada, quantidade de participantes previstos, status da ação e quantidade real de participantes.

O sistema utiliza exclusivamente **dados fictícios e coletivos**, não contemplando informações individuais de estudantes, diagnósticos, condições clínicas ou qualquer outro dado pessoal de saúde.

## Objetivo

Desenvolver uma aplicação computacional utilizando a linguagem C para auxiliar equipes escolares e de saúde no planejamento, registro e acompanhamento de ações coletivas do Programa Saúde na Escola (PSE), proporcionando uma organização clara das informações e respeitando os limites de privacidade dos estudantes.

## Funcionalidades implementadas

O sistema possui as seguintes funcionalidades:

- **Cadastro de ações:** permite registrar novas ações, informando seus dados principais, como código, escola, tema, data e quantidade de participantes previstos.
- **Listagem de ações:** apresenta os registros cadastrados durante a execução do programa.
- **Pesquisa de ações:** permite localizar registros por código, nome da escola ou tema, incluindo pesquisas por partes do texto.
- **Atualização de status:** permite alterar o status de uma ação para PLANEJADA, REALIZADA ou CANCELADA.
- **Registro de participantes reais:** ao marcar uma ação como realizada, permite informar a quantidade efetiva de participantes.
- **Resumo geral:** apresenta o total de ações cadastradas, a quantidade por status e os dados de participação das ações realizadas.
- **Validação de dados:** verifica entradas numéricas, campos obrigatórios e datas, incluindo a validade dos dias de cada mês e anos bissextos.
- **Validação de menus:** trata opções inválidas selecionadas pelo usuário.

## Tecnologias e conceitos utilizados

- **Linguagem:** C
- **Padrão:** C11
- **Compilador:** GCC
- **Execução:** Terminal do Windows
- **Ambiente de desenvolvimento:** Visual Studio Code
- Estruturas condicionais (`if`, `else` e `switch`);
- Estruturas de repetição;
- Vetores;
- Funções;
- Estruturas (`struct`);
- Manipulação de strings;
- Validação de entradas;
- Algoritmos e pseudocódigo;
- Fluxogramas;
- Modelagem de casos de uso;
- Testes de software.

## Regras e limitações

- O sistema permite cadastrar até **100 ações por execução**.
- Cada ação possui um código identificador, que não pode ser repetido.
- Os status disponíveis são PLANEJADA, REALIZADA e CANCELADA.
- Uma ação marcada como realizada deve possuir a quantidade real de participantes informada.
- O resumo de participação considera somente as ações com status REALIZADA.
- Caso a soma de participantes previstos nas ações realizadas seja zero, o percentual de participação não pode ser calculado.
- Os registros são armazenados exclusivamente em memória e são perdidos quando o programa é encerrado.
- O sistema não possui banco de dados ou armazenamento permanente.

## Como executar o projeto

### Pré-requisitos

- Windows;
- GCC instalado e configurado no PATH do sistema;
- Visual Studio Code ou outro terminal compatível.

### Compilação

Na pasta principal do projeto, execute:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic src/main.c -o AEP.exe
```

### Execução

Após a compilação, execute:

```powershell
.\AEP.exe
```

O menu principal será apresentado no terminal, permitindo acessar as funcionalidades disponíveis.

## Estrutura do repositório

```text
PSE-em-Acao/
│
├── README.md
│
├── src/
│   └── main.c
│
├── documentacao/
│   ├── Documento_Primeira_Entrega.pdf
│   │
│   ├── uml/
│   │   ├── diagrama_casos_de_uso.png
│   │   └── descricao_casos_de_uso.pdf
│   │
│   ├── manual/
│   │   └── manual_usuario_pse_em_acao.pdf
│   │
│   └── evidencias/
│       └── (capturas de tela da execução e dos testes)
│
└── testes/
    └── casos_de_teste.md
```

## Documentação do projeto

O desenvolvimento foi dividido em duas etapas principais:

### Primeira entrega — Planejamento e análise

- Contextualização do problema;
- Questão norteadora;
- Objetivo geral e objetivos específicos;
- Justificativa acadêmica e social;
- Identificação dos usuários;
- Definição do escopo;
- Requisitos funcionais e não funcionais;
- Fluxograma geral;
- Fluxograma detalhado do cadastro de ação;
- Pseudocódigos;
- Planejamento das sprints;
- Referências bibliográficas.

### Segunda entrega — Desenvolvimento e documentação

- Implementação da aplicação em linguagem C;
- Desenvolvimento das cinco funcionalidades principais;
- Validação de dados e entradas do usuário;
- Diagrama de casos de uso;
- Descrição dos casos de uso;
- Documentação dos casos de teste;
- Manual do usuário;
- Evidências de execução;
- Considerações finais;
- Vídeo de apresentação do projeto.

## Integrantes

| **Integrante** | **RA** |
|---|---|
| Eduardo Souza Machado França | 26011111-2 |
| Vitor Sakamoto | 26001770-2 |
| Anderson Pereira | 26006212-2 |

## Contexto acadêmico

**Instituição:** Universidade Cesumar – Unicesumar  
**Curso:** Análise e Desenvolvimento de Sistemas  
**Atividade:** Atividade de Estudo Programado (AEP)  
**Semestre:** 2º semestre de 2026  
**Caráter:** Projeto interdisciplinar envolvendo as disciplinas do semestre.

## Status do projeto

**Implementação e documentação da segunda entrega concluídas em desenvolvimento.**

O sistema possui suas funcionalidades principais implementadas e testadas, acompanhadas de documentação técnica e orientações para utilização.

O projeto atende ao escopo acadêmico proposto, utilizando conceitos fundamentais de programação estruturada e engenharia de software.

Como possibilidades de evolução futura, destacam-se a implementação de armazenamento permanente em arquivos ou banco de dados e o desenvolvimento de uma interface gráfica.
