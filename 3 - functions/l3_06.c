/* 
(BOCA:L3_6) Problema: Alguns números tem uma propriedade curiosa. Caso você
inverta a ordem dos algarismos desse número ele continuará tendo o mesmo valor.
A esses números, damos o nome de Palíndromos. Você deverá implementar um
programa que identifica se um dado número é Palíndromo ou não.
a) A identificação do número palíndromo deverá ser feita por uma função (a ser
implementada) que receberá um número inteiro num e retornará verdadeiro se o
número for palíndromo e falso caso contrário. A função deverá ter o seguinte
cabeçalho: int EhPalindromo(int num);
• Entrada: uma sequência de inteiros, separados por uma quebra de linha.
• Saída: caso o número seja palíndromo, exibe 'S'. Caso não seja, exibe 'N'. Todas as saídas
apresentam uma quebra de linha entre si.
• Exemplo de Entradas:
8999
4546
2133
9999
1111
25252
469
1
2
3
98
99
100
789
445
4654
21558
45654
14741 
2369632
• Exemplo de Saídas:
N
N
N
S
S
S
N
S
S
S
N
S
N
N
N
N
N
S
S
S
*/

#include <stdio.h>

int EhPalindromo(int num);

int main(){
	int num;
	
	while (scanf("%d\n", &num) == 1){
		if (EhPalindromo(num) == 1)
			printf("S\n");
		else
			printf("N\n");
	}

	return 0;
}

int EhPalindromo(int num){
	int numinicial, numcontrario = 0;
	
	numinicial = num;
	while (numinicial!= 0) {
		numcontrario = numcontrario*10 + numinicial%10;
		numinicial = numinicial/10;
	}
	if (num == numcontrario)
		return 1;
	else
		return 0;
}
