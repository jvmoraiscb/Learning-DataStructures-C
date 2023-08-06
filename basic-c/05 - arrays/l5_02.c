/* 
(BOCA:L5_2) Problema: Faça um programa que lê notas (de 0 a 100) de N
participantes de um concurso para um vetor. No final, o programa deverá dizer se o
vetor está ordenado em ordem crescente, decrescente, ou se está desordenado.
 Entrada: 1 número inteiro N representando a o número de participantes, seguido de N
notas separadas por espaço.
 Saída: “CRESCENTE” se estiverem em ordem crescente, “DECRESCENTE” se estiverem em
ordem decrescente, “DESORDENADO” se estiverem desordenados,
“CRESCENTE&DECRESCENTE” caso seja unitário ou tenha todos os itens iguais.
 Exemplo de Entrada:
1 41
2 56 54
5 5 31 32 62 10
5 5 10 20 62 90
5 10 10 10 10 10
 Exemplo de Saída:
CRESCENTE&DECRESCENTE
DECRESCENTE
DESORDENADO
CRESCENTE
CRESCENTE&DECRESCENTE
*/

#include <stdio.h>

void preencheVetor(int notas[], int numNotas);
void imprimeOrdem(int notas[], int numNotas);

int main()
{
    int numNotas;
    scanf("%d", &numNotas);
    int notas[numNotas];

    preencheVetor(notas, numNotas);
    imprimeOrdem(notas, numNotas);

    return 0;
}

void preencheVetor(int vetor[], int tamanhoVetor)
{
    int nota;

    for(nota = 0; nota < tamanhoVetor; nota++)
    {
        scanf("%d", &vetor[nota]);
    }
}

void imprimeOrdem(int notas[], int numNotas)
{
    int nota;
    int numCrescente = 0, numDecrescente = 0, numIguais = 0;

    for(nota = 0; nota < numNotas; nota++)
    {
        if (nota != 0)
        {
            if(notas[nota] > notas[nota - 1])
                numCrescente++;
            else if(notas[nota] < notas[nota - 1])
                numDecrescente++;
            else
                numIguais++;
        }
    }

    if (numIguais == numNotas - 1 || numNotas == 1)
        printf("CRESCENTE&DECRESCENTE");
    else if (numCrescente > 0 && numDecrescente > 0)
        printf("DESORDENADO");
    else if (numCrescente > 0)
        printf("CRESCENTE");
    else if (numDecrescente > 0)
        printf("DECRESCENTE");
}