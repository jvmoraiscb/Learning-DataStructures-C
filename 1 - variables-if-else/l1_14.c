/*
(BOCA:L1_14) Problema: Faça um programa que diga se um ponto está contido em
um retângulo dado os cantos opostos do mesmo. Pontos que caiam na linha do
retângulo são considerados dentro.
 Entrada: Coordenadas de dois cantos opostos do retângulo e de um ponto qualquer,
respectivamente. Cantos e pontos são descritos por uma coordenada x e uma y, nessa
ordem.
 Saída: Mensagem dizendo se o ponto está ou não dentro do retângulo.
 Exemplo de Entrada:
0 0 10 10 5 3
0 10 10 0 5 3
10 10 0 0 5 3
10 0 0 10 5 3
1 1 -10 -10 -5 -3
1 -10 -10 1 -5 -3
-10 -10 1 1 -5 -3
-10 1 1 -10 -5 -3
0 0 10 10 -1 -1
0 10 10 0 11 11
 Exemplo de Saída:
Dentro
Dentro
Dentro
Dentro
Dentro
Dentro
Dentro
Dentro
Fora
Fora
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int x1, y1, x2, y2, x0, y0;
	int xdentro, ydentro;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x0, &y0);
	
	if ((x0 >= x1 && x0 <= x2) || (x0 <= x1 && x0 >= x2)) {
	
		xdentro = 1;
	
	}
	
	else {
	
		xdentro = 0;
	
	}
	

	if ((y0 >= y1 && y0 <= y2) || (y0 <= y1 && y0 >= y2)) {
	
		ydentro = 1;
	
	}
	
	else {
	
		ydentro = 0;
	
	}

	if (xdentro == 1 && ydentro == 1) {
	
		printf("Dentro");
	
	}


	else
	
		printf("Fora");

   return 0;
}
