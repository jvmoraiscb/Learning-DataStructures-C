/*
(BOCA:L2_18) Problema: Com dificuldade para estudar Álgebra Linear,
Padi decidiu fixar os conceitos da disciplina fazendo programas de
computador com a matéria. Para começar, quis fazer um programa
que, dado o tamanho da matriz e seus valores, que nunca são iguais,
calculasse o maior valor e imprimisse a posição dele na matriz.
Também com dúvidas em Programação, Padi agora pede sua ajuda e
você deve implementar o código para depois tirar as dúvidas do código
dele.
 Entrada: uma linha com os valores L (1 <= L <= 100) e C (1 <= C <=
100), representando o tamanho da matriz em linhas e colunas,
respectivamente. Depois, L linhas com C valores V (-32767 <= V <=
32767) cada.
 Saída: o maior valor V da matriz, seguido de sua posição no formato
(linha, coluna), como exemplificado abaixo.
 Exemplos de Entrada:
2 3
1 2 3
9 8 7
3 5
117 1 2 3 -119
343 -9 8 7 28193
20 15 10 5 3
10 2
117 343
21 8
1996 2100
17 19
18 -16
999 333
666 0
13 -1
24 21
3 9
 Exemplos de Saída:
9 (2, 1)
28193 (2, 5)
2100 (3, 2)
*/

#include <stdio.h>

int main(){
	
	int l, c, i1, i2, v, maior=-32770;
	int pc, pl;
	scanf("%d %d%*c", &l, &c);
	
	for (i1=1; i1<=l; i1++){
		for (i2=1; i2<=c; i2++){
			scanf("%d", &v);
			if (v>maior){
				maior=v;
				pc=i2;
				pl=i1;
			}
		}
		scanf("%*c");
	}
	printf("%d (%d, %d)", maior, pl, pc);
	
	
return 0;
}
