/*
(BOCA:L1_10) Problema: Faça um programa que mostre se um número é par ou
ímpar.
 Entrada: Número inteiro.
 Saída: “Par” ou “Impar”.
 Exemplo de Entrada:
1
2
-3
0
 Exemplo de Saída:
Impar
Par
Impar
Par
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int n;
	
	scanf("%d", &n);
	
	if (n%2 == 0){
	
		printf("Par");
	
	}

	else 
	
		printf("Impar");

   return 0;
}
