/* 
(BOCA: L3_8) Problema: Você subestimou o nível de conhecimento de
Padi desde a última vez que o ajudou e agora ele terminou a Lista 3
antes que você. Para provar que é mais rápido e treinar seus
conhecimentos em implementação de funções, você deve fazer um
programa que, dado o tamanho de uma matriz e seus valores, que
nunca são iguais, transforma seus valores no próximo número primo
maior que o próprio valor se o valor é positivo e menor que o próprio
valor se o valor é negativo. Caso o valor já seja primo ou se o primo
transformado extrapolar os intervalos de entrada possível, o programa
não deve fazer nenhuma mudança.
a) Seu programa deve conter a função int verificaPrimo(int n) que
retorna 1 se o número n passado como parâmetro for primo ou 0 caso
contrário.,
b) Seu programa deve conter a função int transformaPrimo(int n)
que transforma o número n passado como parâmetro no próximo maior
ou menor primo retornando o número transformado.
c) Seu programa deve conter a função int verificaNegativo(int n) que
retorna 1 se o número for negativo ou 0 caso contrário.
 Entrada: uma linha com os valores L (1 <= L <= 100) e C (1 <= C <=
100), representando o tamanho da matriz em linhas e colunas,
respectivamente. Depois, L linhas com C valores V (-32000 <= V <=
32000) cada.
 Saída: a matriz com seus valores transformados, conforme exemplo
abaixo.
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
31998 -31998
3 9
 Exemplos de Saída:
2 2 3
11 11 7
127 2 2 3 -127
347 -11 11 7 28201
23 17 11 5 3
127 347
23 11
1997 2111
17 19
19 -17
1009 337
673 2
13 -2
31998 -31998
3 11 
*/

#include <stdio.h>

int verificaPrimo(int n);

int transformaPrimo(int n);

int verificaNegativo(int n);

int main(){
	int nLinhas, nColunas, n, iL, iC;
	
	scanf("%d %d", &nLinhas, &nColunas);
	
	for (iL=1; iL<=nLinhas; iL++){
		for (iC=1; iC<=nColunas; iC++){
			scanf("%d", &n);
			if (verificaPrimo(n) == 0)
				n = transformaPrimo(n);
			printf("%d ", n);
		}
		printf("\n");
	}
	
	return 0;
}

int verificaPrimo(int n){
	int div, cont=0;
	
	if (verificaNegativo(n) == 1){
		for (div=-1; div>=n; div--){
			if (n%div == 0)
				cont++;
		}
	}
	else{
		for (div=1; div<=n; div++){
			if (n%div == 0)
				cont++;
		}
	}
	if (cont == 2)
		return 1;
	else
		return 0; 
}


int transformaPrimo(int n){
	int i, mult;
	
	mult = n;
	
	if ((verificaNegativo(n)) == 1){
		for (i=n; i>=-32000; i--){
			if (verificaPrimo(i) == 1){
				mult = i;
				break;
			}
		}
	}
	else{
		for (i=n; i<=32000; i++){
			if (verificaPrimo(i) == 1){
				mult = i;
				break;
			}
		}
	}
	return (mult);
}

int verificaNegativo(int n){

	if (n<0)
		return 1;
	else
		return 0;
}
