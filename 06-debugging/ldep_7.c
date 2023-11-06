/*
(BOCA:LDEP1_7) O objetivo desta questão é treinar a capacidade de encontrar erros
e acertar códigos. Para isso, conserte o código dado (arquivo “codigo_quebrado.c” no
zip juntamente com a descrição do problema), para que ele seja capaz de imprimir as
notas de um aluno que sejam maiores ou iguais a média de suas próprias notas.
• Entrada: 3 números inteiros representando as notas de um aluno.
• Saída: O programa deverá imprimir “Notas acima da media:” seguido das notas que forem
iguais ou maiores que a média das notas do aluno. As notas deverão ser separadas por um
espaço e a mensagem deverá ser finalizada com um ponto de exclamação “!”. Ver
exemplos de formatação abaixo.
• Exemplo de Entrada:
1 2 3
10 10 9
7 7 7
• Exemplo de Saída:
Notas acima da media: 2 3!
Notas acima da media: 10 10!
Notas acima da media: 7 7 7!
*/
#include <stdio.h>

int main(){
	
	float n1, n2, n3;
	float media;

	scanf("%f %f %f", &n1, &n2, &n3);

	media = (n1 + n2 + n3)/3;
	
	printf("Notas acima da media:");
	if (n1 >= media){ 
		printf(" %.0f", n1);
	}
	if (n2 >= media){ 
		printf(" %.0f", n2);
	}
	if (n3 >= media){ 
		printf(" %.0f", n3);
	}
	printf("!");
	
	return 0;
}
