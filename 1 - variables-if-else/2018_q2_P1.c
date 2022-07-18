/*
(BOCA: P1_2018_Q2) Problema: Considere uma caixa registradora com quantidade
infinita de notas de 5 e notas de 1 e que não possui outras notas além dessas.
Considere também que o troco a ser dado por essa caixa deve, sempre que possível,
priorizar a saída das notas com maior valor. Faça um programa que diga qual de
dois valores a serem dados como troco (i.e., troco 1 ou troco 2) possui a maior
quantidade de notas. Por exemplo, o troco de 7 deve ser dado com 1 nota de 5 e 2 de
1, totalizando 3 notas, já o troco de 10 deve ser dado com 2 notas de 5, totalizando 2
notas, portanto o troco de 7 tem mais notas do que o de 10)
• Entrada: 2 números inteiros (maiores ou iguais a zero) representando o valor do troco 1 e
do troco 2 respectivamente.
• Saída: A saída deverá imprimir: "QTD troco 1 eh maior!" se a quantidade de notas do troco
1 for maior do que a do troco 2; "QTD troco 2 eh maior!" se a quantidade de notas do troco
2 for maior do que a do troco 1; e "Iguais!" se as quantidades forem iguais. Veja o formato
da saída nos exemplos abaixo.
• Exemplo de Entrada:
10 7
10 6
8 11
0 10
• Exemplo de Saída:
QTD troco 2 eh maior!
Iguais!
QTD troco 1 eh maior!
QTD troco 2 eh maior!
*/

#include <stdio.h>
int main(){
	
	int t1, t2, tf1, tf2;
	
	scanf("%d %d", &t1, &t2);
	
	if (t1%5==0){
		tf1=t1/5;
	}
	else{
		tf1=t1/5+t1%5;
	}
	if (t2%5==0){
		tf2=t2/5;
	}
	else{
		tf2=t2/5+t2%5;
	}
	
	if (tf1>tf2){
		printf("QTD troco 1 eh maior!");
	}
	else if (tf2>tf1){
		printf("QTD troco 2 eh maior!");
	}
	else {
		printf("Iguais!");
	}
	
return 0;
}
