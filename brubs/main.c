#define NUM_FLORES 7
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include <conio.h>//biblioteca para usar getch()

// Minhas bibliotecas
//#include "animacao.h"
#include "venda.h"
#include "funcoes.h"

// Protótipos
void arte_menu();
void menu_principal();
void menu_venda(char **flores, int *quantidade, int *quantidade_buque, int *buque_pronto);


// End Protótipos

void arte_menu(){
	system("cls");
	printf("\n");
	printf("\t		Bem Vindo(a) ao Jardim das Abelhas!\n");
	printf("\t		      	  	       __\n");
	printf("\t    		       .' '.          // \\  \n");
	printf("\t          .            .   .          \\\\_/ //\n");
	printf("\t               .         .         . -(||)(')\n");
	printf("\t                 ' .  . ' ' .  . '    '''\n");
	printf("\t                   _\n");	
    printf("\t                  _(_)_                          wWWWw    _\n");
    printf("\t      @@@@       (_)@(_)   vVVVv     _     @@@@  (___)  _(_)_\n");
    printf("\t     @@()@@ wWWWw  (_)\\    (___)   _(_)_  @@()@@   Y   (_)@(_)\n");
    printf("\t      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \\|/    (_)\ \n");
    printf("\t       /      Y       \\|    \\|/    /(_)    \\|      |/      |\n");
    printf("\t    \\ |     \\ |/       | / \\ | /  \\|/       |/    \\|      \\|/\n");
    printf("\t    \\\\|//   \\\\|///  \\\\\\|//\\\\\\|/// \\|///  \\\\\\|//  \\\\|//  \\\\\\|//\n");
    printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}



void menu_principal(){
	printf("\n");
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
	
}
	

int main (){
	setlocale(LC_ALL, "Portuguese");
	system("color 0E");
	
	const char *nomes[NUM_FLORES] = {"Lírios", "Rosas", "Girassóis", "Violetas", "Orquídeas", "Astromélias", "Tulipas"};
	//char *flores_buque[] = {"Rosas", "Lírios", "Tulipas", "Astromélias"};
	char opcaoM, **flores;
	int i, *quantidade, *quantidade_buque, buque_pronto = 0;
	
	
	//alocação dinâmica para o vetor de nomes de flores
	flores = (char **) malloc(NUM_FLORES * sizeof(char *));
	for (i = 0; i < NUM_FLORES; i++) {
        flores[i] = (char *)malloc(20 * sizeof(char)); // aloca até 20 caracteres para cada nome
        strcpy(flores[i], nomes[i]); //preenchendo o vetor nome com o nome das flores
    }
    //alocação para o vetor quantidade de flores
    quantidade = (int *)calloc(NUM_FLORES, sizeof(int));
    
    //alocação para o vetor quantidade de flores na função vendaBuque()
    quantidade_buque = (int *)calloc(4, sizeof(int));
	
	if(flores == NULL || quantidade == NULL || quantidade_buque == NULL){
		printf("\n\t ERRO: Memória Insuficiente!");
		exit(1);
	}

	//nome(); //animacao.h
	
	
	do{	
		arte_menu();
		menu_principal();
		
		printf("\n\t DIGITE A OPÇÃO DESEJADA: ");
		//opcaoM = getch();
		scanf(" %c", &opcaoM);
		
		switch(opcaoM){
		case '1':
			cadastro();
			Sleep(8000);
			
			break;
		
		case '2':
			remover();
			Sleep(8000);
			break;
		
		case '3':
			consulta();
			Sleep(8000);
			break;
		
		case '4':
			lista();
			Sleep(8000);
			break;
		
		case '5':
			menu_venda(flores, quantidade, quantidade_buque, &buque_pronto);
			break;
		
		case '6':
			printf("\n\tSaindo...");
			sleep(1500);
			break;
 	
		default:
			arte_menu();
			menu_principal();
			printf("\n\t OPÇÃO INVÁLIDA! DIGITE NOVAMENTE: ");
			opcaoM = getch();
			//system("cls");
		}
	
	} while (opcaoM != '6');
	
	 // liberação de memória de cada string
    for (i = 0; i < NUM_FLORES; i++) {
        free(flores[i]); // Libera cada string
    }
	
	// liberar memória alocada
	free(flores); 
	free(quantidade);
	free(quantidade_buque);
	
	return 0;
}
