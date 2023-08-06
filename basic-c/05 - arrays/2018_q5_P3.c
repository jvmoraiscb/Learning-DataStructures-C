/* 
Problema: (BOCA: P3_2018_Q5_a) Faça um programa que realize a soma de
números enormes. Esses números enormes não podem ser armazenados nos tipos
básicos de dados da linguagem C, portanto você deverá usar vetores para armazenar
os números (uma posição para cada dígito). Para fazer a soma, o programa deverá
implementar com vetores o método de soma que aprendemos no ensino
fundamental (ver exemplo abaixo). O programa receberá uma lista com uma
quantidade n de números, deverá somar cada par de números consecutivos (ex.
número 0 somado com o 1, o 2 com o 3, a 4 com o 5, etc.) e apresentar o resultado da
soma de cada par números em uma linha.
Exemplo de soma de 3124 com 88:
1 1
3 1 2 4
+ 8 8
---------
3 2 1 2
• Entrada: Um número n (sendo n um par maior ou igual a 1) indicando a quantidade de
pares de números dados, seguido dos números em si, sendo um número em cada linha. Os
números dados em cada linha serão representados por dígitos (0 a 9) separados por
espaço. O segundo número do par terá sempre uma quantidade menor ou igual de dígitos
do que o primeiro número do par. O número dado em cada linha será sempre terminado
com um -1 e nunca terá mais do que 50 dígitos. Por exemplo, o número 17293 seria dado
em uma linha como: 1 7 2 9 3 -1.
• Saída: A saída será composta de várias linhas (metade das linhas de entrada), sendo cada
uma delas para apresentar o resultado da soma de dois números consecutivos. Ver a
formatação nos exemplos abaixo.
OBS: Não precisa utilizar ou separar em tipos.
• Exemplo de Entrada:
8
9 9 9 9 9 9 9 9 9 8 -1
2 -1
3 1 2 4 -1
2 1 -1
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 -1
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 -1
1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 -1
9 8 7 6 5 4 3 2 1 -1
1 2 3 4 5 -1
5 4 3 2 1 -1
1 0 0 0 0 1 -1
0 1 1 -1
6 -1
7 -1
1 0 8 2 1 -1
5 0 0 -1
• Exemplo de Saída:
10000000000
3145
199999999999999999999999999999999999998
123456789123456790111111110
66666
100012
13
11321
*/

#include <stdio.h>

void preencheVetor(int *vetor);
void imprimeVetor(int *vetor);
void somaVetores(int *vetor1, int *vetor2, int *soma);

int main()
{
    int i, nPares;
    scanf("%d", &nPares);

    for(i = 0; i < nPares; i++)
    {
        int num1[50] = {0}, num2[50] = {0}, soma[50] = {0};
        preencheVetor(num1);
        preencheVetor(num2);
        
        somaVetores(num1, num2, soma);
        imprimeVetor(soma);
    }

    return 0;
}

void preencheVetor(int *vetor)
{
    int i = -1;
    int vetorAtual[50];

    while(1)
    {
        int num;
        scanf("%d", &num);
        if(num == -1)
            break;

        i++;
        vetorAtual[i] = num;
    }
    int i0, i1 = 49;
    for(i0 = i; i0 >= 0; i0--)
    {
        vetor[i1] = vetorAtual[i0];
        i1--;
    }
}

void imprimeVetor(int *vetor)
{
    int i, inicioNumero = 0;

    for (i = 0; i < 50; i++){
        if(vetor[i] != 0)
            inicioNumero = 1;

        if(inicioNumero == 1)
            printf("%d", vetor[i]);
    }
    printf("\n");
}

void somaVetores(int *vetor1, int *vetor2, int *soma)
{
    int i;

    for(i = 49; i >= 0; i--)
    {
        soma[i] += vetor1[i] + vetor2[i];
        if(soma[i] > 9 && i != 0)
        {
            soma[i] = soma[i] - 10;
            soma[i-1] += 1;
        }
    }
}