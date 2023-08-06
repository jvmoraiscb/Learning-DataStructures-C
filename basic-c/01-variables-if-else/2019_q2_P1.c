/*
(BOCA: P1_2019_Q2) Problema: Faça um programa que implemente as operações de
uma calculadora para números inteiros e informe os resultados.
• Entrada: 2 números inteiros (num1 e num2) e o sinal da operação (‘+’, ‘-’, ‘*’ e ‘/’ para
representar respectivamente a soma, subtração, multiplicação e divisão). A entrada será
dada respeitando a sequência “num1 sinal num2”, sendo os três separados por espaço.
• Saída: A saída deverá imprimir: "SOMA:", “SUB:”, “MULT:” e “DIV:” seguido do resultado
para as operações de soma, subtração, multiplicação e divisão respectivamente. Para a
divisão, o programa deverá imprimir também “, RESTO:” seguido do valor do resto da
divisão quando houver resto. Veja o formato da saída nos exemplos abaixo.
• Exemplo de Entrada:
2 + 3
4 - 5
10 * 11
7 / 2
6 / 3
• Exemplo de Saída:
SOMA:5
SUB:-1
MULT:110
DIV:3, RESTO:1
DIV:2
*/

#include <stdio.h>

int main(){

	int n1, n2;
	char sinal;
	
	scanf("%d %c %d",&n1,&sinal,&n2);
	
	if(sinal=='+'){
		printf("SOMA:%d", n1+n2);
	}
	if(sinal=='-'){
		printf("SUB:%d", n1-n2);
	}
	if(sinal=='*'){
		printf("MULT:%d", n1*n2);
	}
	if(sinal=='/'){
		if (n1%n2==0){
			printf("DIV:%d", n1/n2);
		}
		else{
			printf("DIV:%d, RESTO:%d", n1/n2, n1%n2);
		}
	}

return 0;
}
