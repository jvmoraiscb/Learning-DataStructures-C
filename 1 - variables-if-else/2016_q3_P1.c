/*
(BOCA: P1_2016_Q3) Problema: Faça um programa para verificar a validade de
um código de 4 caracteres, em que o primeiro caractere deve ser maiúsculo, o
segundo deve ser um dígito, o terceiro deve ser uma vogal, e o quarto deve ser uma
consoante minúscula.
 Entrada: 4 caracteres.
 Saída: O programa deverá imprimir “Invalido” se algum dos caracteres não respeitar as
regras de construção do código, e deverá imprimir o próprio código em maiúsculo, caso
contrário.
 Exemplo de Entrada:
e1ac
E@ac
E1cc
E1A1
E1Ac
Q2id
E2i$
 Exemplo de Saída:
Invalido
Invalido
Invalido
Invalido
E1AC
Q2ID
Invalido
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	char n1, n3, n4;
	int n1o, n2o, n3o, n4o;
	int c1, c2, c3, c4, cf;
	int n3b, n4b;
	char n3bc, n4bc;
	
	scanf("%c%d%c%c", &n1, &n2o, &n3, &n4);
	
	n1o = n1;
	n3o = n3;
	n4o = n4;
	
	if ((n1o >= 65) && (n1o <=90)){
	
	c1 = 1;
	
	}
	
	else {
	
	c1 = 0;
	
	}
	
	if ((n2o >= 0) && (n2o <=9)){
	
	c2 = 1;
	
	}
	
	else {
	
	c2 = 0;
	
	}

	if ((n3o == 65) || (n3o == 69) || (n3o == 73) || (n3o == 79) || (n3o == 85)){
	
	c3 = 1;
	n3bc = n3;
	
	}
	
	else if ((n3o == 65+32) || (n3o == 69+32) || (n3o == 73+32) || (n3o == 79+32) || (n3o == 85+32)) {
	
	c3 = 1;
	
	n3b = n3o - 32;
	n3bc = n3b;
	
	}
	
	else {
	
	c3 = 0;
	
	}
	
	if ((n4o > 97) && (n4o <= 122) && (n4o !=101) && (n4o !=105) && (n4o !=111) && (n4o !=117)){
	
	c4 = 1;
	
	n4b = n4o - 32;
	n4bc = n4b;
	
	}
	
	else {
	
	c4 = 0;
	
	}
	
	cf = c1 + c2 + c3 + c4;
	
	if (cf == 4){
	
	printf("%c%d%c%c", n1, n2o, n3bc, n4bc);
	
	}
	
	else {
	
	printf("Invalido");
	
	}

 return 0;
}
