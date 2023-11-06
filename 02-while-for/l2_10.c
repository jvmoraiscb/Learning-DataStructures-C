/*
(BOCA:L2_10) Problema: Faça um programa que imprima na tela as tabuadas de n
até m.
 Entrada: Dois inteiros n e m, indicando quais tabuadas serão impressas. Considere que n e
m formem um intervalo fechado, ou seja, n e m precisam ser avaliados.
 Saída: Como saída, seu programa deverá exibir os valores da tabuada no formato a x b
= (a*b), separados sempre por quebra de linha das tabuadas de “n” até “m”.
 Exemplo de Entrada 1:
1 3
 Exemplo de Saída 1:
1 x 1 = 1
1 x 2 = 2
1 x 3 = 3
...
1 x 10 = 10
2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
...
2 x 10 = 20
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
...
3 x 10 = 30
*/

#include <stdio.h>

int main(){
	int n, m, i, i2=1;
	
	scanf("%d %d", &n, &m);
	
	for (i=n;i<=m;i++){
		while (i2<=10){
			printf("%d x %d = %d\n", i, i2, i*i2);
			i2++;
		}
	i2=1;
	}
	
return 0;
}
