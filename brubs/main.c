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
void menu_venda(char **flores, char **plantas, char **itens, int *quantidade, int *quantidade_buque, int *quantidade_plantas, int *quantidade_sem, int *quantidade_item);


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
	
	const char *nomesF[NUM_FLORES] = {"Rosas", "Lírios", "Tulipas", "Astromélias", "Orquídeas", "Violetas", "Girassóis"};
	//const char *nomeBuque
	const char *nomesP[NUM_FLORES] = {"Suculentas", "Cactos", "Samabaias", "Buxinhos", "Bromélias", "Dracenas", "Lavandas"};
	//const char *nomesSem
	const char *nomesItens[NUM_FLORES] = {"Terra 5kg", "Terra 10kg", "Humus 2kg", "Vaso pequeno", "Vaso médio"};
	
	
	char opcaoM, **flores, **plantas, **itens;
	int i, *quantidade, *quantidade_buque, *quantidade_plantas, *quantidade_sem, *quantidade_item;
	
	
	//alocação dinâmica para o vetor de nomes de flores
	flores = (char **) malloc(NUM_FLORES * sizeof(char *));
	for (i = 0; i < NUM_FLORES; i++) {
        flores[i] = (char *)malloc(20 * sizeof(char)); 
        strcpy(flores[i], nomesF[i]); //preenchendo o vetor flores com o nome das flores
    }
    
    //buque =
    plantas = (char **) malloc(NUM_FLORES * sizeof(char *));
	for (i = 0; i < NUM_FLORES; i++) {
        plantas[i] = (char *)malloc(20 * sizeof(char)); 
        strcpy(plantas[i], nomesP[i]); 
    }
    
    itens = (char **) malloc(NUM_FLORES * sizeof(char *));
	for (i = 0; i < 5; i++) {
        itens[i] = (char *)malloc(20 * sizeof(char)); 
        strcpy(itens[i], nomesItens[i]); 
    }
    
    //sementes = 
    
    //alocação para o vetor quantidade de flores
    quantidade = (int *)calloc(NUM_FLORES, sizeof(int));
    
    //alocação para o vetor quantidade de flores na função vendaBuque()
    quantidade_buque = (int *)calloc(5, sizeof(int));
    
    quantidade_plantas = (int *)calloc(NUM_FLORES, sizeof(int));
    
    quantidade_sem = (int *)calloc(5, sizeof(int));
    
    quantidade_item = (int *)calloc(5, sizeof(int));
	
	if(flores == NULL || quantidade == NULL || quantidade_buque == NULL || quantidade_plantas == NULL || quantidade_sem == NULL || quantidade_item == NULL){
		printf("\n\t ERRO: Memória Insuficiente!");
		exit(1);
	}

	//nome(); //animacao.h
	
	
	do{	
		arte_menu();
		menu_principal();
		
		printf("\n\t DIGITE A OPÇÃO DESEJADA: ");
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
			menu_venda(flores, plantas, itens, quantidade, quantidade_buque, quantidade_plantas, quantidade_sem, quantidade_item);
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
    for (i = 0; i < NUM_FLORES; i++) {
        free(plantas[i]); 
    }
	
	// liberar memória alocada
	free(flores); 
	free(plantas);
	free(quantidade);
	free(quantidade_buque);
	free(quantidade_plantas);
	free(quantidade_sem);
	
	return 0;
}
