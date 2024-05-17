// Definindo uma "variável" global e constante para a quantidade máxima de clientes que podem ser armazenados no banco
#define LIMITE_CLIENTES 1000

typedef struct { // Definindo uma estrutura para armazenar as informações dentro de cada cliente
    char nome[100]; // Declarando variável do tipo string com 100 caracteres para armazenar o nome do cliente
    long int cpf; // Declarando variável do tipo inteiro longo para armazenar o cpf
    int conta; // Declarando variável do tipo inteiro para armazenar o tipo de conta
    float valor; // Declarando variável do tipo float para armazenar o valor da conta
    char senha[20]; // Declarando variável do tipo string com 20 caracteres para armazenar a senha 
} Banco; // Definindo o nome da estrutura como Banco

typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, CLIENTES_NAO_ENCONTRADO, CPF_OU_SENHA_INCORRETO, ABRIR, FECHAR, ESCREVER, LER} ERRO;// Definindo uma enumeração de códigos de erro para ficar mais legível de identificar o que cada código significa

typedef ERRO (*funcao)(Banco[], int*); // Definindo um tipo de função que recebe um array de clientes e um ponteiro para a posição atual dos clientes, e retorna um código de erro

ERRO criar(Banco clientes[], int *pos); // Assinatura da função de criar um novo cliente
ERRO deletar(Banco clientes[], int *pos); // Assinatura da função de deletar cliente
ERRO listar(Banco clientes[], int *pos); // Assinatura da função de listar clientes
ERRO debitar(Banco clientes[], int *pos); // Assinatura da função de debitar
ERRO extrato(Banco clientes[], int *pos); // Assinatura da função de extrato
ERRO depositar(Banco clientes[], int *pos); // Assinatura da função de depositar 
ERRO transferir(Banco clientes[], int *pos); // Assinatura da função de transferir
ERRO salvar(Banco clientes[], int *pos); // Assinatura da função de salvar clientes
ERRO carregar(Banco clientes[], int *pos); // Assinatura da função de carregar clientes

void clearBuffer(); // Assinatura da função de limpar buffer