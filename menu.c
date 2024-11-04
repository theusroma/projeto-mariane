#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Protótipos
void arte_menu();
void menu_principal();
// End Protótipos


void arte_menu(){
    printf("\n\n");
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
    printf("\n\n");
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
	
    arte_menu();
    printf("\n\t DIGITE A OPÇÃO DESEJADA: ");
    menu_principal();
	
    return 0;
}
