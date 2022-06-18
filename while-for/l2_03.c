/*
(BOCA:L2_3) Problema: Faça um programa que leia n números positivos e retorne
o maior e o menor destes, a quantidades de pares, a quantidade de ímpares, e a
média deles.
• Entrada: Sua entrada deverá conter a quantidade de números a serem lidos (sempre maior
que zero) seguidos dos números em questão.
• Saída: Sua saída deverá apresentar o maior e o menor dos números em questão, a
quantidade de pares, a quantidade de ímpares e a média deles. Para a média, considere-a
sempre com precisão de 6 casas após a vírgula.
•
• Exemplo de Entrada:
10
1 2 3 4 5 6 7 8 9 10
5
2 7 8 10 11
6
1 2 7 2 2 2
• Exemplo de Saída:
10 1 5 5 5.500000
11 2 3 2 7.600000
7 1 4 2 2.666667
*/
#include <stdio.h>

int main(){
	int n, i=1, r, pares=0, impares=0, maior=0, menor=100000000;
	float media;
	scanf("%d", &n);
	while (i<=n){
		scanf("%d", &r);
		if(r>maior){
			maior=r;
		}
		if(r<menor){
			menor=r;
		}
		if(r%2==0){
			pares+=1;
		}
		if (r%2!=0){
			impares+=1;
		}
		media+=r;
		i++;
	}
	printf("%d %d %d %d %f", maior, menor, pares, impares, media/n);
return 0;
}
