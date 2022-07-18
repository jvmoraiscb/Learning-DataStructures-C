/*
(BOCA:L2_15) Problema: Faça um programa para imprimir a quantidade de
números negativos, a quantidade de números positivos, a soma dos negativos e a
soma dos positivos de uma sequência de números. O programa deverá ler números
da entrada padrão (um por vez) enquanto ainda tiverem números para serem lidos.
Considere que os números estão entre -100 e 100.
 Entrada: uma sequência números inteiros separados por espaço e terminada por um
caractere diferente de white-space (ver ajuda do scanf).
 Saída: a quantidade de números negativos da sequência, a quantidade de números
positivos da sequência, a soma dos números negativos da sequência e a soma dos números
positivos da sequência.
 Exemplo de Entradas:
1 2 3 4 5 6 7 8 9 10 11 12.
-10 -9 -7 -6 -5 -4;
-2 -1 1 2 3 4 5
 Exemplo de Saídas:
0 12 0 78
6 0 -41 0
2 5 -3 15
*/

#include <stdio.h>

int main(){
	
	int n;
	int sp=0, sn=0, qp=0, qn=0;
	
	while (scanf("%d",&n)==1){
		if (n>=1 && n<=100){
			sp+=n;
			qp+=1;
		}
		else if (n<=-1 && n>=-100){
			sn+=n;
			qn+=1;
		}
	}
	printf("%d %d %d %d",qn,qp,sn,sp);
	
return 0;
}
