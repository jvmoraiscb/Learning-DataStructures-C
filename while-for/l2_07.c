/*
(BOCA:L2_7) Problema: Faça um programa para informar se um número é primo.
 Entrada: Seu programa deverá receber um número inteiro para avaliação.
 Saída: Como saída, o programa deverá exibir se o número é primo ou não. Caso seja primo,
a mensagem “Primo“ deverá ser exibida. Caso não seja, a mensagem “Nao primo“ deverá
ser exibida. O formato de saída deve ser seguido RIGOROSAMENTE.
 Exemplo de Entrada:
2
3
4
12
13
 Exemplo de Saída:
Primo
Primo
Nao primo
Nao primo
Primo
*/
#include <stdio.h>

int main(){

	int n, c=0, d=1;
	
	scanf("%d", &n);
	
	while(n>=d){
		if (n%d==0){
			c++;
		}
		d++;
	}
	if (c==2){
		printf("Primo");
	}
	else {
		printf("Nao primo");
	}	
		
return 0;
}
