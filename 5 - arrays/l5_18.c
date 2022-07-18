/* 
(BOCA:L5_18) Problema: Faça um programa para multiplicar duas matrizes de
inteiros. Uma sequência de pares de matrizes será dada, e o programa deverá
multiplicar a primeira pela segunda quando for possível.
 Entrada: um número N representando a quantidade de pares de matrizes a serem
multiplicados seguido de N pares de matrizes. Um par de matrizes é dado por duas matrizes
na sequência, e cada matriz é descrita por um C (número de colunas) e um L (número de
linhas) seguidos do conteúdo em si.
 Saída: A matriz resultante de cada multiplicação, ou “IMPOSSIVEL” caso não seja possível
multiplicar. Uma linha vazia deve separar uma matriz da outra.
 Exemplo de Entrada:
3
2 3
1 2
3 4
5 6
3 2
1 2 3
4 5 6
4 4
1 2 1 2
2 1 2 1
1 1 2 2
2 2 1 1
4 2
1 2 1 2
2 1 2 1
2 2
1 2
3 4
1 2
1
2
 Exemplo de Saída:
9 12 15
19 26 33
29 40 51
IMPOSSIVEL
5
11
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int matrizes[100][100];
    int iMax;
    int jMax;
} tMatriz;

void leMatrizes(tMatriz *matrizes, int nMatrizes);
void imprimeMatrizes(tMatriz *matrizes, int nMatrizes);
void imprimeMatriz(tMatriz matriz);
void imprimeMatrizAxB(tMatriz *matrizes, int nMatrizes);
void preencheZero(tMatriz *matrizes, int nMatrizes);

int main()
{
    int nParesMatrizes;
    scanf("%d", &nParesMatrizes);
    nParesMatrizes *= 2;

    tMatriz matrizes[nParesMatrizes];
    leMatrizes(matrizes, nParesMatrizes);
    //imprimeMatrizes(matrizes, nParesMatrizes);
    imprimeMatrizAxB(matrizes, nParesMatrizes);
}

void leMatrizes(tMatriz *vetorMatrizes, int nMatrizes)
{
    int matriz, i, j;

    for(matriz = 0; matriz < nMatrizes; matriz++)
    {
        scanf("%d%d", &vetorMatrizes[matriz].jMax, &vetorMatrizes[matriz].iMax);
        for(i = 0; i < vetorMatrizes[matriz].iMax; i++)
        {
            for(j = 0; j < vetorMatrizes[matriz].jMax; j++)
            {
                scanf("%d", &vetorMatrizes[matriz].matrizes[i][j]);
            }
        }
    }
}

void imprimeMatrizes(tMatriz *vetorMatrizes, int nMatrizes)
{
    int matriz, i, j;

    for(matriz = 0; matriz < nMatrizes; matriz++)
    {
        for(i = 0; i < vetorMatrizes[matriz].iMax; i++)
        {
            for(j = 0; j < vetorMatrizes[matriz].jMax; j++)
            {
                printf("%d ", vetorMatrizes[matriz].matrizes[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void imprimeMatriz(tMatriz matriz)
{
    int i, j;

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
        {
            printf("%d ", matriz.matrizes[i][j]);
        }
        printf("\n");
    }
}

void imprimeMatrizAxB(tMatriz *vetorMatrizes, int nMatrizes)
{
    int matriz, matrizAtual = 0, i, j;
    tMatriz matrizMultiplicada[nMatrizes];
    preencheZero(matrizMultiplicada, nMatrizes);

    for(matriz = 0; matriz < nMatrizes; matriz = matriz + 2)
    {
        if(vetorMatrizes[matriz].jMax == vetorMatrizes[matriz+1].iMax){
            int qtdSomas;
            qtdSomas = vetorMatrizes[matriz].jMax;
            matrizMultiplicada[matrizAtual].iMax = vetorMatrizes[matriz].iMax;
            matrizMultiplicada[matrizAtual].jMax = vetorMatrizes[matriz+1].jMax;
            //imprimeMatriz(matrizMultiplicada[matrizAtual]);

            for(i = 0; i < matrizMultiplicada[matrizAtual].iMax; i++)
            {
                int i1 = i;
                
                for(j = 0; j < matrizMultiplicada[matrizAtual].jMax; j++)
                {
                    int j2 = j;
                    int somas;
                    int j1 = 0, i2 = 0;

                    for(somas = 0; somas < qtdSomas; somas++)
                    {
                        matrizMultiplicada[matrizAtual].matrizes[i][j] += vetorMatrizes[matriz].matrizes[i1][j1] * vetorMatrizes[matriz+1].matrizes[i2][j2];
                        //printf("%d %d %d\n", matrizMultiplicada[matrizAtual].matrizes[i][j],vetorMatrizes[matriz].matrizes[i1][j1], vetorMatrizes[matriz+1].matrizes[i2][j2]);

                        j1++; i2++;
                    }
                }
            }

            imprimeMatriz(matrizMultiplicada[matrizAtual]);
        }
        else
            printf("IMPOSSIVEL\n");

        printf("\n");
        matrizAtual++;
    }
}

void preencheZero(tMatriz *vetorMatrizes, int nMatrizes)
{
    int matriz, i, j;

    for(matriz = 0; matriz < nMatrizes; matriz++)
    {
        for(i = 0; i < vetorMatrizes[matriz].iMax; i++)
        {
            for(j = 0; j < vetorMatrizes[matriz].jMax; j++)
            {
                vetorMatrizes[matriz].matrizes[i][j] = 0;
            }
        }
    }
}
