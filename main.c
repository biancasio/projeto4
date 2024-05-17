#include <stdio.h>
#include "clientes.h"

int main() {
    funcao funcoes[] = {NULL, criar, deletar, listar, debitar, depositar, extrato, transferir}; // Ajustando o mapeamento
    Banco clientes[LIMITE_CLIENTES];
    int pos = 0; // Inicializando a posição dos clientes
    int opcao;

    ERRO erro = carregar(clientes, &pos);
    if (erro == ABRIR) {
        printf("Erro ao carregar o arquivo para abrir.\n");
        pos = 0;
    } else if (erro == FECHAR) {
        printf("Erro ao carregar o arquivo para fechar.\n");
        pos = 0;
    } else if (erro == LER) {
        printf("Erro ao carregar o arquivo para ler.\n");
        pos = 0;
    }

    do {
        printf("\nMenu principal\n");
        printf("1) Novo Cliente\n");
        printf("2) Deletar Cliente\n");
        printf("3) Listar Cliente\n");
        printf("4) Débito\n");
        printf("5) Depósito\n");
        printf("6) Extrato\n");
        printf("7) Transferência entre contas\n");
        printf("0) Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) { // Adicionando verificação de entrada
            printf("Entrada inválida! Por favor, insira um número.\n");
            clearBuffer(); // Limpar buffer para evitar loops infinitos
            continue;
        }

        if (opcao >= 0 && opcao <= 7) {
            if (funcoes[opcao] != NULL) {
                erro = funcoes[opcao](clientes, &pos);
                if (erro == MAX_CLIENTES) {
                    printf("Máximo de clientes alcançados.\n");
                } else if (erro == SEM_CLIENTES) {
                    printf("Sem clientes cadastrados.\n");
                } else if (erro == CLIENTES_NAO_ENCONTRADO) {
                    printf("Cliente não encontrado.\n");
                } else if (erro == ABRIR) {
                    printf("Erro ao abrir o arquivo.\n");
                } else if (erro == FECHAR) {
                    printf("Erro ao fechar o arquivo.\n");
                } else if (erro == LER) {
                    printf("Erro ao ler o arquivo.\n");
                } else if (erro == ESCREVER) {
                    printf("Erro ao escrever no arquivo.\n");
                }
            }
        } else {
            printf("Opção inválida\n");
            clearBuffer(); // Limpar buffer se a entrada for inválida
        }
    } while (opcao != 0);

    erro = salvar(clientes, &pos);
    if (erro == ABRIR) {
        printf("Erro ao abrir o arquivo para salvar.\n");
    } else if (erro == FECHAR) {
        printf("Erro ao fechar o arquivo após salvar.\n");
    }
    

    return 0;
}
