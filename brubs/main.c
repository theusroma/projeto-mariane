#define NUM_FLORES 7
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>//biblioteca para usar getch()

// Minhas bibliotecas
#include "animacao.h" //animação inicial e artes
#include "venda.h"
#include "funcoes.h"


// Protótipos
void arte_menu();
void menu_principal();
void cadastrarCliente();
void removerCPF();
void consulta();
void lista_ordenada();
void desativar();
void menu_venda(char **flores, char **buques, char **sementes, char **plantas, char **itens, int *quantidade, int *quantidade_buque, int *quantidade_plantas, int *quantidade_sem, int *quantidade_item);
// End Protótipos
	

int main (){
	setlocale(LC_ALL, "Portuguese");
	system("color 0E");
	
	const char *nomesF[NUM_FLORES] = {"Rosas", "Lírios", "Tulipas", "Astromélias", "Orquídeas", "Violetas", "Girassóis"};
	const char *nomesB[5] = {"Rosas Vermelhas", "Rosas Amarelas", "Rosas com Girassol", "Buquê Campestre", "Buquê Astromélias"};
	const char *nomesP[NUM_FLORES] = {"Suculentas", "Cactos", "Samabaias", "Buxinhos", "Bromélias", "Dracenas", "Lavandas"};
	const char *nomesS[5] = {"Morango", "Tomate", "Pimenta Biquinho", "Cenoura", "Flores Sortidas"};
	const char *nomesI[5] = {"Terra 5kg", "Terra 10kg", "Humus 2kg", "Vaso pequeno", "Vaso médio"};
	
	char opcaoM, **flores, **plantas, **itens, **buques, **sementes;
	int i, *quantidade, *quantidade_buque, *quantidade_plantas, *quantidade_sem, *quantidade_item;
	
	//alocação dinâmica para o vetor de nomes de flores
	flores = (char **) malloc(NUM_FLORES * sizeof(char *));
	for (i = 0; i < NUM_FLORES; i++) {
        flores[i] = (char *)malloc(20 * sizeof(char)); 
        strcpy(flores[i], nomesF[i]); //preenchendo o vetor flores com o nome das flores
    }
    
    buques = (char **) malloc(5 * sizeof(char *));
	for (i = 0; i < 5; i++) {
        buques[i] = (char *)malloc(20 * sizeof(char)); 
        strcpy(buques[i], nomesB[i]); 
    }
    
    plantas = (char **) malloc(NUM_FLORES * sizeof(char *));
	for (i = 0; i < NUM_FLORES; i++) {
        plantas[i] = (char *)malloc(20 * sizeof(char)); 
        strcpy(plantas[i], nomesP[i]); 
    }
    
    itens = (char **) malloc(5 * sizeof(char *));
	for (i = 0; i < 5; i++) {
        itens[i] = (char *)malloc(20 * sizeof(char)); 
        strcpy(itens[i], nomesI[i]); 
    }
    
    sementes = (char **) malloc(5 * sizeof(char *));
	for (i = 0; i < 5; i++) {
        sementes[i] = (char *)malloc(20 * sizeof(char)); 
        strcpy(sementes[i], nomesS[i]); 
    }
    
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
			cadastrarCliente();
			Sleep(2000);
			break;
		
		case '2':
			removerCPF();
			Sleep(2000);
			break;
		
		case '3':
			consulta();
			Sleep(5000);
			break;
		
		case '4':
			lista_ordenada();
			Sleep(5000);
			break;
		
		case '5':
			desativar();
			Sleep(1000);
			break;
	
		case '6':
			menu_venda(flores, buques, plantas, sementes, itens, quantidade, quantidade_buque, quantidade_plantas, quantidade_sem, quantidade_item);
			break;
			
		case '7':
			printf("\n\t Saindo...");
			Sleep(1500);
			break;
 	
		default:
			arte_menu();
			menu_principal();
			printf("\n\t OPÇÃO INVÁLIDA! PRESSIONE QUALQUER TECLA: ");
			opcaoM = getch();
			//system("cls");
		}
	
	} while (opcaoM != '7');
	
	 // liberação de memória de cada string
    for (i = 0; i < NUM_FLORES; i++) {
        free(flores[i]); // libera cada string
    }
    for (i = 0; i < 5; i++) {
        free(buques[i]); 
    }
    for (i = 0; i < NUM_FLORES; i++) {
        free(plantas[i]); 
    }
	for (i = 0; i < 5; i++) {
        free(sementes[i]); 
    }
	for (i = 0; i < 5; i++) {
        free(itens[i]); 
    }
	
	// liberar memória alocada
	free(flores); 
	free(buques);
	free(plantas);
	free(sementes);
	free(itens);
	free(quantidade);
	free(quantidade_buque);
	free(quantidade_plantas);
	free(quantidade_sem);
	free(quantidade_item);
	
	return 0;
}
