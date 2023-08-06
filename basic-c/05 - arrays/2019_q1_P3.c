/* 
(BOCA: P3_2019_Q1_a) Problema: Faça um programa para parear duas listas de
números, ou seja, cada número da primeira lista deverá ser pareado com o número
da posição correspondente da segunda lista. Caso não haja mais números a serem
pareados na segunda lista, o pareamento deve recomeçar do primeiro item da
segunda lista. Por exemplo, considerando a primeira lista como 1 2 3 2 7 e a segunda
como 2 4 6, o pareamento será: 1 – 2, 2 – 4, 3 – 6, 2 - 2, 7 – 4.
• Entrada: duas listas de números, sendo cada uma delas representada por um número
inteiro indicando a quantidade de números da lista, seguido (em outra linha) dos números
em si separados por espaço.
• Saída: A mensagem “PARES:” seguida (na outra linha) da lista de pares no formato “#1 -
#2”, em que #1 é um número da primeira lista e #2 é um número da segunda lista, sendo
cada par dado em uma linha. Ver exemplos abaixo!
• Exemplos de Entradas:
5
1 2 3 2 7
3
2 4 6
6
1 2 3 2 1 10
1
2
10
1 2 3 2 1 10 8 3 4 1
3
2 1 3
• Exemplos de Saídas:
PARES:
1 - 2
2 - 4
3 - 6
2 - 2
7 - 4
PARES:
1 - 2
2 - 2
3 - 2
2 - 2
1 - 2
10 - 2
PARES:
1 - 2
2 - 1
3 - 3
2 - 2
1 - 1
10 - 3
8 - 2
3 - 1
4 - 3
1 - 2
*/

#include <stdio.h>

void preencheVetor(int *vetor, int tamanhoVetor);
void printaPares(int *vetor1, int tamanhoVetor1, int *vetor2, int tamanhoVetor2);

int main()
{
    int qtdLista1, qtdLista2;

    scanf("%d", &qtdLista1);
    int lista1[qtdLista1];
    preencheVetor(lista1, qtdLista1);

    scanf("%d", &qtdLista2);
    int lista2[qtdLista2];
    preencheVetor(lista2, qtdLista2);

    printaPares(lista1, qtdLista1, lista2, qtdLista2);

    return 0;
}

void preencheVetor(int *vetor, int tamanhoVetor)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]); 
    }
}

void printaPares(int *vetor1, int tamanhoVetor1, int *vetor2, int tamanhoVetor2)
{
    printf("PARES:\n");
    int iPar1, iPar2 = 0;

    for(iPar1 = 0; iPar1 < tamanhoVetor1; iPar1++)
    {
        if(iPar2 == tamanhoVetor2)
            iPar2 = 0;

        printf("%d - %d\n", vetor1[iPar1], vetor2[iPar2]);
        iPar2++;
    }
}