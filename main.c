#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados


int main(){ // Função principal


 int opcao; // Declarando variável do tipo inteiro para a escolha da opção do menu
    do{ // Início do loop do menu de opções até que o usuário escolha a opção de sair
        printf("\nMenu principal\n"); // Imprimindo o menu de opções
        printf("1) Novo Cliente\n"); // Imprimindo a primeira opção
        printf("2) Deletar Cliente\n"); // Imprimindo a segunda opção
        printf("3) Listar Cliente\n"); // Imprimindo a terceira opção
        printf("4) Débito\n"); // Imprimindo a quarta opção
        printf("5) Depósito\n"); // Imprimindo a quinta opção
        printf("6) Extrato\n"); // Imprimindo a sexta opção
        printf("7) Transferência entre contas\n"); // Imprimindo a sétima opção
        printf("0) Sair\n"); // Imprimindo a última opção
        printf("Escolha uma opção: "); // Pedindo ao usuário para escolher uma opção
        scanf("%d", &opcao); // Lendo a opção escolhida pelo usuário

        opcao--; // Decrementando a opção para acessar o índice do array de funções
            if(opcao > 5) // Verificando se a opção escolhida é válida
                printf("Opção inválida\n"); // Informando para o usuário que a opção escolhida é inválida
            else // Caso nenhuma das condições anteriores sejam verdadeiras, a opção escolhida é sair, portanto o programa se encerrará
                printf("Sair...\n"); // Informando ao usuário que o programa foi encerrado

    } while(opcao >= 0); // Condição para que o loop continue até que o usuário escolha a opção de sair, quando isso acontecer o loop se encerra
}