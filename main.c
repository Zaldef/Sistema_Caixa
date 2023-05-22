//Sistema de caixa com senha, leitura de vendas, calculo de troca e fechamento do caixa com analise geral das vendas
#include <stdio.h>
#include <stdlib.h>

// Mensagem de bem vindo com moldura de barra dupla
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
// Fun��o para verificar atraves de compara��o, parametro de entrada � uma senha definida quando a fun��o � chamada
void verificacao_senha(int senha){
    int tent_senha = 0,qntd_tent_senha = 0;
    // apenas 3 tentativas permitidas, a partir disso o programa encerra
    do{
        if(qntd_tent_senha == 1){
            printf("Senha incorreta, voce tem mais DUAS tentativas!!!");
        }else if(qntd_tent_senha == 2){
            printf("Senha incorreta, voce tem mais UMA tentativas!!!");
        }
        printf("\nDigite a sua senha para abrir o caixa: ");
        scanf("%d",&tent_senha);
        if(tent_senha == senha){
            break;
        }else{
            qntd_tent_senha++;
        }
    }while(qntd_tent_senha<3);
    if(qntd_tent_senha == 3){
        printf("Senha Incorreta !!!\nSistema precisa ser reinicializado !!");
        exit(1);
    }else{
        system("cls");
    }
}
// ira registrar e somar cada valor da compra, com a possibilidade de corrigir o valor do produto anterior caso seja digitado
// incorretamente e retorna o valor total ao final
float leitura_vendas(int qntd_vendas){
    float soma_valor = 0,valor_produto = 0,valor_produto_anterior = 0;
    char resposta = 0;
    int i=0,flag_valor=0;// flag_valor serve para identificar quando um valor foi digitado incorretamente
    printf("\nVALORES DOS PRODUTOS DA COMPRA %d: ", qntd_vendas);
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
            // corrigir SOMENTE o ultimo produto inserido
            }else if(valor_produto<0 && i>1 && flag_valor != 1){
                soma_valor -= valor_produto_anterior;
                i--;
                flag_valor = 1;
            }if(valor_produto == 0){
                i--;
                printf("\nDeseja finalizar a compra?(SIM-S/NAO-N)");
                getchar();
                scanf("%c", &resposta);
            }
        valor_produto_anterior = valor_produto;
    }while(resposta != 'S' && resposta != 's');
    system("cls");
    printf("\nVenda finalizada com %d itens", i);
    return soma_valor;
}
float cal_saldo_caixa(int nota_200,int nota_100, int nota_50,int nota_10,int nota_5,int moeda_1,int moeda_50){
    float saldo_caixa = 0;
    saldo_caixa += (nota_200 * 200);
    saldo_caixa += (nota_100 * 100);
    saldo_caixa += (nota_50 * 50);
    saldo_caixa += (nota_10 * 10);
    saldo_caixa += (nota_5 * 5);
    saldo_caixa += (moeda_1 * 1);
    saldo_caixa += (moeda_50 * 0.5);
    return saldo_caixa;
}
void calculo_troco(int *pont_200,int *pont_100,int *pont_50,int *pont_10,int *pont_5,int *pont_1,int *pont_050, int soma_valor, int *semtroco_flag, float saldo_caixa){
    float valor_pago, troco, valor_troco=0, soma_troco = 0;
    int qntd_200 = 0,qntd_100 = 0, qntd_50 = 0,qntd_10 = 0,qntd_5 = 0,qntd_1 = 0,qntd_050 = 0, troco_flag = 0;
    do{
        printf("\nInsira o valor pago : R$");
        scanf("%f",&valor_pago);
        if(valor_pago < soma_valor){
            printf("Valor inserido menor do que o valor total da compra, digite novamente por favor!!");
        }
    }while(valor_pago < soma_valor);
    do{
        if(troco_flag == 1){
            printf("Erro na digitacao das notas, valor e diferente do valor pago!!!\n Tente novamente\n");
            soma_troco = 0;
        }
        printf("\tInsira a quantidade de notas de R$200.00: ");
        scanf("%d", &qntd_200);
        soma_troco += qntd_200*200;
        printf("\tInsira a quantidade de notas de R$100.00: ");
        scanf("%d", &qntd_100);
        soma_troco += qntd_100 * 100;
        printf("\tInsira a quantidade de notas de R$50.00: ");
        scanf("%d", &qntd_50);
        soma_troco += qntd_50 * 50;
        printf("\tInsira a quantidade de notas de R$10.00: ");
        scanf("%d", &qntd_10);
        soma_troco += qntd_10 * 10;
        printf("\tInsira a quantidade de notas de R$5.00: ");
        scanf("%d", &qntd_5);
        soma_troco += qntd_5 * 5;
        printf("\tInsira a quantidade de moedas de R$1.00: ");
        scanf("%d", &qntd_1);
        soma_troco += qntd_1;
        printf("\tInsira a quantidade de moedas de R$0.50: ");
        scanf("%d", &qntd_050);
        soma_troco += qntd_050*0.50;

        if(soma_troco != valor_pago){
            troco_flag = 1;
        }else{
            troco_flag = 0;
        }
    }while(troco_flag == 1);
    if(soma_troco>saldo_caixa){
        *semtroco_flag = 1;
        return;
    }
    *pont_200 += qntd_200;
    qntd_200 = 0;
    *pont_100 += qntd_100;
    qntd_100 = 0;
    *pont_50 += qntd_50;
    qntd_50 = 0;
    *pont_10 += qntd_10;
    qntd_10 = 0;
    *pont_5 += qntd_5;
    qntd_5 = 0;
    *pont_1 += qntd_1;
    qntd_1 = 0;
    *pont_050 += qntd_050;
    qntd_050 = 0;
    troco = valor_pago-soma_valor;
    if(troco == 0){
        printf("\nNao precisa de troco!");
    }else{
        do{
            if(troco >= 0 && *pont_050 >=1){
                if(troco >= 1 && *pont_1 >=1){
                    if(troco >= 5 && *pont_5 >=1){
                        if(troco >= 10 && *pont_10 >=1){
                            if(troco >= 50 && *pont_50 >=1){
                                if(troco >= 100 && *pont_100 >=1){
                                    if(troco >=200 && *pont_200 >=1){
                                        troco -=200;
                                        *pont_200-=1;
                                        qntd_200++;
                                        valor_troco +=200;
                                    }else{
                                        troco -=100;
                                        *pont_100-=1;
                                        qntd_100++;
                                        valor_troco +=100;
                                        }
                                }else{
                                    troco -=50;
                                    *pont_50-=1;
                                    qntd_50++;
                                    valor_troco +=50;
                                    }
                            }else{
                                troco -=10;
                                *pont_10-=1;
                                qntd_10++;
                                valor_troco +=10;
                            }
                        }else{
                            troco-=5;
                            *pont_5-=1;
                            qntd_5++;
                            valor_troco +=5;
                        }
                    }else{
                        troco-=1;
                        *pont_1-=1;
                        qntd_1++;
                        valor_troco +=1;
                    }
                }else{
                    troco -= 0.5;
                    *pont_050-=1;
                    qntd_050++;
                    valor_troco +=0.5;
                }
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
    moldura_inicial();
    verificacao_senha(2323);
    int nota_200 = 2, nota_100 = 4, nota_50 = 6, nota_10 = 10, nota_5 = 10, moeda_1 = 20, moeda_50 = 20;
    float soma_valor,valor_vendas = 0, saldo_caixa = 0;
    int qntd_vendas = 0,semtroco_flag = 0;
    char resposta=0;

    do{
        system("cls");
        saldo_caixa = cal_saldo_caixa(nota_200,nota_100,nota_50,nota_10,nota_5,moeda_1,moeda_50);
        qntd_vendas++;
        do{
            soma_valor=leitura_vendas(qntd_vendas);
        }while(soma_valor == 0);
        printf("\nValor total da compra: R$%.2f", soma_valor);
            calculo_troco(&nota_200,&nota_100,&nota_50,&nota_10,&nota_5,&moeda_1,&moeda_50,soma_valor,&semtroco_flag,saldo_caixa);
        system("pause");
        if(semtroco_flag == 0){
            valor_vendas += soma_valor;
            printf("\n Deseja fechar o caixa?(SIM-S/NAO-N)");
            getchar();
            scanf("%c", &resposta);
        }else{
            qntd_vendas--;
            resposta = 's';
        }
    }while(resposta != 'S' && resposta != 's');

    system("cls");
    printf("\nNotas Disponiveis:");
    printf("\nNotas de 200 reais: %d",nota_200);
    printf("\nNotas de 100 reais: %d",nota_100);
    printf("\nNotas de 50 reais: %d",nota_50);
    printf("\nNotas de 10 reais: %d",nota_10);
    printf("\nNotas de 5 reais: %d",nota_5);
    printf("\nMoedas de 1: %d",moeda_1);
    printf("\nMoedas de 0.5: %d",moeda_50);
    printf("\n");

// calcula o saldo disponivel atrav�s da quantidade de cedulas
    printf("\nValor disponivel no caixa: %.2f", saldo_caixa);
    printf("\nQuantidade de vendas: %d", qntd_vendas);
    printf("\nValor total das vendas: %.2f", valor_vendas);
    return 0;
}
