/*
(BOCA:LDEP1_6) O objetivo desta questão é treinar a capacidade de encontrar erros
e acertar códigos. Para isso, conserte o código dado (arquivo “codigo_quebrado.c” no
zip juntamente com a descrição do problema), para que ele seja capaz de imprimir a
soma das linhas de uma matriz, seguido, no final, pela soma de todos os valores da
matriz.
• Entrada: Dois inteiros indicando as linhas e colunas da matriz, respectivamente, seguido da
matriz de números inteiros.
• Saída: A soma de cada linha da matriz (uma em cada linha), seguida pela soma total em
uma linha adicional.
• Exemplo de Entrada:
3 3
1 2 1
3 1 5
8 7 1
• Exemplo de Saída:
4
9
16
29
*/
#include <stdio.h>

int main(){
	
	int l, c, i, j;
	int soma = 0, somatotal=0, atual;

	scanf("%d %d", &l, &c);

	
	for (i = 1; i<=l; i++){
		for(j = 1; j<=c; j++){
			scanf("%d", &atual);
			soma += atual;
			somatotal += atual;
		}
		printf("%d\n", soma);
	soma=0;
	}

	printf("%d\n", somatotal);

	return 0;
}
