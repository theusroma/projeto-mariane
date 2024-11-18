#define NUM_FLORES 7
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include <conio.h>//biblioteca para usar getch()

// Minhas bibliotecas
#include "animacao.h"
#include "venda.h"

typedef struct {
	char nome[20]; //nome das flores
	int quantidade; //quantidade de flores
} Flor;

// Protótipos
void arte_menu();
void menu_principal();

// End Protótipos



void arte_menu(){
	system("cls");
	printf("\n");
	printf("\t		Bem Vindo(a) ao Jardim das Abelhas!\n");
	printf("\t		      	  	       __\n");
	printf("\t    		       .' '.          // \\  \n");
	printf("\t          .          .   .          \\\\_/ //\n");
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
	
	char opcaoM;
	int i, venda = 1, quantidade;
	Flor *flores; //array de struct
	
	//alocação dinâmica para o array de struct
	flores = (Flor *) calloc(NUM_FLORES, sizeof(Flor));
	
	if(flores == NULL){
		printf("\n\t ERRO: Memória Insuficiente!");
	}
	
	nome(); //animacao.h
	arte_menu();
	
	do{	
		menu_principal();
		
		printf("\n\t DIGITE A OPÇÃO DESEJADA: ");
		opcaoM = getch();
		
		switch(opcaoM){
		case '1':
			printf("Cadastra");
			break;
		
		case '2':
			printf("Removendo");
			break;
		
		case '3':
			printf("Consulta");
			break;
		
		case '4':
			printf("Lista");
			break;
		
		case '5':
			menu_venda(flores);
			break;
		
		case '6':
			printf("saindo");
			break;
 	
		default:
			arte_menu();
			menu_principal();
			printf("\n\t OPÇÃO INVÁLIDA! DIGITE NOVAMENTE: ");
			opcaoM = getch();
			//system("cls");
		}
	
	} while (opcaoM != '6');
	
	free(flores); // Liberar memória alocada

	return 0;
}
