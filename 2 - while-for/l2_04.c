/*
(BOCA:L2_4) Problema: Faça um programa que leia números inteiros e retorne o
maior dos números digitados até o momento e a média atual. O programa termina
quando o usuário entra o número zero.
 Entrada: Sua entrada deverá receber um número por vez fornecidos pelo usuário.
 Saída: Sua saída deverá apresentar o maior número lido até então e a média atual. Para a
média, considere-a sempre com precisão de 6 casas após a vírgula.
 Exemplo de Entrada:
5
7
2
0
 Exemplo de Saída:
5 5.000000
7 6.000000
7 4.666667
*/
#include <stdio.h>

int main(){
	int maior=0, n=1, i=1;
	float media=0;
	while(n>=1){
		scanf("%d", &n);
		if(n==0){
			break;
		}
		if(n>maior){
			maior=n;
		}
		media+=n;
		printf("%d %f\n", maior, media/i);
		i++;
	}
return 0;
}
