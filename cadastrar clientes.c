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
} Cliente;

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

// funcao q vai cadastar o cliente
void cadastrarcliente() {
    Cliente novocliente;

    // pedindo dados dos cliente ne zé
    printf("\nDigite o nome do cliente: ");
    fgets(novocliente.nome, sizeof(novocliente.nome), stdin);
    novocliente.nome[strcspn(novocliente.nome, "\n")] = '\0';

    printf("Digite o CPF do cliente: ");
    fgets(novocliente.cpf, sizeof(novocliente.cpf), stdin);
    novocliente.cpf[strcspn(novocliente.cpf, "\n")] = '\0';

    // validacao do cpf
    if (!valida_cpf(novocliente.cpf)) {
        printf("CPF inválido! Por favor, insira um CPF válido.\n");
        return;  // Se o CPF for inválido, retorna da função sem salvar o cliente
    }

	// pede ao usuario telefone
    printf("Digite o telefone do cliente: ");
    fgets(novocliente.telefone, sizeof(novocliente.telefone), stdin);
    novocliente.telefone[strcspn(novocliente.telefone, "\n")] = '\0';

    // pede ao usuario nome da rua
    printf("Digite a rua do cliente: ");
    fgets(novocliente.rua, sizeof(novocliente.rua), stdin);
    novocliente.rua[strcspn(novocliente.rua, "\n")] = '\0';

	// pede ao usuario numero da casa
    printf("Digite o numero da casa: ");
    scanf("%d", &novocliente.numero)
	
	// pede ao usuario o nome do bairro
    printf("Digite o bairro do cliente: ");
    fgets(novocliente.bairro, sizeof(novocliente.bairro), stdin);
    novocliente.bairro[strcspn(novocliente.bairro, "\n")] = '\0';

	// pede ao usuario o numero do cep
    printf("Digite o CEP do cliente: ");
    fgets(novocliente.cep, sizeof(novocliente.cep), stdin);
    novocliente.cep[strcspn(novocliente.cep, "\n")] = '\0';

    // exibe as informações já informadas pelo usuario e pergunta se os dados estao corretos
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
        // se o usuario digitar 's'	grava os dados no arqiuvo
        FILE *arquivo = fopen("clientes_temp.txt", "a");
        if (arquivo == NULL) {
            printf("\nErro ao abrir o arquivo!\n");
            return;
        }

        // escrevendo os dados do usuario no arquivo
        fprintf(arquivo, "%s;%s;%s;%s;%d;%s;%s\n", 
                novocliente.nome, novocliente.cpf, novocliente.telefone, 
                novocliente.rua, novocliente.numero, novocliente.bairro, novocliente.cep);
        fprintf(arquivo, "***************************************\n");

        fclose(arquivo);
        printf("\nCliente cadastrado com sucesso!\n");
    } else {
        // se o usuatio digitar n, o cadastro é cancelado
        printf("\nCadastro cancelado. Nenhum dado foi salvo.\n");
    }
}

int main() {
	cadastrarcliente();
//int opcao;
//       
// printf("\n\n");
//    printf("\t(\\o/)_______________________________________________________(\\o/) \n");
//    printf("\t(/|\\)                                                       (/|\\) \n");
//    printf("\t  |  [1] CADASTRAR NOVO CLIENTE                               | \n");
//    printf("\t  |  [2] REMOVER CLIENTE                                      | \n");
//    printf("\t  |  [3] CONSULTAR CLIENTE                                    | \n");
//    printf("\t  |  [4] LISTAR CLIENTES                                      | \n");
//    printf("\t  |  [5] VENDA	                                              | \n");
//    printf("\t  |  [6] SAIR          		                              | \n");
//    printf("\t(\\o/)_______________________________________________________(\\o/) \n");
//	printf("\t(/|\\)                                                       (/|\\) \n");
//    scanf("%d", &opcao);
//    getchar();
//
//    switch (opcao) {
//        case 1:
//            cadastrarcliente();
//            break;
//        case 6:
//            printf("Saindo\n");
//            break;
//        default:
//            printf("Opção inválida!\n");
//            break;
//    }

    return 0;
}
