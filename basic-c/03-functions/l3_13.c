/* 
(BOCA:L3_13) Problema: Você deve ler uma série de palavras, onde cada palavra é
composta somente por letras no intervalo a-z e A-Z. Cada letra possui um valor
específico, a letra 'a' vale 1, a letra 'b' vale 2 e assim por diante, até a letra 'z', que
vale 26. Do mesmo modo, a letra 'A' vale 27, a letra 'B' vale 28 e a letra 'Z' vale 52. O
valor da palavra é soma dos valores das letras. Você deve escrever um programa
para determinar se uma palavra é uma palavra prima ou não. Caso ela não seja
prima, você deverá indicar o próximo número àquela palavra que é primo.
a) Seu programa deve conter a função int CalculaValorPalavra(); que retorna o
número representando a palavra após a soma dos valores de suas letras, ou zero
caso não seja letra.
b) Seu programa deve conter a função int EhPrimo(int n); que retorna verdadeiro se o
número n for primo ou falso caso contrário.
c) Seu programa deve conter a função int ProximoPrimo(int n); que retorna o próximo
primo após n.
Ver formatação abaixo.
 Entrada: várias linhas, sendo que em cada uma delas tem uma palavra com caracteres de az e A-Z.
 Saída: caso seja primo, seu programa deve imprimir a frase “E primo”. Caso contrário, deve
imprimir “Nao e primo”, seguido de um espaço e o valor correspondente ao próximo primo.
 Exemplo de Entradas:
BOCA
PROGII
UFES
Bbba
eAzWOqwHJNYdthamssay
pEVbvQ
VNQZoRyE
UNRkM 
DvY
VebxjnirvOBoHdDukRD
CESOyeeXTeKOjnNUAVN
J
oSUSOeJscNywCXB
wWKgKvtxR
VFUgviZRCNxlHcBIydh
JDxVmhThhKDE
ZKPKlGOBGCKI
sggbIrhf
t
fcysicLJMAtAJi
pKLXpGFvHPoqxA
mioKcwoNfaQb
zLdOXPnmXSj
kxx
 Exemplo de Saídas:
Nao e primo 127
Nao e primo 233
Nao e primo 157
E primo
Nao e primo 461
Nao e primo 163
Nao e primo 307
E primo
E primo
Nao e primo 419
Nao e primo 587
Nao e primo 37
Nao e primo 457
E primo
E primo
Nao e primo 331
Nao e primo 419
Nao e primo 103
Nao e primo 23
Nao e primo 307
Nao e primo 409
Nao e primo 211
Nao e primo 337
E primo
*/

#include <stdio.h>

int CalculaValorPalavra(char c);
int EhPrimo(int n);
int ProximoPrimo(int n);

int main()
{
    int soma=0;
    char c;

    while (scanf("%c", &c) == 1)
    {
        if (c != '\n')
            soma += CalculaValorPalavra(c);
        else
        {
            if (EhPrimo(soma) == 1)
                printf("E primo\n");
            else 
            {
                printf("Nao e primo %d\n", ProximoPrimo(soma));

            }
            soma=0;
        }
    }
    
    return 0;
}

int CalculaValorPalavra(char c)
{
    int valorc;

    if (c >= 'a' && c <= 'z'){
        valorc = c;
        valorc += -96;
    }
    else if (c >= 'A' && c <= 'Z'){
        valorc = c;
        valorc += -38;
    }

    return (valorc);   
}

int EhPrimo(int n)
{
    int div, cont=0;

	for (div=1; div<=n; div++)
    {
		if (n%div == 0)
			cont++;
	}
	if (cont == 2)
		return 1;
	else
		return 0; 
}

int ProximoPrimo(int n)
{
    int i, mult;

    for (i=n; i<=32000; i++){
		if (EhPrimo(i) == 1){
			mult = i;
			break;
		}
    }

    return (mult);
}