/* 
(BOCA:L4_7) Problema: Usando o tipo tReta acima, faça um programa para
informar se uma reta está totalmente contida em um quadrante.
• Entrada: Sua entrada deverá conter a quantidade de retas n a serem lidas, e as retas em
questão. Cada linha conterá uma reta dada por 2 pontos e com cada um deles dado por 2
valores (x e y) separados por espaço.
• Saída: Seu programa deverá apresentar um resultado para cada uma das n retas dizendo
“MESMO” se o ponto inicial e final estiverem em um mesmo quadrante, ou “DIFERENTE”
caso contrário. Considere retas tocando os eixos tendo quadrante diferente.
• Exemplo de Entrada:
7
0 0 0 10
0 0 10 10
1 1 10 10
-1 -1 10 10
-1 -1 -10 -10
-1 1 -10 10
-1 1 10 -10
• Exemplo de Saída:
DIFERENTE
DIFERENTE
MESMO
DIFERENTE
MESMO
MESMO
DIFERENTE 
*/

#include <stdio.h>

typedef struct
{
    int x;
    int y;

} tPonto;

typedef struct 
{
    tPonto pInicial;
    tPonto pFinal;

} tReta;

int quadrante(tPonto ponto);
void imprimeQuadrantes(tReta reta);

void main()
{
    int reta ,numRetas;
    tReta rAtual;

    scanf("%d", &numRetas);

    for (reta = 1; reta <= numRetas; reta++)
    {
        float distanciaInicio, distanciaFinal;

        scanf("%d %d %d %d%*c", &rAtual.pInicial.x, &rAtual.pInicial.y, &rAtual.pFinal.x, &rAtual.pFinal.y);

        imprimeQuadrantes(rAtual);
    }
}

int quadrante(tPonto ponto)
{
    if (ponto.x == 0 || ponto.y == 0)
        return 0;
    else if (ponto.x > 0 && ponto.y > 0)
        return 1;
    else if (ponto.x < 0 && ponto.y > 0)
        return 2;
    else if (ponto.x < 0 && ponto.y < 0)
        return 3;
    else if (ponto.x > 0 && ponto.y < 0)
        return 4;
}

void imprimeQuadrantes(tReta reta)
{
    if ( quadrante(reta.pInicial) != quadrante(reta.pFinal) || quadrante(reta.pInicial) == 0 || quadrante(reta.pFinal) == 0 )
        printf("DIFERENTE\n");
    else
        printf("MESMO\n");
}