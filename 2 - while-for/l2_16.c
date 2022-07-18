/*
(BOCA:L2_16) Problema: Dado duas sequências de números, faça um
programa que imprima o menor número da primeira sequência seguido da
posições primeira e última que ele aparece na segunda sequência. Caso o
menor número da primeira sequência não apareça na segunda nenhuma
vez, o programa deverá considerar o tamanho da segunda sequência
como primeira e última posições.
 Entrada: duas linhas com os números das duas sequências, com um
caractere não numérico no final de cada linha. Cada número está contido
em um intervalo [-32000, 32000].
 Saída: menor número da primeira sequência, posições da primeira e última
vez que o menor da primeira aparece na segunda sequência. Caso o
menor da primeira não apareça nenhuma vez, utilizar o tamanho da
segunda sequência como primeira e última ocorrência. Considerar a
posição começando em 0.
 Exemplos de Entrada:
117 343 21 1996 1988 -3213 0 3312 .
-3213 -3213 333 666 999 312 2345 -3213 3242 -116 b
-117 3234 213 1 4 144 ?
13 7 !
8989 9898 123 321 0 2134 222 -1 k
299 343 -1 123 o
 Exemplos de Saída:
-3213 0 7
-117 2 2
-1 2 2
*/

#include <stdio.h>

int main(){
	
	int n;
	int menor=32001, i=0, pc=0, pf=0;
	int v=0, v2=0;
	
	while (scanf("%d",&n)==1){
		if(n<menor)
			menor=n;
	}
	
	scanf("%*c");
	while (scanf("%d",&n)==1){
		if (n==menor){
			if (v2==0){
				pc=i;
				v2=1;
			}
			else{
				pf=i;
			}
			v=1;
		}
		if (v==0){
			pc++;
			pf++;
		}
		i++;
	}
	printf("%d %d %d", menor, pc, pf);
	
return 0;
}
