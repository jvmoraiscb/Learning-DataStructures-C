/* 
Problema: (BOCA: P2_2016_Q2) Faça um programa que calcule a soma dos maiores
dígitos primos de cada número de uma sequência. Ou seja, que extraia o maior dígito
primo de cada número de uma sequência, e ao final apresente a soma desses dígitos.
Caso o número não apresente dígito primo, não some nada para aquele número.
Modularize o código criando:
a) Uma função que receba um número de um dígito e retorne verdadeiro se ele for
primo e falso caso contrário. Cabeçalho: int EhPrimo(int num);.
b) Uma função que receba um número e retorne o maior dígito primo desse número,
ou zero caso não tenha dígito primo. Por exemplo, retorne: 2 para o número 29, 3
para o número 6434, 0 para o número 111, 0 para o número 804, etc.
Cabeçalho: int MaiorDigitoPrimo(int num);.
• Entrada: uma sequência de números inteiros separados por espaço e terminada com um
caractere não numérico.
• Saída: “SOMA:” seguido da soma dos maiores dígitos primos de cada número da sequência.
• Exemplo de Entrada:
2929 111 6434 804.
1 6434 84 234567 9873 4856 4r
2222 1111 0000 1111 23456 5 1 4 4 4 99s
110 404 666696a
• Exemplo de Saída:
SOMA:5
SOMA:22
SOMA:12
SOMA:0
*/

#include <stdio.h>

int EhPrimo (int num);
int MaiorDigitoPrimo(int num);

#define VERDADEIRO 1
#define FALSO 0
void main()
{
    int num, soma = 0;

    while (scanf("%d", &num) == VERDADEIRO)
        soma += MaiorDigitoPrimo(num);
    
    printf("SOMA:%d", soma);
}

int EhPrimo(int num)
{
    int div, cont=0;

	for (div=1; div<=num; div++)
    {
		if (num%div == 0)
			cont++;
	}
	if (cont == 2)
		return VERDADEIRO;
	else
		return FALSO; 
}

int MaiorDigitoPrimo(int num)
{
    int maiordigito=0;

    while (num > 0)
    {
        if (num%10 > maiordigito && EhPrimo(num%10) == VERDADEIRO)
            maiordigito = num%10;
        num = num/10;
    }

    return maiordigito;
}