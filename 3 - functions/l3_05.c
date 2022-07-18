/* 
(BOCA:L3_5) Problema: Observe a seguinte propriedade que alguns números
maiores que 1000 e menores que 9999 possuem:
Número: abcd
(ab) + (cd) = (ef)
𝑒𝑓 ∗ 𝑒𝑓 = abcd
Exemplo: 3025
30+25 = 55
55 ∗ 55 = 3025
a) A verificação da propriedade de um número deverá ser feita por uma função (a ser
implementada) que receberá um número num e retornará verdadeiro caso num
satisfaça a propriedade, ou falso caso contrário. A função deverá ter o seguinte
cabeçalho: int Propriedade(int num);
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

int Propriedade(int num);

int main(){
	int num, n, m; //intervalo aberto
	
	scanf("%d %d", &n, &m);
	if (n>1000 && m<9999 && n<m){
		for (num=n+1; num<m; num++){
			if (Propriedade(num) == 1)
				printf("%d\n", num);
		}
	}
	return 0;
}

int Propriedade(int num){
	int ab, cd;
	ab = num/100;
	cd = num%100;
	
	if ( (ab+cd)*(ab+cd) == num )
		return 1;
	else
		return 0;
}
