/*
(BOCA: P1_2019_Q1) Problema: Faça um programa para dizer se três números estão
em ordem crescente, decrescente ou tudo doido.
• Entrada: 3 números inteiros. Os números estarão separados por um espaço.
• Saída: A saída deverá imprimir “CRESCENTE”, “DECRESCENTE” ou “TUDO DOIDO” se os
números estiverem respectivamente em ordem crescente, decrescente ou nenhuma das
anteriores.
• Exemplos de Entradas:
1 1 1
3 2 1
-2 10 30
2 1 2
• Exemplos de Saídas:
TUDO DOIDO
DECRESCENTE
CRESCENTE
TUDO DOIDO
*/

#include <stdio.h>

int main(){
	
	int n1, n2, n3;
	
	scanf("%d %d %d",&n1, &n2, &n3);
	
	if ((n1<n2)&&(n2<n3)){
		printf("CRESCENTE");
	}
	else if ((n1>n2)&&(n2>n3)){
		printf("DECRESCENTE");
	}
	else{
		printf("TUDO DOIDO");
	}
	
return 0;
}
