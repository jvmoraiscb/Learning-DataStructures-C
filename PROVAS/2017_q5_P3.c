/* 
Problema: (BOCA: P3_2017_Q5_a) Faça um programa que faça o deslocamento dos
números de uma sequência de acordo com os números de uma segunda sequência.
Cada número n da segunda sequência deverá gerar uma nova sequência como saída
(uma por linha) a partir dos itens da primeira sequência, deslocando esses itens de n
posições para direita. Se o item a ser deslocado ultrapassar a última posição, ele
deve recomeçar na primeira. Cada item n da segunda sequência deve fazer o
deslocamento da primeira sequência considerando o resultado do deslocamento
feito pelo item anterior, i.e. n-1. Assuma posições dos itens da primeira sequência
começando no índice 0. Por exemplo, dada a primeira sequência 1 2 3 e a segunda
sequência 2 1, o programa deverá imprimir duas sequências, uma como o resultado
do deslocamento de duas posições (relativo ao primeiro item da segunda sequência,
i.e. o 2) e outra como resultado do deslocamento de uma posição (relativo ao
segundo item da segunda sequência, i.e. o 1). O 2 (primeiro item da segunda
sequência) resultará na sequência 2 3 1, pois o item da posição 0 da primeira
sequência (i.e. 1) deve ir para a posição 2, o item da posição 1 (i.e. 2) deve ir para a
posição 0 e o item da posição 2 (i.e. 3) deve ir para a posição 1. O 1 (segundo item da
segunda sequência) atuará na sequência resultante de 2 (i.e. atuará na sequência
2 3 1) e resultará na sequência 1 2 3, pois o item da posição 0 da primeira sequência
deslocada por 2 (i.e. item 2) deve ir para a posição 1, o item da posição 1 (i.e. 3) deve
ir para a posição 2 e o item da posição 2 (i.e. 1) deve ir para a posição 0.
• Entrada: Vários pares de sequências. Cada par será dado por uma sequência a ser
deslocada (a primeira) e uma sequência que determinará deslocamentos (a segunda). A
primeira sequência será dada por um número inteiro s (maior do que zero) indicando a
quantidade elementos da sequência seguido dos s números em si. A segunda sequência
conterá números inteiros x representado os deslocamentos (0 <= x <= s-1) e será terminada
com um -1.
• Saída: A saída será composta de várias linhas com cada uma representando o resultado dos
deslocamentos da primeira sequência de cada par de sequências. Cada par de sequências
resultará em tantas linhas quantos elementos existirem na segunda sequência.
• Exemplo de Entrada:
9 1 2 3 4 5 6 7 8 9
2 2 1 -1
3 1 2 3
2 1 -1
12 10 20 30 40 50 60 70 80 90 90 90 90
1 5 6 11 0 -1
• Exemplo de Saída:
8 9 1 2 3 4 5 6 7
6 7 8 9 1 2 3 4 5
5 6 7 8 9 1 2 3 4
2 3 1
1 2 3
90 10 20 30 40 50 60 70 80 90 90 90
70 80 90 90 90 90 10 20 30 40 50 60
10 20 30 40 50 60 70 80 90 90 90 90
20 30 40 50 60 70 80 90 90 90 90 10
20 30 40 50 60 70 80 90 90 90 90 10
*/

#include <stdio.h>

void preencheVetor(int * vetor, int tamanhoVetor);
void deslocaVetor(int * vetor, int tamanhoVetor);
void printaVetor(int * vetor, int tamanhoVetor);
void copiaVetor(int * vetor, int * vetorDeslocado, int tamanhoVetor);


int main()
{
    int qtdNumeros;

    while(scanf("%d", &qtdNumeros) == 1)
    {
        int numeros[qtdNumeros];

        preencheVetor(numeros, qtdNumeros);
        //printaVetor(numeros, qtdNumeros);
        deslocaVetor(numeros, qtdNumeros);
    }

    return 0;
}

void preencheVetor(int * vetor, int tamanhoVetor)
{
    int i;

    for(i = 0; i < tamanhoVetor; i++)
        scanf("%d", &vetor[i]);
}

void deslocaVetor(int * vetor, int tamanhoVetor)
{
    int deslocamento;

    while(1)
    {
        scanf("%d", &deslocamento);
        if(deslocamento == -1)
            break;

        int vetorDeslocado[tamanhoVetor];

        int i;
        for(i = 0; i < tamanhoVetor; i++)
        {
            vetorDeslocado[calculaDeslocamento(i, deslocamento, tamanhoVetor)] = vetor[i];
        }

        printaVetor(vetorDeslocado, tamanhoVetor);
        copiaVetor(vetor, vetorDeslocado, tamanhoVetor);
    }
}

void printaVetor(int * vetor, int tamanhoVetor)
{
    int i;

    for(i = 0; i < tamanhoVetor; i++)
    {
        if(i == 0)    
            printf("%d", vetor[i]);
        else
            printf(" %d", vetor[i]);
    }
    printf("\n");
}

int calculaDeslocamento(int i, int deslocamento, int tamanhoVetor)
{
    int valorDeslocamento = i + deslocamento;

    if(valorDeslocamento >= tamanhoVetor)
        valorDeslocamento = valorDeslocamento - tamanhoVetor;

    return valorDeslocamento;
}

void copiaVetor(int * vetor, int * vetorDeslocado, int tamanhoVetor)
{
    int i;
    for(i = 0; i < tamanhoVetor; i++)
        vetor[i] = vetorDeslocado[i];
}
