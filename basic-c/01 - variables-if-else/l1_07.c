/*
(BOCA:L1_7) Problema: Faça um programa em que dada uma temperatura em
Celsius ou Fahrenheit converta esta temperatura para a outra unidade.
 Entrada: Temperatura e unidade correspondente.
 Saída: Temperatura convertida.
 Exemplo de Entrada:
10 f
10 F
10 c
10 C
 Exemplo de Saída:
-12.22 (C)
-12.22 (C)
50.00 (F)
50.00 (F)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	char cf; //temperatura em C ou F
	char spc; //espaço depois do valor
	float t; //valor da temperatura
	float cv; //resultado
	
	scanf("%f%c%c", &t, &spc, &cf);
	
	if (spc == ' ' && cf == 'C'){ 
	
	cv = t*9/5 + 32;
	
	printf("%.2f (F)", cv);
	
	}

	if (spc == ' ' && cf == 'c'){ 
	
	cv = t*9/5 + 32;
	
	printf("%.2f (F)", cv);
	
	}
	
	if (spc == ' ' && cf == 'F'){ 
	
	cv = (t - 32) * 5/9;
	
	printf("%.2f (C)", cv);
	
	}
	
	if (spc == ' ' && cf == 'f'){ 
	
	cv = (t - 32) * 5/9;
	
	printf("%.2f (C)", cv);
	
	}


   return 0;
}
