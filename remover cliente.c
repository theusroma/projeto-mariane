#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    char cpf[12];  
    char telefone[15];
} Cliente;

void removerCPF();

void removerCPF() {
    int verificacao;
    Cliente clienteLido;
    char cpfProcurado[12];  
    FILE *arquivo = fopen("clientes.txt", "r");
    FILE *arquivoTemp = fopen("clientes_temp.txt", "w");

    if (arquivo == NULL) {
        printf("Sem clientes cadastrados ainda.\n");
        return;
    }

    printf("Digite o CPF do usuário que deseja excluir:\n");
    fgets(cpfProcurado, sizeof(cpfProcurado), stdin);
    
   

    int clienteEncontrado = 0;
    
    while (fscanf(arquivo, "%99s %12s %14s", clienteLido.nome, clienteLido.cpf, clienteLido.telefone) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) == 0) {
            
            printf("Cliente encontrado:\nNome: %s\nTelefone: %s\n", clienteLido.nome, clienteLido.telefone);
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente com CPF: %s nao encontrado.\n", cpfProcurado);
        fclose(arquivo);
        fclose(arquivoTemp);
        return;
    }

    
    printf("Tem certeza que deseja excluir esse cliente?\nDigite [1] para sim, [2] para nao: \n");
    scanf("%d", &verificacao);
    getchar();

    if (verificacao != 1) {
        printf("Exclusao cancelada.\n");
        fclose(arquivo);
        fclose(arquivoTemp);
        return;
    }

    
    arquivo = fopen("clientes.txt", "r");
    arquivoTemp = fopen("clientes_temp.txt", "w");

    int clienteRemovido = 0;
    
    while (fscanf(arquivo, "%99s %12s %14s", clienteLido.nome, clienteLido.cpf, clienteLido.telefone) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) != 0) {
            fprintf(arquivoTemp, "%s %s %s\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone);
        } else {
            clienteRemovido = 1;
        }
    }

    if (clienteRemovido) {
        printf("Cliente com CPF: %s foi removido com sucesso.\n", cpfProcurado);
    } else {
        printf("Erro ao remover o cliente. CPF não encontrado.\n");
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    
    remove("clientes.txt");
    rename("clientes_temp.txt", "clientes.txt");
}

int main() {
    removerCPF();
    return 0;
}
