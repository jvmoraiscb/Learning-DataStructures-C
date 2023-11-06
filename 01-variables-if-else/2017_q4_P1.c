/*
(BOCA: P1_2017_Q4) Problema: Faça um programa para descobrir o maior de 2
horários informados (com informação de horas, minutos e segundos) e imprimir o
algarismo das dezenas do valor da soma das horas, minutos e segundos do maior
horário.
• Entrada: 6 números inteiros positivos representando respectivamente os 3 valores que
compõem cada um dos horários informados (horas, minutos e segundos). Considere que os
horários informados são validos (i.e. não haverá horário fora do possível, ex. 26:23:2). Ex.
23 45 50 20 50 10 para representar 23:45:50 e 20:50:10 respectivamente.
• Saída: O programa deverá imprimir “IGUAIS” caso os dois horários sejam iguais, ou o valor
do digito da casa das dezenas da soma das horas, minutos e segundos do maior horário. Ex.
dados 19:45:50 19:50:11, o segundo horário informado seria escolhido resultando na soma
19+50+11=80. Portanto, 8 seria impresso por ser o algarismo das dezenas. Caso não exista
algarismo das dezenas (e.g. se a soma for menor do que 10), 0 deverá ser impresso.
• Exemplo de Entrada:
23 45 50 20 50 10
19 45 50 19 50 11
1 3 2 1 3 5
11 13 9 11 13 9
• Exemplo de Saída:
RESP:1
RESP:8
RESP:0
IGUAIS
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int h1, m1, s1, h2, m2, s2;
	int soma;
	
	
	scanf("%d%d%d%d%d%d", &h1, &m1, &s1, &h2, &m2, &s2);
	
if ((h1!=h2) || (m1!=m2) || (s1!=s2))

	{
	if (h1>h2){
	
		soma = h1+m1+s1;
	
	}
	
	else if (h2>h1){
	
		soma = h2+m2+s2;
	}	
	
	else if (m1>m2){
	
		soma = h1+m1+s1;
	
	}
	
	else if (m2>m1){
	
		soma = h2+m2+s2;
	}
	
	else if (s1>s2){
	
		soma = h1+m1+s1;
	
	}
	
	else {
	
		soma = h2+m2+s2;
	
	}
	
	if (soma<10){
	
		printf("RESP:0");
	
	}
	
	else if ((soma>=10) && (soma<100)){
	
		soma /=10;
		printf("RESP:%d", soma);
	
	}
	
	else {
	
		soma %=100;
		soma /=10;
		printf("RESP:%d", soma);
	
	}

}

else {

	printf("IGUAIS");

}

 return 0;
}
