/*
(BOCA L2_21) Problema: Dado um conjunto de 1 a 9 números inteiros e um
texto entre aspas com indicadores %i, crie um programa que imprima esse
texto substituindo cada %i pelo i-ésimo número do conjunto.
 Entrada: um número n informando o número de elementos do conjunto,
seguido dos n elementos do conjunto, seguido pelo texto entre aspas.
 Saída: O texto sem aspas, com todos os indicadores %i substituídos pelos
números corretos. Caso i seja maior que n ou menor que ‘1’ substituir o
indicador %i por “ERRO” (sem aspas).
 Exemplos de Entrada:
4 22 23 31 2 "Meu nome e fulano e eu tenho %1 anos e faco %2 no dia
%3/%4"
3 6 5 4 "Eu tirei %3, %1 e %2 nas provas. Da pra passar de final"
2 12 6 "Eu fiz %2 questoes a mais que o fulano. Ele so fez %3"
 Exemplos de Saída:
Meu nome e fulano e eu tenho 22 anos e faco 23 no dia 31/2
Eu tirei 4, 6 e 5 nas provas. Da pra passar de final
Eu fiz 6 questoes a mais que o fulano. Ele so fez ERRO
*/

#include <stdio.h>

int main(){
	
	int n1, n2, n3, n4, n5, n6, n7, n8, n9;
	int n, nvalor, v=0;
	char l;
	
	scanf("%d", &n);
	if (n==1)
		scanf("%d ", &n1);
	else if (n==2)
		scanf("%d %d ", &n1, &n2);
	else if (n==3)
		scanf("%d %d %d ", &n1, &n2, &n3);
	else if (n==4)
		scanf("%d %d %d %d ", &n1, &n2, &n3, &n4);
	else if (n==5)
		scanf("%d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5);
	else if (n==6)
		scanf("%d %d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5, &n6);
	else if (n==7)
		scanf("%d %d %d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5, &n6, &n7);
	else if (n==8)
		scanf("%d %d %d %d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8);
	else if (n==9)
		scanf("%d %d %d %d %d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9);
	
	scanf("%c", &l);
	while (1){
		scanf("%c", &l);
		if (l=='"')
			break;
		else if (l=='%')
			v=1;	
		else if (v==1){	
			if (l=='1' && n>=1)	
				printf("%d", n1);
			else if (l=='2' && n>=2)	
				printf("%d", n2);
			else if (l=='3' && n>=3)	
				printf("%d", n3);
			else if (l=='4' && n>=4)	
				printf("%d", n4);
			else if (l=='5' && n>=5)	
				printf("%d", n5);
			else if (l=='6' && n>=6)	
				printf("%d", n6);
			else if (l=='7' && n>=7)	
				printf("%d", n7);
			else if (l=='8' && n>=8)	
				printf("%d", n8);
			else if (l=='9' && n==9)	
				printf("%d", n9);
			else
				printf("ERRO");
			v=0;
		}
		else
			printf("%c", l);
	
	}
	
	return 0;
}
