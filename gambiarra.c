#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100]; 
    char telefone[15];
    int cpf;
} Cliente;

void removerCPF() {
    int verificacao;
    Cliente clienteLido;
    int cpfProcurado;
    
    
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Sem clientes cadastrados ainda.\n");
        return;
    }

    
    printf("Digite o CPF do usuario que deseja excluir: ");
    scanf("%d", &cpfProcurado);

    int clienteEncontrado = 0;

    
    while (fscanf(arquivo, "%99[^;];%d;%14[^\n]\n", clienteLido.nome, &clienteLido.cpf, clienteLido.telefone) != EOF) {
        if (clienteLido.cpf == cpfProcurado) {
            printf("Cliente encontrado:\nNome: %s\nTelefone: %s\n", clienteLido.nome, clienteLido.telefone);
            clienteEncontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (!clienteEncontrado) {
        printf("Cliente com CPF: %d nao encontrado.\n", cpfProcurado);
        return;
    }

    
    printf("Tem certeza que deseja excluir esse cliente?\nDigite:\n[1] sim;\n[2] nao.\n");
    scanf("%d", &verificacao);

    if (verificacao != 1) {
        printf("Exclusao cancelada.\n");
        return;
    }

    
    arquivo = fopen("clientes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    int clienteRemovido = 0;

    
    while (fscanf(arquivo, "%99[^;];%d;%14[^\n]\n", clienteLido.nome, &clienteLido.cpf, clienteLido.telefone) != EOF) {
        if (clienteLido.cpf != cpfProcurado) {
            fprintf(temp, "%s;%d;%s\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone);
        } else {
            clienteRemovido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    
    if (clienteRemovido) {
        remove("clientes.txt");
        rename("temp.txt", "clientes.txt");
        printf("Cliente com CPF: %d foi removido com sucesso.\n", cpfProcurado);
    } else {
        printf("Erro ao remover o cliente. CPF nao encontrado.\n");
        remove("temp.txt");
    }
}

int main() {
    removerCPF();
    return 0;
}
