#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nome[100];
    char telefone[15];
    char cpf[12];
} Cliente;

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

void removerCPF() {
    int verificacao;
    Cliente clienteLido;
    char cpfProcurado[12];  // CPF com tamanho fixo de 11 caracteres + '\0'

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
    while (fscanf(arquivo, "%99[^;]; %11s; %11s\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) == 0) {
            printf("Cliente encontrado:\nNome: %s\nTelefone: %s\n", clienteLido.nome, clienteLido.telefone);
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
    while (fscanf(arquivo, "%99[^;]; %11s; %11s\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) != 0) {
            fprintf(temp, "%s; %s; %s\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone);
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

int main() {
    removerCPF();
    return 0;
}
