/*
(BOCA:L1_8) Problema: Faça um programa que mostre se uma letra é ou não uma
vogal.
 Entrada: Uma letra do alfabeto.
 Saída: Mensagem dizendo se é ou não vogal.
 Exemplo de Entrada:
a
q
E
W
 Exemplo de Saída:
Vogal
Nao vogal
Vogal
Nao vogal
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	char l; //letra inserida
	
	scanf("%c", &l);
	
	if ((l == 'a') || (l == 'e') || (l == 'i') || (l == 'o') || (l == 'u') || (l == 'A') || (l == 'E')
	|| (l == 'I') || (l == 'O') || (l == 'U')) {
	
	printf("Vogal");
	
	} 
	
	else {
	
	printf("Nao vogal");
	
	}




   return 0;
}
