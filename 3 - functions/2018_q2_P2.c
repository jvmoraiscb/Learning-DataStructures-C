/* 
Problema: (BOCA: P2_2018_Q2_a) Faça um programa que conte a quantidade de
pares de números de uma sequência de pares de números, cujo os maiores dígitos
de cada número do par são iguais.
Modularize o código criando:
a) Uma função que receba dois números inteiros e retorne verdadeiro se eles forem
iguais e falso caso contrário. Cabeçalho: int EhIgual(int a, int b);.
b) Uma função que receba um número inteiro e retorne o seu maior dígito. Por
exemplo, retorne: 6 para o número 162, 1 para o número 10, 5 para o número
12354, etc. Cabeçalho: int MaiorDigito(int num);.
• Entrada: uma sequência de pares de números inteiros no formato “(#a,#b)”, em que #a e
#b são os dois números inteiros (maior do que 0) do par. Veja exemplos de entrada abaixo.
• Saída: a quantidade de números da sequência de pares, cujo o maior dígito de #a é igual ao
maior dígito de #b. Veja o formato de saída nos exemplos abaixo.
• Exemplo de Entrada:
(2929,191)(43434,804)(1,1)(12,31)
(1,1121)(123,421)(56,761)
(123,5234)(95,273)(56213,64431)(943,11321)(1323,321)(6665,5556)
• Exemplo de Saída:
COUNT:2
COUNT:0
COUNT:3
*/

#include <stdio.h>

int MaiorDigito(int num);
int EhIgual(int a, int b);

void main()
{
    int num1, num2, contador = 0;

    while (scanf("(%d,%d)", &num1, &num2) == 2)
    {
        if (EhIgual (MaiorDigito(num1), MaiorDigito(num2) ))
            contador++;
    }
    printf("COUNT:%d", contador);
}

int MaiorDigito(int num)
{
    int maiorDigito = 0;

    while (num > 0)
    {
        if (num%10 > maiorDigito)
            maiorDigito = num%10;
        num = num/10;
    }
    
    return maiorDigito;
}

int EhIgual(int a, int b)
{
    if (a == b)
        return 1;
    else
        return 0;
}