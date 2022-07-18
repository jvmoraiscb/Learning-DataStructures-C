/* 
(BOCA:L3_11) Problema: Implemente um programa que dado a relação de números par ou
impar, retorne os N primeiros números desse tipo. Para isso, crie funções que dizem se o
número é par ou ímpar, uma função para printar os N primeiros pares a partir do 2 e uma
função para printar os N primeiros números ímpares a partir do 1.
As funções deverão ter os seguintes cabeçalhos:
a) int EhPar (int x)
b) void PrintaPares (int N)
c) void PrintaImpares (int N)
Obs: Cada numero na saída é separado por um único espaço.
 Entrada: A entrada é dada por TIPO, sendo 0 para PAR e 1 para IMPAR, e N, onde N está
entre 1<=N<=99999.
 Saída: Os N primeiros números do tipo pedido (par/ímpar).
 Exemplo de Entradas:
0 4
1 5
0 10
 Exemplo de Saídas:
2 4 6 8
1 3 5 7 9
2 4 6 8 10 12 14 16 18 20 
*/

#include <stdio.h>

int EhPar(int x);
void PrintaPares(int N); // Identificador == 0
void PrintaImpares(int N); // Identificador == 1

int main()
{
    int Identificador, N, i;

    scanf("%d %d", &Identificador, &N);
    
    if(N >= 1 && N <= 99999){
        if (Identificador == 0)
            PrintaPares(N);
        else if (Identificador == 1)
            PrintaImpares(N);
    }

    return 0;
}

int EhPar(int x)
{
    if (x%2 == 0)
        return 1;
    else
        return 0;
}

void PrintaPares(int N)
{
    int x=1, v=0;
    while (1)
    {
        if(EhPar(x) == 1){
            printf("%d ", x);
            v++;
        }
        if (v == N)
            break;
        x++;
           
    }
}

void PrintaImpares(int N)
{
    int x=1, v=0;
    while (1)
    {
        if(EhPar(x) == 0){
            printf("%d ", x);
            v++;   
        }
        if (v == N)
            break;
        x++;
    }
}