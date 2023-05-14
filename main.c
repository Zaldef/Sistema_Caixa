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
} // Mensagem de bem vindo com moldura de barra dupla
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
        printf("Senha Incorreta !!!\nSistema precisa ser reinicializado !!");
        exit(1);
    }else{
        printf("Senha correta!!!\n");
        printf("Abrindo caixa");
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
    system("cls");
    printf("\nVenda finalizada com %d itens", i);
    return soma_valor;
}
void troco(float soma_valor,int *moeda_50,int *moeda_1,int *nota_5,int *nota_10,int *nota_50,int *nota_100,int *nota_200, int *semtroco_flag){
    int qntd_200 = 0,qntd_100 = 0, qntd_50 = 0,qntd_10 = 0,qntd_5 = 0,qntd_1 = 0,qntd_050 = 0;
    float valor_pago, troco, valor_troco=0;
    do{
        printf("\nInsira o valor pago : R$");
        scanf("%f",&valor_pago);
        if(valor_pago < soma_valor){
            printf("Valor inserido menor do que o valor total da compra, digite novamente por favor!!");
        }
    }while(valor_pago < soma_valor);
    troco = valor_pago-soma_valor;
    if(troco == 0){
        printf("\nNao precisa de troco!");
    }else{
        do{
            if(troco >= 0 && *moeda_50 >=1){
                if(troco >= 1 && *moeda_1 >=1){
                    if(troco >= 5 && *nota_5 >=1){
                        if(troco >= 10 && *nota_10 >=1){
                            if(troco >= 50 && *nota_50 >=1){
                                if(troco >= 100 && *nota_100 >=1){
                                    if(troco >=200 && *nota_200 >=1){
                                        troco -=200;
                                        *nota_200--;
                                        qntd_200++;
                                        valor_troco +=200;
                                    }else{
                                        troco -=100;
                                        *nota_100--;
                                        qntd_100++;
                                        valor_troco +=100;
                                    }
                                }else{
                                    troco -=50;
                                    *nota_50--;
                                    qntd_50++;
                                    valor_troco +=50;
                                }
                            }else{
                                troco -=10;
                                *nota_10--;
                                qntd_10++;
                                valor_troco +=10;
                            }
                        }else{
                            troco-=5;
                            *nota_5--;
                            qntd_5++;
                            valor_troco +=5;
                        }
                    }else{
                        troco-=1;
                        *moeda_1--;
                        qntd_1++;
                        valor_troco +=1;
                    }
                }else{
                    troco -= 0.5;
                    *moeda_50--;
                    qntd_050++;
                    valor_troco +=0.5;
                }
            }
        if( troco > 0 && moeda_50 ==0){
            *semtroco_flag = 1;
            break;
        }
        }while(troco > 0);
        printf("\nO troco sera de: R$%.2f", valor_troco);
        if(qntd_200 != 0){
            if(qntd_200 == 1){
                printf("\n\t%d nota de R$200",qntd_200);
            }else{
                printf("\n\t%d notas de R$200",qntd_200);
            }
        }
        if(qntd_100 != 0){
            if(qntd_100 == 1){
                printf("\n\t%d nota de R$100",qntd_100);
            }else{
                printf("\n\t%d notas de R$100",qntd_100);
            }
        }
        if(qntd_50 != 0){
            if(qntd_50 == 1){
                printf("\n\t%d nota de R$50",qntd_50);
            }else{
                printf("\n\t%d notas de R$50",qntd_50);
            }
        }
        if(qntd_10 != 0){
            if(qntd_10 == 1){
                printf("\n\t%d nota de R$10",qntd_10);
            }else{
                printf("\n\t%d notas de R$10",qntd_10);
            }
        }
        if(qntd_5 != 0){
            if(qntd_5 == 1){
                printf("\n\t%d nota de R$5",qntd_5);
            }else{
                printf("\n\t%d notas de R$5",qntd_5);
            }
        }
        if(qntd_1 != 0){
            if(qntd_1 == 1){
                printf("\n\t%d moeda de R$1",qntd_1);
            }else{
                printf("\n\t%d moedas de R$1",qntd_1);
            }
        }
        if(qntd_050 != 0){
            if(qntd_050 == 1){
                printf("\n\t%d moeda de R$0.50",qntd_050);
            }else{
                printf("\n\t%d moedas de R$0.50",qntd_050);
            }
        }
    }
}
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    moldura_inicial();
    verificacao_senha(2323);
    float soma_valor;
    int nota_200 = 2, nota_100 = 4, nota_50 = 6, nota_10 = 10, nota_5 = 10, moeda_1 = 20, moeda_50 = 20,semtroco_flag;
    soma_valor=leitura_vendas();
    printf("\nValor total da compra: R$%.2f", soma_valor);
    troco(soma_valor, &moeda_50,&moeda_1,&nota_5,&nota_10,&nota_50,&nota_50,&nota_200,&semtroco_flag);
    system("pause");
    system("cls");
    printf("\n%d",nota_200);
    printf("\n%d",nota_100);
    printf("\n%d",nota_50);
    printf("\n%d",nota_10);
    printf("\n%d",nota_5);

    return 0;
}
