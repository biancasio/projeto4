#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include <string.h> // Importa a biblioteca string.h para que possamos utilizar as funções de manipulação de strings
#include "clientes.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele

ERRO criar(Banco clientes[], int *pos){ // Função de adicionar cliente, recebe um array de contatos e um ponteiro para a posição atual dos clientes
  if(*pos >= LIMITE_CLIENTES) // Verificando erro de limite de clientes atingido
    return MAX_CLIENTES; // Retornando código de ultrapassou do limite de clientes

  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
  printf("\nDigite Seu Nome: "); // Pedindo para o usuário nos informar o nome
  fgets(clientes[*pos].nome, 100, stdin); // Lendo o nome digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o CPF: "); // Pedindo para o usuário nos informar seu cpf
  scanf("%ld", &clientes[*pos].cpf); // Lendo o cpf digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o tipo de conta: "); // Pedindo para o usuário nos informar o tipo de conta solicitado
  fgets(clientes[*pos].conta, 5, stdin); // Lendo a conta digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o Valor Inicial: "); // Pedindo para o usuário nos informar o valor da conta
  scanf("%ld", &clientes[*pos].valor); // Lendo o valor digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite a Senha: "); // Pedindo para o usuário nos informar a senha
  scanf("%ld", &clientes[*pos].senha); // Lendo o telefone digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  *pos = *pos + 1; // Incrementando a posição para o próximo contato

  return OK; // Retornando código de sucesso na execução
} // Fechando função de adicionar contato

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

ERRO deletar(Banco clientes[], int *pos){ 
} // Fechando função de listar contatos

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