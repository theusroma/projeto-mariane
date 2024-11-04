#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Protótipos
void arte_menu();
// End Protótipos


void arte_menu(){
    printf("\n\n");
    printf("\t		Bem Vindo(a) ao Jardim das Abelhas!\n");
    printf("\t		      	  	       __\n");
    printf("\t      		       .' '.          // \\  \n");
    printf("\t            .          .   .          \\\\_/ //\n");
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

int main (){
	system("color 0E");
	arte_menu();
	
	return 0;
}
