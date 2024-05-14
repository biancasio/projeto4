#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include "clientes.h"

int main(){ // Função principal
  funcao funcoes[] = {criar, deletar, listar, debitar, depositar, transferir}; // Definindo um array de funções que serão utilizadas no programa

  Banco clientes[LIMITE_CLIENTES];  // Declarando um array de contatos (com limite de 255), onde cada contato possui uma estrutura com as informações de nome, sobrenome, email e telefone
  int pos; // Declarando variável do tipo inteiro para armazenar a posição dos contatos no array

  ERRO erro = funcoes[5](clientes, &pos); // funções que mostram os erros
    if (erro == ABRIR) {
        printf("Erro ao carregar o arquivo para abrir.\n"); //mensagem de erro
        pos = 0;
    } else if (erro == FECHAR) {
        printf("Erro ao carregar o arquivo para fechar.\n"); // mensagem de erro
        pos = 0;
    } else if (erro == LER) {
        printf("Erro ao carregar o arquivo para ler.\n"); // mensagem de erro
        pos = 0;
    }

    int opcao; // Declarando variável do tipo inteiro para a escolha da opção do menu
    do{ // Início do loop do menu de opções até que o usuário escolha a opção de sair
        printf("\nMenu principal\n"); // Imprimindo o menu de opções
        printf("1) Novo Cliente\n");// Imprimindo a primeira opção
        printf("2) Deletar cliente \n"); // Imprimindo a segunda opção
        printf("3) Listar cliente\n"); // Imprimindo a terceira opção
        printf("4) Débito\n"); // Imprimindo a quarta opção
        printf("5) Depósito\n"); // Imprimindo a quinta opção
        printf("6) Extrato\n"); // Imprimindo a sexta opção
        printf("7) Transferência entre contas\n"); // Imprimindo a setima opção
        printf("0) Sair\n"); // Imprimindo a última opção
        printf("Escolha uma opção: "); // Pedindo ao usuário para escolher uma opção
        scanf("%d", &opcao); // Lendo a opção escolhida pelo usuário

        opcao--; // Decrementando a opção para acessar o índice do array de funções
            if (opcao < -1 || opcao > 4) { // Verificando se a opção escolhida é válida
             printf("Opção inválida\n"); // Informando para o usuário que a opção escolhida é inválida
        } else if (opcao == 0) { 
            erro = funcoes[opcao](clientes, &pos); 
            if (erro == MAX_CLIENTES) {
              printf("Máximo de clientes alcançados\n"); // se a posição for igual a máxima de contatos mostra erro
            }
        } else if (opcao == 1) {
            erro = funcoes[opcao](clientes, &pos);
            if (erro == SEM_CLIENTES) { // se não possuir contatos para deletar mostrar 
                printf("Sem clientes para deletar\n"); // mensagem de erro
            } else if (erro == CLIENTES_NAO_ENCONTRADO) { // se o contato não for encontrado
                printf("cliente não existe\n"); // mensagem de erro
            }
        } else if (opcao == 2) { // se a opção for igual a 2
            erro = funcoes[opcao](clientes, &pos); // mostrar erro
            if (erro == CLIENTES_NAO_ENCONTRADO) {
                printf("Sem clientes para listar\n"); // mensagem de erro
            }
        } else if (opcao == 3 || opcao == 4) {
            funcoes[opcao](clientes, &pos);
        } else {
            printf("Sair...\n"); // Informando ao usuário que o programa foi encerrado
        }
    } while (opcao != -1); // Condição para que o loop continue até que o usuário escolha a opção de sair, quando isso acontecer o loop se encerra

    erro = funcoes[3](clientes, &pos);
    if (erro == ABRIR) { // erros possiveis do arquivo binário
        printf("Erro para abrir o arquivo ao salvar\n"); // mensagem de erro do arquivo
    } else if (erro == FECHAR) {
        printf("Erro para fechar o arquivo ao salvar\n"); // mensagem de erro do arquivo
    } else if (erro == ESCREVER) {
        printf("Erro ao escrever no arquivo ao salvar\n"); // mensagem de erro do arquivo
    }

    return 0;
}