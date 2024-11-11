#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define clientes "clientes.txt"

typedef struct {
    char nome[100];
    char cpf[15];
    char telefone[15];
} Cliente;

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

    printf("Digite o telefone do cliente: ");
    fgets(novocliente.telefone, sizeof(novocliente.telefone), stdin);
    novocliente.telefone[strcspn(novocliente.telefone, "\n")] = '\0';  

    // abre o arquivo, esse 'a' serve pros dados que serao nao apagarem oq ja tiver no arquivo
    FILE *arquivo = fopen(clientes, "a");
    if (arquivo == NULL) {
        printf("\n erro ze\n");
        return;
    }

    // escreve os dados dos clientes pro arqivo 
    fprintf(arquivo, "Nome: %s\n", novocliente.nome);
    fprintf(arquivo, "CPF: %s\n", novocliente.cpf);
    fprintf(arquivo, "Telefone: %s\n", novocliente.telefone);
    fprintf(arquivo, "\n***************************************\n");

    fclose(arquivo);

    printf("\nCliente cadastrado com sucesso!\n");
}

int main() {
    int opcao;
    
 printf("\n\n");
    printf("\t(\\o/)_______________________________________________________(\\o/) \n");
    printf("\t(/|\\)                                                       (/|\\) \n");
    printf("\t  |  [1] CADASTRAR NOVO CLIENTE                               | \n");
    printf("\t  |  [2] REMOVER CLIENTE                                      | \n");
    printf("\t  |  [3] CONSULTAR CLIENTE                                    | \n");
    printf("\t  |  [4] LISTAR CLIENTES                                      | \n");
    printf("\t  |  [5] VENDA	                                              | \n");
    printf("\t  |  [6] SAIR          		                              | \n");
    printf("\t(\\o/)_______________________________________________________(\\o/) \n");
	printf("\t(/|\\)                                                       (/|\\) \n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            cadastrarcliente();
            break;
        case 2:
            printf("Saindo\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}


//void menu_principal(){
//    printf("\n\n");
//    printf("\t(\\o/)_______________________________________________________(\\o/) \n");
//    printf("\t(/|\\)                                                       (/|\\) \n");
//    printf("\t  |  [1] CADASTRAR NOVO CLIENTE                               | \n");
//    printf("\t  |  [2] REMOVER CLIENTE                                      | \n");
//    printf("\t  |  [3] CONSULTAR CLIENTE                                    | \n");
//    printf("\t  |  [4] LISTAR CLIENTES                                      | \n");
//    printf("\t  |  [5] VENDA	                                              | \n");
//    printf("\t  |  [6] SAIR          		                              | \n");
//    printf("\t(\\o/)_______________________________________________________(\\o/) \n");
//    printf("\t(/|\\)                                                       (/|\\) \n");
//}
