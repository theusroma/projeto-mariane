#define NUM_FLORES 7
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>//biblioteca para usar getch()

void arte_venda();
void arte_funcoes();
void menu_venda(char **flores, char **buques, char **sementes, char **plantas, char **itens, int *quantidade, int *quantidade_buque, int *quantidade_plantas, int *quantidade_sem, int *quantidade_item);
void vendaFlores(int *quantidade);
void vendaBuque(int *quantidade_buque);
void vendaPlantas(int *quantidade_plantas, int *quantidade_sem);
void vendaItens(int *quantidade_item);
void resumoPedido(char **flores, char **buques, char **sementes, char **plantas, char **itens, int *quantidade, int *quantidade_buque, int *quantidade_plantas, int *quantidade_sem, int *quantidade_item);


void arte_venda(){
	printf("\n");
	printf("\t		Floricultura Jardim das Abelhas\n");
	printf("\t		      	  	       __\n");
	printf("\t    		       .' '.          // \\  \n");
	printf("\t            .          .   .          \\\\_/ //\n");
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


void menu_venda(char **flores, char **buques, char **plantas, char **sementes, char **itens, int *quantidade, int *quantidade_buque, int *quantidade_plantas, int *quantidade_sem, int *quantidade_item){
	int i, op_V, pagamento;
	
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
		printf("\t |  [2] Buquês                                                | \n");
		printf("\t |  [3] Outras plantas                                        | \n");
		printf("\t |  [4] Itens	                                              | \n");
		printf("\t |  [5] Voltar                                                | \n");
		printf("\t |            		                                      | \n ");
		printf("\t | Digite a opção de venda (0 para finalizar): ");
		scanf("%d", &op_V);
		
        switch(op_V) {
            case 1:
            	vendaFlores(quantidade);
                break;
            case 2:
                vendaBuque(quantidade_buque);
                break;
            case 3:
                vendaPlantas(quantidade_plantas, quantidade_sem);
                break;
            case 4:
                vendaItens(quantidade_item);
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
                //break;
                return;
            default:
            	arte_menu();
                printf("\n\t OPÇÃO INVÁLIDA! DIGITE NOVAMENTE: ");
                break;
        }
    } while(op_V != 0); 
    
    resumoPedido(flores, buques, plantas, sementes, itens, quantidade, quantidade_buque, quantidade_plantas, quantidade_sem, quantidade_item);
    
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
	
	if(pagamento < 1 && pagamento > 4){
		printf("\t |            		                                      | \n ");
	    printf("\t | Opção inválida! Digite Novamente.                         |");
	}
	
	system("cls");
	arte_venda();
	printf("\t(\\o/)_______________________________________________________(\\o/) \n");
	printf("\t(/|\\)        		                                    (/|\\) \n");
	printf("\t  |	      Obrigado pela compra! Volte sempre!             | \n");
	printf("\t(\\o/)_______________________________________________________(\\o/) \n");
	printf("\t(/|\\)                                                       (/|\\) \n");
	Sleep(6000);
}                                                                             

void vendaFlores(int *quantidade){
	int i, op_flores, quant_flor;
	
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

void vendaBuque(int *quantidade_buque){
	int quantidade, tipoBuque;
	
	printf("\t |                                                            | \n");
	printf("\t |                                                            | \n");
	printf("\t |             =========== BUQUÊS ===========                 | \n");
    printf("\t |------------------------------------------------------------| \n");
	printf("\t |  [1] Rosas Vermelhas                                       | \n");
	printf("\t |  [2] Rosas Amarelas                                        | \n");
	printf("\t |  [3] Rosas com Girassol         		              | \n");
	printf("\t |  [4] Buquê Campestre         		              | \n");
	printf("\t |  [5] Buquê Astromélias         		              | \n");
	printf("\t |                                                            | \n");
		
	do{	
		printf("\t | Selecione o buquê desejado (0 para finalizar): ");
		scanf("%d", &tipoBuque);
		
		if (tipoBuque == 0) {
	        break; // finaliza o pedido
	    	}
	
	    if (tipoBuque >= 1 && tipoBuque <= 5) {
	    	printf("\t | Quantidade: ");
	        scanf("%d", &quantidade);
	        
			quantidade_buque[tipoBuque - 1] += quantidade; //atualiza a quantidade na struct
	    } else {
	    	printf("\t |            		                                      | \n ");
	        printf("\t | Opção inválida! Digite Novamente.                         |");
	    }
	    
	} while(tipoBuque != 0);
}

void vendaPlantas(int *quantidade_plantas, int *quantidade_sem){
	int i, quantidade, op_P, tipo_planta, tipo_sem;
	
	do{
		printf("\t |            		                                      | \n ");
		printf("\t |            		                                      | \n ");
		printf("\t |               =========== PLANTAS ===========              | \n");
		printf("\t |------------------------------------------------------------| \n");
		printf("\t |  [1] Sementes                                              | \n");
		printf("\t |  [2] Plantas no vaso                                       | \n");
		printf("\t |                                                            | \n");
		printf("\t | Escolha uma opção (0 para finalizar): ");
		scanf("%d", &op_P);
		
		if (op_P == 0) {
			break;
		}
		
		if (op_P == 1){
			printf("\t |            		                                      | \n ");
			printf("\t |            		                                      | \n ");
			printf("\t |              =========== SEMENTES ===========              | \n");
			printf("\t |------------------------------------------------------------| \n");
			printf("\t |  [1] Morango                                               | \n");
			printf("\t |  [2] Tomate                                                | \n");
			printf("\t |  [3] Pimenta Biquinho                                      | \n");
			printf("\t |  [4] Cenoura                                               | \n");
			printf("\t |  [5] Flores Sortidas                                       | \n");
			printf("\t |                                                            | \n");
			
			do{
				printf("\t | Selecione a semente desejada (0 para finalizar): ");
	        	scanf("%d", &tipo_sem); 
	        	
	        	if (tipo_sem == 0) {
	        		break;  
				}
	        	
	        	if (tipo_sem >= 1 && tipo_sem <= 5) {
		            printf("\t | Quantidade: ");
		            scanf("%d", &quantidade); 
		            quantidade_sem[tipo_sem - 1] += quantidade;  //adiciona ao vetor de quantidade
		        } else {
		        	printf("\t |            		                                      | \n ");
		            printf("\t | Opção inválida! Digite novamente.                        |");
				}
			} while(op_P != 0);
			
		} else if (op_P == 2) {
    		printf("\t |            		                                      | \n ");
			printf("\t |            		                                      | \n ");
			printf("\t |               =========== PLANTAS ===========              | \n");
			printf("\t |------------------------------------------------------------| \n");
			printf("\t |  [1] Suculentas                                            | \n");
			printf("\t |  [2] Cactos                                                | \n");
			printf("\t |  [3] Samabaias          		                      | \n");
			printf("\t |  [4] Buxinhos	                                      | \n");
			printf("\t |  [5] Bromélias          		                      | \n");
			printf("\t |  [6] Dracenas          		                      | \n");
			printf("\t |  [7] Lavandas             		                      | \n");
			printf("\t |                                                            | \n");
			
			do{
			printf("\t | Selecione a planta desejada (0 para finalizar): ");
        	scanf("%d", &tipo_planta); 
        	
        	if (tipo_planta == 0) {
        		break;  
			}
        	
        	if (tipo_planta >= 1 && tipo_planta <= NUM_FLORES) {
	            printf("\t | Quantidade: ");
	            scanf("%d", &quantidade); 
	            quantidade_plantas[tipo_planta - 1] += quantidade;  //adiciona ao vetor de quantidade
	        } else {
	        	printf("\t |            		                                      | \n ");
	            printf("\t | Opção inválida! Digite novamente.                        |");
			}
			} while(op_P != 0);
		
		} else{
			printf("\t |            		                                      | \n ");
            printf("\t | Opção inválida! Tente novamente.                  |");
            scanf("%d", &tipo_planta);
		}	
		
	} while(op_P != 0);
}

void vendaItens(int *quantidade_item){
	int quantidade, tipoItem; 

	printf("\t |            		                                      | \n ");
	printf("\t |            		                                      | \n ");
	printf("\t |               =========== ITENS ===========                | \n");
	printf("\t |------------------------------------------------------------| \n");
	printf("\t |  [1] Pacote de terra 5kg                                   | \n");
	printf("\t |  [2] Pacote de terra 10kg                                  | \n");
	printf("\t |  [3] Humus de minhoca 2kg                                  | \n");
	printf("\t |  [4] Vaso pequeno                                          | \n");
	printf("\t |  [5] Vaso médio                                            | \n");
	printf("\t |                                                            | \n");

	do{
		printf("\t | Escolha uma opção (0 para finalizar): ");
		scanf("%d", &tipoItem);	
		  
		if (tipoItem == 0) {
	        break; // finaliza o pedido
	    	}
	
	    if (tipoItem >= 1 && tipoItem <= 5) {
	    	printf("\t | Quantidade: ");
	        scanf("%d", &quantidade);
			quantidade_item[tipoItem - 1] += quantidade; //atualiza a quantidade na struct
	    } else {
	    	printf("\t |            		                                      | \n ");
	        printf("\t | Opção inválida! Digite Novamente.                         |");
	    }
	    
	} while(tipoItem != 0);
}

void resumoPedido(char **flores, char **buques, char **plantas, char **itens, char **sementes, int *quantidade, int *quantidade_buque, int *quantidade_plantas, int *quantidade_sem, int *quantidade_item){
	int i, total = 0, pagamento;
    	
	system("cls");
	arte_venda();
	printf("\t  ____________________________________________________________ \n");
	printf("\t |            		                                      | \n ");
	printf("\t |             VENDA FINALIZADA! Resumo do pedido:            | \n");
	printf("\t |------------------------------------------------------------| \n");
	
	printf("\t |-> FLORES:                                                  | \n");
	for (i = 0; i < NUM_FLORES; i++) {
		if (quantidade[i] > 0) {
        	printf("\t | - %s: %d unidades\n", flores[i], quantidade[i]);
        	total += quantidade[i]; // soma o total de flores compradas
        }
    }
    printf("\t |------------------------------------------------------------| \n");    	
    
    printf("\t |-> BUQUÊS:                                                  | \n");
    for (i = 0; i < 5; i++) {
		if (quantidade_buque[i] > 0) { 
        	printf("\t | - %s: %d unidades\n", buques[i], quantidade_buque[i]);
        	total += quantidade_buque[i];
    	}
	}
	printf("\t |------------------------------------------------------------| \n");	
	
	printf("\t |-> PLANTAS:                                                 | \n");
	for (i = 0; i < NUM_FLORES; i++) {
		if (quantidade_plantas[i] > 0) { 
        	printf("\t | - %s: %d unidades\n", plantas[i], quantidade_plantas[i]);
        	total += quantidade_plantas[i]; 
		}
	}
	printf("\t |------------------------------------------------------------| \n");	
	
	printf("\t |-> SEMENTES:                                                | \n");
	for (i = 0; i < 5; i++) {
		if (quantidade_sem[i] > 0) { 
            printf("\t | - %s: %d unidades\n", sementes[i], quantidade_sem[i]);
            total += quantidade_sem[i]; 
    	}	
    }
    printf("\t |------------------------------------------------------------| \n");
    
    printf("\t |-> ITENS:                                                   | \n");
    for (i = 0; i < 5; i++) {
    	if (quantidade_item[i] > 0) { 
            printf("\t | - %s: %d unidades\n", itens[i], quantidade_item[i]);
            total += quantidade_item[i]; 
    	}
	}
	
	printf("\t |------------------------------------------------------------| \n");
    printf("\t |                                                            | \n");
    printf("\t |-> TOTAL DE ITENS: %d                                        | \n", total);
}
