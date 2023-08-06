/*
(BOCA:L2_9) Problema: Faça um programa que imprima os números primos
contidos em um intervalo n e m fornecidos pelo usuário seguidos por seus múltiplos
até o final do intervalo.
 Entrada: Seu programa deverá receber dois inteiros n e m, indicando o intervalo a ser
avaliado. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam ser
avaliados. Considere também que n sempre seja menor que m.
 Saída: Como saída, o programa deverá exibir todos os números primos contidos no intervalo
aberto (n,m) e também seus múltiplos. Cada número primo do intervalo deverá ser impresso
em uma linha separada, e seus múltiplos deverão ser todos impressos na linha seguinte
separados por espaço. Caso o número primo não tenha múltiplos, imprima “ * “ na linha
seguinte. Caso não haja primo no intervalo, não imprima nada.
 Exemplo de Entrada 1:
2 10
 Exemplo de Saída 1:
3
6 9
5
*
7
*
 Exemplo de Entrada 2:
2 20
 Exemplo de Saída 2:
3
6 9 12 15 18
5
10 15
7
14
11
*
13
*
17
*
19
*
 Exemplo de Entrada 3:
5 30
 Exemplo de Saída 3:
7
14 21 28
11
22
13
26
17
*
19
*
23
*
29
*
*/
#include <stdio.h>

int main(){
	int n, m, d=1, c=0, i, mt;
	int v=0;
	
	scanf("%d %d", &n, &m);
	
	for(i=n+1; i<m; i++){
        while(d <= i){
            if(i%d==0){
        	c++;
            }
        d++;
        }       
        if(c==2){
        	printf("%d\n", i);
        	mt=i+1;
        	while(mt<m){
        		if (mt%i==0){
        		printf("%d ", mt);
        		v=1;
        		}
        	mt++;
        	}
        	if (v==0){
        		printf("*");
        	}
        printf("\n");
        }
        d=1;
        c=0;
        v=0;
    }
return 0;
}
