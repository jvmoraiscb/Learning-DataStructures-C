/* 
(BOCA:L4_6) Problema: Utilizando o tipo tPonto, implemente um tipo de dados
tReta para representar uma reta no plano cartesiano com coordenadas inteiras.
Implemente as seguintes funções para o tipo: (a) inicialização da reta a partir de um
ponto inicial e outro final; (b) inicialização a partir da leitura de dois pontos da
entrada padrão; (c) apresentação da reta com os pontos iniciais pi e finais pf no
seguinte formato “[(pi.x,pi.y):(pf.x,pf.y)]”; (d) obtenção do ponto inicial da reta; (e)
obtenção do ponto final da reta; (f) movimentação da reta; (g) tamanho da reta. Com
esse tipo, faça um programa que leia pontos e retas e informe se o ponto está mais
próximo do início ou do fim da reta.
• Entrada: Sua entrada deverá conter a quantidade de pontos e retas n a serem lidos, e os
pontos e retas em questão. Cada linha conterá um ponto, dado por 2 valores (x e y)
separados por espaço, e uma reta, isto é, mais dois pontos como o primeiro.
• Saída: Seu programa deverá apresentar um resultado para cada um dos n pares (ponto e
reta) dizendo “INICIO” se estiver mais próximo do início, “FIM” se estiver mais próximo do
final, ou “EQUIDISTANTE” se estiver a uma mesma distância do início e do fim.
• Exemplo de Entrada:
7
0 0 0 0 0 10
0 0 0 -10 0 10
0 0 0 -10 -5 5
5 5 0 0 10 10
6 6 0 0 10 10
0 10 0 0 10 10
0 5 0 0 10 10
• Exemplo de Saída:
INICIO
EQUIDISTANTE
FIM
EQUIDISTANTE
FIM
EQUIDISTANTE
INICIO 
*/

#include <stdio.h>
#include <math.h>

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


float calculaDistancia(tPonto pontoAnterior, tPonto pontoAtual);
void imprimeDistanciaReta(float distanciaInicio, float distanciaFinal);

void main()
{
    int ponto ,numPontos;
    tPonto pAtual;
    tReta rAtual;

    scanf("%d", &numPontos);

    for (ponto = 1; ponto <= numPontos; ponto++)
    {
        float distanciaInicio, distanciaFinal;

        scanf("%d %d %d %d %d %d%*c", &pAtual.x, &pAtual.y, &rAtual.pInicial.x, &rAtual.pInicial.y, &rAtual.pFinal.x, &rAtual.pFinal.y);

        distanciaInicio = calculaDistancia(pAtual, rAtual.pInicial);
        distanciaFinal = calculaDistancia(pAtual, rAtual.pFinal);

        imprimeDistanciaReta(distanciaInicio, distanciaFinal);
    }
}

float calculaDistancia(tPonto pontoAnterior, tPonto pontoAtual)
{
    float distanciaX, distanciaY;

    distanciaX = pontoAtual.x - pontoAnterior.x;
    distanciaY = pontoAtual.y - pontoAnterior.y;

    return sqrt(pow(distanciaX, 2) + pow(distanciaY, 2));
}

void imprimeDistanciaReta(float distanciaInicial, float distanciaFinal)
{
    if (distanciaInicial == distanciaFinal)
        printf("EQUIDISTANTE\n");
    else if (distanciaInicial < distanciaFinal)
        printf("INICIO\n");
    else if (distanciaInicial > distanciaFinal)
        printf("FIM\n");
}