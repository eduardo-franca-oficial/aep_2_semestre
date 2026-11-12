# Casos de Teste — PSE em Ação

## 1. Objetivo

Este documento apresenta os casos de teste utilizados para verificar o funcionamento do sistema PSE em Ação, desenvolvido em linguagem C.

Os testes têm como finalidade avaliar as funcionalidades implementadas, verificar a consistência dos dados durante a execução e identificar possíveis erros no processamento das informações.

## 2. Ambiente de testes

- **Sistema:** PSE em Ação
- **Linguagem:** C
- **Compilador:** GCC (MSYS2 UCRT64)
- **Editor:** Visual Studio Code
- **Execução:** Terminal do Windows
- **Armazenamento:** Memória durante a execução do programa

## 3. Critérios de avaliação

Cada caso de teste apresenta um procedimento e um resultado esperado.

O resultado real deverá ser preenchido após a execução do teste, utilizando uma das seguintes classificações:

- **Aprovado:** o sistema apresentou o comportamento esperado.
- **Reprovado:** o sistema apresentou um comportamento diferente do esperado.
- **Não executado:** o teste ainda não foi realizado.

## 4. Casos de teste

### 4.1 Cadastro de ações

| ID | Procedimento | Resultado esperado | Resultado real |
|---|---|---|---|
| CT01 | Cadastrar uma ação com todos os campos válidos. | A ação deve ser cadastrada com sucesso e receber status planejada. | A preencher |
| CT02 | Cadastrar uma ação utilizando um código já existente. | O sistema deve impedir o cadastro duplicado. | A preencher |
| CT03 | Informar um código igual a zero. | O sistema deve rejeitar o código. | A preencher |
| CT04 | Informar uma quantidade negativa de participantes planejados. | O sistema deve rejeitar o cadastro. | A preencher |
| CT05 | Deixar um campo obrigatório vazio. | O sistema deve solicitar novamente o preenchimento. | A preencher |
| CT06 | Informar letras em um campo que exige número inteiro. | O sistema deve informar que a entrada é inválida e solicitar novamente um número. | A preencher |
| CT07 | Informar uma data inexistente, como 31/02/2026. | O sistema deve rejeitar a data e solicitar outra. | A preencher |
| CT08 | Informar uma data válida, como 20/11/2026. | O sistema deve aceitar a data. | A preencher |

### 4.2 Listagem de ações

| ID | Procedimento | Resultado esperado | Resultado real |
|---|---|---|---|
| CT09 | Selecionar a opção de listagem sem possuir ações cadastradas. | O sistema deve informar que não existem ações cadastradas. | A preencher |
| CT10 | Cadastrar duas ou mais ações e selecionar a listagem. | O sistema deve apresentar todos os registros e seus respectivos dados. | A preencher |

### 4.3 Pesquisa de ações

| ID | Procedimento | Resultado esperado | Resultado real |
|---|---|---|---|
| CT11 | Pesquisar uma ação utilizando um código existente. | O sistema deve localizar e apresentar a ação correspondente. | A preencher |
| CT12 | Pesquisar utilizando um código inexistente. | O sistema deve informar que nenhuma ação foi encontrada. | A preencher |
| CT13 | Pesquisar uma ação pelo nome completo da escola. | O sistema deve apresentar as ações correspondentes. | A preencher |
| CT14 | Pesquisar utilizando apenas parte do nome da escola. | O sistema deve localizar as correspondências. | A preencher |
| CT15 | Pesquisar utilizando parte do tema da ação. | O sistema deve apresentar as ações correspondentes. | A preencher |
| CT16 | Selecionar uma opção de pesquisa inválida. | O sistema deve informar que a opção é inválida. | A preencher |

### 4.4 Atualização de status

| ID | Procedimento | Resultado esperado | Resultado real |
|---|---|---|---|
| CT17 | Atualizar uma ação planejada para realizada. | O sistema deve solicitar a quantidade real de participantes e atualizar o status. | A preencher |
| CT18 | Informar uma quantidade real negativa durante a atualização. | O sistema deve rejeitar o valor e solicitar novamente. | A preencher |
| CT19 | Atualizar uma ação planejada para cancelada. | O sistema deve atualizar o status para cancelada. | A preencher |
| CT20 | Informar um código inexistente durante a atualização. | O sistema deve informar que a ação não foi encontrada. | A preencher |
| CT21 | Informar um status inexistente. | O sistema deve rejeitar a alteração. | A preencher |
| CT22 | Tentar marcar diretamente uma ação cancelada como realizada. | O sistema deve impedir a operação. | A preencher |

### 4.5 Resumo geral

| ID | Procedimento | Resultado esperado | Resultado real |
|---|---|---|---|
| CT23 | Gerar o resumo sem possuir ações cadastradas. | O sistema deve informar que não existem ações cadastradas. | A preencher |
| CT24 | Gerar o resumo com ações em diferentes status. | O sistema deve apresentar corretamente a quantidade de ações por status. | A preencher |
| CT25 | Gerar o resumo com ações realizadas e diferentes quantidades de participantes. | O sistema deve somar os participantes e calcular corretamente o percentual de participação. | A preencher |

## 5. Dados utilizados nos testes de resumo

Para verificar os cálculos do sistema, recomenda-se utilizar os seguintes registros fictícios:

| Código | Participantes planejados | Participantes reais | Status |
|---|---:|---:|---|
| 101 | 50 | 45 | Realizada |
| 102 | 40 | 36 | Realizada |
| 103 | 30 | 0 | Planejada |
| 104 | 20 | 0 | Cancelada |

**Resultado esperado:**

- Total de ações: 4.
- Ações planejadas: 1.
- Ações realizadas: 2.
- Ações canceladas: 1.
- Participantes planejados nas ações realizadas: 90.
- Participantes reais: 81.
- Percentual de participação: 90%.

O percentual é calculado considerando somente as ações com status realizada.

## 6. Considerações sobre os testes

Os casos de teste foram definidos com base nas funcionalidades e validações implementadas no sistema PSE em Ação.

A execução desses procedimentos permite verificar o comportamento do programa em situações comuns e em condições de entrada inválida, contribuindo para a identificação de falhas e a avaliação da confiabilidade da aplicação.

Os resultados reais deverão ser registrados após a execução dos testes no ambiente de desenvolvimento.

**Observação:** os dados utilizados são fictícios e representam ações coletivas, sem identificação individual de estudantes ou informações clínicas pessoais.
