/*
(BOCA: P1_2017_Q3) Problema: Faça um programa para comparar dois códigos
alfanuméricos se eles forem válidos. Cada código contém dois caracteres que só
podem ser letras ou números, qualquer outro caractere invalida o código. Os códigos
são considerados iguais quando seus respectivos caracteres são iguais
indiferentemente da letra ser maiúscula ou minúscula.
• Entrada: dois códigos de dois caracteres cada. Os códigos são separados por um espaço (i.e.
‘ ‘).
• Saída: O programa deverá imprimir “Invalido” se algum dos códigos for inválido, deverá
imprimir “IGUAIS” se os códigos forem iguais considerando os critérios acima, ou
“DIFERENTES”, caso contrário.
• Exemplo de Entrada:
aw Aw
AW aw
a1 A1
12 12
%s %s
CD e1
• Exemplo de Saída:
IGUAIS
IGUAIS
IGUAIS
IGUAIS
Invalido
DIFERENTES
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	char s1, s2, s3, s4;
	int n1, n2, n3, n4;
	int v1, v2;
	int vv1, vv2, vv3, vv4;
	
	scanf("%c%c %c%c", &s1, &s2, &s3, &s4);
	
	n1 = s1;
	n2 = s2;
	n3 = s3;
	n4 = s4;
	
	
	if ((n1>=48) && (n1<=57) || (n1>=65) && (n1<=90) || (n1>=97) && (n1<=122)){
	
		vv1 = 1;
	
	}
	
	else {
	
		vv1 = 0;
	
	}
	
	if ((n2>=48) && (n2<=57) || (n2>=65) && (n2<=90) || (n2>=97) && (n2<=122)){
	
		vv2 = 1;
	
	}
	
	else {
	
		vv2 = 0;
	
	}
	
	if ((n3>=48) && (n3<=57) || (n3>=65) && (n3<=90) || (n3>=97) && (n3<=122)){
	
		vv3 = 1;
	
	}
	
	else {
	
		vv3 = 0;
	
	}
	
	if ((n4>=48) && (n4<=57) || (n4>=65) && (n4<=90) || (n4>=97) && (n4<=122)){
	
		vv4 = 1;
	
	}
	
	else {
	
		vv4 = 0;
	
	}
	
	if ((n1 == n3) || (n1+32 == n3) || (n1 == n3-32) || (n3+32 == n1) || (n3 == n1-32)) {
	
		v1 = 1;
	
	}
	
	else {
	
		v1 = 0;
	
	}
	
	if ((n2 == n4) || (n2+32 == n4) || (n2 == n4-32) || (n4+32 == n2) || (n4 == n2-32)) {
	
		v2 = 1;
	
	}
	
	else {
	
		v2 = 0;
	
	}
	
	
	if (vv1 + vv2 + vv3 + vv4 != 4){
	
		printf("Invalido");
	
	}
	
	else if (v1+v2==2)  {
	
		printf("IGUAIS");
	
	}
	
	else
	{
		printf("DIFERENTES");
	
	} 
	
 return 0;
}
