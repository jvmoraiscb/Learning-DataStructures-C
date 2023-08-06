/*
(BOCA:L1_15) Problema: Faça um programa que diga se o algarismo da ordem de um
número (unidade, dezena ou centena, dependendo do que for informado) é par ou
ímpar. Exemplos: se o número dado fosse 123 e a ordem de interesse fosse a
unidade, então a resposta seria ÍMPAR, pois 3 é o algarismo da unidade; se o número
dado fosse 2123 e a ordem de interesse fosse a dezena, então a resposta seria PAR,
pois 2 é o algarismo da dezena; se o número dado fosse 45 e a ordem de interesse
fosse a centena, então a resposta seria PAR, pois o algarismo da centena seria um
zero (considerando 45 igual a 045).
• Entrada: Um número inteiro n (0 ≤ n ≤ 99999) seguido pela ordem de interesse (1, 2 ou 3).
A ordem (unidade, dezena ou centena) é representada por um número (1, 2 ou
respectivamente).
• Saída: Imprimir “PAR” se o algarismo da ordem de interesse for par e “IMPAR” caso
contrário.
• Exemplo de Entrada:
1 1
1 2
234 3
234 2
234 1
345 3
345 2
345 1
• Exemplo de Saída:
IMPAR
PAR
PAR
IMPAR
PAR
IMPAR
PAR
IMPAR
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	float n, mat;
	int mat2;
	int ordem;
	int ninteiro;
	float nantes;
	
	scanf("%f%d", &n, &ordem);
	
	if (ordem == 1){
	
	mat = n;
	mat2 = mat;
	
	}		
	
	if (ordem == 2){
	
	nantes = n/100;
	ninteiro = nantes;
	
	mat = (nantes - ninteiro)*10;
	mat2 = mat;
	
	}		
	
	if (ordem == 3){
	
	nantes = n/1000;
	ninteiro = nantes;
	
	mat = (nantes - ninteiro)*10;
	mat2 = mat;
	
	}
	
	if ((mat2%2==0) || mat2==0) {
	
	printf("PAR");
	
	}
	
	else {
	
	printf("IMPAR");
	
	}		
	
   return 0;
}
