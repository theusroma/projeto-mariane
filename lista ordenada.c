#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char telefone[15];
    char cpf[12];
} Cliente;

void lista_ordenada();
int compararClientes(const void *a, const void *b);

int compararCliente(const void *a, const void *b) {
    Cliente *clienteA = (Cliente *)a;
    Cliente *clienteB = (Cliente *)b;
    return strcmp(clienteA->nome, clienteB->nome);
}

void lista_ordenada(){
	
	// Abrir o arquivo para leitura
	FILE *arquivo = fopen("clientes.txt", "r");
	
	if (arquivo == NULL) {
	        printf("Erro ao abrir o arquivo.\n");
	        return 1;
	    }
	
    Cliente cliente[100];
	
	int i = 0, j = 0;
	
	    
	    
	    
	
	    // Ler os dados do arquivo
	    while (fscanf(arquivo, "%99[^;]; %11s; %11s; %49[^;]; %6[^;]; %49[^;]; %9[^;];\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep) != EOF) {
	        i++;
	    }
	
	    // Fechar o arquivo
	    fclose(arquivo);
	
	    // Ordenar os clientes em ordem alfabética pelo nome
	    qsort(cliente, i, sizeof(Cliente), compararCliente);
	
	    // Exibir os clientes ordenados
	    printf("Clientes cadastrados:\n");
	    for (j = 0; j < i; j++) {
	        printf("Nome: %s\n", cliente[j].nome);
	        printf("CPF: %s\n", cliente[j].cpf);
	        printf("Telefone: %s\n", cliente[j].telefone);
		printf("Rua: %s\n",cliente[j].rua);
		printf("Numero: %s\n",cliente[j].numero);    
		printf("Bairro: %s\n",cliente[j].bairro);
		printf("CEP: %s\n",cliente[j].cep);
		   
	    }
	
}

	int main(){
		
		lista_ordenada();
	
	return 0;	
	}


	
	    
