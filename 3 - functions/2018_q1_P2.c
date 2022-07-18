/* 
Problema: (BOCA: P2_2018_Q1_a) Faça um programa para somar as ocorrências de
números pares que estiverem em posições pares e as ocorrências de números
ímpares que estiverem em posição ímpar de uma lista de números. Assuma que a
lista de números começa da posição 0 (par), e continua com as posições 1 (ímpar), 2
(par), etc.
• Entrada: 1 número inteiro n > 0 informando a quantidade de números da lista seguido de n
números inteiros n > 0. Todos os números serão separados por espaço.
• Saída: A mensagem “SOMA:” seguida da soma total dos números pares que ocorreram em
posições pares e números ímpares que ocorreram em posição ímpar. Considere que o
primeiro item da lista está na posição 1, o segundo na 2, e assim por diante.
• Exemplo de Entrada:
10
1 2 3 4 5 6 7 8 9 10
6
10 9 8 7 6 5
1
3
1
2
• Exemplo de Saída:
SOMA:0
SOMA:45
SOMA:0
SOMA:2
*/

#include <stdio.h>

void main()
{
    int i, qtdNumeros, num, somaPares = 0, somaImpares = 0;

    scanf("%d", &qtdNumeros);
    for(i = 0; i < qtdNumeros; i++)
    {
        scanf("%d", &num);
        if (i%2 == 0 && num%2 == 0)
            somaPares += num;
        else if (i%2 != 0 && num%2 != 0)
            somaImpares += num;
    }

    printf("SOMA:%d", somaPares + somaImpares);
}