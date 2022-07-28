/*
(BOCA:L2_5) Problema: Escreva um programa para calcular o valor de π de acordo
com a seguinte fórmula:
for (k=1; k<=n; k++){
	pi+=6/pow(k, 2);
}
 Entrada: Seu programa deverá receber o valor de n.
 Saída: Seu programa deverá exibir o valor calculado para 𝜋, sempre com precisão de 6
casas após a vírgula.
 Exemplo de Entrada:
1
2
3
100
 Exemplo de Saída:
2.449490
2.738613
2.857738
3.132077
*/
#include <stdio.h>
#include <math.h>

int main(){
	int n, k;
	float pi=0;
	
	scanf("%d", &n);
	
	for (k=1; k<=n; k++){
		pi+=6/pow(k, 2);
	}
	
	printf("%f", sqrt(pi));
	
return 0;
}
