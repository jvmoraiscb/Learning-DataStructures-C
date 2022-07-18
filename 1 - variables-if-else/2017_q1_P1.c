/*
(BOCA: P1_2017_Q1) Problema: Faça um programa para dizer o resultado de uma
operação (soma, adição, multiplicação e divisão) entre dois números inteiros.
Atentar para o fato de todas as operações serem inteiras.
• Entrada: 2 números inteiros e um caractere (‘+’, ‘-’, ‘*’ e ‘/’) representando as operações
(soma, adição, multiplicação e divisão respectivamente). Os números e o caractere estarão
separados por um espaço.
• Saída: Resposta da operação correspondente no formato “RESP:#”, em que # representa o
número com a resposta. Caso a operação não seja nenhuma das permitidas, imprimir
“Invalido”.
• Exemplo de Entrada:
10 33 +
10 33 –
10 3 *
90 3 /
10 3 /
9 3 $
• Exemplo de Saída:
RESP:43
RESP:-23
RESP:30
RESP:30
RESP:3
Invalido
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int n1, n2, nf, v;
	char op;
	
	scanf("%d%d %c", &n1, &n2, &op);
	
	if (op == '+'){
	
	nf = n1 + n2;
	v = 1;
	
	}
	
	if (op == '-'){
	
	nf = n1 - n2;
	v = 1;
	
	}
	
	if (op == '*'){
	
	nf = n1 * n2;
	v = 1;
	
	}
	
	if (op == '/'){
	
	nf = n1 / n2;
	v = 1;
	
	}

	if ((op != '+') && (op != '-') && (op != '/') && (op != '*')) {
	
	v = 0;
	
	}
	
	if (v == 1){
	
		printf("RESP:%d", nf);
	
	}
	
	else {
	
		printf("Invalido");
	
	}


 return 0;
}
