/* 
(BOCA:L5_7) Problema: Faça um programa que verifique se os itens (inteiros) de
uma sequência de números formam uma progressão aritmética.
• Entrada: um número inteiro N representando uma quantidade de números, seguido de N
números inteiros, todos separados por espaço.
• Saída: Imprima “RESP:” seguido da razão se for uma progressão aritmética, ou “NAO” caso
contrário.
• Exemplo de Entrada:
1 41
2 56 54
4 2 2 2 2
5 2 4 6 8 10
7 5 4 3 2 1 0 -1
• Exemplo de Saída:
NAO
RESP:-2
RESP:0
RESP:2
RESP:-1
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanhoVetor);
void verificaRazaoPA(int vetor[], int tamanhoVetor);

int main()
{
    int qtdNumeros;
    scanf("%d", &qtdNumeros);
    int vetorNumeros[qtdNumeros];

    preencheVetor(vetorNumeros, qtdNumeros);
    verificaRazaoPA(vetorNumeros, qtdNumeros);

    return 0;
}

void preencheVetor(int vetor[], int tamanhoVetor)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]); 
    }
}

void verificaRazaoPA(int vetor[], int tamanhoVetor)
{
    int i, razao, vPA = 0;

    for (i = 1; i < tamanhoVetor; i++)
    {
        if (i == 1)
            razao = vetor[i] - vetor[i - 1];
        else
        {
            if(vetor[i] - vetor[i - 1] != razao)
                vPA = -1;
        }
    }

    if (vPA == 0 && tamanhoVetor > 1)
        printf("RESP:%d", razao);
    else
        printf("NAO");
}