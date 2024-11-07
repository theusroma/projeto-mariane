#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
//getch()
#include <conio.h>

// minhas bibliotecas


// Protótipos
void arte_menu();
void menu_principal();
void menu_venda();
void flores_indivi();
void flores_buque();
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
    printf("\t                    _\n");	
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
	char opcaoV;
	
	arte_menu();
	
	do{
		printf("\n");
		printf("\t(\\o/)_______________________________________________________(\\o/) \n");
		printf("\t(/|\\)                                                       (/|\\) \n");
		printf("\t  |  [1] REALIZAR VENDA DE FLORES                             | \n");
		printf("\t  |  [2] REALIZAR VENDA DE BUQUÊ                              | \n");
		printf("\t  |  [3] VOLTAR                                               | \n");
		printf("\t  |  					                      | \n");
		printf("\t  |  				                              | \n");
		printf("\t  |                      		                      | \n");
		printf("\t(\\o/)_______________________________________________________(\\o/) \n");
		printf("\t(/|\\)                                                       (/|\\) \n");
		
		printf("\n\t DIGITE A OPÇÃO DESEJADA: ");
        opcaoV = getch();
        
        switch(opcaoV) {
            case '1':
                printf("\n\tVenda de flores\n");
                flores_indivi();
                break;
            case '2':
                printf("\n\tVenda de buquê\n");
                flores_buque();
                break;
            case '3':
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
                printf("\n\t OPÇÃO INVÁLIDA! TENTE NOVAMENTE!");
        }

    } while(opcaoV != '3');
}

void flores_indivi(){
	printf("oii");
}

void flores_buque(){
	printf("tchauu");
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	system("color 0E");
	
	char opcaoM;
	
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
			printf("\n\t OPÇÃO INVÁLIDA! TENTE NOVAMENTE! ");
			opcaoM = getch;	
		}
	
	} while (opcaoM != '6');
	
	return 0;
}
