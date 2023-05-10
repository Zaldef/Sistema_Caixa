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
void verificacao_senha(int senha){
    int tent_senha = 0,qntd_tent_senha = 0,flag_senha = 0;
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
        /*for(int i=0;i<3;i++){
            sleep(1);
            printf(".");
        }*/
        system("cls");
    }
}
float leitura_vendas(){
    float soma_valor = 0,valor_produto = 0,valor_produto_anterior = 0;
    char resposta = 0;
    int i=0,flag_valor=0;
    printf("\nVALORES DOS ITENS VENDIDOS: ");
    do{
        if(flag_valor == 1){
            printf("\nCorrija o valor do item %d: R$", i);
            scanf("%f", &valor_produto);
            }else{
                i++;
                printf("\nDigite o valor do item %d: R$", i);
                scanf("%f", &valor_produto);
            }
        if(valor_produto>0){
            flag_valor = 0;
            soma_valor += valor_produto;
            }else if(valor_produto<0){
                soma_valor -= valor_produto_anterior;
                i--;
                flag_valor = 1;
            }else{
                i--;
                printf("\nDeseja finalizar a compra?(SIM-S/NAO-N)");
                getchar();
                scanf("%c", &resposta);
                getchar();
            }
        valor_produto_anterior = valor_produto;
    }while(resposta != 'S');
    printf("\nValor total: R$%2.f", soma_valor);
    printf("\nVenda finalizada com %d itens", i);
    return soma_valor;
}
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    moldura_inicial();
    verificacao_senha(2323);
    float nota_200 = 2, nota_100 = 4, nota_50 = 6, nota_10 = 10, nota_5 = 10, moeda_1 = 20, moeda_50 = 20, soma_valor;
    soma_valor=leitura_vendas();
    printf("Soma_Valor: %.2f", soma_valor);
    return 0;
}
