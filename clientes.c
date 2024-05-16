#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include <string.h> // Importa a biblioteca string.h para que possamos utilizar as funções de manipulação de strings
#include "clientes.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele

ERRO criar(Banco clientes[], int *pos){ // Função de adicionar um novo cliente, recebe um array de contatos e um ponteiro para a posição atual dos clientes
  if(*pos >= LIMITE_CLIENTES) // Verificando erro de limite de clientes atingido
    return MAX_CLIENTES; // Retornando código de ultrapassou do limite de clientes

  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
  printf("\nDigite Seu Nome: "); // Pedindo para o usuário nos informar o nome
  fgets(clientes[*pos].nome, 100, stdin); // Lendo o nome digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o CPF: "); // Pedindo para o usuário nos informar seu cpf
  scanf("%ld", &clientes[*pos].cpf); // Lendo o cpf digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Tipo de Conta:\n");
  printf("Digite 1 para Conta Comum\n");
  printf("Digite 2 para Conta Plus\n"); // Pedindo para o usuário nos informar o tipo de conta solicitado
  scanf("%d", &clientes[*pos].conta); // Lendo a conta digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o Valor Inicial: "); // Pedindo para o usuário nos informar o valor da conta
  scanf("%f", &clientes[*pos].valor); // Lendo o valor digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite a Senha: "); // Pedindo para o usuário nos informar a senha
  fgets(clientes[*pos].senha, 20, stdin); // Lendo o telefone digitado pelo usuário
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
    if(clientes[i].conta == 1) // Verificando se o tipo de conta é comum
    {
      printf("Tipo de Conta: Comum\t"); // Imprimindo o tipo de conta do cliente
    }
    else if(clientes[i].conta == 2) // Verificando se o tipo de conta é plus
    {
      printf("Tipo de Conta: Plus\t"); // Imprimindo o tipo de conta do cliente
    }
    printf("Valor Inicial: %f\n", clientes[i].valor); // Imprimindo o valor da conta
  }  // Fechando for para listar contatos

  return OK; // Retornando código de sucesso na execução
} // Fechando função de listar contatos]

ERRO deletar(Banco clientes[], int *pos){ 
} // Fechando função de listar contatos

ERRO debitar(Banco clientes[], int *pos){ 
  int cpf_debito; // Declarando variavel para armazenar o cpf do cliente que deseja debitar
  char senha_debito[10]; // Declarando variavel para armazenar a senha do cliente que deseja debitar
  float valor_debito; // Declarando variavel para armazenar o valor que deseja debitar
  float taxa; // Declarando variavel para armazenar a taxa de debito
  float limite; // Declarando variavel para armazenar o limite de debito
  int cpf_existe = 0; // Declarando variavel para verificar se o cpf existe

  clearBuffer(); // Limpando o Buffer do teclado
  printf("CPF: "); // Pedindo para o usuário nos informar o cpf
  scanf("%d", &cpf_debito); // Lendo o cpf digitado pelo usuário
  clearBuffer(); // Limpando o Buffer do teclado

  printf("Senha: "); // Pedindo para o usuário nos informar a senha
  fgets(senha_debito, 10, stdin); // Lendo a senha digitada pelo usuário
  clearBuffer(); // Limpando o Buffer do teclado

  printf("Valor a ser debitado: "); // Pedindo para o usuário nos informar o valor a ser debitado
  scanf("%f", &valor_debito); // Lendo o valor digitado pelo usuário
  clearBuffer(); // Limpando o Buffer do teclado

  for (int i = 0; i < *pos; i++) { // Loop para percorrer todos os clientes
      if (strcmp(senha_debito, clientes[i].senha) == 0 && cpf_debito == clientes[i].cpf) // Verificando se a senha e o cpf são válidos
      { 
          cpf_existe = 1; // Atualizando a variável cpf_existe para indicar que o cpf existe

          if(clientes[i].conta == 1) // Verificando se a conta é comum
          {
              taxa = 0.05; // Atualizando a variável taxa para o valor de 5%
              limite = -1000.00; // Atualizando a variável limite para o valor de -1000.00
          }
          else if(clientes[i].conta == 2) // Verificando se a conta é plus
          {
              taxa = 0.03; // Atualizando a variável taxa para o valor de 3% 
              limite = -5000.00; // Atualizando a variável limite para o valor de -5000.00
          }
          else {
              printf("Tipo de conta inválido"); // Exibindo mensagem de erro para o usuário
          }

          if(clientes[i].valor - valor_debito >= limite) // Verificando se o saldo é suficiente para realizar o débito
          {
              clientes[i].valor -= (valor_debito * taxa) + valor_debito; // Atualizando o saldo do cliente com o valor debitado e a taxa de debito
              printf("Débito realizado com sucesso!\n"); // Exibindo mensagem de sucesso para o usuário

          }
          else { // Caso o saldo não seja suficiente para realizar o débito
              printf("Saldo insuficiente para o débito.\n"); // Exibindo mensagem de erro para o usuário
          }
        }
      }
        
  if (cpf_existe != 1) // Verificando se o cpf existe
  { // Caso o cpf não exista
      printf("Senha ou CPF incorreto\n"); // Exibindo mensagem de erro para o usuário
      return CPF_OU_SENHA_INCORRETO; // Retornando código de erro
  } 

  return OK; // Retornando código de sucesso
} // Fechando função de debito

ERRO extrato(Banco clientes[], int *pos){ 
} // Fechando função de extrato

ERRO depositar(Banco clientes[], int *pos){ 
  int cpf_deposito; // Declarando variavel para armazenar o cpf do cliente que deseja depositar
  float valor_deposito; // Declarando variavel para armazenar o valor que deseja depositar
  int cpf_existe = 0; // Declarando variavel para verificar se o cpf existe

  clearBuffer(); // Limpando o Buffer do teclado
  printf("CPF: "); // Pedindo para o usuário nos informar o cpf
  scanf("%d", &cpf_deposito); // Lendo o cpf digitado pelo usuário
  clearBuffer(); // Limpando o Buffer do teclado

  printf("Valor a ser depositado: "); // Pedindo para o usuário nos informar o valor a ser depositado
  scanf("%f", &valor_deposito); // Lendo o valor digitado pelo usuário
  clearBuffer(); // Limpando o Buffer do teclado

  for (int i = 0; i < *pos; i++) { // Loop para percorrer todos os clientes
      if (cpf_deposito == clientes[i].cpf) // Verificando se a senha e o cpf são válidos
      {
          cpf_existe = 1; // Atualizando a variável cpf_existe para indicar que o cpf existe
          clientes[i].valor += valor_deposito; // Atualizando o saldo do cliente com o valor depositado
          printf("Depósito realizado com sucesso!\n"); // Exibindo mensagem de sucesso para o usuário
      }
  }

  if (cpf_existe != 1) // Verificando se o cpf existe
  {
      printf("CPF incorreto\n"); // Exibindo mensagem de erro para o usuário
      return CPF_OU_SENHA_INCORRETO; // Retornando código de erro
  }

  return OK; // Retornando código de sucesso
  
} // Fechando função de depositar

ERRO transferir(Banco clientes[], int *pos){ 
  int cpf_origem; // Declarando variavel para armazenar o cpf do cliente que deseja transferir
  char senha_origem[20]; // Declarando variavel para armazenar a senha do cliente que deseja transferir
  int cpf_destino; // Declarando variavel para armazenar o cpf do cliente que receberá a transferência
  float valor_transferencia; // Declarando variavel para armazenar o valor a ser transferido
  float taxa; // Declarando variavel para armazenar a taxa de transferência
  float limite; // Declarando variavel para armazenar o limite de transferência
  int cpf_existe = 0; // Declarando variavel para verificar se o cpf existe

  clearBuffer(); // Limpando o Buffer do teclado
  printf("Digite o CPF da conta de origem: "); // Pedindo para o usuário nos informar o cpf da conta de origem
  scanf("%d", &cpf_origem); // Lendo o cpf da conta de origem digitado pelo usuário
  clearBuffer(); // Limpando o Buffer do teclado

  printf("Digite a senha da conta de origem: "); // Pedindo para o usuário nos informar a senha da conta de origem
  fgets(senha_origem, 20, stdin); // Lendo a senha da conta de origem digitada pelo usuário

  clearBuffer(); // Limpando o Buffer do teclado 
  printf("Digite o CPF da conta de destino: "); // Pedindo para o usuário nos informar o cpf da conta de destino
  scanf("%d", &cpf_destino); // Lendo o cpf da conta de destino digitado pelo usuário
  clearBuffer(); // Limpando o Buffer do teclado

  printf("Digite o valor a ser transferido: "); // Pedindo para o usuário nos informar o valor a ser transferido
  scanf("%f", &valor_transferencia); // Lendo o valor a ser transferido digitado pelo usuário
  clearBuffer(); // Limpando o Buffer do teclado

  for (int i = 0; i < *pos; i++) { // Loop para percorrer todos os clientes
      if (strcmp(senha_origem, clientes[i].senha) == 0 && cpf_origem == clientes[i].cpf) // Verificando se a senha e o cpf de origem são válidos
      {
          cpf_existe += 1; // Atualizando a variável cpf_existe para indicar que o cpf de origem existe

          if(clientes[i].conta == 1) // Verificando se a conta é comum
          {
              taxa = 0.05; // Atualizando a variável taxa para o valor de 5%
              limite = -1000.00; // Atualizando a variável limite para o valor de -1000.00
          }
          else if(clientes[i].conta == 2) // Verificando se a conta é plus
          {
              taxa = 0.03; // Atualizando a variável taxa para o valor de 3%
              limite = -5000.00; // Atualizando a variável limite para o valor de -5000.00
          }
          else { // Caso o tipo de conta não seja comum ou plus
              printf("Tipo de conta inválido"); // Exibindo mensagem de erro para o usuário
          }

          for (int j = 0; j < *pos; j++) // Loop para percorrer todos os clientes
          { 
              if (cpf_destino == clientes[j].cpf) // Verificando se o cpf de destino é válido
              {
                  cpf_existe += 1; // Atualizando a variável cpf_existe para indicar que o cpf de destino existe

                  if(clientes[i].valor - valor_transferencia >= limite) // Verificando se o saldo é suficiente para realizar o débito
                  {
                      clientes[i].valor -= (valor_transferencia * taxa) + valor_transferencia; // Atualizando o saldo do cliente com o valor debitado e a taxa de debito
                      clientes[j].valor += valor_transferencia; // Atualizando o saldo do cliente com o valor depositado
                      printf("Transferência realizada com sucesso!\n"); // Exibindo mensagem de sucesso para o usuário
                  } else { // Caso o saldo não seja suficiente para realizar o débito
                      printf("Saldo insuficiente para o débito.\n"); // Exibindo mensagem de erro para o usuário
                  }

              } 
          }
      } 
  }

  if (cpf_existe != 2) // Verificando se o cpf de origem e de destino existem
  {
      printf("Senha ou CPF incorreto\n"); // Exibindo mensagem de erro para o usuário
      return CPF_OU_SENHA_INCORRETO; // Retornando código de erro
  }

  return OK; // Retornando código de sucesso
  
} // Fechando função de transferir

ERRO salvar(Banco clientes[], int *pos){ 
} // Fechando função de salvar

ERRO carregar(Banco clientes[], int *pos){ 
} // Fechando função de carregar

void clearBuffer(){ // Função de Limpar Buffer, para evitar o erro gerado ao tentar obter a entrada de informações do usuário
    int c;  // Declarando variável do tipo inteiro para armazenar o caractere lido do buffer
    while ((c = getchar()) != '\n' && c != EOF); // Loop para limpar o buffer do teclado, comparando o valor lido com o valor \n (New Line), e também comparando com o valor EOF (End Of File), para garantir que ele não continue tentando ler quando chegar ao final do arquivo
} // Fechando função de limpar buffer