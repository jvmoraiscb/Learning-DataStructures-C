/* 
Problema: (BOCA: P2_2017_Q2) Faça um programa que conte a quantidade de
números palíndromos de uma sequência. Um número é considerado palíndromo
quando ele é igual a sua escrita de trás para frente (ex. 123 não é palíndromo, pois
quando escrito de trás para frente vira 321, porém 232 é).
Modularize o código criando:
a) Uma função que receba dois números inteiros e retorne verdadeiro se eles forem
iguais e falso caso contrário. Cabeçalho: int EhIgual(int a, int b);.
b) Uma função que receba um número inteiro e retorne sua versão invertida (ou seja,
de trás para frente). Por exemplo, retorne: 321 para o número 123, 3 para o
número 3, 2323 para o número 3232, 22 para o número 22, etc.
Cabeçalho: int InverteNumero(int num);.
• Entrada: uma sequência de números inteiros separados por espaço e terminada com um
caractere não numérico.
• Saída: a quantidade de números palíndromos da sequência. Veja o formato de saída nos
exemplos abaixo.
• Exemplo de Entrada:
2929 111 43434 804.
1 6336 84 234567 1234321 4856 4r
2222 1111 0 1111 23456 5 1 4 4 4 99s
• Exemplo de Saída:
COUNT:2
COUNT:4
COUNT:10
*/

#include <stdio.h>

int EhIgual(int a, int b);
int InverteNumero(int num);

void main ()
{
    int num, countPalindromos = 0;

    while (scanf("%d", &num) == 1)
    {
        if(EhIgual(num, InverteNumero(num)) == 1)
            countPalindromos++;
    }

    printf("COUNT:%d", countPalindromos);
}

int EhIgual(int a, int b)
{
    if (a == b)
        return 1;
    else
        return 0;
}

int InverteNumero(int num)
{
    int numInvertido = 0;

    while(num != 0)
    {
        numInvertido = numInvertido*10 + num%10;
        num = num/10;
    }

    return numInvertido;
}