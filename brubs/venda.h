#define NUM_FLORES 7
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>//biblioteca para usar getch()

void arte_menu();
void arte_venda();
void menu_venda(char **flores, int *quantidade);
int vendaFlores(char **flores, int *quantidade);

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

void menu_venda(char **flores, int *quantidade){
	int i, opcaoV, sair = 0, total = 0;
	
	system("cls");
	arte_venda();
	
	printf("\n");
	printf("\t  ____________________________________________________________ \n");
	printf("\t |                                                            | \n");
	printf("\t |                      GERENCIAR PEDIDO                      | \n");
	
	do{
		printf("\t |            		                                      | \n ");
		printf("\t |               =========== VENDA ===========                | \n");
		printf("\t |------------------------------------------------------------| \n");
		printf("\t |  [1] Flores                                                | \n");
		printf("\t |  [2] Buquê                                                 | \n");
		printf("\t |  [3] Outras plantas                                        | \n");
		printf("\t |  [4] Itens	                                              | \n");
		printf("\t |  [5] Voltar                                                | \n");
		printf("\t |            		                                      | \n ");
		printf("\t | Digite a opção de venda (0 para finalizar): ");
		scanf("%d", &opcaoV);
		
        switch(opcaoV) {
            case 1:
            	vendaFlores(flores, quantidade);
                break;
            case 2:
                printf("\n\tVenda de buquê\n");
                break;
            case 3:
                printf("\n\tVenda de outras plantas\n");
                break;
            case 4:
                printf("\n\tVenda de outras itens\n");
                break;        
            case 5:
            	//arte_menu();
            	system("cls");
                printf("\n\tVoltando ao menu principal");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                //sair = 1;
                //break;
                return;
            case 0: //finalizar pedido
            system("cls");
            arte_venda();
	            printf("\n");
				printf("\t  ____________________________________________________________ \n");
				printf("\t |                                                            | \n");
				printf("\t |              Venda finalizada! Resumo do pedido:           | \n");
				printf("\t |------------------------------------------------------------| \n");
				
				
				
			    printf("\t |============================================================| \n");
			    
			    for (i = 0; i < NUM_FLORES; i++) {
			        if (quantidade[i] > 0) { 
			            printf("\t- %s: %d unidades\n", flores[i], quantidade[i]);
			            total += quantidade[i]; // soma o total de flores compradas
			        }
			    }
			    if (total == 0) {
			        printf("\tNenhuma flor foi comprada.\n");
			    } else {
			        printf("\n\tTotal de flores compradas: %d\n", total);
			    }
			    printf("\t===================================\n");
			    printf("\n\tObrigado pela compra!\n");
			    Sleep(8000);
			    //sair = 1;
            	break;
            default:
            	arte_menu();
                printf("\n\t OPÇÃO INVÁLIDA! DIGITE NOVAMENTE: ");
                break;
        }

    } while(opcaoV != 0); //loop até que o usuário escolha "voltar" ou "finalizar"
    
    
    
    
}
	/*
	printf("\t |                                                         |");
    printf("\n\t |       ###########  FORMA DE PAGAMENTO ###########       |");
    printf("\n\t |                                                         |");
    printf("\n\t | [1] - Cartão de débito                                  |");
    printf("\n\t | [2] - Cartão de crédio                                  |");
    printf("\n\t | [3] - Vale refeição                                     |");
    printf("\n\t | [4] - Dinheiro                                          |"); */

int vendaFlores(char **flores, int *quantidade){
	int i, op_flores, quant_flor;
	const char *nomes[NUM_FLORES] = {"Lírios", "Rosas", "Girassóis", "Violetas", "Orquídeas", "Astromélias", "Tulipas"};
	
	//Preenchendo o vetor nome com o nome das flores
	for (i = 0; i < NUM_FLORES; i++) {
        	strcpy(flores[i], nomes[i]); 
    	}
    //fazer um vetor que armazene só as flores escolhidas, e adicionar os valores, talvez struct
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
	
	do{
		printf("\t | Selecione a flor desejada (0 para finalizar): ");
		scanf("%d", &op_flores);	
		
		if (op_flores == 0) {
                break; // Finaliza o pedido
            	}

            if (op_flores < 1 || op_flores > 7) {
            	printf("\t | Opção inválida! Pressione qualquer tecla.                  |");
				printf("\n\t |            		                                      | \n ");
                scanf("%d", &op_flores);	
            } else {
	            printf("\t | Quantidade: ");
	            scanf("%d", &quant_flor);
				quantidade[op_flores - 1] += quant_flor; //atualiza a quantidade na struct
            }
            
	} while (op_flores != 0); 
		
	return 0;
}
