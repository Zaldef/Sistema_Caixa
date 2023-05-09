// 	╬ 206, ═ 205, ╠ 204, ╦ 203, ╩ 202, ╔ 201, ╚ 200, ╝ 188, ╗ 187, ║ 186, ╣ 185
// Evitar colocar em tela cheia e depois minimizar
    /*printf("Carregando");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".\n");*/
    // tela inicial
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
/*#include <unistd.h> // função sleep */
void moldura_inicial(){
    printf("%c",201);
    for(int i=0; i<87; i++){
        printf("%c",205);
    }
    printf("%c\n",187);
    printf("%c",186);
    printf("                                     Bem vindo !!!                                     ");
    printf("%c\n",186);
    printf("%c",204);
    for(int i=0; i<87; i++){
        printf("%c",205);
    }
    printf("%c\n",185);
}
void verificacao_senha(int senha,int tent_senha,int qntd_tent_senha,int flag_senha){
    do{
    printf("%c",186);
    printf("Digite a sua senha para abrir o caixa:                                      ");
    printf("%c",186);
    gotoxy(10,5);
    scanf("%d",&tent_senha);

    if(tent_senha == senha){
        flag_senha++;
    }else{
        qntd_tent_senha++;
        }
    }while(flag_senha == 0 || qntd_tent_senha>=3);
    printf("%d",qntd_tent_senha);
    printf("%d",flag_senha);
}
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char ch = '*';
    int x = 10, y = 5;
    moldura_inicial();
    verificacao_senha(2323,0,0,0);
    move(x, y);
    printf("%c\n",186);


    return 0;
}
