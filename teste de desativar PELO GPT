#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cpf[15];
    char telefone[15];
    char rua[50];
    int numero;
    char bairro[50];
    char cep[10];
    int status; // 1 = Ativo, 0 = Desativado
} Cliente;

// Validar CPF
int valida_cpf(char cpf[11]) {
    int int_cpf[11], i, soma = 0, digito1, digito2, aux = 0;
    for (i = 0; i < 11; i++) {
        int_cpf[i] = cpf[i] - 48;  // Convertendo os caracteres para inteiros
    }
    
    // Verifica se os números do CPF são iguais
    if (int_cpf[0] == int_cpf[1] && int_cpf[1] == int_cpf[2] && int_cpf[2] == int_cpf[3] && int_cpf[3] == int_cpf[4] &&
        int_cpf[4] == int_cpf[5] && int_cpf[5] == int_cpf[6] && int_cpf[6] == int_cpf[7] && int_cpf[7] == int_cpf[8] &&
        int_cpf[8] == int_cpf[9] && int_cpf[9] == int_cpf[10]) {
        return 0;  // Retorna CPF inválido
    }

    // Cálculo do primeiro número verificando
    for (i = 0; i < 9; i++) {
        soma += int_cpf[i] * (10 - i);
    }
    aux = soma % 11;
    if (aux == 0 || aux == 1) {
        digito1 = 0;
    } else {
        digito1 = 11 - aux;
    }

    // Cálculo do segundo número verificando
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

    // Testa se os dois números verificadores estão corretos
    if (int_cpf[9] == digito1 && int_cpf[10] == digito2) {
        return 1;  // CPF válido
    } else {
        return 0;  // CPF inválido
    }
}

// Função para cadastrar cliente
void cadastrarcliente() {
    Cliente novocliente;

    // Pedindo dados do cliente
    printf("\nDigite o nome do cliente: ");
    fgets(novocliente.nome, sizeof(novocliente.nome), stdin);
    novocliente.nome[strcspn(novocliente.nome, "\n")] = '\0';

    printf("Digite o CPF do cliente: ");
    fgets(novocliente.cpf, sizeof(novocliente.cpf), stdin);
    novocliente.cpf[strcspn(novocliente.cpf, "\n")] = '\0';

    // Validação do CPF
    if (!valida_cpf(novocliente.cpf)) {
        printf("CPF inválido! Por favor, insira um CPF válido.\n");
        return;  // Se o CPF for inválido, retorna da função sem salvar o cliente
    }

    // Pedindo o telefone
    printf("Digite o telefone do cliente: ");
    fgets(novocliente.telefone, sizeof(novocliente.telefone), stdin);
    novocliente.telefone[strcspn(novocliente.telefone, "\n")] = '\0';

    // Pedindo o nome da rua
    printf("Digite a rua do cliente: ");
    fgets(novocliente.rua, sizeof(novocliente.rua), stdin);
    novocliente.rua[strcspn(novocliente.rua, "\n")] = '\0';

    // Pedindo o número da casa
    printf("Digite o numero da casa: ");
    scanf("%d", &novocliente.numero);
    getchar(); // Limpar o buffer

    // Pedindo o bairro
    printf("Digite o bairro do cliente: ");
    fgets(novocliente.bairro, sizeof(novocliente.bairro), stdin);
    novocliente.bairro[strcspn(novocliente.bairro, "\n")] = '\0';

    // Pedindo o CEP
    printf("Digite o CEP do cliente: ");
    fgets(novocliente.cep, sizeof(novocliente.cep), stdin);
    novocliente.cep[strcspn(novocliente.cep, "\n")] = '\0';

    // Exibe as informações e pergunta se estão corretas
    printf("\n    Confirmação dos Dados    \n");
    printf("Nome: %s\n", novocliente.nome);
    printf("CPF: %s\n", novocliente.cpf);
    printf("Telefone: %s\n", novocliente.telefone);
    printf("Endereço: %s, %d - %s, CEP: %s\n", novocliente.rua, novocliente.numero, novocliente.bairro, novocliente.cep);
    printf("\nOs dados estão corretos? (s/n): ");

    char confirmacao;
    scanf("%c", &confirmacao);
    getchar();
    if (confirmacao == 's' || confirmacao == 'S') {
        // Se o usuário digitar 's', grava os dados no arquivo
        FILE *arquivo = fopen("clientes_temp.txt", "a");
        if (arquivo == NULL) {
            printf("\nErro ao abrir o arquivo!\n");
            return;
        }

        // Gravando os dados do cliente
        novocliente.status = 1;  // Marca o cliente como ativo
        fprintf(arquivo, "%s;%s;%s;%s;%d;%s;%s;%d\n", 
                novocliente.nome, novocliente.cpf, novocliente.telefone, 
                novocliente.rua, novocliente.numero, novocliente.bairro, novocliente.cep, novocliente.status);

        fclose(arquivo);
        printf("\nCliente cadastrado com sucesso!\n");
    } else {
        // Se o usuário digitar 'n', o cadastro é cancelado
        printf("\nCadastro cancelado. Nenhum dado foi salvo.\n");
    }
}

// Função para desativar o cliente
void desativar_cliente(char *cpf_cliente) {
    FILE *arquivo = fopen("clientes_temp.txt", "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *temp_arquivo = fopen("clientes_temp2.txt", "w");
    if (temp_arquivo == NULL) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    Cliente cliente;
    int encontrado = 0;

    while (fscanf(arquivo, "%49[^;];%14[^;];%14[^;];%49[^;];%d;%49[^;];%9[^;];%d\n", 
                  cliente.nome, cliente.cpf, cliente.telefone, 
                  cliente.rua, &cliente.numero, cliente.bairro, 
                  cliente.cep, &cliente.status) != EOF) {
        if (strcmp(cliente.cpf, cpf_cliente) == 0) {
            cliente.status = 0; // Marca como desativado
            encontrado = 1;
        }
        // Escreve o cliente no arquivo temporário
        fprintf(temp_arquivo, "%s;%s;%s;%s;%d;%s;%s;%d\n", 
                cliente.nome, cliente.cpf, cliente.telefone, 
                cliente.rua, cliente.numero, cliente.bairro, cliente.cep, cliente.status);
    }

    fclose(arquivo);
    fclose(temp_arquivo);

    if (encontrado) {
        remove("clientes_temp.txt"); // Apaga o arquivo original
        rename("clientes_temp2.txt", "clientes_temp.txt"); // Renomeia o temporário para o original
        printf("Cliente desativado com sucesso!\n");
    } else {
        printf("Cliente não encontrado.\n");
    }
}

int main() {
    int opcao;
    
    do {
        printf("\n1. Cadastrar Cliente\n");
        printf("2. Desativar Cliente\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer

        switch (opcao) {
            case 1:
                cadastrarcliente();
                break;
            case 2: {
                char cpf[15];
                printf("Digite o CPF do cliente a desativar: ");
                fgets(cpf, sizeof(cpf), stdin);
                cpf[strcspn(cpf, "\n")] = '\0'; // Remove newline
                desativar_cliente(cpf);
                break;
            }
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}
