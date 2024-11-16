#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include <conio.h>//biblioteca para usar getch()

// Minhas bibliotecas
#include "animacao.h"

// Protótipos
void arte_menu();
void arte_venda();
void menu_principal();
int flores(int op);
// End Protótipos


/* void venda_flores(){
	printf("\n");
}
*/ 

int flores(int op){
	printf("\t |            		                                      | \n ");
	printf("\t |            		                                      | \n ");
	printf("\t |               =========== FLORES ===========               | \n");
	printf("\t |------------------------------------------------------------| \n");
	printf("\t |                     CANTEIRO DA SEMANA                     | \n");
	printf("\t |------------------------------------------------------------| \n");
	printf("\t |  [1] Lírios                                                | \n");
	printf("\t |  [2] Rosas                                                 | \n");
	printf("\t |  [3] Girassóis                                             | \n");
	printf("\t |  [4] Violetas	                                      | \n");
	printf("\t |  [5] Orquídeas          		                      | \n");
	printf("\t |  [6] Astromélias          		                      | \n");
	printf("\t |  [7] Tulipas          		                      | \n");
	printf("\t |                                                            | \n");
	printf("\t | Selecione a flor desejada (0 para finalizar): ");
	
	scanf("%d", &op); // Lê a flor escolhida pelo cliente
	
}

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

void arte_venda(){
	printf("\n");
	printf("\t		Floricultura Jardim das Abelhas\n");
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

void menu_venda(){
	int opcaoV, op_flores;
	
	system("cls");
	arte_venda();
	
	printf("\n");
	printf("\t  ____________________________________________________________ \n");
	printf("\t |                                                            | \n");
	printf("\t |                      GERENCIAR PEDIDO                      | ");
	
	do{
		printf("\n\t |                                                            | \n");
		printf("\t |------------------------------------------------------------| \n");
		printf("\t |  [1] Flores                                                | \n");
		printf("\t |  [2] Buquê                                                 | \n");
		printf("\t |  [3] Outras plantas                                        | \n");
		printf("\t |  [4] Itens	                                              | \n");
		printf("\t |            		                                      | \n ");
		printf("\t | Digite a opção de venda: ");
		scanf("%d", &opcaoV);
		
        switch(opcaoV) {
            case 1:
            	flores(op_flores);
                break;
            case 2:
                printf("\n\tVenda de buquê\n");
                break;
            case 3:
                printf("\n\tVenda de outras plantas\n");
                break;
                    
            case 4:
            	//arte_menu();
            	system("cls");
                printf("\n\tVoltando ao menu principal");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                arte_menu();
                break;
                
            default:
            	arte_menu();
                printf("\n\t OPÇÃO INVÁLIDA! DIGITE NOVAMENTE: ");
                break;
        }

    } while(opcaoV != '4');
}
	

int main (){
	setlocale(LC_ALL, "Portuguese");
	system("color 0E");
	
	char opcaoM;
	int venda = 1;
	
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
			menu_venda();
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
	
	
	return 0;
}
