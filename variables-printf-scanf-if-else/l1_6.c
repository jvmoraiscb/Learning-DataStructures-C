/*
(BOCA:L1_6) Problema: Faça um programa que calcule a média de duas notas e
diga se o aluno está aprovado caso sua média seja maior ou igual a 7.0, reprovado
caso média menor que 5.0 ou de recuperação caso contrário.
 Entrada: 2 notas parciais em números inteiros.
 Saída: Média e mensagem apropriada. Precisão de 1 casa decimal.
 Exemplo de Entrada:
6 5
8 8
2 2
 Exemplo de Saída:
5.5 - De Recuperacao
8.0 - Aprovado
2.0 - Reprovado
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	float n1, n2;
	float media;
	
	scanf("%f%f", &n1, &n2);
	
	media = n1/2 + n2/2;
	
	if (media>=7.0){
	
	printf("%.1f - Aprovado", media);
	}

	if (media<7.0 && media>=5.0){
	
	printf("%.1f - De Recuperacao", media);
	}

	if (media<5.0){
	
	printf("%.1f - Reprovado", media);
	}



    return 0;
}
