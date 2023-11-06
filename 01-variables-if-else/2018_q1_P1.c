/*
(BOCA: P1_2018_Q1) Problema: Faça um programa para dizer os quatro pontos
representando os cantos de um retângulo em um plano cartesiano. O retângulo será
inicialmente descrito por dois pontos representando cantos opostos.
• Entrada: 4 números inteiros representando dois pontos de cantos opostos de um retângulo.
Os dois primeiros números representam as coordenadas x e y do primeiro ponto e os dois
últimos as coordenadas x e y do segundo ponto. Os números estarão separados por um
espaço.
• Saída: A saída deverá imprimir os quatro pontos do retângulo dado na entrada seguindo a
ordem: canto superior esquerdo, canto inferior esquerdo, canto inferior direito e canto
superior direito. Cada ponto deverá ser dado entre parênteses seguindo o formato dos
exemplos abaixo.
• Exemplo de Entrada:
1 1 2 2
1 2 2 1
2 1 1 2
2 2 1 1
• Exemplo de Saída:
(1,2)(1,1)(2,1)(2,2)
(1,2)(1,1)(2,1)(2,2)
(1,2)(1,1)(2,1)(2,2)
(1,2)(1,1)(2,1)(2,2)
*/

#include <stdio.h>

int main(){
	
	int x1, y1, x2, y2;
	
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	if ((x1<x2) && (y1<y2)){
		printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x1,y2, x1,y1, x2,y1, x2,y2);
	}
	else if ((x1>x2) && (y1>y2)){
		printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x2,y1, x2,y2, x1,y2, x1,y1);
	}
	else if ((x1>x2) && (y1<y2)){
		printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x2,y2, x2,y1, x1,y1, x1,y2);
	}
	else if ((x1<x2) && (y1>y2)){
		printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x1,y1, x1,y2, x2,y2, x2,y1);
	}
return 0;
}
