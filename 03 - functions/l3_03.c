/* 
(BOCA: L3_3) Problema: Faça um programa que imprima os números primos
contidos em um intervalo n e m fornecidos pelo usuário.
a) A identificação do número primo deverá ser feita por uma função (a ser
implementada) que receberá um número num e retornará verdadeiro se o número
for primo e falso caso contrário. A função deverá ter o seguinte cabeçalho:
int EhPrimo(int num);
 Entrada: Seu programa deverá receber dois inteiros n e m, indicando o intervalo a ser
avaliado. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam ser
avaliados. Considere também que n sempre seja menor que m.
 Saída: Como saída, o programa deverá exibir todos os números primos contidos no
intervalo aberto (n,m). Todos os números exibidos deverão ser separados por um espaço e
estarem numa mesma linha. O formato de saída deve ser seguido RIGOROSAMENTE.
 Exemplo de Entrada:
2 5
2 10
10 20
1268 1301
 Exemplo de Saída:
3
3 5 7
11 13 17 19
1277 1279 1283 1289 1291 1297
*/

#include <stdio.h>

int EhPrimo(int num);

int main(){
	int i, num, n, m; //limites
	
	scanf("%d %d", &n, &m);
	for (i=n+1; i<m; i++){
		num = i;
		if (EhPrimo(num) != 0)
			printf("%d ", num);
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
