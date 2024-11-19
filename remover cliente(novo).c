#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100]; 
    char telefone[15];
    char cpf[12];
} Cliente;

void removerCPF() {
    int verificacao;
    Cliente clienteLido;
    char cpfProcurado[12];
    
    // Abrindo arquivo para leitura
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Sem clientes cadastrados ainda.\n");
        return;
    }

    printf("Digite o CPF do usuario que deseja excluir: ");
    scanf("%12[^\n]", cpfProcurado);

    int clienteEncontrado = 0;

    // Buscando o cliente pelo CPF
    while (fscanf(arquivo, "%99[^;];%12[^;];%14[^;]\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) == 0) {
            printf("Cliente encontrado:\nNome: %s\nTelefone: %s\n", clienteLido.nome, clienteLido.telefone);
            clienteEncontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (!clienteEncontrado) {
        printf("Cliente com CPF: %s nao encontrado.\n", cpfProcurado);
        return;
    }

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
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    int clienteRemovido = 0;

    // Copia todos os clientes para o arquivo temporário, exceto o cliente a ser removido
    while (fscanf(arquivo, "%99[^;];%12[^;];%14[^;]\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) != 0) {
            fprintf(temp, "%s;%s;%s\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone);
        } else {
            clienteRemovido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Se o cliente foi removido, substitui o arquivo original pelo arquivo temporário
    if (clienteRemovido) {
        remove("clientes.txt");
        rename("temp.txt", "clientes.txt");
        printf("Cliente com CPF: %s foi removido com sucesso.\n", cpfProcurado);
    } else {
        printf("Erro ao remover o cliente. CPF nao encontrado.\n");
        remove("temp.txt");
    }
}

int main() {
    removerCPF();
    return 0;
}
