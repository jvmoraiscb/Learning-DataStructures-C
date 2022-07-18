/*
(BOCA: P1_2017_Q2) Problema: Faça um programa para identificar o tipo do
conjunto de pessoas passado. As pessoas serão identificadas por números inteiros
de 1 a 10 inclusive, em que identidades de 1 a 5 são de homens e identidades de 6 a
10 são de mulheres. Identidades fora desses limites são inválidas.
• Entrada: 2 números inteiros representando a identidade de duas pessoas.
• Saída: O programa deverá imprimir “Invalido” caso alguma das identidades dadas seja
inválida, ou o tipo do grupo das duas pessoas informadas. Os tipos dos grupos serão um dos
seguintes casos: “Um homem” caso as duas identidades informadas sejam da mesma
pessoa e ela seja homem; “Uma mulher” caso as duas identidades informadas sejam da
mesma pessoa e ela seja mulher; “Um casal” caso as duas identidades informadas sejam de
pessoas diferentes e de sexo opostos; “Par de homens” caso as duas identidades
informadas sejam de pessoas diferentes e do sexo masculino; “Par de mulheres” caso as
duas identidades informadas sejam de pessoas diferentes e do sexo feminino.
• Exemplo de Entrada:
3 3
6 6
1 10
1 5
9 8
11 3
• Exemplo de Saída:
Um homem
Uma mulher
Um casal
Par de homens
Par de mulheres
Invalido
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int n1, n2;
	
	scanf("%d%d", &n1, &n2);
	
	if ((n1 == n2) && (n1 >=1) && (n1 <=5)) {
	
		printf("Um homem");
	
	}
	
	else if ((n1 == n2) && (n1 >=6) && (n1 <=10)) {
	
		printf("Uma mulher");
	
	}
	
	else if ((n1 != n2) && (n1 <=5) && (n1>=1) && (n2>=6) && (n2<=10) || (n1 != n2) && (n1 <=10) && (n1>=6) && (n2>=1) && (n2<=5)) {
	
		printf("Um casal");
	
	}
	
	else if ((n1 != n2) && (n1>=1) && (n1<=5) && (n2>=1) && (n2<=5)) {
	
		printf("Par de homens");
	
	}

	else if ((n1 != n2) && (n1>=6) && (n1<=10) && (n2>=6) && (n2<=10)) {
	
		printf("Par de mulheres");
	
	}
	
	else {
	
		printf("Invalido");
	
	}


 return 0;
}
