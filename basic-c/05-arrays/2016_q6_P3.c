/* 
Problema: (BOCA: P3_2016_Q6) Os bilionários do mundo, donos de pequenos
arquipélagos de ilhas, decidiram construir um muro ao redor de suas ilhas para
evitar que invasores entrassem em seu território. Portanto, eles decidiram calcular
quanto seria necessário gastar para proteger cada arquipélago. Para construir o
muro aproveitando ao máximo das propriedades de terra, eles decidiram construí-lo
na borda de cada ilha. Cada bilionário tem um mapa representado o arquipélago e
esse mapa indica se uma determinada posição representa água ou terra. Uma
posição do mapa representando terra pode ser definida como borda quando pelo
menos uma de suas 8 posições vizinhas representa água. O custo final do muro do
arquipélago será dado pelo número de posições no mapa que deverão conter muro
futuramente. Faça um programa para calcular esse custo.
 Entrada: A entrada consiste de dois inteiros w e h (menores do que 600) definindo
respectivamente a largura e a altura do mapa representando o arquipélago. Seguidos de h
linhas de w caracteres descrevendo cada posição do mapa. Caracteres com valor 1
representarão água e caracteres com valor 0 representarão terra. Assuma que as posições
localizadas nas bordas do mapa sempre conterão agua.
 Saída: Sua saída deverá simplesmente informar o custo para proteger o arquipélago.
 Exemplo de Entrada:
8 10
11111111
10011111
10001101
10001111
11001111
11111111
11000011
11000001
11000011
11111111
6 5
111111
100011
100001
100011
111111
 Exemplo de Saída:
22
9
*/

#include <stdio.h>

typedef struct
{
    int iMax;
    int jMax;
    int matriz[500][500];
} tMatriz;

int ehBorda(tMatriz * matriz, int i, int j);
void leMapa(tMatriz * matriz);
void analisaMapa(tMatriz * matriz);
void imprimeMatriz(tMatriz matriz);

int main()
{
    tMatriz mapa[1];

    leMapa(mapa);
    //imprimeMatriz(mapa[0]);
    analisaMapa(mapa);

    return 0;
}

void leMapa(tMatriz * matriz)
{
    int i, j;
    scanf("%d %d", &matriz[0].jMax, &matriz[0].iMax);

    for(i = 0; i < matriz[0].iMax; i++)
    {
        for(j = 0; j < matriz[0].jMax; j++)
        {
            scanf("%1d", &matriz[0].matriz[i][j]);
        }
    }
}

void analisaMapa(tMatriz * matriz)
{
    int i, j, qtdBorda = 0;

    for(i = 0; i < matriz[0].iMax; i++)
    {
        for(j = 0; j < matriz[0].jMax; j++)
        {
            if(matriz[0].matriz[i][j] == 0 && ehBorda(matriz, i, j) == 1)
                qtdBorda++;
        }
    }
    printf("%d\n", qtdBorda);
}

void imprimeMatriz(tMatriz matriz)
{
    int i, j;

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
        {
            printf("%d", matriz.matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int ehBorda(tMatriz * matriz, int i, int j)
{
    /* 
        1 1 1
        1 0 1
        1 1 1
    */

    if(matriz[0].matriz[i][j-1] == 1 || matriz[0].matriz[i][j+1] == 1 || matriz[0].matriz[i+1][j-1] == 1 || matriz[0].matriz[i+1][j] == 1 || matriz[0].matriz[i+1][j+1] == 1 || matriz[0].matriz[i-1][j-1] == 1 || matriz[0].matriz[i-1][j] == 1 || matriz[0].matriz[i-1][j+1] == 1)
        return 1;
    else
        return 0;
}
