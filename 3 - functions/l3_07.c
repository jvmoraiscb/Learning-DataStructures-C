/* 
(BOCA:L3_7) Problema: Dado as coordenadas x e y das extremidades inferior
esquerda e superior direita de dois retângulos, calcule a área total ocupada por eles.
a) O cálculo da área total deverá ser realizado por uma função (a ser implementada)
que receberá as coordenadas das extremidades de cada retângulo e retornará o
resultado. A função deverá ter o seguinte cabeçalho:
int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);
b) O cálculo da área de um retângulo deverá ser realizado por uma função (a ser
implementada) que receberá as coordenadas das extremidades desse retângulo e
retornará o resultado. A função deverá ter o seguinte cabeçalho:
int area (int x1, int y1, int x2, int y2);
Atenção: As coordenadas da extremidade inferior esquerda do primeiro retângulo serão
sempre menores (ou iguais) que todas as outras. As coordenadas da extremidade
superior direita do segundo retângulo serão sempre maiores (ou iguais) que todas as
outras. Nenhum retângulo estará inteiramente contido dentro de outro.
• Entrada: duas linhas, uma para cada retângulo. Cada linha conterá 4 números inteiros
representando as coordenadas x e y das extremidades inferior esquerda e superior direita,
exatamente nessa ordem.
• Saída: “RESP:” seguido de um número inteiro representando a área total ocupada pelos
dois retângulos.
• Exemplo de Entradas:
0 0 2 2
4 4 6 6
5 6 8 9
9 9 12 12
-13 -5 7 0
0 0 15 10
• Exemplo de Saídas:
RESP:8
RESP:18
RESP:250
*/

#include <stdio.h>

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);

int area (int x1, int y1, int x2, int y2);

int main(){
	int r1_x1, r1_y1, r1_x2, r1_y2;
	int r2_x1, r2_y1, r2_x2, r2_y2;
	int areatotal;
	
	scanf("%d %d %d %d\n", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
	scanf("%d %d %d %d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);
	
	areatotal = area_total (r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);
	
	printf("RESP:%d", areatotal);
	
	return 0;
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2)
{
	int AreaR1, AreaR2;
	
	AreaR1 = area (r1_x1, r1_y1, r1_x2, r1_y2);

	if (r2_x1 > r1_x2 && r2_y1 > r1_y2)
		AreaR2 = area (r2_x1, r2_y1, r2_x2, r2_y2);
	else
		AreaR2 = area (r2_x1, r2_y1, r2_x2, r2_y2) - area (r2_x1, r2_y1, r1_x2, r1_y2); 
		//retangulos sobrepostos

	return (AreaR1+AreaR2);
}

int area (int x1, int y1, int x2, int y2){
	
	return ((x2 - x1) * (y2 - y1));
}
