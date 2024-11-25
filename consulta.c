
void consulta() {
	
	arte_funcoes();

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
    while (fscanf(arquivo, "%49[^;]; %11s; %11s; %49[^;]; %6[^;]; %49[^;]; %9[^;]; %d;\n", clienteLido.nome, clienteLido.cpf, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep, &clienteLido.status) != EOF) {
        if (strcmp(clienteLido.cpf, cpfProcurado) == 0) {
            printf("Cliente encontrado:\nNome: %s\nTelefone: %s\nRua: %s\nNumero: %s\nBairro: %s\nCEP: %s\nStatus: %d\n", clienteLido.nome, clienteLido.telefone, clienteLido.rua, clienteLido.numero, clienteLido.bairro, clienteLido.cep, clienteLido.status);
            clienteEncontrado = 1;
            break;
        }
    }
