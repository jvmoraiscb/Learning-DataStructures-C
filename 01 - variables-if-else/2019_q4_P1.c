/*
(BOCA: P1_2019_Q4) Problema: Faça um programa que verifique a validade de um CPF.
Um CPF é composto por 11 dígitos numéricos #1#2#3.#4#5#6.#7#8#9-#10#11, sendo
os nove primeiros a base e os dois últimos os verificadores. Para que um CPF seja
válido, seus dígitos verificadores devem obedecer a um cálculo feito a partir dos outros
dígitos do CPF. Um CPF com todos dígitos iguais já é inválido independente do cálculo
do dígito verificador.
Cálculo do dígito verificador #10:
soma = #1 * 10 + #2 * 9 + #3 * 8 + #4 * 7 + #5 * 6 + #6 * 5 + #7 * 4 + #8 * 3 + #9 * 2
Se o resto da divisão da soma por 11 for menor que 2, então o dígito é 0
Se o resto da divisão da soma por 11 for maior ou igual 2, então o dígito é (11 - resto)
Cálculo do dígito verificador #11:
soma = #1 * 11 + #2 * 10 + #3 * 9 + #4 * 8 + #5 * 7 + #6 * 6 + #7 * 5 + #8 * 4 + #9 * 3 + #10 * 2
Se o resto da divisão da soma por 11 for menor que 2, então o dígito é 0
Se o resto da divisão da soma por 11 for maior ou igual 2, então o dígito é (11 - resto)
• Entrada: Um CPF no formato ###.###.###-##. Veja o formato de entrada nos exemplos abaixo.
• Saída: A saída deverá imprimir: "CPF valido!" se o CPF informado for válido; "CPF invalido:
digitos iguais!" se ele for inválido por ter todos os dígitos iguais; "CPF invalido: primeiro
digito!" se ele for inválido por ter o primeiro dígito verificador diferente do esperado; "CPF
invalido: segundo digito!" se ele for inválido por ter o segundo dígito verificador diferente do
esperado; e, "CPF invalido: dois digitos!" se ele for inválido por ter os dois dígitos verificadores
diferentes dos esperados. Veja o formato da saída nos exemplos abaixo.
• Exemplo de Entrada:
999.999.999-99
111.444.777-35
111.444.777-25
111.444.777-34
111.444.777-23
529.982.247-25
• Exemplo de Saída:
CPF invalido: digitos iguais!
CPF valido!
CPF invalido: primeiro digito!
CPF invalido: segundo digito!
CPF invalido: dois digitos!
CPF valido!
*/

#include <stdio.h>

int main(){
	int cpf1,cpf2,cpf3,cpf4;
	int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11;
	int vd10, vd11;
	int v1=0, v2=0;
	
	scanf("%d.%d.%d-%d",&cpf1,&cpf2,&cpf3,&cpf4);
	
	d1=cpf1/100;
	d2=(cpf1-d1*100)/10;
	d3=cpf1-d1*100-d2*10;
	d4=cpf2/100;
	d5=(cpf2-d4*100)/10;
	d6=cpf2-d4*100-d5*10;
	d7=cpf3/100;
	d8=(cpf3-d7*100)/10;
	d9=cpf3-d7*100-d8*10;
	d10=cpf4/10;
	d11=cpf4-d10*10;
	
	vd10=d1*10+d2*9+d3*8+d4*7+d5*6+d6*5+d7*4+d8*3+d9*2;
	if (vd10%11<2)
	vd11=d1*11+d2*10+d3*9+d4*8+d5*7+d6*6+d7*5+d8*4+d9*3;
	else
	vd11=d1*11+d2*10+d3*9+d4*8+d5*7+d6*6+d7*5+d8*4+d9*3+(11-vd10%11)*2;
	
	if (vd10%11<2){
		if(d10==0){
			v1=1;
		}
	}
	else{
		if (d10==11-vd10%11)
			v1=1;
	}
	if (vd11%11<2){
		if (d11==0)
			v2=1;
	}
	else{
		if (d11==11-vd11%11)
			v2=1;
	}
	if (d1==d2 && d2==d3 && d3==d4 && d5==d6 && d6==d7 && d7==d8 && d8==d9 && d9==d10 && d10==d11)
		printf("CPF invalido: digitos iguais!");
	else {
		if (v1==1 && v2==1)
			printf("CPF valido!");
		else if (v1==0 && v2==1)
			printf("CPF invalido: primeiro digito!");
		else if (v1==1 && v2==0)
			printf("CPF invalido: segundo digito!");
		else if (v1==0 && v2==0)
			printf("CPF invalido: dois digitos!");
		}
	//printf("%d %d %d %d", d10, d11, 11-162%11, 11-vd11%11);
	
return 0;
}
