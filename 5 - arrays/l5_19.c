/* 
(BOCA:L5_19) Problema: Um satélite tira fotos regulares da terra, e as imagens
são armazenadas em matrizes. Após um certo processamento na imagem, é possível
diferenciar água de terra (valores 0 representam terra e valores 1 representam
água). Assumindo que temos todas as fotos tiradas no período de maré mais baixa,
faça um programa para dizer a quantidade de terra visível no momento da aquisição
da foto e para predizer a quantidade de terra que estará visível após um
determinado número de horas (ver Figura 1). Considere que cada posição da matriz
é uma unidade, e que a quantidade de terra deverá ser reportada nessa unidade.
Considere também que a maré avança uma unidade para a esquerda, para a direita,
uma para cima, e uma para baixo a cada hora (a maré não avança na diagonal).
Assuma que as bordas da foto sempre conterão água e que não haverá bacias de
água.
Figura 1: Exemplo de evolução da maré, da esquerda para a direita: foto inicial (152 unidades), predição após
uma hora (112 unidades), predição após duas horas (76 unidades), predição após três horas (50 unidades),
predição após quatro horas (28 unidades).
 Entrada: a entrada consiste um número de horas h (0 ≤ h ≤ 8 para evitar descida da maré),
de dois inteiros w e h (≤ 600) definindo respectivamente a largura e a altura da foto.
Seguidos de h linhas de w caracteres descrevendo cada posição da foto. Caracteres com
valor 1 representarão água e caracteres com valor 0 representarão terra.
 Saída: quantidade de terra visível na aquisição da foto seguida da quantidade predita,
separadas por espaço.
 Exemplo de Entrada:
1
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
 Exemplo de Saída:
24 5
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int matrizes[600][600];
    int iMax;
    int jMax;
} tMatriz;

void leMatrizInicial(tMatriz *vetorMatrizes, int *dados);
void atualizaMatriz(tMatriz * vetorMatrizes);
void imprimeMatriz(tMatriz matriz);
void geraMatrizAnalise(tMatriz *vetorMatrizes, int nHoras);
void imprimeResultados(tMatriz *vetorMatrizes, int *dados);

int main()
{
    int dados[4]; //0.horas 1.largura 2.altura 3.unidadesTerraRestantesInicial
    scanf("%d%d%d%*c", &dados[0], &dados[1], &dados[2]);
    tMatriz matrizTerraMare[1];
    
    leMatrizInicial(matrizTerraMare, dados);
    //imprimeMatriz(matrizTerraMare[0]);
    geraMatrizAnalise(matrizTerraMare, dados[0]);

    imprimeResultados(matrizTerraMare, dados);

    return 0;
}

void leMatrizInicial(tMatriz *vetorMatrizes, int *dados)
{
    int i, j;
    int largura = dados[1], altura = dados[2];

    vetorMatrizes[0].jMax = largura;
    vetorMatrizes[0].iMax = altura;

    for(i = 0; i < vetorMatrizes[0].iMax; i++)
    {
        for(j = 0; j < vetorMatrizes[0].jMax; j++)
        {
            char c;

            scanf("%c", &c);
            if(c == '1')
                vetorMatrizes[0].matrizes[i][j] = 1;
            else if (c == '0')
                vetorMatrizes[0].matrizes[i][j] = 0;
        }
        scanf("%*c");
    }

    int unidadesTerraRestantesInicial = 0;
    for(i = 0; i < vetorMatrizes[0].iMax; i++)
    {
        for(j = 0; j < vetorMatrizes[0].jMax; j++)
        {
            if (vetorMatrizes[0].matrizes[i][j] == 0)
                unidadesTerraRestantesInicial++;   
        }
    }
    dados[3] = unidadesTerraRestantesInicial;
}

void geraMatrizAnalise(tMatriz *vetorMatrizes, int nHoras)
{
    int hora, i, j;

    for(hora = 0; hora < nHoras; hora++)
    {
        for(i = 0; i < vetorMatrizes[0].iMax; i++)
        {
            for(j = 0; j < vetorMatrizes[0].jMax; j++)
            {
                if (vetorMatrizes[0].matrizes[i][j] == 0)
                {
                    if(vetorMatrizes[0].matrizes[i-1][j] == 1 || vetorMatrizes[0].matrizes[i+1][j] == 1 || vetorMatrizes[0].matrizes[i][j-1] == 1 || vetorMatrizes[0].matrizes[i][j+1] == 1)
                        vetorMatrizes[0].matrizes[i][j] = -1;
                    else
                        vetorMatrizes[0].matrizes[i][j] = 0;
                }
                else
                    vetorMatrizes[0].matrizes[i][j] = 1;
            }
        }

        atualizaMatriz(vetorMatrizes);
        //imprimeMatriz(vetorMatrizes[0]);
    }
}

void imprimeMatriz(tMatriz matriz)
{
    int i, j;

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
        {
            printf("%d", matriz.matrizes[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void atualizaMatriz(tMatriz * vetorMatrizes)
{
    int i, j;

    for(i = 0; i < vetorMatrizes[0].iMax; i++)
    {
        for(j = 0; j < vetorMatrizes[0].jMax; j++)
        {
            if (vetorMatrizes[0].matrizes[i][j] == -1)
                vetorMatrizes[0].matrizes[i][j] = 1;   
        }
    }
}

void imprimeResultados(tMatriz *vetorMatrizes, int *dados)
{
    int i, j;
    int unidadesTerraRestantesInicial = dados[3];
    int unidadesTerraRestantesFinal = 0;

    for(i = 0; i < vetorMatrizes[0].iMax; i++)
    {
        for(j = 0; j < vetorMatrizes[0].jMax; j++)
        {
            if (vetorMatrizes[0].matrizes[i][j] == 0)
                unidadesTerraRestantesFinal++;   
        }
    }
    
    printf("%d %d\n", unidadesTerraRestantesInicial, unidadesTerraRestantesFinal);
}