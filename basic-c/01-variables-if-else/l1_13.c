/*
(BOCA:L1_13) Problema: Faça um programa que distribuía itens para um grupo de
pessoas, e retorne quem foi a última pessoa a receber um item. Assuma que a
distribuição é feita da seguinte forma: a pessoa 1 recebe um item, depois a pessoa 2
recebe um item, e assim por diante até a pessoa n. Caso ainda haja itens, o processo
recomeça da pessoa 1. Observação para os alunos que já sabem programar: Não
pode usar comandos de loop, como while, for, etc.
• Entrada: Número de pessoas e número de itens.
• Saída: Número da pessoa a receber o último item. O formato deve seguir os exemplos
abaixo.
• Exemplo de Entrada:
1 10
2 1
2 2
2 3
2 5
3 6
3 7
• Exemplo de Saída:
RESP:1
RESP:1
RESP:2
RESP:1
RESP:1
RESP:3
RESP:1
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int p; //pessoas
	int i; //itens
	int mat; //calculos
	
	scanf("%d%d", &p, &i);
	
	if (i%p == 0){
	
		mat = p;
		
		printf("RESP:%d", mat);
	
	}
	
	else {
	
		mat = i%p;
	
		printf("RESP:%d", mat);
			
   		}		

   return 0;
}
