#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//matheus eu e o joao achamos que poderia adicionar na struct o dia, mes, ano, tambem seria bom adicionar o endereço, tipo rua, numero, bairro, cep,
// complemento, e pensamo tambem se seria uma boa ideia listar todas as informações no final e fazer tipo uma confirmação se os dados estão corretos
// o jao falo que da pra fazer tudo em um arquivo temporário e dai quando confirmar, da um rename no arquivo temporario par original e pode deletar 
// o arquivo antigo

typedef struct {
    char nome[100];
    char cpf[15];
    char telefone[15];
} Cliente;

// funcao q vai cadastar o cliente
void cadastrarcliente() {
    Cliente novocliente;
    
    // mudamo aqui matheus
    FILE *arquivoTemp = fopen("clientes_temp.txt", "w");
    
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
    FILE *arquivo = fopen("clientes_temp.txt", "a");
    if (arquivo == NULL) {
        printf("\n erro ze\n");
        return;
    }

	//mudamos aqui tambem matheus, a mariane ajudou
    // escreve os dados dos clientes pro arqivo 
    fprintf(arquivo, "%s;%s;%s", novocliente.nome, novocliente.cpf, novocliente.telefone);
    fprintf(arquivo, "\n***************************************\n");

    fclose(arquivo);

    printf("\nCliente cadastrado com sucesso!\n");
}

int main() {
    cadastrarcliente();
 /*    
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
*/
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
