/* 
(BOCA:L4_5) Problema: Com o tipo tPonto definido acima, faça um programa que
leia n pontos e informe a distância para seu predecessor em ordem de
aparecimento. Caso não haja predecessor, imprima “-”.
• Entrada: Sua entrada deverá conter a quantidade de pontos n a serem lidos, e os pontos
em questão. Cada ponto será dado em uma linha e por 2 valores (x e y) separados por
espaço.
• Saída: Seu programa deverá exibir o valor da distância (com precisão de 2 casas decimais)
para seu predecessor (em relação à ordem de leitura), ou um ”-” caso seja o primeiro item.
• Exemplo de Entrada:
7
30 11
-04 03
-30 -11
30 -11
30 0
0 11
0 0
• Exemplo de Saída:
-
34.93
29.53
60.00
11.00
31.95
11.00 
*/

#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;

} tPonto;

int quadrante(tPonto ponto);
tPonto simetrico(tPonto p);
void imprimeCoordenadas(tPonto p, tPonto pSimetrico);
float calculaDistancia(tPonto pontoAnterior, tPonto pontoAtual);

void main()
{
    int ponto ,numPontos;
    tPonto pAtual, pAnterior;

    scanf("%d", &numPontos);

    for (ponto = 1; ponto <= numPontos; ponto++)
    {
        float distancia;

        scanf("%d %d", &pAtual.x, &pAtual.y);
        if (ponto == 1)
            printf("-\n");
        else{
            distancia = calculaDistancia(pAnterior, pAtual);
            printf("%.2f\n", distancia);
        }

        pAnterior = pAtual;
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

tPonto simetrico(tPonto ponto)
{
    tPonto pontoSimetrico = ponto;

    pontoSimetrico.x *= -1;
    pontoSimetrico.y *= -1;

    return pontoSimetrico;
}

void imprimeCoordenadas(tPonto ponto, tPonto pontoSimetrico)
{
    printf("(%d,%d) %d (%d,%d) %d\n", ponto.x, ponto.y, quadrante(ponto), pontoSimetrico.x, pontoSimetrico.y, quadrante(pontoSimetrico));
}

float calculaDistancia(tPonto pontoAnterior, tPonto pontoAtual)
{
    float distanciaX, distanciaY;

    distanciaX = pontoAtual.x - pontoAnterior.x;
    distanciaY = pontoAtual.y - pontoAnterior.y;

    return sqrt(pow(distanciaX, 2) + pow(distanciaY, 2));
}