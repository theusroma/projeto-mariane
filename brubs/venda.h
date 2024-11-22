#define NUM_FLORES 7
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>//biblioteca para usar getch()

void arte_venda();
void arte_funcoes();
void menu_venda(char **flores, int *quantidade, int *quantidade_buque, int *buque_pronto);
void vendaFlores(int *quantidade);
void vendaBuque(int *quantidade_buque, int *buque_pronto);
void vendaPlantas();
void casoZero(char **flores, int *quantidade, int *quantidade_buque, int *buque_pronto);


void arte_venda(){
	printf("\n");
	printf("\t		Floricultura Jardim das Abelhas\n");
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

void arte_funcoes(){
	system("cls");
	printf("========================================================================================================================\n");
	printf(" __/)      °  |        o     __/)     °   |        o     __/)       ° |        o     __/)       ° |        o     __/) \n");
	printf("(__(=:        |     .       (__(=:        |     .       (__(=:        |      .      (__(=:        |     .       (__(=: \n");
	printf("   \\)         |   °            \\)         |   °            \\)         |    °           \\)         |   °            \\)\n");
	printf("       .      *       .           .       *       .              .    *        .              .   *       .     \n");
	printf("   °.       (\\__	      °         (\\__              °        (\\__	              °         (\\__	          °  \n");
	printf("           :=)__)  o            .      :=)__)    o           .    :=)__)   o              .    :=)__)   o            .\n");
	printf("            (/          *               (/            *            (/            *              (/            *     \n");
	printf(" °. 	.     °               °.          °              °.          °               °.           °                 °. \n");
	printf("========================================================================================================================\n");
}


void menu_venda(char **flores, int *quantidade, int *quantidade_buque, int *buque_pronto){
	int i, opcaoV, pagamento;
	
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
            	vendaFlores(quantidade);
                break;
            case 2:
                vendaBuque(quantidade_buque, &buque_pronto);
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
            	casoZero(flores, quantidade, quantidade_buque, &buque_pronto);
            	break;
            default:
            	arte_menu();
                printf("\n\t OPÇÃO INVÁLIDA! DIGITE NOVAMENTE: ");
                break;
        }
    } while(opcaoV != 0); 
    
    casoZero(flores, quantidade, quantidade_buque, &buque_pronto);
    
    printf("\t |            		                                      | \n ");
	printf("\t |         =========== FORMA DE PAGAMENTO ===========         | \n");
	printf("\t |------------------------------------------------------------| \n");
	printf("\t |  [1] Cartão de débito                                      | \n");
	printf("\t |  [2] Cartão de crédito                                     | \n");
	printf("\t |  [3] Dinheiro                                              | \n");
	printf("\t |  [4] PIX	                                              | \n");
	printf("\t |            		                                      | \n ");
	printf("\t | Opção de pagamento: ");
	scanf("%d", &pagamento);
	
}

void vendaFlores(int *quantidade){
	int i, op_flores, quant_flor;
	//const char *nomes[NUM_FLORES] = {"Lírios", "Rosas", "Girassóis", "Violetas", "Orquídeas", "Astromélias", "Tulipas"};
	
	//Preenchendo o vetor nome com o nome das flores
	//for (i = 0; i < NUM_FLORES; i++) {
    //    	strcpy(flores[i], nomes[i]); 
    //	}
    //fazer um vetor que armazene só as flores escolhidas, e adicionar os valores, talvez struct
	printf("\t |            		                                      | \n ");
	printf("\t |            		                                      | \n ");
	printf("\t |               =========== FLORES ===========               | \n");
	printf("\t |------------------------------------------------------------| \n");
	printf("\t |                     CANTEIRO DA SEMANA                     | \n");
	printf("\t |------------------------------------------------------------| \n");
	printf("\t |  [1] Rosas                                                 | \n");
	printf("\t |  [2] Lírios                                                | \n");
	printf("\t |  [3] Tulipas          		                      | \n");
	printf("\t |  [4] Astromélias	                                      | \n");
	printf("\t |  [5] Orquídeas          		                      | \n");
	printf("\t |  [6] Violetas          		                      | \n");
	printf("\t |  [7] Girassóis             		                      | \n");
	printf("\t |                                                            | \n");
	
	do{
		printf("\t | Selecione a flor desejada (0 para finalizar): ");
		scanf("%d", &op_flores);	
		
		if (op_flores == 0) {
                break; // Finaliza o pedido
            	}

            if (op_flores >= 1 && op_flores <= NUM_FLORES) {
            	printf("\t | Quantidade: ");
	            scanf("%d", &quant_flor);
	            
				quantidade[op_flores - 1] += quant_flor; //atualiza a quantidade na struct
				
            } else {
            	printf("\t |            		                                      | \n ");
	            printf("\t | Opção inválida! Digite Novamente.                         |");
            }
            
	} while (op_flores != 0); 	
}

void vendaBuque(int *quantidade_buque, int *buque_pronto){
	int opcaoB, quantidade, tipo_flor;
	
	do{
		printf("\t |            		                                      | \n ");
		printf("\t |            		                                      | \n ");
		printf("\t |               =========== BUQUÊS ===========               | \n");
		printf("\t |------------------------------------------------------------| \n");
		printf("\t |  [1] Buquê Personalizado                                   | \n");
		printf("\t |  [2] Buquês Prontos                                        | \n");
		printf("\t |                                                            | \n");
		printf("\t | Escolha uma opção (0 para finalizar): ");
		scanf("%d", &opcaoB);
	
		if (opcaoB == 0) {
			break;
		}
    
	    if (opcaoB == 1) {
	    	printf("\t |                                                            | \n");
	    	printf("\t |                                                            | \n");
	    	printf("\t |         =========== BUQUÊ PERSONALIZADO ===========        | \n");
		    printf("\t |------------------------------------------------------------| \n");
			printf("\t |                     CANTEIRO DA SEMANA                     | \n");
			printf("\t |------------------------------------------------------------| \n");
			printf("\t |  [1] Rosas                                                 | \n");
			printf("\t |  [2] Lírios                                                | \n");
			printf("\t |  [3] Tulipas          		                      | \n");
			printf("\t |  [4] Astromélias          		                      | \n");
			printf("\t |                                                            | \n");
	    	do{
				printf("\t | Selecione a flor desejada (0 para finalizar): ");
	        	scanf("%d", &tipo_flor);  // Armazena a escolha do tipo de flor
	        	
	        	if (tipo_flor == 0) {
	        		break;  
				}
	        	
	        	if (tipo_flor >= 1 && tipo_flor <= 4) {
		            printf("\t | Quantidade: ");
		            scanf("%d", &quantidade); 
		            quantidade_buque[tipo_flor - 1] += quantidade;  //adiciona ao vetor de quantidade
		        } else {
		        	printf("\t |            		                                      | \n ");
		            printf("\t | Opção inválida! Digite novamente.                        |");
				}
			} while(opcaoB != 0);
			
    	} else if (opcaoB == 2) {
    		printf("\t |                                                            | \n");
	    	printf("\t |                                                            | \n");
	    	printf("\t |            =========== BUQUÊS PRONTOS ===========          | \n");
		    printf("\t |------------------------------------------------------------| \n");
			printf("\t |  [1] Buquê Rosas Vermelhas                                 | \n");
			printf("\t |  [2] Buquê Rosas Amarelas                                  | \n");
			printf("\t |  [3] Buquê Rosas com Girassol        		      | \n");
			printf("\t |  [4] Buquê Campestre         		              | \n");
			printf("\t |  [5] Buquê Astromélias         		              | \n");
			printf("\t |                                                            | \n");
			printf("\t | Selecione o buquê desejado (0 para finalizar): ");
			scanf("%d", &buque_pronto);
		} else{
			printf("\t |            		                                      | \n ");
            printf("\t | Opção inválida! Tente novamente.                  |");
            scanf("%d", &buque_pronto);
		}
    } while(opcaoB != 0);
	
}

void vendaPlantas(){
	
}

void casoZero(char **flores, int *quantidade, int *quantidade_buque, int *buque_pronto){
	int i, total = 0, pagamento;
    	
	system("cls");
	arte_venda();
	/* 
	printf("\t |            		                                      | \n ");
	printf("\t |         =========== FORMA DE PAGAMENTO ===========         | \n");
	printf("\t |------------------------------------------------------------| \n");
	printf("\t |  [1] Cartão de débito                                      | \n");
	printf("\t |  [2] Cartão de crédito                                     | \n");
	printf("\t |  [3] Dinheiro                                              | \n");
	printf("\t |  [4] PIX	                                              | \n");
	printf("\t | Opção de pagamento: ");
	scanf("%d", &pagamento);
 */
	//if (pagamento >= 1 && pagamento <= 4){
		printf("\t  ____________________________________________________________ \n");
		printf("\t |            		                                      | \n ");
		printf("\t |              Venda finalizada! Resumo do pedido:           | \n");
		printf("\t |------------------------------------------------------------| \n");
	
		//flores individuais
	    for (i = 0; i < NUM_FLORES; i++) {
	        if (quantidade[i] > 0) { 
	        	printf("\t |  -> FLORES INDIVIDUAIS:                                  | \n");
	            printf("\t | - %s: %d unidades\n", flores[i], quantidade[i]);
	            total += quantidade[i]; // soma o total de flores compradas
	        }
	    }
	    
	    //buquê personalizado
	    for (i = 0; i < 4; i++) {
	        if (quantidade_buque[i] > 0) { 
	        
	        	printf("\t |  Buquê personalizado:                                  | \n");
	            printf("\t | - %s: %d unidades\n", flores[i], quantidade_buque[i]);
	            total += quantidade_buque[i]; 
	        }
	    }
	    
	    //buquê pronto
	    if (*buque_pronto > 0) {
	        printf("\t |  Buquê pronto:                                  | \n");
	        if(*buque_pronto == 1)
	        	printf("\t |  Buquê Rosas Vermelhas                                 | \n");
	        else if (*buque_pronto == 2)
	        	printf("\t |  Buquê Rosas Amarelas                                  | \n");
	        else if (*buque_pronto == 3)
	        	printf("\t |  Buquê Rosas com Girassol                              | \n");
	        else if (*buque_pronto == 4)
	        	printf("\t |  Buquê Astromélias                                     | \n");
	        else
	        	printf("\t |  Buquê Campestre                                       | \n");		
	        total++; // Adiciona o buquê pronto ao total
    	}
	    
	    printf("\t |  Total de itens: %d                              | \n", total);
	    printf("\t |  Obrigado pela compra!                             | \n");

	    //Sleep(10000);
	    //sair = 1;	
	//}
	
}
