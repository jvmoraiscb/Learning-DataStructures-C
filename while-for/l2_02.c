/*
(BOCA:L2_2) Problema: Faça um programa para apresentar todos os números
contidos em um intervalo e que sejam múltiplos de 3, 4 ou 7.
 Entrada: Sua entrada deverá conter dois valores n e m correspondentes aos extremos do
intervalo. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam
ser avaliados. Considere também que n sempre seja menor que m.
 Saída: Sua saída deverá conter todos os múltiplos de 3, 4 ou 7 pertencentes ao intervalo.
 Exemplo de Entrada:
2 5
20 25
10 15
30 40
 Exemplo de Saída:
3 4
21 24
12 14
32 33 35 36 39
*/
#include <stdio.h>

int main(){
	int n, m, i;
	scanf ("%d %d", &n, &m);
	for (i=n+1; i<m; i++){
		if ((i%3==0)||(i%4==0)||(i%7==0)){
			printf("%d ",i);
		}
	}

return 0;
}
