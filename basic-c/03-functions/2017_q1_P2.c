/* 
Problema: (BOCA: P2_2017_Q1) Faça um programa para dizer a posição da primeira
ocorrência do menor número de uma lista de números.
• Entrada: 1 número inteiro n ≥ 0 informando a quantidade de números da lista seguido de n
números inteiros. Todos os números serão separados por espaço.
• Saída: A mensagem “POS:” seguida posição da primeira ocorrência do menor número, ou
não imprimir nada caso a lista seja vazia. Considere que o primeiro item da lista está na
posição 1, o segundo na 2, e assim por diante.
• Exemplo de Entrada:
10
1 1 3 4 1 6 7 8 9 10
5
10 2 4 1 -6
1
2
0
• Exemplo de Saída:
POS:1
POS:5
POS:1

*/

#include <stdio.h>

void main()
{
    int qNum, num, menorNum = 32000, pMenorNum = 0, i;

    scanf("%d", &qNum);

    for (i = 1; i <= qNum; i++)
    {
        scanf("%d", &num);
        if (num < menorNum)
        {
            menorNum = num;
            pMenorNum = i;
        }
        //printf("POS:%d\n", pMenorNum);    
    }
    
    if (qNum > 0)
        printf("POS:%d", pMenorNum);

}