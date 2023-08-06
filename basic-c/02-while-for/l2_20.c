/*
(BOCA:L2_20) Problema: Faça um programa que dados os coeficientes de uma
equação de 3° grau, correspondentes ao a, b, c e d respectivamente
(ax³ + bx² + cx + d = y) e dados os limites e e f do intervalo fechado [e,f], avalie esse
intervalo procurando o pico e o vale e então os imprima na tela.
Atenção: Considerar avaliação discreta, ou seja, analisar somente os números
inteiros do intervalo. Caso não haja pico ou vale, o programa deve informar que não
há. Usar loop para avaliar o intervalo indo no sentido de e para f. Soluções analíticas
não serão consideradas corretas.
 Entrada: números reais representando os coeficientes a, b, c e d de uma equação de
terceiro grau seguidos de dois números inteiros e e f, descrevendo um intervalo fechado.
 Saída: cada vez que seu programa encontrar um pico ou um vale ele deverá informar (em
uma linha) qual dos dois foi encontrado seguidos do valor x de onde eles foram
encontrados. Caso não haja máximo ou mínimo até o final do intervalo, imprimir uma
mensagem “Nao ha pico” ou “Nao ha vale” respectivamente. Veja exemplos de formatação
abaixo.
 Exemplo de Entradas:
0.03 0 0 0 -10 10
1 9 -1 2 -10 10
0 0.2 0 0 -20 20
-0.0001 0.01 1 1 -120 200
 Exemplo de Saídas:
Nao ha pico
Nao ha vale
Pico em x=-6
Vale em x=0
Vale em x=0
Nao ha pico
Vale em x=-33
Pico em x=100
*/

#include <stdio.h>
#include <math.h>

int main(){

	int e, f, i;
	int vvale=0, vpico=0; //verifica a existencia de pico ou vale
	float a, b, c, d, y, yantes, ydepois;
	
	scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &e, &f);
	
	/*ax³ + bx² + cx + d ----> 3ax² + 2bx² + c (derivação)
	if (pow(2*b,2)-4*3*a*c>=0){
	
		x1=(-2*b + sqrt(pow(2*b, 2) - 4*3*a*c))/2*3*a;
		x2=(-2*b - sqrt(pow(2*b, 2) - 4*3*a*c))/2*3*a;
	} */
	
	for (i=e; i<=f; i++){
		
		y = a*pow(i,3) + b*pow(i,2) + c*i + d;
		yantes = a*pow(i-1,3) + b*pow(i-1,2) + c*(i-1) + d;
		ydepois = a*pow(i+1,3) + b*pow(i+1,2) + c*(i+1) + d;
		
		if (yantes<y && ydepois<y){
			printf("Pico em x=%d\n", i);
			vpico=1;
		}
		else if (yantes>y && ydepois>y){
			printf("Vale em x=%d\n", i);
			vvale=1;
		}
	}
	if (vpico==0)
		printf("Nao ha pico\n");
	if (vvale==0)
		printf("Nao ha vale\n");

	return 0;
}
