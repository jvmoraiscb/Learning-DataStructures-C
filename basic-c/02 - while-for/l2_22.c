/*
(BOCA:L2_22) Problema: Dado um inteiro não-negativo, repetidamente some seus
dígitos, até que o resultado tenha somente um dígito.
Por exemplo: 29 = 2 + 9 = 11; 11 = 1 + 1 = 2.
• Entrada: um inteiro não negativo.
• Saída: “RESP:” seguido de um inteiro correspondente à soma final.
• Exemplo de Entradas:
45523
23
39
• Exemplo de Saídas:
RESP:1
RESP:5
RESP:3
*/
#include <stdio.h>

int main(){
	int n, somad=0;;
	
	scanf("%d", &n);
	while(1){
		while (n!=0){
			somad+= n%10;
			n = n/10;
		}
		n = somad;
		somad = 0;
		if (n<10)
			break;
	}
	printf("RESP:%d", n);
	return 0;
}
