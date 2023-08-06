/*
(BOCA: P1_2016_Q1) Problema: Faça um programa para dizer o dia da semana de
acordo com o número informado, sendo Domingo para 1, Segunda para 2, ..., Sabado
para 7 e Invalido para qualquer outra coisa.
 Entrada: 1 número inteiro.
 Saída: Dia da semana correspondente {Domingo, Segunda, Terca, Quarta, Quinta, Sexta,
Sabado, ou Invalido}.
 Exemplo de Entrada:
1
2
3
4
5
6
7
11
 Exemplo de Saída:
Domingo
Segunda
Terca
Quarta
Quinta
Sexta
Sabado
Invalido
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int dia;	
	
	scanf("%d", &dia);
	
	if (dia == 1) {
	
		printf("Domingo");
	
	}
	
	else if (dia == 2) {
	
		printf("Segunda");
	
	}
	
	else if (dia == 3) {
	
		printf("Terca");
	
	}
	
	else if (dia == 4) {
	
		printf("Quarta");
	
	}
	
	else if (dia == 5) {
	
		printf("Quinta");
	
	}
	
	else if (dia == 6) {
	
		printf("Sexta");
	
	}
	
	else if (dia == 7) {
	
		printf("Sabado");
		
	}
	
	else {
	
		printf("Invalido");
	
	}
		
  return 0;
}
