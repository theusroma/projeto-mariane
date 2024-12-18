#define NUM_FLORES 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h> //biblioteca para usar getch()
#include <ctype.h>


typedef struct {
    char nome[50];
    char cpf[12];
    char telefone[15];
    char rua[50];
    char numero[7];
    char bairro[50];
    char cep[10];
    int status; // 1 para ativo, 0 para desativado
} Cliente;

//Protótipos
void arte_funcoes();
int valida_cpf(char cpf[11]);
int validarCPF();
void cadastrarCliente();
void removerCPF();
void consulta();
void lista_ordenada();
int compararClientes(const void *a, const void *b);
void desativar();
//End Protótipos

//validar cpf
int valida_cpf(char cpf[11]) {
    int int_cpf[11], i, soma = 0, digito1, digito2, aux = 0;
    for (i = 0; i < 11; i++) {
        int_cpf[i] = cpf[i] - 48;  // Convertendo os caracteres para inteiros
    }
    
    // verifivca se os numeros do cpf sao iguais
    if (int_cpf[0] == int_cpf[1] && int_cpf[1] == int_cpf[2] && int_cpf[2] == int_cpf[3] && int_cpf[3] == int_cpf[4] &&
        int_cpf[4] == int_cpf[5] && int_cpf[5] == int_cpf[6] && int_cpf[6] == int_cpf[7] && int_cpf[7] == int_cpf[8] &&
        int_cpf[8] == int_cpf[9] && int_cpf[9] == int_cpf[10]) {
        return 0;  // retorna cpf invalido
    }

    // calculo do primeiro numero que verifica
    for (i = 0; i < 9; i++) {
        soma += int_cpf[i] * (10 - i);
    }
    aux = soma % 11;
    if (aux == 0 || aux == 1) {
        digito1 = 0;
    } else {
        digito1 = 11 - aux;
    }

    // calculo do segundo numero que verifica
    soma = 0;
    for (i = 0; i < 10; i++) {
        soma += int_cpf[i] * (11 - i);
    }
    aux = soma % 11;
    if (aux == 0 || aux == 1) {
        digito2 = 0;
    } else {
        digito2 = 11 - aux;
    }

    // testa se os 2 numeros verificadores estao certos
    if (int_cpf[9] == digito1 && int_cpf[10] == digito2) {
        return 1;  // cpf valido
    } else {
        return 0;  // cpf invalido
    }
}

// Função para verificar se o CPF tem exatamente 11 dígitos numéricos
int validarCPF(const char* cpf) {
    int i;
    if (strlen(cpf) != 11) {
        return 0; // CPF inválido se não tiver 11 caracteres
    }
    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0; // CPF inválido se algum caractere não for número
        }
    }
    return 1; // CPF válido
}

int compararClientes(const void *a, const void *b);

int compararCliente(const void *a, const void *b) {
    Cliente *clienteA = (Cliente *)a;
    Cliente *clienteB = (Cliente *)b;
    return strcmp(clienteA->nome, clienteB->nome);
}

// funcao q vai cadastar o cliente
void cadastrarCliente(){
	Cliente novocliente;
	
	arte_funcoes();
	
	getchar();
    // pedindo dados dos cliente ne zé
    printf("\n Digite o CPF do cliente: ");
    fgets(novocliente.cpf, sizeof(novocliente.cpf), stdin);
    novocliente.cpf[strcspn(novocliente.cpf, "\n")] = '\0';
    

    // validacao do cpf
    if (!valida_cpf(novocliente.cpf)) {
        printf("\n CPF inválido! Por favor, insira um CPF válido.\n");
        return;  // se o CPF for inválido, retorna da função sem salvar o cliente
    }
    getchar();
    printf("\n Digite o nome do cliente: ");
    fgets(novocliente.nome, sizeof(novocliente.nome), stdin);
    novocliente.nome[strcspn(novocliente.nome, "\n")] = '\0';

	// pede ao usuario telefone
	
    printf("\n Digite o telefone do cliente: ");
    fgets(novocliente.telefone, sizeof(novocliente.telefone), stdin);
    novocliente.telefone[strcspn(novocliente.telefone, "\n")] = '\0';

    // pede ao usuario nome da rua
    
    printf("\n Digite a rua do cliente: ");
    fgets(novocliente.rua, sizeof(novocliente.rua), stdin);
    novocliente.rua[strcspn(novocliente.rua, "\n")] = '\0';

	// pede ao usuario numero da casa
	
	printf("\n Digite o numero da casa: ");
	fgets(novocliente.numero, sizeof(novocliente.numero), stdin);
	novocliente.numero[strcspn(novocliente.numero, "\n")] = '\0';

	// pede ao usuario o nome do bairro
	
	printf("\n Digite o bairro do cliente: ");
	fgets(novocliente.bairro, sizeof(novocliente.bairro), stdin);
	novocliente.bairro[strcspn(novocliente.bairro, "\n")] = '\0';

	// pede ao usuario o numero do cep
	
    printf("\n Digite o CEP do cliente: ");
    fgets(novocliente.cep, sizeof(novocliente.cep), stdin);
    novocliente.cep[strcspn(novocliente.cep, "\n")] = '\0';
    
    novocliente.status = 1; //MUDA O STATUS por causa da desativação

	printf("\n------------------------------------------------------------------------------------------------------------------------");
    // exibe as informações já informadas pelo usuario e pergunta se os dados estao corretos
    
    printf("\n\t    Confirmação dos Dados    \n");
    printf("\n Nome: %s\n", novocliente.nome);
    printf("\n CPF: %s\n", novocliente.cpf);
    printf("\n Telefone: %s\n", novocliente.telefone);
    printf("\n Endereço: %s, %s - %s, CEP: %s\n", novocliente.rua, novocliente.numero, novocliente.bairro, novocliente.cep);
    printf("\n Os dados estão corretos? (s/n): ");

    char confirmacao;
    scanf("%c", &confirmacao);
    getchar(); 
    if (confirmacao == 's' || confirmacao == 'S') {
        // se o usuario digitar 's'	grava os dados no arqiuvo
        FILE *arquivo = fopen("clientes.txt", "a");
        if (arquivo == NULL) {
            printf("\n\tErro ao abrir o arquivo!\n");
            return;
        }

        // escrevendo os dados do usuario no arquivo
       fprintf(arquivo, "%s; %s; %s; %s; %s; %s; %s; %d;\n", 
        novocliente.nome, 
        novocliente.cpf, 
        novocliente.telefone, 
        novocliente.rua, 
        novocliente.numero, 
        novocliente.bairro, 
        novocliente.cep, 
        novocliente.status); // Inclui o status do cliente

        fclose(arquivo);
        printf("\n Cliente cadastrado com sucesso!\n");
    } else {
        // se o usuatio digitar n, o cadastro é cancelado
        printf("\n Cadastro cancelado. Nenhum dado foi salvo.\n");
    }
}
void removerCPF(){
	int verificacao;
    Cliente clienteLido;
    char cpfProcurado[12];  // CPF com tamanho fixo de 11 caracteres + '\0'
	
	arte_funcoes();
	
    // Abrindo arquivo para leitura
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo de clientes. Certifique-se de que o arquivo 'clientes.txt' existe.\n");
        return;
    }

    // Solicita o CPF do cliente a ser removido
    printf(" Digite o CPF do usuario que deseja excluir (apenas numeros, 11 digitos): ");
    scanf("%11s", cpfProcurado);

    // Validação do CPF
    if (!validarCPF(cpfProcurado)) {
        printf(" CPF invalido! Por favor, forneca um CPF valido com 11 digitos numericos.\n");
        fclose(arquivo);
        return;
    }

    int clienteEncontrado = 0;

    // Buscando o cliente pelo CPF
    while (fscanf(arquivo, "%49[^;]; %11s; %11s; %49[^;]; %6[^;]; %49[^;]; %9[^;]; %d;\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep, &clienteLido.status) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) == 0) {
            printf("\n   Cliente encontrado:\n");
            printf("\n Nome: %s", clienteLido.nome);
            printf("\n Telefone: %s", clienteLido.telefone);
            printf("\n Rua: %s", clienteLido.rua);
            printf("\n Numero: %s", clienteLido.numero);
            printf("\n Bairro: %s", clienteLido.bairro);
            printf("\n CEP: %s", clienteLido.cep);
            printf("\n Status: %d\n", clienteLido.status);
            clienteEncontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (clienteEncontrado != 1) {
        printf(" Cliente com CPF: %s nao encontrado.\n", cpfProcurado);
        return;
    }

    // Confirmação de exclusão
    printf("\n Tem certeza que deseja excluir esse cliente?\n Digite:\n [1] sim;\n [2] nao.\n");
    scanf("%d", &verificacao);

    if (verificacao == 2) {
        printf(" Exclusao cancelada.\n");
        return;
    }

    // Reabre o arquivo para leitura e prepara o arquivo temporário para escrita
    arquivo = fopen("clientes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf(" Erro ao abrir os arquivos para leitura e escrita.\n");
        if (arquivo != NULL) fclose(arquivo);
        if (temp != NULL) fclose(temp);
        return;
    }

    int clienteRemovido = 0;

    // Copia todos os clientes para o arquivo temporário, exceto o cliente a ser removido
    while (fscanf(arquivo, "%49[^;]; %11s; %11s; %49[^;]; %6[^;]; %49[^;]; %9[^;]; %d;\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep, &clienteLido.status) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) != 0) {
            fprintf(temp, "%s; %s; %s; %s; %s; %s; %s; %d;\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep, clienteLido.status);
        } else {
            clienteRemovido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Se o cliente foi removido, substitui o arquivo original pelo arquivo temporário
    if (clienteRemovido) {
        if (remove("clientes.txt") != 0) {
            printf(" Erro ao remover o arquivo original.\n");
            return;
        }
        if (rename("temp.txt", "clientes.txt") != 0) {
            printf(" Erro ao renomear o arquivo temporario.\n");
            return; 
        }
        printf(" Cliente com CPF: %s foi removido com sucesso.\n", cpfProcurado);
    } else {
        printf(" Erro ao remover o cliente. CPF nao encontrado.\n");
        remove("temp.txt");
    }
}


void consulta() {
	
	arte_funcoes();

    Cliente clienteLido;
    char cpfProcurado[12];  // CPF com tamanho fixo de 11 caracteres + '\0'

    // Abrindo arquivo para leitura
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo de clientes. Certifique-se de que o arquivo 'clientes.txt' existe.\n");
        return;
    }

    // Solicita o CPF do cliente a ser buscado
    printf(" Digite o CPF do usuario que deseja buscar(apenas numeros, 11 digitos): ");
    scanf("%11s", cpfProcurado);

    // Validação do CPF
    if (!validarCPF(cpfProcurado)) {
        printf(" CPF invalido! Por favor, forneca um CPF valido com 11 digitos numericos.\n");
        fclose(arquivo);
        return;
    }

    int clienteEncontrado = 0;

    // Buscando o cliente pelo CPF
    while (fscanf(arquivo, "%49[^;]; %11s; %11s; %49[^;]; %6[^;]; %49[^;]; %9[^;]; %d;\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep, &clienteLido.status) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) == 0) {
            printf("\n   Cliente encontrado:\n");
			printf("\n Nome: %s", clienteLido.nome);
			printf("\n CPF: %s", clienteLido.cpf);
			printf("\n Telefone: %s", clienteLido.telefone);
			printf("\n Rua: %s", clienteLido.rua);
			printf("\n Numero: %s", clienteLido.numero);
			printf("\n Bairro: %s", clienteLido.bairro);
			printf("\n CEP: %s", clienteLido.cep);
			printf("\n Status: %d", clienteLido.status);
            clienteEncontrado = 1;
            break;
        }
    }

    if (clienteEncontrado != 1) {
        printf(" Cliente com CPF: %s nao encontrado.\n", cpfProcurado);
        return;
    }
	
    fclose(arquivo);
}

void lista_ordenada(){
	
	arte_funcoes();
	
	int i = 0, j = 0;
	Cliente cliente[100];
	
	
	// Abrir o arquivo para leitura
	FILE *arquivo = fopen("clientes.txt", "r");
	
	if (arquivo == NULL) {
	        printf("Erro ao abrir o arquivo.\n");
	        return ;
	    }
	
	    // Ler os dados do arquivo
	    while (fscanf(arquivo, "%49[^;]; %11s; %11s; %49[^;]; %6[^;]; %49[^;]; %9[^;]; %d;\n",  cliente[i].nome, cliente[i].cpf, cliente[i].telefone, cliente[i].rua, cliente[i].numero, cliente[i].bairro, cliente[i].cep, &cliente[i].status) != EOF) {
	        i++;
	    }
	
	    // Fechar o arquivo
	    fclose(arquivo);
	
	    // Ordenar os clientes em ordem alfabética pelo nome
	    qsort(cliente, i, sizeof(Cliente), compararCliente);
	
	    // Exibir os clientes ordenados
	    printf("\n   Clientes cadastrados:\n");
	    printf("\n");
	    for (j = 0; j < i; j++) {
	    printf(" Nome: %s\n", cliente[j].nome);
	    printf(" CPF: %s\n", cliente[j].cpf);
	    printf(" Telefone: %s\n", cliente[j].telefone);
		printf(" Rua: %s\n",cliente[j].rua);
		printf(" Numero: %s\n",cliente[j].numero);    
		printf(" Bairro: %s\n",cliente[j].bairro);
		printf(" CEP: %s\n",cliente[j].cep);
		printf(" Status: %d\n",cliente[j].status);
		printf("\n\n");
	    }
	    //system("pause");
}

void desativar() {
	
	arte_funcoes();
	
    char cpf[12];
    getchar();
    printf("\n Digite o CPF do cliente a ser desativado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0'; // Remove o '\n' da string

    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("\n Erro ao abrir o arquivo 'clientes.txt'!\n");
        return;
    }

    FILE *arquivo_temp = fopen("clientes_temp_modificado.txt", "w");
    if (arquivo_temp == NULL) {
        printf("\n Erro ao criar o arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    Cliente cliente;
    int encontrado = 0;

    // Loop para processar cada linha do arquivo
    while (fscanf(arquivo, "%49[^;]; %11[^;]; %11[^;]; %49[^;]; %6[^;]; %49[^;]; %9[^;]; %d;\n",
                  cliente.nome, cliente.cpf, cliente.telefone, cliente.rua, 
                  cliente.numero, cliente.bairro, cliente.cep, &cliente.status) != EOF) {
        // Comparação do CPF fornecido com o CPF lido
        if (strcmp(cliente.cpf, cpf) == 0) {
            if (cliente.status == 1) { // Verifica se já está ativo
                cliente.status = 0;  // Desativa o cliente
                encontrado = 1;
                printf("\n Cliente '%s' desativado com sucesso!\n", cliente.nome);
            } else {
                printf("\n Cliente '%s' já está desativado!\n", cliente.nome);
            }
        }
        // Escreve no arquivo temporário, com ou sem alterações
        fprintf(arquivo_temp, "%s; %s; %s; %s; %s; %s; %s; %d;\n", cliente.nome, cliente.cpf, 
                cliente.telefone, cliente.rua, cliente.numero, cliente.bairro, 
                cliente.cep, cliente.status);
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    if (encontrado) {
        remove("clientes.txt");
        rename("clientes_temp_modificado.txt", "clientes.txt");
    } else {
        printf("\nCliente com CPF %s não encontrado!\n", cpf);
        remove("clientes_temp_modificado.txt");
    }
}

   
