//Sistema de caixa com senha, leitura de vendas, calculo de troca e fechamento do caixa com analise geral das vendas
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // função sleep

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
    printf("%c",200);
    for(int i=0; i<87; i++){
        printf("%c",205);
    }
    printf("%c",188);
}
// Função para verificar atraves de comparação, parametro de entrada é uma senha definida quando a função é chamada
void verificacao_senha(int senha){
    int tent_senha = 0,qntd_tent_senha = 0;
    // apenas 3 tentativas permitidas, a partir disso o programa encerra
    do{
        if(qntd_tent_senha == 1){
            printf("\tSenha incorreta, voce tem mais DUAS tentativas!!!");
        }else if(qntd_tent_senha == 2){
            printf("\tSenha incorreta, voce tem mais UMA tentativas!!!");
        }
        printf("\n\tDigite a sua senha para abrir o caixa: ");
        scanf("%d",&tent_senha);
        if(tent_senha == senha){
            break;
        }else{
            qntd_tent_senha++;
        }
    }while(qntd_tent_senha<3);
    if(qntd_tent_senha == 3){
        printf("\tSenha Incorreta !!!\nSistema precisa ser reinicializado !!");
        exit(1);
    }else{
        printf("\tSenha correta, abrindo caixa.");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        system("cls");
    }
}
// ira registrar e somar cada valor da compra, com a possibilidade de corrigir o valor do produto anterior caso seja digitado
// incorretamente e retorna o valor total ao final
float leitura_vendas(int qntd_vendas){
    float soma_valor = 0,valor_produto = 0,valor_produto_anterior = 0;
    char resposta = 0;
    int i=0,flag_valor=0;// flag_valor serve para identificar quando um valor foi digitado incorretamente
    printf("\n\tVALORES DOS PRODUTOS DA COMPRA %d: \n", qntd_vendas);
    do{
        if(flag_valor == 1){
            printf("\tCorrija o valor do item %d: \tR$", i);
            scanf("%f", &valor_produto);
            }else{
                i++;
                printf("\tDigite o valor do item %d: \tR$", i);
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
                printf("\n\tDeseja finalizar a compra?(SIM-S/NAO-N)");
                getchar();
                scanf("%c", &resposta);
            }
        valor_produto_anterior = valor_produto;
    }while(resposta != 'S' && resposta != 's');
    printf("\tFinalizando a venda.");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    system("cls");
    printf("\n\tVenda finalizada com %d itens", i);
    return soma_valor;
}
// calcula quantidade total no caixa
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
// função de calculo de troco, ele opera num caixa "virtual" dentro dessa função e no final opera com ponteiros para autalizar o caixa real com os valores
// do caixa virtual
void calculo_troco(int *pont_200,int *pont_100,int *pont_50,int *pont_10,int *pont_5,int *pont_1,int *pont_050, float soma_valor, int *semtroco_flag, float saldo_caixa, int nota_200,int nota_100,int nota_50,int nota_10,int nota_5,int moeda_1,int moeda_50){
    float valor_pago, troco, valor_troco=0, soma_troco = 0;
    int qntd_200 = 0,qntd_100 = 0, qntd_50 = 0,qntd_10 = 0,qntd_5 = 0,qntd_1 = 0,qntd_050 = 0,qntd_r_200,qntd_r_100,qntd_r_50,qntd_r_10,qntd_r_5,qntd_r_1,qntd_r_050, troco_flag = 0;
    // verificação do valor pago
    do{
        printf("\n\tInsira o valor pago : \tR$");
        scanf("%f",&valor_pago);
        if(valor_pago < soma_valor){
            printf("\tValor inserido menor do que o valor total da compra, digite novamente por favor!!");
        }
    }while(valor_pago < soma_valor);
    // loop para inserção das notas
    do{
        if(troco_flag == 1){
            printf("\tErro na digitacao das notas, valor e diferente do valor pago!!!\n\tTente novamente\n");
            soma_troco = 0;
        }
        // zerando as variaveis para utilizar
        qntd_r_200 = 0;
        qntd_r_100 = 0;
        qntd_r_50 = 0;
        qntd_r_10 = 0;
        qntd_r_5 = 0;
        qntd_r_1 = 0;
        qntd_r_050 = 0;
        printf("\tInsira a quantidade de notas de R$200.00:\t ");
        scanf("%d", &qntd_r_200);
        soma_troco += qntd_r_200*200;
        printf("\tInsira a quantidade de notas de R$100.00:\t ");
        scanf("%d", &qntd_r_100);
        soma_troco += qntd_r_100 * 100;
        printf("\tInsira a quantidade de notas de R$50.00:\t ");
        scanf("%d", &qntd_r_50);
        soma_troco += qntd_r_50 * 50;
        printf("\tInsira a quantidade de notas de R$10.00:\t ");
        scanf("%d", &qntd_r_10);
        soma_troco += qntd_r_10 * 10;
        printf("\tInsira a quantidade de notas de R$5.00:\t\t ");
        scanf("%d", &qntd_r_5);
        soma_troco += qntd_r_5 * 5;
        printf("\tInsira a quantidade de moedas de R$1.00:\t ");
        scanf("%d", &qntd_r_1);
        soma_troco += qntd_r_1;
        printf("\tInsira a quantidade de moedas de R$0.50:\t ");
        scanf("%d", &qntd_r_050);
        soma_troco += qntd_r_050*0.50;
        // ve4rificação se a soma das notas bate com o valor declarado pago
        if(soma_troco != valor_pago){
            troco_flag = 1;
        }else{
            troco_flag = 0;
        }
    }while(troco_flag == 1);
    // guardando as notas no caixa "virtual"
    nota_200 += qntd_r_200;
    nota_100 += qntd_r_100;
    nota_50 += qntd_r_50;
    nota_10 += qntd_r_10;
    nota_5 += qntd_r_5;
    moeda_1 += qntd_r_1;
    moeda_50 += qntd_r_050;
    //verificação se existe troco suficiente no caixa
    saldo_caixa = cal_saldo_caixa(nota_200,nota_100,nota_50,nota_10,nota_5,moeda_1,moeda_50);
    //caso não tenha troco, ele desconsidera a compra e ativa a flag
    if(soma_troco>saldo_caixa){
        *semtroco_flag = 1;
        return;
    }
    troco = valor_pago-soma_valor;
    if(troco == 0){
        printf("\n\tNao precisa de troco!");
    }else{
        //calculo troco
        do{
            if(troco >= 0 && moeda_50 >=1){
                if(troco >= 1 && moeda_1 >=1){
                    if(troco >= 5 && nota_5 >=1){
                        if(troco >= 10 && nota_10 >=1){
                            if(troco >= 50 && nota_50 >=1){
                                if(troco >= 100 && nota_100 >=1){
                                    if(troco >=200 && nota_200 >=1){
                                        troco -=200;
                                        nota_200-=1;
                                        qntd_200++;
                                        valor_troco +=200;
                                    }else{
                                        troco -=100;
                                        nota_100-=1;
                                        qntd_100++;
                                        valor_troco +=100;
                                        }
                                }else{
                                    troco -=50;
                                    nota_50-=1;
                                    qntd_50++;
                                    valor_troco +=50;
                                    }
                            }else{
                                troco -=10;
                                nota_10-=1;
                                qntd_10++;
                                valor_troco +=10;
                            }
                        }else{
                            troco-=5;
                            nota_5-=1;
                            qntd_5++;
                            valor_troco +=5;
                        }
                    }else{
                        troco-=1;
                        moeda_1-=1;
                        qntd_1++;
                        valor_troco +=1;
                    }
                }else{
                    troco -= 0.5;
                    moeda_50-=1;
                    qntd_050++;
                    valor_troco +=0.5;
                }
            }
            // caso acabe o troco, ativa a flag
            if( troco > 0 && moeda_50 ==0){
            *semtroco_flag = 1;
            return;
            }
        }while(troco > 0);
        // Impressão do troco na tela
        printf("\n\tO troco sera de: \tR$%.2f", valor_troco);
        if(qntd_200 != 0){
            if(qntd_200 == 1){
                printf("\n\t\t%d nota de R$200",qntd_200);
            }else{
                printf("\n\t\t%d notas de R$200",qntd_200);
            }
        }
        if(qntd_100 != 0){
            if(qntd_100 == 1){
                printf("\n\t\t%d nota de R$100",qntd_100);
            }else{
                printf("\n\t\t%d notas de R$100",qntd_100);
            }
        }
        if(qntd_50 != 0){
            if(qntd_50 == 1){
                printf("\n\t\t%d nota de R$50",qntd_50);
            }else{
                printf("\n\t\t%d notas de R$50",qntd_50);
            }
        }
        if(qntd_10 != 0){
            if(qntd_10 == 1){
                printf("\n\t\t%d nota de R$10",qntd_10);
            }else{
                printf("\n\t\t%d notas de R$10",qntd_10);
            }
        }
        if(qntd_5 != 0){
            if(qntd_5 == 1){
                printf("\n\t\t%d nota de R$5",qntd_5);
            }else{
                printf("\n\t\t%d notas de R$5",qntd_5);
            }
        }
        if(qntd_1 != 0){
            if(qntd_1 == 1){
                printf("\n\t\t%d moeda de R$1",qntd_1);
            }else{
                printf("\n\t\t%d moedas de R$1",qntd_1);
            }
        }
        if(qntd_050 != 0){
            if(qntd_050 == 1){
                printf("\n\t\t%d moeda de R$0.50",qntd_050);
            }else{
                printf("\n\t\t%d moedas de R$0.50",qntd_050);
            }
        }
        // atualizando o caixa real com os valores do caixa "virtual"
        *pont_200 = nota_200;
        *pont_100 = nota_100;
        *pont_50 = nota_50;
        *pont_10 = nota_10;
        *pont_5 = nota_5;
        *pont_1 = moeda_1;
        *pont_050 = moeda_50;
    }
}

void fechamento_de_caixa(int nota_200,int nota_100,int nota_50,int nota_10,int nota_5,int moeda_1,int moeda_50,float saldo_caixa,int qntd_vendas,float valor_vendas){
     system("cls");
    printf("\n\tNotas Disponiveis:");
    printf("\n\t\tNotas de 200 reais: \t%d",nota_200);
    printf("\n\t\tNotas de 100 reais: \t%d",nota_100);
    printf("\n\t\tNotas de 50 reais: \t%d",nota_50);
    printf("\n\t\tNotas de 10 reais: \t%d",nota_10);
    printf("\n\t\tNotas de 5 reais: \t%d",nota_5);
    printf("\n\t\tMoedas de 1: \t\t%d",moeda_1);
    printf("\n\t\tMoedas de 0.5: \t\t%d",moeda_50);
    // calcula o saldo disponivel através da quantidade de cedulas
    saldo_caixa = cal_saldo_caixa(nota_200,nota_100,nota_50,nota_10,nota_5,moeda_1,moeda_50);
    printf("\n\tValor disponivel no caixa: \t%.2f", saldo_caixa);
    printf("\n\tQuantidade de vendas: \t\t%d", qntd_vendas);
    printf("\n\tValor total das vendas: \t%.2f", valor_vendas);

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
        qntd_vendas++;
        // calculo de vendas
        soma_valor=leitura_vendas(qntd_vendas);
        if(soma_valor != 0 ){
            printf("\n\tValor total da compra: \tR$%.2f", soma_valor);
            calculo_troco(&nota_200,&nota_100,&nota_50,&nota_10,&nota_5,&moeda_1,&moeda_50,soma_valor,&semtroco_flag,saldo_caixa,nota_200,nota_100,nota_50,nota_10,nota_5,moeda_1,moeda_50);
            if(semtroco_flag == 0){
                valor_vendas += soma_valor;
                printf("\n\tDeseja fechar o caixa?(SIM-S/NAO-N)");
                getchar();
                scanf("%c", &resposta);
            }else{
                qntd_vendas--;
                resposta = 's';
            }
        }else{
            qntd_vendas--;
            printf("\n\tDeseja fechar o caixa?(SIM-S/NAO-N)");
            getchar();
            scanf("%c", &resposta);
        }
    }while(resposta != 'S' && resposta != 's');
    fechamento_de_caixa(nota_200,nota_100,nota_50,nota_10,nota_5,moeda_1,moeda_50,saldo_caixa,qntd_vendas,valor_vendas);
    return 0;
}
