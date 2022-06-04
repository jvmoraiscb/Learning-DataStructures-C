/*
(BOCA:L2_1) Problema: Desenvolva um programa para exibir todos os números
pares contidos em um determinado intervalo.
• Entrada: Sua entrada deverá conter dois valores n e m correspondentes aos extremos do
intervalo. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam
ser avaliados. Considere também que n sempre seja menor que m.
• Saída: Sua saída deverá conter todos os números pares pertencentes ao intervalo. O
formato deverá seguir os exemplos abaixo, i.e. “RESP:” seguido dos números.
• Exemplo de Entrada:
2 5
1 7
10 10
-10 -6
• Exemplo de Saída:
RESP:4
RESP:2 4 6
RESP:
RESP:-8
*/
#include <stdio.h>

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	printf("RESP:");
	for (i=n+1; i<m; i++){
		if (i%2==0) {
			printf("%d ",i);
		}	
	}	
return 0;
}
