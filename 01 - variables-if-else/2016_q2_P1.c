/*
Instruções gerais para o BOCA: O BOCA é um programa de correção automática dos
exercícios. Portanto, é necessário seguir estritamente os padrões de entrada e saída das
questões. Apesar de em um programa comum para um usuário qualquer você ter que
usar printf’s para pedir uma entrada de dados para o usuário, em programas para o
BOCA os printf’s e scanf’s devem ser usados com muita cautela, e seguindo
rigorosamente os formatos de entrada e saída definidos para cada questão a ser
submetida para o BOCA. O sistema compara letrinha por letrinha da saída do seu
programa (isto é, tudo que foi escrito na tela) com a saída esperada por ele, portanto
tudo deve ser escrito na saída padrão (ex. tela do monitor) conforme indicado nos
exemplos das questões. Qualquer printf realizado sem necessidade pode invalidar a
resposta. Lembre-se que os exemplos dados podem não cobrir todos os casos de teste
das questões.
(BOCA: P1_2016_Q2) Problema: Faça um programa para dizer se um grupo de
pontos está ou não em uma reta definida por:
𝑎𝑥 + 𝑏 = 𝑦
 Entrada: 8 números inteiros. Os dois primeiros definindo a e b respectivamente. Os 6
últimos definindo os x e y de 3 pontos na sequência: x1, y1, x2, y2, x3 e y3.
 Saída: O programa deverá imprimir “Nenhum” se nenhum dos três pontos estiverem na
reta, “Um” se apenas um dos pontos estiver na reta, “Dois” se apenas dois dos pontos
estiverem na reta, “Todos” se os três pontos estiverem na reta.
 Exemplo de Entrada:
2 1 0 0 3 3 1 4
2 1 0 1 3 3 1 4
2 1 0 1 2 5 1 4
2 1 0 1 2 5 2 5
 Exemplo de Saída:
Nenhum
Um
Dois
Todos
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int a, b, x1, y1, x2, y2, x3, y3;
	int quant, quant1, quant2, quant3;
	
	
	scanf("%d%d%d%d%d%d%d%d", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);
	
	if (a*x1 + b == y1){
	
		quant1 = 1;
	
	}
	else {
	
		quant1 = 0;
	
	}
	
	
	
	if (a*x2 + b == y2){
	
		quant2 = 1;
	
	}
	else {
	
		quant2 = 0;
	
	}
	
	
	if (a*x3 + b == y3){
	
		quant3 = 1;
	
	}
	else {
	
		quant3 = 0;
	
	}
	
	
	quant = quant1 + quant2 + quant3;
	
	if (quant == 0){
	
		printf("Nenhum");
	
	}
	
	if (quant == 1){
	
		printf("Um");
	
	}


	if (quant == 2){
	
		printf("Dois");
	
	}

	if (quant == 3){
	
		printf("Todos");
	
	}

 return 0;
}
