/* 
Problema: (BOCA: P3_2017_Q6_a) Você deve fazer um sistema para controlar um
robô de solda. O robô recebe coordenadas x e y de uma placa de circuito, onde ele
deve efetuar uma solda. A placa é representada por uma imagem composta por
zeros e uns e tendo cada elemento em uma posição (x,y) diferente da imagem. Você
deve identificar os locais a serem soldados na imagem e gerar a lista de coordenadas
dos pontos de solda. Para identificar os pontos de solda, você utilizará um template.
O template será representado também por uma imagem de zeros e uns, porém
sempre com dimensões menores do que a imagem da placa. Todos os locais da
imagem da placa que forem iguais a esse template devem ser soldados. A busca deve
ser feita varrendo linha a linha de cima para baixo e cada linha da esquerda para a
direita. Assuma a posição (0,0) da imagem e do template como sendo o canto
superior esquerdo e a posição final como sendo o canto inferior direito. OBS:
Cuidado para não extrapolar as dimensões da imagem ao varrer com o template.
• Entrada: A entrada consiste de duas imagens, uma representado a imagem da placa e outra
representando a imagem do template. Cada imagem será descrita por dois inteiros L e C
(dados em uma linha) representando respectivamente a quantidade de linhas e de colunas
da imagem seguidos dos elementos da imagem em si. Os elementos da imagem serão
dados em L linhas e C colunas. Ver exemplos de entrada abaixo.
• Saída: A saída deverá informar todos os pontos de solda da placa, sendo cada ponto dado
em uma linha e descrito pelas coordenadas x,y. Veja exemplo do formato de saída abaixo.
• Exemplo de Entrada:
10 8
10111111
00011101
10100000
10001101
10001101
11101101
10101001
00000101
10100000
11101101
3 3
101
000
101
10 8
10111111
00011101
10100000
10010101
10010101
11110101
10111001
00000101
10100000
11101101
3 5
10101
10101
10101
• Exemplo de Saída:
0,0
5,1
0,6
5,7
3,3
*/

#include <stdio.h>

typedef struct
{
    int iMax;
    int jMax;
    int matriz[500][500];

} tMatriz;

int templateEstaContido(tMatriz template, tMatriz matriz, int i, int j);
tMatriz preencheMatriz();
void verificaSolda(tMatriz matriz, tMatriz template);
void imprimeMatriz(tMatriz matriz);

int main()
{
    tMatriz placa, template;
    placa = preencheMatriz();
    template = preencheMatriz();
    
    verificaSolda(placa, template);
}

tMatriz preencheMatriz()
{
    tMatriz matriz;

    int i, j;
    scanf("%d %d", &matriz.iMax, &matriz.jMax);

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
        {
            scanf("%1d", &matriz.matriz[i][j]);
        }
    }

    return matriz;
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

void verificaSolda(tMatriz matriz, tMatriz template)
{
    int limiteI = matriz.iMax - template.iMax+1, limiteJ = matriz.jMax - template.jMax+1;
    int i, j;

    for(i = 0; i < limiteI; i++)
    {
        for(j = 0; j < limiteJ; j++)
        {
            if(templateEstaContido(template, matriz, i, j) == 1)
                printf("%d,%d\n", j, i);
        }
    }
}

int templateEstaContido(tMatriz template, tMatriz matriz, int i, int j)
{
    int elementosIguais = 0;
    int i0, j0, iTemplate = 0;

    for(i0 = i; i0 < i + template.iMax; i0++)
    {
        int jTemplate = 0;
        for(j0 = j; j0 < j + template.jMax; j0++)
        {
            if(matriz.matriz[i0][j0] == template.matriz[iTemplate][jTemplate])
                elementosIguais++;

            jTemplate++;
        }
        iTemplate++;
    }

    if(elementosIguais == template.iMax * template.jMax)
        return 1;
    else
        return 0;
}