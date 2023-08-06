/* 
 (BOCA:L4_4) Problema: Implemente um tipo de dados tPonto para representar um
ponto cartesiano com coordenadas inteiras. Implemente as seguintes funções para o
tipo: (a) inicialização do ponto a partir de um x e um y dados; (b) inicialização de
ponto com coordenadas lidas da entrada padrão; (c) apresentação das coordenadas
do ponto na saída padrão com o formato “(x,y)”; (d) alteração da abscissa x do
ponto; (e) alteração da ordenada y do ponto; (f) obtenção da abscissa x do ponto; (g)
obtenção da ordenada y do ponto; (h) movimentação do ponto por um delta x e um
delta y; (i) cálculo da distância entre dois pontos; (j) identificação do quadrante do
ponto (1, 2, 3 ou 4 para os quadrantes normais e 0 para pontos em cima dos eixos);
(k) obtenção do ponto simétrico a um ponto. Com esse tipo, faça um programa que
leia n pontos e informe seu quadrante, seu simétrico e o quadrante do seu simétrico.
• Entrada: Sua entrada deverá conter a quantidade de pontos n a serem lidos, e os pontos
em questão. Cada ponto será dado em uma linha e por 2 valores (x e y) separados por
espaço.
• Saída: Sua saída deverá apresentar o ponto seguido do seu quadrante, do seu simétrico e
do quadrante do seu simétrico.
• Exemplo de Entrada:
7
4 0
0 4
4 1
4 -1
-4 1
-4 -1
0 0
• Exemplo de Saída:
(4,0) 0 (-4,0) 0
(0,4) 0 (0,-4) 0
(4,1) 1 (-4,-1) 3
(4,-1) 4 (-4,1) 2
(-4,1) 2 (4,-1) 4
(-4,-1) 3 (4,1) 1
(0,0) 0 (0,0) 0 
*/

#include <stdio.h>

typedef struct
{
    int x;
    int y;

} tPonto;

int quadrante(tPonto ponto);
void imprimeCoordenadas(tPonto p, tPonto pSimetrico);
tPonto simetrico(tPonto p);
tPonto lePonto();

void main()
{
    int ponto ,numPontos;

    scanf("%d", &numPontos);

    for (ponto = 1; ponto <= numPontos; ponto++)
    {
        tPonto p, pSimetrico;

        p = lePonto();
        pSimetrico = simetrico(p);

        imprimeCoordenadas(p, pSimetrico);
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

void imprimeCoordenadas(tPonto ponto, tPonto pontoSimetrico)
{
    printf("(%d,%d) %d (%d,%d) %d\n", ponto.x, ponto.y, quadrante(ponto), pontoSimetrico.x, pontoSimetrico.y, quadrante(pontoSimetrico));
}

tPonto simetrico(tPonto ponto)
{
    tPonto pontoSimetrico = ponto;

    pontoSimetrico.x *= -1;
    pontoSimetrico.y *= -1;

    return pontoSimetrico;
}

tPonto lePonto()
{
    tPonto p;

    scanf("%d %d", &p.x, &p.y);
    
    return p;
}