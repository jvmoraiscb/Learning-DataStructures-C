/* 
(BOCA: P3_2019_Q2_a) Problema: Faça um programa para contar o número de
ocorrências de um padrão vertical ou horizontal em uma matriz. O programa deverá
ler a quantidade de elementos do padrão juntamente com um indicador dizendo se
ele será horizontal ou vertical (representado por “H” e “V” respectivamente).
Posteriormente, o programa deverá ler a matriz contendo os possíveis padrões e
fazer a contagem considerando a quantidade de elementos e o tipo do padrão a ser
contado, horizontal ou vertical. A matriz será formada por zeros “0” e xises “X”,
sendo os padrões formados por sequências de “X”.
• Entrada: na limeira linha, um inteiro e representando o número de elementos do padrão e
um caractere t, “H” ou “V”, representando respectivamente um padrão horizontal ou
vertical; na segunda linha, um inteiro l representando o número de linhas e um inteiro c
representando o número de colunas da matriz; na linhas seguintes, serão dados os
elementos de cada linha da matriz, sendo eles sem separação por espaço. Veja exemplos
abaixo.
• Saída: A mensagem “CONT:” seguida de “V” ou “H” dependendo do tipo de padrão contado
e o número de ocorrências do padrão. Ver exemplos abaixo!
• Exemplos de Entradas:
2H
4 5
0X0X0
00XX0
0XX00
0X00X
2V
5 4
0X0X
00XX
0XX0
0X00
0X00
3V
8 4
0X0X
XXXX
0XX0
0X00
0X00
0X0X
0X0X
0X0X
• Exemplos de Saídas:
CONT: H 2
CONT: V 4
CONT: V 7
*/

#include <stdio.h>

typedef struct
{
    int iMax;
    int jMax;
    char matriz[100][100];

}   tMatriz;

tMatriz preencheMatriz();
void imprimeMatriz(tMatriz matriz);
void verificaPadrao(tMatriz matriz, int tamanhoPadrao, char tipoPadrao);

int main()
{
    int tamanhoPadrao; char tipoPadrao;
    scanf("%d%c%*c", &tamanhoPadrao, &tipoPadrao);

    tMatriz matriz = preencheMatriz();
    //imprimeMatriz(matriz);
    verificaPadrao(matriz, tamanhoPadrao, tipoPadrao);

    return 0;
}

tMatriz preencheMatriz()
{
    tMatriz matriz;

    int i, j;
    scanf("%d %d%*c", &matriz.iMax, &matriz.jMax);

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
        {
            scanf("%c", &matriz.matriz[i][j]);
        }
        scanf("%*c");
    }

    return matriz;
}

void verificaPadrao(tMatriz matriz, int tamanhoPadrao, char tipoPadrao)
{
    int i, j, i0, j0;
    int qtdPadrao = 0, qtdX;

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
        {
            if(tipoPadrao == 'H')
            {
                qtdX = 0;
                for(j0 = j; j0 < j+tamanhoPadrao; j0++)
                {
                    //printf("%c\n", matriz.matriz[i][j0]);
                    if(matriz.matriz[i][j0] == 'X')
                        qtdX++;
                }
                if(qtdX == tamanhoPadrao)
                    qtdPadrao++;
            }
            if(tipoPadrao == 'V')
            {
                qtdX = 0;
                for(i0 = i; i0 < i+tamanhoPadrao; i0++)
                {
                    if(matriz.matriz[i0][j] == 'X')
                        qtdX++;
                }
                if(qtdX == tamanhoPadrao)
                    qtdPadrao++;
            }
        }
    }

    printf("CONT: %c %d\n", tipoPadrao, qtdPadrao);
}

void imprimeMatriz(tMatriz matriz)
{
    int i, j;

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
        {
            printf("%c", matriz.matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}