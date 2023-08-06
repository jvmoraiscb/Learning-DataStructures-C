/*
(BOCA:LDEP1_4) Seu Madruga é o mais novo integrante do PET Engenharia de
Computação e como todo calouro do projeto, tem suas limitações para
programar. Durante seus estudos, Seu Madruga foi desafiado a calcular todos os
números primos até um valor fornecido pelo usuário. Porém, Seu Madruga teve
dificuldades e o melhor que conseguiu fazer foi dado código (arquivo
“codigo_quebrado.c” no zip juntamente com a descrição do problema). Ajude Seu
Madruga a enviar o programa correto para o BOCA apenas corrigindo seu
código.
• Entrada: um número inteiro não negativo.
• Saída: Todos os números primos até o número fornecido pelo usuário, considerando o
número fornecido como parte do intervalo de interesse.
• Exemplo de Entrada:
2
5
25
100
• Exemplo de Saída:
2
2 3 5
2 3 5 7 11 13 17 19 23
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/
#include <stdio.h>

int main(){
	int i, den=1, qtd, cont=0;

	scanf("%d", &qtd);

	for(i=2; i<=qtd; i++){
		while(den <= i){
			if(i%den==0){
			cont++;
			}
		den++;
		}
		   	
		if(cont==2){
			printf("%d ", i);
		}
		den=1;
		cont=0;
	}

return 0;
}
