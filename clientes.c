#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include <string.h> // Importa a biblioteca string.h para que possamos utilizar as funções de manipulação de strings
#include "clientes.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele

ERRO adicionar(Banco clientes[], int *pos){ // Função de adicionar cliente, recebe um array de contatos e um ponteiro para a posição atual dos clientes
  if(*pos >= LIMITE_CLIENTES) // Verificando erro de limite de contatos atingido
    return MAX_CLIENTES; // Retornando código de ultrapassou do limite de contatos

  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
  printf("\nDigite Seu Nome: "); // Pedindo para o usuário nos informar o nome do contato
  fgets(clientes[*pos].nome, 20, stdin); // Lendo o nome digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o CPF: "); // Pedindo para o usuário nos informar o sobrenome do contato
  scanf("%ld", &clientes[*pos].cpf); // Lendo o telefone digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o tipo de conta: "); // Pedindo para o usuário nos informar o email do contato
  fgets(clientes[*pos].conta, 100, stdin); // Lendo o email digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o Valor Inicial: "); // Pedindo para o usuário nos informar o telefone do contato
  scanf("%ld", &clientes[*pos].telefone); // Lendo o telefone digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite a Senha: "); // Pedindo para o usuário nos informar o telefone do contato
  scanf("%ld", &clientes[*pos].senha); // Lendo o telefone digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  *pos = *pos + 1; // Incrementando a posição para o próximo contato

  return OK; // Retornando código de sucesso na execução
} // Fechando função de adicionar contato