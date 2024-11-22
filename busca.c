
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

void BuscaCPF() {

    Cliente clienteLido;
    char cpfProcurado[12];  // CPF com tamanho fixo de 11 caracteres + '\0'

    // Abrindo arquivo para leitura
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes. Certifique-se de que o arquivo 'clientes.txt' existe.\n");
        return;
    }

    // Solicita o CPF do cliente a ser buscado
    printf("Digite o CPF do usuario que deseja buscar(apenas numeros, 11 digitos): ");
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

    

    if (clienteEncontrado != 1) {
        printf("Cliente com CPF: %s nao encontrado.\n", cpfProcurado);
        return;
    }
	
    fclose(arquivo);
}
   


int main() {
    BuscaCPF();
    return 0;
}
