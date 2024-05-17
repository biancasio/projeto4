// Definindo uma "variável" global e constante para a quantidade máxima de contatos que podem ser armazenados na agenda
#define LIMITE_CLIENTES 1000

typedef struct { // Definindo uma estrutura para armazenar as informações dentro de cada contato
    char nome[100]; // Declarando variável do tipo string com 20 caracteres para armazenar o nome do cliente
    long int cpf; // Declarando variável do tipo inteiro longo para armazenar o cpf
    char conta[5]; // Declarando variável do tipo string com 5 caracteres para armazenar o tipo de conta
    long int valor; // Declarando variável do tipo inteiro longo para armazenar o valor da conta
    long int senha; // Declarando variável do tipo inteiro longo para armazenar a senha 
} Banco; // Definindo o nome da estrutura como Agenda

typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, CLIENTES_NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERRO;// Definindo uma enumeração de códigos de erro para ficar mais legível de identificar o que cada código significa

typedef ERRO (*funcao)(Banco[], int*); // Definindo um tipo de função que recebe um array de contatos e um ponteiro para a posição atual dos contatos, e retorna um código de erro

ERRO criar(Banco clientes[], int *pos); // Assinatura da função de adicionar contato
ERRO deletar(Banco clientes[], int *pos); // Assinatura da função de deletar contato
ERRO listar(Banco clientes[], int *pos); // Assinatura da função de listar contatos
ERRO debitar(Banco clientes[], int *pos); // Assinatura da função de debitar contato
ERRO extrato(Banco clientes[], int *pos); // Assinatura da função de debitar contato
ERRO depositar(Banco clientes[], int *pos); // Assinatura da função de depositar contato
ERRO transferir(Banco clientes[], int *pos); // Assinatura da função de transferir contato
ERRO salvar(Banco clientes[], int *pos); // Assinatura da função de salvar contatos
ERRO carregar(Banco clientes[], int *pos); // Assinatura da função de carregar contatos

void clearBuffer(); // Assinatura da função de limpar buffer