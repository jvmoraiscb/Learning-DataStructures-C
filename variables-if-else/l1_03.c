/*
(BOCA:L1_3) Problema: Faça um programa que calcule o perímetro de um
retângulo.
 Entrada: Coordenadas (x,y) dos cantos inferior esquerdo e superior direito do retângulo.
 Saída: Perímetro do retângulo. Precisão de 2 casas decimais.
 Exemplo de Entrada:
0 15 20 25
0 0 13.5 7.75
 Exemplo de Saída:
60.00
42.50
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	float cx1, cy1, cx2, cy2, peri;
	
	scanf("%f%f%f%f", &cx1, &cy1, &cx2, &cy2);
	
	peri = (cx2 - cx1)*2 + (cy2 - cy1)*2;
	
	printf("%.2f", peri);




    return 0;
}
