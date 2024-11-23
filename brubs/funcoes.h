#define NUM_FLORES 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>//biblioteca para usar getch()
#include <ctype.h>

typedef struct {
    char nome[50];
    char cpf[15];
    char telefone[15];
    char rua[50];
    int numero;
    char bairro[50];
    char cep[10];
} Cliente;

int valida_cpf(char cpf[11]);
int validarCPF();
void cadastrarCliente();
void removerCPF();
void consulta();
void lista();
void desativar();

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

// funcao q vai cadastar o cliente
void cadastrarCliente(){
	Cliente novocliente;
	
	arte_funcoes();
	
    // pedindo dados dos cliente ne zé
    printf("\n Digite o nome do cliente: ");
    fgets(novocliente.nome, sizeof(novocliente.nome), stdin);
    novocliente.nome[strcspn(novocliente.nome, "\n")] = '\0';

    printf("\n\n Digite o CPF do cliente: ");
    fgets(novocliente.cpf, sizeof(novocliente.cpf), stdin);
    novocliente.cpf[strcspn(novocliente.cpf, "\n")] = '\0';

    // validacao do cpf
    if (!valida_cpf(novocliente.cpf)) {
        printf("\n CPF inválido! Por favor, insira um CPF válido.\n");
        return;  // se o CPF for inválido, retorna da função sem salvar o cliente
    }

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
scanf("%d", &novocliente.numero);
getchar(); // Limpa o buffer

// pede ao usuario o nome do bairro
printf("\n Digite o bairro do cliente: ");
fgets(novocliente.bairro, sizeof(novocliente.bairro), stdin);
novocliente.bairro[strcspn(novocliente.bairro, "\n")] = '\0';

	// pede ao usuario o numero do cep
    printf("\n\n Digite o CEP do cliente: ");
    fgets(novocliente.cep, sizeof(novocliente.cep), stdin);
    novocliente.cep[strcspn(novocliente.cep, "\n")] = '\0';

	printf("\n------------------------------------------------------------------------------------------------------------------------");
    // exibe as informações já informadas pelo usuario e pergunta se os dados estao corretos
    printf("\n\t    Confirmação dos Dados    \n");
    printf("\n Nome: %s\n", novocliente.nome);
    printf("\n CPF: %s\n", novocliente.cpf);
    printf("\n Telefone: %s\n", novocliente.telefone);
    printf("\n Endereço: %s, %d - %s, CEP: %s\n", novocliente.rua, novocliente.numero, novocliente.bairro, novocliente.cep);
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
        fprintf(arquivo, "%s;%s;%s;%s;%d;%s;%s;\n", 
                novocliente.nome, novocliente.cpf, novocliente.telefone, 
                novocliente.rua, novocliente.numero, novocliente.bairro, novocliente.cep);
        fprintf(arquivo, "***************************************\n");
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
        printf("Erro ao abrir o arquivo de clientes. Certifique-se de que o arquivo 'clientes.txt' existe.\n");
        return;
    }

    // Solicita o CPF do cliente a ser removido
    printf("Digite o CPF do usuario que deseja excluir (apenas numeros, 11 digitos): ");
    scanf("%11s", cpfProcurado);

    // Validação do CPF
    if (!validarCPF(cpfProcurado)) {
        printf("CPF invalido! Por favor, forneca um CPF valido com 11 digitos numericos.\n");
        fclose(arquivo);
        return;
    }

    int clienteEncontrado = 0;

    // Buscando o cliente pelo CPF
    while (fscanf(arquivo, "%99[^;]; %11s; %11s; %49[^;]; %6[^;]; %49[^;]; %9[^;];\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) == 0) {
            printf("Cliente encontrado:\nNome: %s\nTelefone: %s\nRua: %s\nNumero: %s\nBairro: %s\nCEP: %s\n", clienteLido.nome, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep);
            clienteEncontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (clienteEncontrado != 1) {
        printf("Cliente com CPF: %s nao encontrado.\n", cpfProcurado);
        return;
    }

    // Confirmação de exclusão
    printf("Tem certeza que deseja excluir esse cliente?\nDigite:\n[1] sim;\n[2] nao.\n");
    scanf("%d", &verificacao);

    if (verificacao == 2) {
        printf("Exclusao cancelada.\n");
        return;
    }

    // Reabre o arquivo para leitura e prepara o arquivo temporário para escrita
    arquivo = fopen("clientes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos para leitura e escrita.\n");
        if (arquivo != NULL) fclose(arquivo);
        if (temp != NULL) fclose(temp);
        return;
    }

    int clienteRemovido = 0;

    // Copia todos os clientes para o arquivo temporário, exceto o cliente a ser removido
    while (fscanf(arquivo, "%99[^;]; %11s; %11s; %49[^;]; %6[^;]; %49[^;]; %9[^;];\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) != 0) {
            fprintf(temp, "%s; %s; %s; %s; %s; %s; %s;\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep);
        } else {
            clienteRemovido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Se o cliente foi removido, substitui o arquivo original pelo arquivo temporário
    if (clienteRemovido) {
        if (remove("clientes.txt") != 0) {
            printf("Erro ao remover o arquivo original.\n");
            return;
        }
        if (rename("temp.txt", "clientes.txt") != 0) {
            printf("Erro ao renomear o arquivo temporario.\n");
            return;
        }
        printf("Cliente com CPF: %s foi removido com sucesso.\n", cpfProcurado);
    } else {
        printf("Erro ao remover o cliente. CPF nao encontrado.\n");
        remove("temp.txt");
    }
}


void consulta(){
	arte_funcoes();
}

void lista(){
	arte_funcoes();
}

void desativar(){
	arte_funcoes();
}
