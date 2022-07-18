/*
(BOCA: P1_2016_Q4) Problema: Faça um programa para descobrir qual de 3
números possui o menor algarismo na casa das centenas.
 Entrada: 3 números inteiros positivos e menores que 999999.
 Saída: O programa deverá imprimir “N1” caso o primeiro número possua o menor
algarismo, “N2” caso o segundo número possua o menor algarismo, “N3” caso o terceiro
número possua o menor algarismo. Caso os referidos algarismos de dois números sejam
iguais, o que aparecer primeiro terá precedência (ex. se o algarismo de segundo número for
igual ao do terceiro e eles forem menores do que o primeiro, “N2” será impresso). Caso um
número não possua algarismo das centenas, ele deverá ser desconsiderado, e se nenhum
dos 3 números possuir algarismo das centenas, “Nenhum” deverá ser impresso.
 Exemplo de Entrada:
5111 4992 330
66666 2 550
1 3 5
333 221 222
4223 221 222
223 221 552
999 888 7777
 Exemplo de Saída:
N1
N3
Nenhum
N2
N1
N1
N3
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int n1, n2, n3;
	float f1, f2, f3;
	int ff1, ff2, ff3;
	int fn1, fn2, fn3;
	
	
	scanf("%d%d%d", &n1, &n2, &n3);
	
	if ((n1<=99) && (n2<=99) && (n3<=99) || (n1>999999) && (n2>999999) && (n3>999999)) {
	
		printf("Nenhum");
	}
	
	else {
	
	f1 = n1;
	f2 = n2;
	f3 = n3;

	fn1 = f1/1000;
	ff1 = (f1/1000 - fn1)*10;
	
	fn2 = f2/1000;
	ff2 = (f2/1000 - fn2)*10;
	
	fn3 = f3/1000;
	ff3 = (f3/1000 - fn3)*10;
	
	if (n1<99){
	
	ff1 = 10;
	
	}
	
	if (n2<99){
	
	ff2 = 10;
	
	}
	
	if (n3<99){
	
	ff3 = 10;
	
	}
	
	if ((ff1 < ff2) && (ff1 < ff3) || (ff1 == ff2) && (ff1 < ff3) || (ff1 == ff3) && (ff1 < ff3) || (ff1 == ff2) && (ff1 == ff3)) {
	
		printf("N1");
	}
	
	if ((ff2 < ff1) && (ff2 < ff3) || (ff2 == ff3) && (ff2 < ff1)) {
	
		printf("N2");	
	}
	
	if ((ff3 < ff1) && (ff3 < ff2)) {
	
		printf("N3");
	}
		}
 return 0;
}
