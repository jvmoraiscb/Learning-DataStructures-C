/* 
(BOCA:L5_10) Problema: Faça um programa que leia uma sequência de números
para um vetor A e ordene em ordem crescente a sequência de números. Ao final,
imprima A. Implemente uma função auxiliar para fazer a ordenação dos elementos
de um vetor e uma para imprimir os elementos de um vetor, protótipos
(cabeçalhos): void OrdenaCrescente(int vet[], int qtd); e
void ImprimeDadosDoVetor(int vet[], int qtd);
 Entrada: um número inteiro N representando uma quantidade de números, seguido de N
números inteiros, todos separados por espaço.
 Saída: Sequência de números ordenada.
 Exemplo de Entrada:
1 41
2 56 54
3 1 2 3
4 2 4 1 3
7 5 4 3 2 1 0 -1
0
 Exemplo de Saída:
{41}
{54, 56}
{1, 2, 3}
{1, 2, 3, 4}
{-1, 0, 1, 2, 3, 4, 5}
{}
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanhoVetor);
void imprimeDadosDoVetor(int vetor[], int tamanhoVetor);
void ordenaCrescente(int vetor[], int tamanhoVetor);
int encontraMenorInteiro(int vetor[], int tamanhoVetor, int i);

int main()
{
    int qtdNumeros;
    scanf("%d", &qtdNumeros);
    int vetorNumero[qtdNumeros];
    preencheVetor(vetorNumero, qtdNumeros);

    ordenaCrescente(vetorNumero, qtdNumeros);
    imprimeDadosDoVetor(vetorNumero, qtdNumeros);

    return 0;
}

void ordenaCrescente(int vetor[], int tamanhoVetor)
{
   int i, iMenorInteiro, inteiroFlutuante;

    for (i = 0; i < tamanhoVetor; i++)
    {
        iMenorInteiro = encontraMenorInteiro(vetor, tamanhoVetor, i);
        inteiroFlutuante = vetor[i];
        vetor[i] = vetor[iMenorInteiro];
        vetor[iMenorInteiro] = inteiroFlutuante;
    } 
}

void preencheVetor(int vetor[], int tamanhoVetor)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]); 
    }
}

void imprimeDadosDoVetor(int vetor[], int tamanhoVetor)
{
    int i;

    printf("{");
    for (i = 0; i < tamanhoVetor; i++)
    {
        if(i == 0)
            printf("%d", vetor[i]);
        else
            printf(", %d", vetor[i]);
    }
    printf("}");
}

int encontraMenorInteiro(int vetor[], int tamanhoVetor, int i)
{
    int i2, menorInteiro, iMenorInteiro;

    for (i2 = i; i2 < tamanhoVetor; i2++)
    {
        if (i2 == i)
        {
            menorInteiro = vetor[i2];
            iMenorInteiro = i2;
        }
        else if(vetor[i2] < menorInteiro)
        {
            menorInteiro = vetor[i2];
            iMenorInteiro = i2;
        }
    }

    return iMenorInteiro;
}