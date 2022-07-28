/* 
(BOCA: L3_12) Problema: Dado um inteiro não-negativo, repetidamente
some seus dígitos, até que o resultado tenha somente um dígito. A cada
soma, o valor deverá ser impresso e após ele, deverá ser impresso se o
número é ímpar ou par, e se ele é primo.
a) Seu programa deve conter a função int somadosdigitos(int n); que
retorna a soma dos dígitos do número n.
b) Seu programa deve conter a função void parImpar(int n); que
imprime Par se n for par ou Impar se n for ímpar.
d) Seu programa deve conter a função void valorPrimo(int n); que
imprime Nao e primo se n não for primo ou Primo se n for primo.
• Entrada: um inteiro não negativo
• Saída: o valor de cada soma, seguido pela identificação de que se o
número é par ou ímpar. Se for par, deve imprimir: Par, se for ímpar,
imprimir: Impar. Se for primo: Primo, caso não: Nao e primo.
• Exemplos de Entrada:
455
39
23
• Exemplos de Saída:
14 Par Nao e primo
5 Impar Primo
12 Par Nao e primo
3 Impar Primo
5 Impar Primo
*/

#include <stdio.h>

int somadosdigitos(int n);
void parImpar(int n);
void valorPrimo(int n);

int main()
{
    int n;

    scanf("%d", &n);

    if (n >= 0){
        while (1)
        {
            n = somadosdigitos(n);
            printf("%d ", n);
            parImpar(n);
            valorPrimo(n);
            if (n < 10)
                break;
        }
    }
    return 0;
}

int somadosdigitos(int n)
{
    int soma=0;

    while (n > 0)
    {
        soma += n%10;
        n = n/10;
    }
    return (soma);
}

void parImpar(int n)
{
    if (n%2 == 0)
        printf("Par ");
    else
        printf("Impar ");
}

void valorPrimo(int n)
{
    int div, cont=0;
	for (div=1; div<=n; div++){
		if (n%div == 0)
			cont++;
	}
	if (cont == 2)
		printf("Primo\n");
	else
		printf("Nao e primo\n");
}