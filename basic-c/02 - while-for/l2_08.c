/*
(BOCA:L2_8) Problema: Faça um programa que imprima os números primos
contidos em um intervalo n e m fornecidos pelo usuário.
• Entrada: Seu programa deverá receber dois inteiros n e m, indicando o intervalo a ser
avaliado. Considere que n e m formem um intervalo aberto, ou seja, n e m não precisam ser
avaliados. Considere também que n sempre seja menor que m.
• Saída: Como saída, o programa deverá exibir todos os números primos contidos no
intervalo aberto (n,m). Todos os números exibidos deverão ser separados por um espaço e
estarem numa mesma linha. O formato de saída deve ser seguido RIGOROSAMENTE, i.e.
com “RESP:” no início e seguido dos números.
• Exemplo de Entrada:
2 5
2 10
10 20
1268 1301
• Exemplo de Saída:
RESP:3
RESP:3 5 7
RESP:11 13 17 19
RESP:1277 1279 1283 1289 1291 1297
*/
#include <stdio.h>

int main(){
	int n, m, d=1, c=0, i;
	
	scanf("%d %d", &n, &m);
	printf("RESP:");
	
	for(i=n+1; i<m; i++){
        while(d <= i){
            if(i%d==0){
        	c++;
            }
        d++;
        }       
        if(c==2){
        	printf("%d ", i);
        }
        d=1;
        c=0;
    }
	
return 0;
}
