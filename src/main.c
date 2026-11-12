#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ACOES 100
#define PLANEJADA 1
#define REALIZADA 2
#define CANCELADA 3

typedef struct {
    int codigo;
    char escola[100];
    char tema[100];
    char data[11];
    char publicoAlvo[100];
    char responsavel[100];
    int participantesPlanejados;
    int participantesReais;
    int status;
} Acao;

Acao acoes[MAX_ACOES];
int quantidadeAcoes = 0;


int dataValida(char data[]) {
    int dia, mes, ano;
    int diasNoMes;

    if (strlen(data) != 10) {
        return 0;
    }

    if (data[2] != '/' || data[5] != '/') {
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit((unsigned char)data[i])) {
            return 0;
        }
    }

    dia = (data[0] - '0') * 10 + (data[1] - '0');
    mes = (data[3] - '0') * 10 + (data[4] - '0');

    ano = (data[6] - '0') * 1000 +
          (data[7] - '0') * 100 +
          (data[8] - '0') * 10 +
          (data[9] - '0');

    if (ano < 1 || mes < 1 || mes > 12) {
        return 0;
    }

    switch (mes) {
        case 2:
            diasNoMes = 28;

            if ((ano % 400 == 0) ||
                (ano % 4 == 0 && ano % 100 != 0)) {
                diasNoMes = 29;
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            diasNoMes = 30;
            break;

        default:
            diasNoMes = 31;
    }

    if (dia < 1 || dia > diasNoMes) {
        return 0;
    }

    return 1;
}

void exibirMenu();
void cadastrarAcao();
void listarAcoes();
void pesquisarAcao();
void atualizarStatus();
void gerarResumo();


void lerTexto(char mensagem[], char destino[], int tamanho);
int lerInteiro(char mensagem[]);
int codigoExiste(int codigo);


int contemTexto(char texto[], char busca[]) {
    char textoMinusculo[100];
    char buscaMinuscula[100];
    int i;

    for (i = 0; texto[i] != '\0' && i < 99; i++) {
        textoMinusculo[i] = tolower((unsigned char)texto[i]);
    }
    textoMinusculo[i] = '\0';

    for (i = 0; busca[i] != '\0' && i < 99; i++) {
        buscaMinuscula[i] = tolower((unsigned char)busca[i]);
    }
    buscaMinuscula[i] = '\0';

    return strstr(textoMinusculo, buscaMinuscula) != NULL;
}


int main() {
    int opcao = 0;

    do {
        exibirMenu();
        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                cadastrarAcao();
                break;

            case 2:
                listarAcoes();
                break;

            case 3:
                pesquisarAcao();
                break;

            case 4:
                atualizarStatus();
                break;

            case 5:
                gerarResumo();
                break;

            case 6:
                printf("\nEncerrando o PSE em Acao...\n");
                break;

            default:
                printf("\nOpcao invalida! Escolha entre 1 e 6.\n");
        }

    } while (opcao != 6);

    return 0;
}

void exibirMenu() {
    printf("\n====================================\n");
    printf("             PSE EM ACAO\n");
    printf("====================================\n");
    printf("1 - Cadastrar acao\n");
    printf("2 - Listar acoes\n");
    printf("3 - Pesquisar acao\n");
    printf("4 - Atualizar status\n");
    printf("5 - Gerar resumo geral\n");
    printf("6 - Sair\n");
    printf("====================================\n");
}

void lerTexto(char mensagem[], char destino[], int tamanho) {
    do {
        printf("%s", mensagem);

        if (fgets(destino, tamanho, stdin) == NULL) {
            destino[0] = '\0';
            continue;
        }

        destino[strcspn(destino, "\n")] = '\0';

        if (strlen(destino) == 0) {
            printf("Este campo e obrigatorio!\n");
        }

    } while (strlen(destino) == 0);
}

int lerInteiro(char mensagem[]) {
    char entrada[100];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            continue;
        }

        valor = strtol(entrada, &fim, 10);

        if (fim == entrada || (*fim != '\n' && *fim != '\0')) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
            continue;
        }

        return (int)valor;
    }
}

int codigoExiste(int codigo) {
    int i;

    for (i = 0; i < quantidadeAcoes; i++) {
        if (acoes[i].codigo == codigo) {
            return 1;
        }
    }

    return 0;
}

void cadastrarAcao() {
    Acao novaAcao;

    printf("\n========== CADASTRO DE ACAO ==========\n");

    if (quantidadeAcoes >= MAX_ACOES) {
        printf("Limite de acoes cadastradas atingido!\n");
        return;
    }

    novaAcao.codigo = lerInteiro("Codigo da acao: ");

    if (novaAcao.codigo <= 0) {
        printf("O codigo deve ser maior que zero!\n");
        return;
    }

    if (codigoExiste(novaAcao.codigo)) {
        printf("Ja existe uma acao com esse codigo!\n");
        return;
    }

    lerTexto("Nome da escola: ", novaAcao.escola, 100);
    lerTexto("Tema da acao: ", novaAcao.tema, 100);
    do {
    lerTexto("Data (DD/MM/AAAA): ", novaAcao.data, 11);

    if (!dataValida(novaAcao.data)) {
        printf("Data invalida! Utilize DD/MM/AAAA.\n");
    }

    } while (!dataValida(novaAcao.data));
    lerTexto("Publico-alvo: ", novaAcao.publicoAlvo, 100);
    lerTexto("Responsavel: ", novaAcao.responsavel, 100);

    novaAcao.participantesPlanejados =
        lerInteiro("Quantidade planejada de participantes: ");

    if (novaAcao.participantesPlanejados < 0) {
        printf("A quantidade nao pode ser negativa!\n");
        return;
    }

    novaAcao.participantesReais = 0;
    novaAcao.status = PLANEJADA;

    acoes[quantidadeAcoes] = novaAcao;
    quantidadeAcoes++;

    printf("\nAcao cadastrada com sucesso!\n");
    printf("Codigo: %d\n", novaAcao.codigo);
    printf("Status: Planejada\n");
}


void listarAcoes() {
    int i;

    printf("\n========== LISTAGEM DE ACOES ==========\n");

    if (quantidadeAcoes == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    for (i = 0; i < quantidadeAcoes; i++) {
        printf("\n--------------------------------------\n");

        printf("Codigo: %d\n", acoes[i].codigo);
        printf("Escola: %s\n", acoes[i].escola);
        printf("Tema: %s\n", acoes[i].tema);
        printf("Data: %s\n", acoes[i].data);
        printf("Publico-alvo: %s\n", acoes[i].publicoAlvo);
        printf("Responsavel: %s\n", acoes[i].responsavel);

        printf("Participantes planejados: %d\n",
               acoes[i].participantesPlanejados);

        printf("Participantes reais: %d\n",
               acoes[i].participantesReais);

        printf("Status: ");

        switch (acoes[i].status) {
            case PLANEJADA:
                printf("Planejada\n");
                break;

            case REALIZADA:
                printf("Realizada\n");
                break;

            case CANCELADA:
                printf("Cancelada\n");
                break;

            default:
                printf("Desconhecido\n");
        }
    }

    printf("\n======================================\n");
    printf("Total de acoes cadastradas: %d\n", quantidadeAcoes);
}



void pesquisarAcao() {
    int opcao;
    int codigo;
    int i;
    int encontrou = 0;
    char busca[100];

    printf("\n========== PESQUISAR ACAO ==========\n");
    printf("1 - Pesquisar por codigo\n");
    printf("2 - Pesquisar por escola\n");
    printf("3 - Pesquisar por tema\n");

    opcao = lerInteiro("Escolha o tipo de pesquisa: ");

    if (opcao < 1 || opcao > 3) {
        printf("Opcao de pesquisa invalida!\n");
        return;
    }

    if (opcao == 1) {
        codigo = lerInteiro("Digite o codigo da acao: ");

        for (i = 0; i < quantidadeAcoes; i++) {
            if (acoes[i].codigo == codigo) {
                encontrou = 1;

                printf("\nAcao encontrada!\n");
                printf("Codigo: %d\n", acoes[i].codigo);
                printf("Escola: %s\n", acoes[i].escola);
                printf("Tema: %s\n", acoes[i].tema);
                printf("Data: %s\n", acoes[i].data);
                printf("Publico-alvo: %s\n", acoes[i].publicoAlvo);
                printf("Responsavel: %s\n", acoes[i].responsavel);
                printf("Participantes planejados: %d\n",
                       acoes[i].participantesPlanejados);
                printf("Participantes reais: %d\n",
                       acoes[i].participantesReais);

                break;
            }
        }
    } 
    else {
        if (opcao == 2) {
            lerTexto("Digite o nome ou parte do nome da escola: ",
                     busca, 100);
        } else {
            lerTexto("Digite o tema ou parte do tema: ",
                     busca, 100);
        }

        for (i = 0; i < quantidadeAcoes; i++) {
            int corresponde = 0;

            if (opcao == 2) {
                corresponde = contemTexto(acoes[i].escola, busca);
            } else {
                corresponde = contemTexto(acoes[i].tema, busca);
            }

            if (corresponde) {
                encontrou = 1;

                printf("\n----------------------------------\n");
                printf("Codigo: %d\n", acoes[i].codigo);
                printf("Escola: %s\n", acoes[i].escola);
                printf("Tema: %s\n", acoes[i].tema);
                printf("Data: %s\n", acoes[i].data);
                printf("Publico-alvo: %s\n", acoes[i].publicoAlvo);
                printf("Responsavel: %s\n", acoes[i].responsavel);
                printf("Participantes planejados: %d\n",
                       acoes[i].participantesPlanejados);
                printf("Participantes reais: %d\n",
                       acoes[i].participantesReais);
            }
        }
    }

    if (!encontrou) {
        printf("\nNenhuma acao encontrada com os dados informados.\n");
    }

    printf("\n====================================\n");
}


void atualizarStatus() {
    int codigo;
    int novoStatus;
    int i;
    int encontrou = 0;
    int participantes;

    printf("\n========== ATUALIZAR STATUS ==========\n");

    if (quantidadeAcoes == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    codigo = lerInteiro("Digite o codigo da acao: ");

    for (i = 0; i < quantidadeAcoes; i++) {
        if (acoes[i].codigo == codigo) {
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("Acao nao encontrada!\n");
        return;
    }

    printf("\nAcao encontrada: %s\n", acoes[i].tema);

    printf("\nStatus atual: ");

    switch (acoes[i].status) {
        case PLANEJADA:
            printf("Planejada\n");
            break;

        case REALIZADA:
            printf("Realizada\n");
            break;

        case CANCELADA:
            printf("Cancelada\n");
            break;
    }

    printf("\nSelecione o novo status:\n");
    printf("1 - Planejada\n");
    printf("2 - Realizada\n");
    printf("3 - Cancelada\n");

    novoStatus = lerInteiro("Novo status: ");

    if (novoStatus < PLANEJADA || novoStatus > CANCELADA) {
        printf("Status invalido!\n");
        return;
    }

    if (novoStatus == REALIZADA) {
        if (acoes[i].status == CANCELADA) {
            printf("Nao e possivel concluir uma acao cancelada.\n");
            return;
        }

        while (1) {
            participantes = lerInteiro(
                "Quantidade real de participantes: "
            );

            if (participantes < 0) {
                printf("A quantidade nao pode ser negativa!\n");
                continue;
            }

            break;
        }

        acoes[i].participantesReais = participantes;
    }

    acoes[i].status = novoStatus;

    printf("\nStatus atualizado com sucesso!\n");

    printf("Novo status: ");

    switch (acoes[i].status) {
        case PLANEJADA:
            printf("Planejada\n");
            break;

        case REALIZADA:
            printf("Realizada\n");
            break;

        case CANCELADA:
            printf("Cancelada\n");
            break;
    }
}



void gerarResumo() {
    int i;

    int totalPlanejadas = 0;
    int totalRealizadas = 0;
    int totalCanceladas = 0;

    int participantesPlanejados = 0;
    int participantesReais = 0;

    double percentualParticipacao = 0.0;

    printf("\n========== RESUMO GERAL ==========\n");

    if (quantidadeAcoes == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    for (i = 0; i < quantidadeAcoes; i++) {

        switch (acoes[i].status) {

            case PLANEJADA:
                totalPlanejadas++;
                break;

            case REALIZADA:
                totalRealizadas++;

                participantesPlanejados +=
                    acoes[i].participantesPlanejados;

                participantesReais +=
                    acoes[i].participantesReais;

                break;

            case CANCELADA:
                totalCanceladas++;
                break;
        }
    }

    if (participantesPlanejados > 0) {
        percentualParticipacao =
            ((double)participantesReais /
             participantesPlanejados) * 100;
    }

    printf("\nQuantidade total de acoes: %d\n",
           quantidadeAcoes);

    printf("\n--- ACOES POR STATUS ---\n");

    printf("Planejadas: %d\n", totalPlanejadas);
    printf("Realizadas: %d\n", totalRealizadas);
    printf("Canceladas: %d\n", totalCanceladas);

    printf("\n--- PARTICIPACAO ---\n");

    printf("Participantes planejados: %d\n",
           participantesPlanejados);

    printf("Participantes reais: %d\n",
           participantesReais);

    if (participantesPlanejados > 0) {
        printf("Percentual de participacao: %.2f%%\n",
               percentualParticipacao);
    } else {
        printf("Percentual de participacao: Nao disponivel\n");
        printf("Nao existem participantes planejados nas acoes realizadas.\n");
    }

    printf("\n==================================\n");
}
