/*
(BOCA:L2_11) Problema: Observe a seguinte propriedade que alguns números
maiores que 1000 e menores que 9999 possuem:
Número: abcd
(ab) + (cd) = (ef)
𝑒𝑓 ∗ 𝑒𝑓 = abcd
Exemplo: 3025
30+25 = 55
55 ∗ 55 = 3025
 Entrada: Dois inteiros n e m (sendo n SEMPRE menor que m), contidos no intervalo
(1000,9999). Ou seja, 1000 < n,m < 9999 e n<m.
 Saída: Como saída, seu programa deverá exibir os números maiores que n e menores que m
que satisfaçam esta propriedade, separados por uma quebra de linha.
 Exemplo de Entrada:
1001 9990
 Exemplo de Saída:
2025
3025
9801
*/

#include <stdio.h>

int main(){

	int n, m, n1, n2, i; // entre 1000 e 9999
	
	scanf("%d %d", &n, &m);
	
	if ((n<m) && (n>=1000) && (n<=9999) && (m>=1000) && (m<=9999)){
		for (i=n+1;i<m;i++){
			n1=i/100;
			n2=(i-n1*100);
		
			if ((n1+n2)*(n1+n2)==i){
				printf("%d\n", i);
			}
		
		}
	}
	
return 0;
}
