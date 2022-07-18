/* 
Problema: (BOCA: P2_2016_Q1) Faça um programa para dizer a quantidade de
números pares ou ímpares de uma lista de números dependendo do tipo do
primeiro item. Ou seja, se o primeiro item for par, imprimir a quantidade de pares, e
se o primeiro item for ímpar, imprimir a quantidade de ímpares.
 Entrada: 1 número inteiro n > 0 informando a quantidade de números da lista seguido de n
números inteiros. Todos os números serão separados por espaço.
 Saída: A mensagem “QTD PARES:” seguida da quantidade de pares se o primeiro número
for par, e a mensagem ” QTD IMPARES:” seguida da quantidade de ímpares se o primeiro
número for ímpar.
 Exemplo de Entrada:
10
1 2 3 4 5 6 7 8 9 10
5
10 2 4 1 6
 Exemplo de Saída:
QTD IMPARES:5
QTD PARES:4
*/

#define PAR 1
#define IMPAR 2
#include <stdio.h>

void main()
{
    int n, nItens, i;
    int parImpar, qtdPares = 0, qtdImpares = 0;

    scanf("%d\n%d", &nItens, &n);
    if (n%2 == 0)
    {
        parImpar = PAR;
        qtdPares++;
    }
    else{
        parImpar = IMPAR;
        qtdImpares++;
    }

    for (i = 1; i <= nItens - 1 ; i++)
    {
        scanf(" %d", &n);
        if (parImpar == PAR)
        {
            if (n%2 == 0)
                qtdPares++;
        }
        else if (parImpar == IMPAR)
        {
            if (n%2 != 0)
                qtdImpares++;
        }
    }

    if (parImpar == PAR)
        printf("QTD PARES:%d", qtdPares);
    else if (parImpar == IMPAR)
        printf("QTD IMPARES:%d", qtdImpares);
    
}