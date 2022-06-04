/*
(BOCA:L1_2) Problema: Faça um programa que calcule o perímetro de um
retângulo.
 Entrada: Altura e largura do retângulo.
 Saída: Perímetro do retângulo. Precisão de 2 casas decimais.
 Exemplo de Entrada:
10 20
14.83 53.29
1.9 117.1
 Exemplo de Saída:
60.00
136.24
238.00
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	float altura, largura, resultado;
	
	scanf("%f", &altura);
	scanf("%f", &largura);
	
	resultado = altura*2 + largura*2;
	
	printf("%.2f", resultado);	

    return 0;
}
