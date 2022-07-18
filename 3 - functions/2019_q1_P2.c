/* 
(BOCA: P2_2019_Q1_a) Problema: Faça um programa para calcular o custo de
impressão de um pedido em uma gráfica que imprime em 3 tipos de papel. Cada
papel tem um custo diferente.
• Entrada: uma linha contendo 3 números inteiros positivos representando o custo do papel
de tipo 1, 2 e 3 respectivamente; um pedido de impressão dado por uma lista de números,
com cada um deles representando o tipo a ser impresso. A lista de tipos será dada por um
número inteiro n (dado em uma linha) representando a quantidade de itens da lista,
seguido dos itens (números 1, 2 ou 3) da lista separados por espaço na linha seguinte.
• Saída: custo da impressão da sequência de itens, sendo ele dado pela mensagem “CUSTO:”
seguida do valor.
• Exemplos de Entradas:
2 4 6
5
1 2 3 2 1
10 20 40
10
3 1 2 3 3 3 1 1 1 2
10 20 40
1
2
• Exemplos de Saídas:
CUSTO:18
CUSTO:240
CUSTO:20
*/

#include <stdio.h>

void main()
{
    int custoPapel1, custoPapel2, custoPapel3, i, nPapel, tipoPapel, custoTotal = 0;
    
    scanf("%d %d %d\n", &custoPapel1, &custoPapel2, &custoPapel3);
    scanf("%d\n", &nPapel);

    for(i = 1; i <= nPapel; i++)
    {
        scanf("%d", &tipoPapel);
        if (tipoPapel == 1)
            custoTotal += custoPapel1;
        else if (tipoPapel == 2)
            custoTotal += custoPapel2;
        else if (tipoPapel == 3)
            custoTotal += custoPapel3;
    }

    printf("CUSTO:%d", custoTotal);
}