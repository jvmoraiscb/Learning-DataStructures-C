/* 
Problema: (BOCA: P3_2016_Q4) Faça um programa que diga quantos números de
uma lista de números são maiores do que cada elemento dessa lista. Isto é, para cada
elemento da lista, diga quantos dos elementos são maiores do que ele.
 Entrada: Um número c de casos a serem tratados seguido de c casos, um cada linha. Cada
caso será descrito por um número n > 0 representado a quantidade de elementos da lista
de números, seguido de n números inteiros positivos.
 Saída: A saída será composta por c linhas, uma para cada caso, com cada linha contendo n
números indicando quantidade de elementos que são maiores do que aquele respectivo
elemento. Por exemplo, o primeiro caso abaixo, “5 1 2 3 4 5”, contém 5 elementos “1 2 3 4
5” e tem como saída “4 3 2 1 0”, pois o elemento 1 possui 4 elementos maiores do que ele,
o 2 possui 3, o 3 possui 2, o 4 possui 1 e o 5 possui 0.
 Exemplo de Entrada:
5
5 1 2 3 4 5
6 6 5 4 3 2 1
1 3
2 4 3
7 1 2 3 4 3 2 1
 Exemplo de Saída:
4 3 2 1 0
0 1 2 3 4 5
0
0 1
5 3 1 0 1 3 5
*/

#include <stdio.h>

void analisaCaso();

int main()
{
    int nCasos, caso;
    scanf("%d%*c", &nCasos);

    for(caso = 0; caso < nCasos; caso++)
    {
        //printf("caso:%d\n", caso);
        analisaCaso();
    }
}

void analisaCaso()
{
    int i = 0, nNumeros;
    scanf("%d", &nNumeros);
    int numeros[nNumeros];

    for(i = 0; i < nNumeros; i++)
        scanf("%d", &numeros[i]);

    int i1, i2;
    for(i1 = 0; i1 < nNumeros; i1++)
    {
        int qtdNumerosMaiores = 0;

        for(i2 = 0; i2 < nNumeros; i2++)
        {
            if(numeros[i2] > numeros[i1])
                qtdNumerosMaiores++;
        }

        if(i1 == 0)
            printf("%d", qtdNumerosMaiores);
        else
            printf(" %d", qtdNumerosMaiores);
    }
    printf("\n");
}