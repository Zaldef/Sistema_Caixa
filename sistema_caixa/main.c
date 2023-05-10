#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
void moldura_inicial(){
    printf("%c",201);
    for(int i=0; i<87; i++){
        printf("%c",205);
    }
    printf("%c\n",187);
    printf("%c",186);
    printf("                                     Bem vindo !!!                                     ");
    printf("%c\n",186);
    printf("%c",200);
    for(int i=0; i<87; i++){
        printf("%c",205);
    }
    printf("%c",188);
}
int verificacao_senha(int senha,int tent_senha,int qntd_tent_senha,int flag_senha){
    do{
        if(qntd_tent_senha == 1){
            printf("Senha incorreta, voce tem mais DUAS tentativas!!!");
        }else if(qntd_tent_senha == 2){
            printf("Senha incorreta, voce tem mais UMA tentativas!!!");
        }
        printf("\nDigite a sua senha para abrir o caixa: ");
        scanf("%d",&tent_senha);
        if(tent_senha == senha){
            flag_senha++;
            break;
        }else{
            qntd_tent_senha++;
        }
    }while(qntd_tent_senha<3);
    if(qntd_tent_senha == 3){
        printf("Sistema precisa ser reinicializado !!");
        exit(1);
    }else{
        printf("Senha correta!!!\n");
        printf("Abrindo caixa");
        for(int i=0;i<3;i++){
            sleep(1);
            printf(".");
        }
        system("cls");
    }
}
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    moldura_inicial();
    verificacao_senha(2323,0,0,0);
    float nota_200 = 2, nota_100 = 4, nota_50 = 6, nota_10 = 10, nota_5 = 10, moeda_1 = 20, moeda_50 = 20, valor_produto = 0, valor_anterior = 0, soma_valor = 0;
    int i = 1;
    char resposta = 0;
    
    do{
        printf("\nVALORES DOS ITENS VENDIDOS: ");
        printf("\nDigite o valor do item %d", i);
        scanf("%f", &valor_produto);
        
        if (valor_produto < 0){
            soma_valor -= valor_anterior;
        }else{
            valor_anterior = valor_produto;
            soma_valor += valor_produto;
        }
    }while(resposta != S );
    return 0;
}
