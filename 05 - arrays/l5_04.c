/* 
(BOCA:L5_4) Problema: Faça um programa que lê números de uma sequência de
N números para um vetor. No final, ler um intervalo fechado (a e b, onde a < b) e
dizer quantos números estão dentro do intervalo e quantos números estão fora do
intervalo.
 Entrada: 1 número inteiro N representando a quantidade de números, seguido de N
números, seguido por dois números a e b representando o intervalo, todos separados por
espaço.
 Saída: Quantidade de números dentro do intervalo seguido pela quantidade de números
fora dele. Ver exemplo abaixo da formatação de saída.
 Exemplo de Entrada:
1 41 30 50
2 56 54 60 80
5 5 31 32 62 10 0 20
5 5 10 20 30 25 5 25
5 10 10 10 10 10 20 30
 Exemplo de Saída:
1 0
0 2
2 3
4 1
0 5
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanhoVetor);
void verificaIntervalos(int vetor[], int tamanhoVetor, int a, int b, int valores[]);
void imprimeValores(int valores[]);

int main()
{
    int valores[2]; // Numeros dentro do intervalo, Numeros fora do intervalo
    int intervaloA, intervaloB, qtdNumeros;
    scanf("%d", &qtdNumeros);
    int numeros[qtdNumeros];

    preencheVetor(numeros, qtdNumeros);

    scanf("%d%d", &intervaloA, &intervaloB);
    verificaIntervalos(numeros, qtdNumeros, intervaloA, intervaloB, valores);
    imprimeValores(valores);
}

void preencheVetor(int vetor[], int tamanhoVetor)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]); 
    }
}

void verificaIntervalos(int vetor[], int tamanhoVetor, int a, int b, int valores[])
{
    int i, qtdNumDentro = 0, qtdNumFora = 0;

    for (i = 0; i < tamanhoVetor; i++)
    {
        if(vetor[i] >= a && vetor[i] <= b)
            qtdNumDentro++;
        else
            qtdNumFora++;
    }
    
    valores[0] = qtdNumDentro;
    valores[1] = qtdNumFora;
}

void imprimeValores(int valores[])
{
    printf("%d %d", valores[0], valores[1]);
}

