/*
(BOCA:L1_4) Problema: Construa um programa para calcular a área de um círculo
e o raio de um círculo com metade desta área. Utilize o valor de Π = 3.141592.
 Entrada: Raio do círculo.
 Saída: Área do círculo e raio de um círculo cuja área é metade da área. Precisão de 2 casas
decimais.
 Exemplo de Entrada:
10
1.99
429.73
 Exemplo de Saída:
 314.16 7.07
12.44 1.41
580151.12 303.86
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	float r1, a1, r2, a2, pi;
		
	pi = 3.141592;
	
	scanf("%f", &r1);
	
	a1 = pi*r1*r1;
	a2 = a1/2;
	r2 = sqrt(a2/pi);
	
	printf("%.2f %.2f", a1, r2);

    return 0;
}
