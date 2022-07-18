/* 
(BOCA:L5_8) Problema: Faça um programa que leia uma sequência de números
para um vetor A e troque os elementos de posição impar com os de posição par
imediatamente seguintes. Ao final, imprima A. Implemente uma função auxiliar para
fazer a troca dos elementos de um vetor e uma para imprimir os elementos de um
vetor, protótipos (cabeçalhos): void TrocaParEImpar(int vet[], int qtd); e
void ImprimeDadosDoVetor(int vet[], int qtd);
 Entrada: um número inteiro N representando uma quantidade de números, seguido de N
números inteiros, todos separados por espaço.
 Saída: Sequência de números com ordem trocada.
 Exemplo de Entrada:
1 41
2 56 54
3 1 2 3
4 1 2 3 4
7 5 4 3 2 1 0 -1
0
 Exemplo de Saída:
{41}
{54, 56}
{2, 1, 3}
{2, 1, 4, 3}
{4, 5, 2, 3, 0, 1, -1}
{}
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanhoVetor);
void trocaParEImpar(int vetor[], int tamanhoVetor);
void imprimeDadosDoVetor(int vetor[], int tamanhoVetor);

int main()
{
    int qtdNumeros;
    scanf("%d", &qtdNumeros);
    int vetorNumero[qtdNumeros];
    preencheVetor(vetorNumero, qtdNumeros);

    trocaParEImpar(vetorNumero, qtdNumeros);
    imprimeDadosDoVetor(vetorNumero, qtdNumeros);

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

void trocaParEImpar(int vetor[], int tamanhoVetor)
{
    int i;

   for (i = 0; i < tamanhoVetor; i++)
    {
        int numFlutuante;

        if(i%2 == 0 && i != tamanhoVetor-1)
        {
            numFlutuante = vetor[i];
            vetor[i] = vetor[i + 1];
            vetor[i + 1] = numFlutuante;
        }
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