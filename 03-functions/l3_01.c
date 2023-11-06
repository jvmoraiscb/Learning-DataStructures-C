/*
(BOCA:L3_1) Problema: Dado o programa abaixo que lê pares de números
separados por espaço e imprime o resultado da soma, da subtração, da divisão e da
multiplicação deles, implemente as funções Soma, Subtração, Divisão e Multiplicação
(cabeçalhos definidos abaixo) que fazem respectivamente cada uma das operações
com os dois números lidos. A única alteração permitida no programa é a
implementação das funções que recebem dois floats e retornam um float.
#include <stdio.h>
float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);
int main(){
float num1, num2;
while ( scanf("%f %f", &num1, &num2) == 2 ){
float result;
result = Soma(num1, num2);
printf("%.2f", result);
result = Subtracao(num1, num2);
printf(" %.2f", result);
result = Divisao(num1, num2);
printf(" %.2f", result);
result = Multiplicacao(num1, num2);
printf(" %.2f\n", result);
}
 return 0;
}
 Entrada: uma lista de pares de números separados por espaço, um par em cada linha.
 Saída: por linha, o resultado da soma, da subtração, da divisão e da multiplicação de cada
par separados por espaço. Precisão de 2 casas decimais.
 Exemplo de Entrada:
1.5 1
2.75 1.1
1231 1231
500.0 -1
 Exemplo de Saída:
2.50 0.50 1.50 1.50
3.85 1.65 2.50 3.03
2462.00 0.00 1.00 1515361.00
499.00 501.00 -500.00 -500.00
*/
#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main (){
	float num1, num2;
	
	while (scanf("%f %f", &num1, &num2) == 2 ){
		float result;
		result = Soma(num1, num2);
		printf("%.2f", result);
		result = Subtracao(num1, num2);
		printf(" %.2f", result);
		result = Divisao(num1, num2);
		printf(" %.2f", result);
		result = Multiplicacao(num1, num2);
		printf(" %.2f\n", result);
	}

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
