/*
(BOCA:L3_2) Problema: Usando as funções do exercício L3_1, faça um programa
que resolva uma operação composta contendo operações básicas (soma, subtração,
adição e multiplicação). Assuma que os dados serão apresentados em notação pósfixada (i.e. operando da esquerda, operando da direita e operador). Desconsidere a
precedência dos operadores, i.e. considere que para cada operação básica (indo da
esquerda para direita), existe um parênteses para garantir sua precedência da
ordem apresentada. Portanto, o resultado da primeira operação (da esquerda para a
direita) será sempre utilizado como operando da esquerda da próxima operação.
Por exemplo:
 a b + representa (a + b)
 a b + c / representa ((a + b) / c)
 a b * c / d – e * representa ((((a * b) / c) – d) * e)
 1.5 1 + 2 * representa ((1.5 + 1) * 2)
 Entrada: Uma sequência de operandos (números) e operadores (sinais ‘+’, ‘-‘, ‘/’, ‘*’)
separados por um espaço ‘ ‘ representando uma operação composta a ser resolvida.
Considere que sempre haverá pelo menos uma operação básica para ser realizada (i.e. dois
operandos e um operador).
 Saída: resultado da operação composta. Precisão de 2 casas decimais.
 Exemplo de Entradas:
1.5 1 +
1.5 1 + 2 *
2.75 1.1 - 2 * 3 /
2.5 2.5 + 5 / 5 *
 Exemplo de Saídas:
2.50
5.00
1.10
5.00
*/

#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main (){
	float num1, num2, result;
	char operador;
	
	scanf("%f", &num1);
	
	while (scanf(" %f %c",&num2, &operador) == 2){
		if (operador == '+')
			result = Soma(num1, num2);
		if (operador == '-')
		result = Subtracao(num1, num2);
		if (operador == '/')
		result = Divisao(num1, num2);
		if (operador == '*')
		result = Multiplicacao(num1, num2);
		num1 = result;
	}
	
	printf("%.2f", result);

	return 0;
}

float Soma(float num1, float num2){
	float resp;
	resp = num1 + num2;
	
	return(resp);
}
float Subtracao(float num1, float num2){
	float resp;
	resp = num1 - num2;
	
	return(resp);
}
float Divisao(float num1, float num2){
	float resp;
	resp = num1 / num2;
	
	return(resp);
}
float Multiplicacao(float num1, float num2){
	float resp;
	resp = num1 * num2;
	
	return(resp);
}
