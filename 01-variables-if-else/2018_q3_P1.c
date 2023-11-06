/*
(BOCA: P1_2018_Q3) Problema: Faça um programa que compare dois códigos de 3
caracteres cada, fazendo uma análise para cada par de caracteres correspondentes.
A análise deve comparar cada caractere de um código com seu respectivo caractere
no outro código e dizer se é igual, diferente ou se difere apenas por ser maiúsculo ou
minúsculo (e.g., comparar o primeiro caractere do primeiro código com o primeiro
do segundo código, e fazer mesmo para o segundo e terceiro caracteres). Caso algum
dos códigos seja inválido, o programa deve informar apenas que o código é inválido.
Um código é considerado válido se seu primeiro caractere é um dígito numérico, se
o segundo caractere é uma letra minúscula e se o terceiro caractere é uma letra.
• Entrada: 2 códigos de três caracteres cada. Os códigos estarão separados por um caractere
de espaço. Veja o formato de entrada nos exemplos abaixo.
• Saída: A saída deverá imprimir: "Codigo invalido!" se algum dos dois códigos não for valido;
ou, deverá imprimir, para cada caractere comparado, “I”, “D” ou “C” representando
respectivamente se o caractere de um código, em relação ao respectivo caractere do outro
código, é igual, diferente ou se difere apenas por ser maiúsculo e minúsculo. Veja o formato
da saída nos exemplos abaixo.
• Exemplo de Entrada:
1aB 2aB
3bC 3dc
5hz 9hZ
9zh 9zI
0zH 0ai
8oi 0ni
1fm 1fn
2gF 4dG
%ea 2ea
5ha 5Ea
5h_ 4h?
• Exemplo de Saída:
DII
IDC
DIC
IID
IDD
DDI
IID
DDD
Codigo invalido!
Codigo invalido!
Codigo invalido!
*/

#include <stdio.h>

int main(){

	char a1, a2, a3, b1, b2, b3;
	
	scanf("%c%c%c %c%c%c",&a1,&a2,&a3,&b1,&b2,&b3);
	
	if ((a1>=48) && (a1<=57) && (b1>=48) && (b1<=57) && (a2>=97) && (a2<=122) && (b2>=97) && (b2<=122) && (a3>=65) && (a3<=122) && (a3!=91) && (a3!=92) && (a3!=93) && (a3!=94) && (a3!=95) && (a3!=96) && (b3<=122) && (b3!=91) && (b3!=92) && (b3!=93) && (b3!=94) && (b3!=95) && (b3!=96)){	
		if (a1==b1){
			printf("I");
		}
		else{
			printf("D");
		}
		if (a2==b2){
			printf("I");
		}
		else{
			printf("D");
		}
		if (a3==b3){
			printf("I");
		}
		else if ((a3==b3-32)||(a3-32==b3)){
			printf("C");
		}
		else{
			printf("D");
		}
	}
	else {
		printf("Codigo invalido!");
	}

return 0;
}
