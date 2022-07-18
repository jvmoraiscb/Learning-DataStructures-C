/* 
(BOCA:L5_5) Problema: Faça um programa para ler uma sequência de N números
para um vetor e procurar a primeira ocorrência de um número X nesse vetor.
• Entrada: 1 número inteiro X a ser procurado, um número inteiro N representando a
quantidade de números, seguido de N números inteiros, todos separados por espaço.
• Saída: Índice da primeira ocorrência de X no vetor, ou o tamanho do vetor caso ele não
esteja presente. Ver exemplo abaixo da formatação de saída.
• Exemplo de Entrada:
41 1 41
5 2 56 54
31 5 5 31 31 62 10
25 5 5 10 20 30 25
10 5 10 10 10 10 10
• Exemplo de Saída:
RESP:0
RESP:2
RESP:1
RESP:4
RESP:0
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanhoVetor);
void encontraNumX(int vetor[], int tamanhoVetor[], int numX);

int main()
{
    int numX, qtdNumeros;
    scanf("%d%d", &numX, &qtdNumeros);
    int vetorNumero[qtdNumeros];

    preencheVetor(vetorNumero, qtdNumeros);
    encontraNumX(vetorNumero, qtdNumeros, numX);

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

void encontraNumX(int vetor[], int tamanhoVetor[], int numX)
{
    int i, resp, vNumX = 0;

    for (i = 0; i < tamanhoVetor; i++)
    {
        if (vetor[i] == numX)
        {
            resp = i;
            vNumX = 1;
            break;
        }    
    }
    if (vNumX == 0)
        resp = tamanhoVetor;

    printf("RESP:%d", resp);
}