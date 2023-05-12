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
    printf("%c",204);
    for(int i=0; i<87; i++){
        printf("%c",205);
    }
    printf("%c",185);
}
void verificacao_senha(int senha){
    int tent_senha = 0,qntd_tent_senha = 0,flag_senha = 0;
    do{
        if(qntd_tent_senha == 1){
            printf("%c",186); //Moldura
            printf("Senha incorreta, voce tem mais DUAS tentativas!!!");
        }else if(qntd_tent_senha == 2){
            printf("%c",186); //Moldura
            printf("Senha incorreta, voce tem mais UMA tentativas!!!");
        }
        printf("\n%c",186); //Moldura
        printf("Digite a sua senha para abrir o caixa:                                                 ");
        printf("%c",186); //Moldura
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");//Moldura
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
    //Terceiro passo
    int qntd_200 = 0,qntd_100 = 0, qntd_50 = 0,qntd_10 = 0,qntd_5 = 0,qntd_1 = 0,qntd_050 = 0;
    float valor_pago, troco, valor_troco=0;
    printf("\nValor total da compra: %.2f", soma_valor);
    do{
        printf("\nInsira o valor pago : R$");
        scanf("%f",&valor_pago);
        if(valor_pago < soma_valor){
            printf("Valor inserido menor do que o valor total da compra, digite novamente por favor!!");
        }
    }while(valor_pago < soma_valor);
    troco = valor_pago-soma_valor;
    if(troco != soma_valor){
        do{
            if(troco >= 0 && moeda_50 >=1){
                if(troco >= 1 && moeda_1 >=1){
                    if(troco >= 5 && nota_5 >=1){
                        if(troco >= 10 && nota_10 >=1){
                            if(troco >= 50 && nota_50 >=1){
                                if(troco >= 100 && nota_100 >=1){
                                    if(troco >=200 && nota_200 >=1){
                                        troco -=200;
                                        nota_200--;
                                        qntd_200++;
                                        valor_troco +=200;
                                    }else{
                                        troco -=100;
                                        nota_100--;
                                        qntd_100++;
                                        valor_troco +=100;
                                    }
                                }else{
                                    troco -=50;
                                    nota_50--;
                                    qntd_50++;
                                    valor_troco +=50;
                                }
                            }else{
                                troco -=10;
                                nota_10--;
                                qntd_10++;
                                valor_troco +=10;
                            }
                        }else{
                            troco-=5;
                            nota_5--;
                            qntd_5++;
                            valor_troco +=5;
                        }
                    }else{
                        troco-=1;
                        moeda_1--;
                        qntd_1++;
                        valor_troco +=1;
                    }
                }else{
                    troco -= 0.5;
                    moeda_50--;
                    qntd_050++;
                    valor_troco +=0.5;
                }
            }
        }while(troco > 0);
        printf("\nO troco será: R$%.2f", valor_troco);
        printf("\n200 %d",qntd_200);
        printf("\n100 %d",qntd_100);
        printf("\n50 %d",qntd_50);
        printf("\n10 %d",qntd_10);
        printf("\n5 %d",qntd_5);
        printf("\n1 %d",qntd_1);
        printf("\n0.50 %d",qntd_050);
    }else{
    printf("\nNao precisa de troco!");
    }
    return 0;
}
