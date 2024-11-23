// Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <windows.h>
#include <unistd.h> // Para usar a função 'usleep'

void anima(){Sleep(60);} //Delay
void arte_menu();


void move(){
	Sleep(40);
}

// Protótipo
void nome();

void nome() {
    printf(" ________   .---.       ,-----.     .-------.   .-./`)     _______     ___    _   .---. ,---------.   ___    _ .-------.       ____     \n"); Sleep(40);
    printf("|        |  | ,_|     .'  .-,  '.   |  _ _   \\  \\ .-.')   /   __  \\  .'   |  | |  | ,_| \\          \\'   |  | ||  _ _   \\    .'  __ `.  \n"); Sleep(40);
    printf("|   .----',-./  )    / ,-.|  \\ _ \\  | ( ' )  |  / `-' \\  | ,_/  \\__) |   .'  | |,-./  )  `--.  ,---'|   .'  | || ( ' )  |   /   '  \\  \\ \n"); Sleep(40);
    printf("|  _|____ \\  '_ '`) ;  \\  '_ /  | : |(_ o _) /   `-'`'',-./  )       .'   '_ | |\\  '_ '`)   |  \\    | '_    | ||(_ o _) /   |___|  /  | \n"); Sleep(40);
    printf("|_( )_   | > (_)  ) |  _`,/ \\ _/  | | (_,_).' __ .---. \\  '_ '`)     '   ( \\.-.| > (_)  )   :_ _:   '   ( \\.-.|| (_,_).' __    _.-`   | \n"); Sleep(40);
    printf("(_ o._)__|(  .  .-' : (  '\\_/ \\   ; |  |\\ \\  |  ||   |  > (_)  )  __ ' (`. _` /|(  .  .-'   (_I_)   ' (`. _` /||  |\\ \\  |  |.'   _    | \n"); Sleep(40);
    printf("|(_,_)     `-'`-'|___\\ `''/  \\  ) / |  | \\ `'   /|   | (  .  .-'_/  )| (_ (_) _) `-'`-'|___(_(=)_)  | (_ (_) _)|  | \\ `'   /|  _( )_  | \n"); Sleep(40);
    printf("|   |       |        \\'. \\_/``''.'  |  |  \\    / |   |  `-'`-'     /  \\ /  . \\ /  |        \\(_I_)    \\ /  . \\ /|  |  \\    / \\ (_ o _) / \n"); Sleep(40);
    printf("'---'       `--------`  '-----'    ''-'   `'-'  '---'    `._____.'    ``-'`-''   `--------`'---'     ``-'`-'' ''-'   `'-'   '.(_,_).'   \n\n"); Sleep(40);
    
    printf("                             .-./`)     ____    .-------.     ______     .-./`) ,---.    ,---.                                         \n"); Sleep(40);
    printf("                             \\ '_ .') .'  __ `. |  _ _   \\   |    _ `''. \\ .-.')|    \\  /    |                                         \n"); Sleep(40);
    printf("                            (_ (_) _)/   '  \\  \\| ( ' )  |   | _ | ) _  \\/ `-' \\|  ,  \\/  ,  |                                         \n"); Sleep(40);
    printf("                              / .  \\ |___|  /  ||(_ o _) /   |( ''_'  ) | `-'`''|  |\\_   /|  |                                         \n"); Sleep(40);
    printf("                         ___  |-'`|     _.-`   || (_,_).' __ | . (_) `. | .---. |  _( )_/ |  |                                         \n"); Sleep(40);
    printf("                        |   | |   '  .'   _    ||  |\\ \\  |  ||(_    ._) ' |   | | (_ o _) |  |                                         \n"); Sleep(40);
    printf("                        |   `-'  /   |  _( )_  ||  | \\ `'   /|  (_.\\.' /  |   | |  (_,_)  |  |                                         \n"); Sleep(40);
    printf("                         \\      /    \\ (_ o _) /|  |  \\    / |       .'   |   | |  |      |  |                                         \n"); Sleep(40);
    printf("                          `-..-'      '.(_,_).' ''-'   `'-'  '-----'`     '---' '--'      '--'                                         \n\n"); Sleep(40);
    
    printf("                                                 ______        ____       .-'''-.                                                      \n"); Sleep(40);
    printf("                                                |    _ `''.  .'  __ `.   / _     \\                                                     \n"); Sleep(40);
    printf("                                                | _ | ) _  \\/   '  \\  \\ (`' )/`--'                                                     \n"); Sleep(40);
    printf("                                                |( ''_'  ) ||___|  /  |(_ o _).                                                        \n"); Sleep(40);
    printf("                                                | . (_) `. |   _.-`   | (_,_). '.                                                      \n"); Sleep(40);
    printf("                                                |(_    ._) '.'   _    |.---.  \\  :                                                     \n"); Sleep(40);
    printf("                                                |  (_.\\.' / |  _( )_  |\\    `-'  |                                                     \n"); Sleep(40);
    printf("                                                |       .'  \\ (_ o _) / \\       /                                                      \n"); Sleep(40);
    printf("                                                '-----'`     '.(_,_).'   `-...-'                                                       \n\n"); Sleep(40);
    
    printf("                           ____     _______       .-''-.    .---.     .---.  .---.    ____       .-'''-.                               \n"); Sleep(40);
    printf("                         .'  __ `. \\  ____  \\   .'_ _   \\   | ,_|     |   |  |_ _|  .'  __ `.   / _     \\                              \n"); Sleep(40);
    printf("                        /   '  \\  \\| |    \\ |  / ( ` )   ',-./  )     |   |  ( ' ) /   '  \\  \\ (`' )/`--'                              \n"); Sleep(40);
    printf("                        |___|  /  || |____/ / . (_ o _)  |\\  '_ '`)   |   '-(_{;}_)|___|  /  |(_ o _).                                 \n"); Sleep(40);
    printf("                           _.-`   ||   _ _ '. |  (_,_)___| > (_)  )   |      (_,_)    _.-`   | (_,_). '.                               \n"); Sleep(40);
    printf("                        .'   _    ||  ( ' )  \\'  \\   .---.(  .  .-'   | _ _--.   | .'   _    |.---.  \\  :                              \n"); Sleep(40);
    printf("                        |  _( )_  || (_{;}_) | \\  `-'    / `-'`-'|___ |( ' ) |   | |  _( )_  |\\    `-'  |                              \n"); Sleep(40);
    printf("                        \\ (_ o _) /|  (_,_)  /  \\       /   |        \\(_{;}_)|   | \\ (_ o _) / \\       /                               \n"); Sleep(40);
    printf("                         '.(_,_).' /_______.'    `'-..-'    `--------`'(_,_) '---'  '.(_,_).'   `-...-'                                \n\n"); Sleep(40);
}

void arte_menu(){
	system("cls");
	printf("\n");
	printf("\t		Bem Vindo(a) ao Jardim das Abelhas!\n");
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

void menu_principal(){
	printf("\n");
	printf("\t(\\o/)_______________________________________________________(\\o/) \n");
	printf("\t(/|\\)                                                       (/|\\) \n");
	printf("\t  |  [1] CADASTRAR NOVO CLIENTE                               | \n");
	printf("\t  |  [2] REMOVER CLIENTE                                      | \n");
	printf("\t  |  [3] CONSULTAR CLIENTE                                    | \n");
	printf("\t  |  [4] LISTAR CLIENTES                                      | \n");
	printf("\t  |  [5] DESATIVAR CLIENTE	                              | \n");
	printf("\t  |  [6] VENDA          		                      | \n");
	printf("\t  |  [7] SAIR          		                              | \n");
	printf("\t(\\o/)_______________________________________________________(\\o/) \n");
	printf("\t(/|\\)                                                       (/|\\) \n");
}
