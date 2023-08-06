/*
(BOCA:L1_1) Problema: Faça um programa para ler 2 números inteiros e calcular
a soma de suas raízes quadradas.
 Entrada: 2 números inteiros.
 Saída: Soma das raízes quadradas dos números dados na entrada. Precisão de 2 casas
decimais.
 Exemplo de Entrada:
16 25
40 20
2 2
100 144
 Exemplo de Saída:
9.00
10.80
2.83
22.00
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int n1, n2;
    float somar2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    somar2 = sqrt(n1) + sqrt(n2);
    printf("%.2f", somar2);

    return 0;
}