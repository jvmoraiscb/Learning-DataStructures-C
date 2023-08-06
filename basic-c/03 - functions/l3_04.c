/* 
(BOCA: L3_4) Problema: Faça um programa que imprima os números primos
contidos em um intervalo n e m fornecidos pelo usuário seguidos por seus múltiplos
até o final do intervalo.
a) A identificação do número primo deverá ser feita por uma função (a ser
implementada) que receberá um número num e retornará verdadeiro se o número
for primo e falso caso contrário. A função deverá ter o seguinte cabeçalho:
int EhPrimo(int num);
b) A impressão dos múltiplos de um número deverá ser feita por uma função (a ser
implementada) que receberá um número num e um número máximo max e
imprimirá todos os múltiplos de num menores do que max. A função deverá ter o
seguinte cabeçalho: void ImprimeMultiplos(int num, int max)
 Entrada: Seu programa deverá receber dois inteiros n e m, indicando o intervalo a ser
avaliado. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam ser
avaliados. Considere também que n sempre seja menor que m.
 Saída: Como saída, o programa deverá exibir todos os números primos contidos no intervalo
aberto (n,m) e também seus múltiplos. Cada número primo do intervalo deverá ser impresso
em uma linha separada, e seus múltiplos deverão ser todos impressos na linha seguinte
separados por espaço. Caso o número primo não tenha múltiplos, imprima “ * “ na linha
seguinte. Caso não haja primo no intervalo, não imprima nada.
 Exemplo de Entrada 1:
2 10
 Exemplo de Saída 1:
3
6 9
5
*
7
*
 Exemplo de Entrada 2:
2 20
 Exemplo de Saída 2:
3
6 9 12 15 18
5
10 15
7
14
11
*
13
*
17
*
19
*
 Exemplo de Entrada 3:
5 30
 Exemplo de Saída 3:
7
14 21 28
11
22
13
26
17
*
19
*
23
*
29
*
*/

#include <stdio.h>

int EhPrimo(int num);

void ImprimeMultiplos(int num, int m);

int main(){
	int i, num, n, m; //limites;
	
	scanf("%d %d", &n, &m);
	for (i=n+1; i<m; i++){
		num = i;
		if (EhPrimo(num) != 0) {
			printf("%d\n", num);
			ImprimeMultiplos(num, m);
		}
	}	
	
	return 0;
}

int EhPrimo(int num){
	int div, cont=0;
	for (div=1; div<=num; div++){
		if (num%div == 0)
			cont++;
	}
	if (cont == 2)
		return 1;
	else
		return 0;
}

void ImprimeMultiplos(int num, int m){
	int mult, ExisteMultiplo = 0;
	
	for (mult=num+1; mult<m; mult++){
		if (mult%num == 0){
			printf("%d ", mult);
			ExisteMultiplo = 1;
		}
	}
	if (ExisteMultiplo == 0){
		printf("*");
	}
	printf("\n");
}
