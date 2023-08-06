/* 
(BOCA:L5_9) Problema: Faça um programa que leia uma sequência de números
para um vetor A e inverta a sequência de números, isto é, o último elemento deverá
ser o primeiro, o penúltimo deverá ser o segundo e assim por diante. Ao final,
imprima A. Implemente uma função auxiliar para fazer a inversão dos elementos de
um vetor e uma para imprimir os elementos de um vetor, protótipos (cabeçalhos):
void InverteVetor(int * vet, int qtd); e void ImprimeDadosDoVetor(int vet[], int qtd);
 Entrada: um número inteiro N representando uma quantidade de números, seguido de N
números inteiros, todos separados por espaço.
 Saída: Sequência de números com ordem invertida.
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
{3, 2, 1}
{4, 3, 2, 1}
{-1, 0, 1, 2, 3, 4, 5}
{}
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanhoVetor);
void inverteVetor(int vetor[], int tamanhoVetor);
void imprimeDadosDoVetor(int vetor[], int tamanhoVetor);

int main()
{   
    int qtdNumeros;
    scanf("%d", &qtdNumeros);
    int vetorNumero[qtdNumeros];
    preencheVetor(vetorNumero, qtdNumeros);

    inverteVetor(vetorNumero, qtdNumeros);
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

void inverteVetor(int vetor[], int tamanhoVetor)
{
    int i;

   for (i = 0; i < tamanhoVetor / 2; i++)
    {
        int numFlutuante;

        numFlutuante = vetor[i];
        vetor[i] = vetor[tamanhoVetor-1 - i];
        vetor[tamanhoVetor-1 - i] = numFlutuante;
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