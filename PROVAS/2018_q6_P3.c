/* 
Problema: (BOCA: P3_2018_Q6_a) Você deve fazer um sistema para contar a
quantidade de erros ocorridos em uma fábrica. Os erros serão identificados por
imagens. As imagens serão compostas por zeros e uns. Você deve identificar a
quantidade de erros ocorridos em uma imagem, procurando por um padrão
(procurando por um template). O template também será representado por uma
imagem de zeros e uns, porém sempre com dimensões menores do que a imagem
original. Todos os locais da imagem original que forem iguais a esse template devem
ser contados como erro. A busca deve ser feita varrendo toda a imagem original.
OBS: Cuidado para não extrapolar as dimensões da imagem ao varrer com o
template.
• Entrada: A entrada consiste de duas imagens, uma representado a imagem original e outra
representando a imagem do template de erro. Cada imagem será descrita por dois inteiros
L e C (dados em uma linha) representando respectivamente a quantidade de linhas e de
colunas da imagem seguidos dos elementos da imagem em si. Os elementos da imagem
serão dados em L linhas e C colunas. Ver exemplos de entrada abaixo.
• Saída: A saída deverá informar a quantidade de erros encontrados, seguindo o formato
“RESP:#”, em que # representa a quantidade de erros encontrados. Veja exemplo do
formato de saída abaixo.
OBS: Não precisa utilizar ou separar em tipos.
• Exemplo de Entrada:
6 7
0000100
0101010
1111111
0101010
1110011
0100010
3 3
010
111
010
5 4
0010
0111
0110
1111
1000
1 3
010
• Exemplo de Saída:
RESP:4
RESP:1
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
void verificaErros(tMatriz matriz, tMatriz template);
void imprimeMatriz(tMatriz matriz);

int main()
{
    tMatriz imagem, template;
    imagem = preencheMatriz();
    template = preencheMatriz();
    
    verificaErros(imagem, template);
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

void verificaErros(tMatriz matriz, tMatriz template)
{
    int limiteI = matriz.iMax - template.iMax+1, limiteJ = matriz.jMax - template.jMax+1;
    int i, j, qtdErros = 0;

    for(i = 0; i < limiteI; i++)
    {
        for(j = 0; j < limiteJ; j++)
        {
            if(templateEstaContido(template, matriz, i, j) == 1)
                qtdErros++;
        }
    }
    printf("RESP:%d", qtdErros);
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