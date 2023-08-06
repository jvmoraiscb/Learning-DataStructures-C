/*
(BOCA: P1_2019_Q3) Problema: Faça um programa que verifique se uma placa de
carro é válida. Uma placa, composta por 3 letras e 4 números @@@-####, é válida
quando @ são letras maiúsculas ou minúsculas e # são dígitos numéricos.
• Entrada: São 8 caracteres representando uma placa no formato @@@-####, sendo @
letras maiúsculas ou minúsculas, # dígitos numéricos e as letras separadas dos números por
um traço. Veja o formato de entrada nos exemplos abaixo.
• Saída: A saída deverá imprimir: "Codigo valido!" se as regras seguirem a definição de placa
válida; e, “Codigo invalido!” caso contrário. Nesse último caso, a mensagem deverá ser
acompanhada ainda por: "Problema nos numeros!" se apresentar problemas somente na
parte dos números; "Problema nas letras!" se apresentar problemas somente na parte das
letras; e, "Problema nas letras e nos numeros!" caso apresente problemas nas duas partes.
Veja o formato da saída nos exemplos abaixo.
• Exemplo de Entrada:
AbC-1001
aaC-3211
a2C-3211
JCs-32k1
a8C-3n21
• Exemplo de Saída:
Codigo valido!
Codigo valido!
Codigo invalido!Problema nas letras!
Codigo invalido!Problema nos numeros!
Codigo invalido!Problema nas letras e nos numeros!
*/

#include <stdio.h>

int main(){

	char l1,l2,l3,l4, n1,n2,n3,n4;
	int vn, vl, vh;
	
	scanf("%c%c%c%c%c%c%c%c",&l1,&l2,&l3,&l4,&n1,&n2,&n3,&n4);
	
	if ((n1>='0' && n1<='9')&&(n2>='0' && n2<='9')&&(n3>='0' && n3<='9')&&(n4>='0' && n4<='9')){
		vn=1;
	}
	else{
		vn=0;
	}
	if ((l1>='A' && l1<='Z' || l1>='a' && l1<='z')&&(l2>='A' && l2<='Z' || l2>='a' && l2<='z')&&(l3>='A' && l3<='Z' || l3>='a' && l3<='z')){
		vl=1;
	}
	else{
		vl=0;
	}
	if (l4=='-'){
		vh=1;
	}
	else{
		vh=0;
	}
	if ((vn==1)&&(vl==1)&&(vh==1)){
		printf("Codigo valido!");
	}
	else {
		printf("Codigo invalido!");
		if (vh==1){
			if ((vn==1)&&(vl==0)){
				printf("Problema nas letras!");
			}
			else if ((vn==0)&&(vl==1)){
				printf("Problema nos numeros!");
			}
			else if ((vn==0)&&(vl==0)){
				printf("Problema nas letras e nos numeros!");
			}
		}
	}

	
return 0;
}
