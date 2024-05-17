#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include <string.h> // Importa a biblioteca string.h para que possamos utilizar as funções de manipulação de strings
#include "clientes.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele


ERRO criar(Banco clientes[], int *pos) {
    if (*pos >= LIMITE_CLIENTES) { // Verificando erro de limite de clientes atingido
        return MAX_CLIENTES; // Retornando código de ultrapassou do limite de clientes
    }

    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("\nDigite Seu Nome: "); // Pedindo para o usuário nos informar o nome
    fgets(clientes[*pos].nome, 100, stdin); // Lendo o nome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o CPF: "); // Pedindo para o usuário nos informar seu cpf
    if (scanf("%ld", &clientes[*pos].cpf) != 1) {
        printf("Entrada inválida! Por favor, insira um número.\n");
        clearBuffer(); // Limpar buffer para evitar loops infinitos
        return CLIENTES_NAO_ENCONTRADO;
    }
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o tipo de conta: "); // Pedindo para o usuário nos informar o tipo de conta solicitado
    fgets(clientes[*pos].conta, 5, stdin); // Lendo a conta digitada pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o Valor Inicial: "); // Pedindo para o usuário nos informar o valor da conta
    if (scanf("%ld", &clientes[*pos].valor) != 1) {
        printf("Entrada inválida! Por favor, insira um número.\n");
        clearBuffer(); // Limpar buffer para evitar loops infinitos
        return CLIENTES_NAO_ENCONTRADO;
    }
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite a Senha: "); // Pedindo para o usuário nos informar a senha
    if (scanf("%ld", &clientes[*pos].senha) != 1) {
        printf("Entrada inválida! Por favor, insira um número.\n");
        clearBuffer(); // Limpar buffer para evitar loops infinitos
        return CLIENTES_NAO_ENCONTRADO;
    }
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    *pos = *pos + 1; // Incrementando a posição para o próximo contato

    printf("Cliente criado com sucesso.\n"); // Mensagem de sucesso

    return OK; // Retornando código de sucesso na execução
}

ERRO deletar(Banco clientes[], int *pos) {
    if (*pos == 0) {
        return SEM_CLIENTES;
    }

    long int cpf;
    printf("Digite o CPF do cliente a ser deletado: ");
    if (scanf("%ld", &cpf) != 1) {
        printf("Entrada inválida!\n");
        clearBuffer(); // Limpar buffer em caso de entrada inválida
        return CLIENTES_NAO_ENCONTRADO;
    }

    int encontrado = 0;
    for (int i = 0; i < *pos; i++) {
        if (clientes[i].cpf == cpf) {
            encontrado = 1;
            // Deslocar todos os elementos seguintes para a esquerda
            for (int j = i; j < *pos - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (*pos)--;
            printf("Cliente deletado com sucesso.\n"); // Mensagem de sucesso
            break;
        }
    }

    if (!encontrado) {
        return CLIENTES_NAO_ENCONTRADO;
    }

    return OK;
}
ERRO listar(Banco clientes[], int *pos){ // Função de listar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
  if(*pos == 0)  // Verificando erro de nenhum contato foi criado para ser possível listar
    return SEM_CLIENTES; // Retornando código de nenhum contato para listar

  for(int i=0; i<*pos; i++){ // Percorrendo o array de contatos para listar todos os contatos e cada uma de suas informações
    printf("\nPosição: %d\t", i+1); // Imprimindo a posição do contato
    printf("Nome: %s\t", clientes[i].nome); // Imprimindo o nome do contato
    printf("CPF: %ld\n", clientes[i].cpf); // Imprimindo o cpf do cliente
    printf("Tipo de Conta: %s\t", clientes[i].conta); // Imprimindo o tipo de conta do cliente
    printf("Valor Inicial: %ld\n", clientes[i].valor); // Imprimindo o valor da conta
  }  // Fechando for para listar contatos

  return OK; // Retornando código de sucesso na execução
} // Fechando função de listar contatos]


ERRO debitar(Banco clientes[], int *pos){ 
} // Fechando função de listar contatos

ERRO extrato(Banco clientes[], int *pos){ 
} // Fechando função de listar contatos

ERRO depositar(Banco clientes[], int *pos){ 
} // Fechando função de listar contatos

ERRO transferir(Banco clientes[], int *pos){ 
} // Fechando função de listar contatos

ERRO salvar(Banco clientes[], int *pos){ 
} // Fechando função de listar contatos

ERRO carregar(Banco clientes[], int *pos){ 
} // Fechando função de listar contatos

void clearBuffer(){ // Função de Limpar Buffer, para evitar o erro gerado ao tentar obter a entrada de informações do usuário
    int c;  // Declarando variável do tipo inteiro para armazenar o caractere lido do buffer
    while ((c = getchar()) != '\n' && c != EOF); // Loop para limpar o buffer do teclado, comparando o valor lido com o valor \n (New Line), e também comparando com o valor EOF (End Of File), para garantir que ele não continue tentando ler quando chegar ao final do arquivo
} // Fechando função de limpar buffer