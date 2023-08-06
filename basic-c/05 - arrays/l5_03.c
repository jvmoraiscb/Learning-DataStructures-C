/* 
(BOCA:L5_3) Problema: Faça um programa que lê as alturas (de 0 a 100) de uma
sequência de N postes de uma cidade para um vetor. No final, o programa deverá
imprimir o par de posições consecutivas do vetor com a maior diferença entre as
alturas. Se houver mais de um par com a mesma diferença, imprima todos eles.
 Entrada: 1 número inteiro N representando o número de postes, seguido de N alturas
separadas por espaço.
 Saída: O(s) par(es) de postes(s) consecutivos com maior diferença de altura, ou
“IMPOSSIVEL” caso não haja diferença para ser calculada. Ver exemplo abaixo da
formatação de saída.
 Exemplo de Entrada:
1 41
2 56 54
5 5 31 32 62 10
5 5 10 20 30 25
5 10 10 10 10 10
 Exemplo de Saída:
IMPOSSIVEL
(0 1)
(3 4)
(1 2) (2 3)
(0 1) (1 2) (2 3) (3 4)
*/

#include <stdio.h>
#include <math.h>

int encontraMaiorDiferenca(int vetor[], int tamanhoVetor);
void preencheVetor(int vetor[], int tamanhoVetor);
void imprimePares(int vetor[], int tamanhoVetor, int maiorDiferencaAltura);

int main()
{
    int numPostes;
    scanf("%d", &numPostes);
    int alturaPostes[numPostes];

    preencheVetor(alturaPostes, numPostes);
    imprimePares(alturaPostes, numPostes, encontraMaiorDiferenca(alturaPostes, numPostes));

    return 0;
}

void preencheVetor(int vetor[], int tamanhoVetor)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]);
        //printf("%d\n", vetor[i]);
    }
}

int encontraMaiorDiferenca(int vetor[], int tamanhoVetor)
{
    int i, maiorDiferenca = -1;

    for (i = 1; i < tamanhoVetor; i++)
    {
        if (fabs(vetor[i] - vetor[i - 1]) > maiorDiferenca)
            maiorDiferenca = fabs(vetor[i] - vetor[i - 1]);
    }

    return maiorDiferenca;
}

void imprimePares(int vetor[], int tamanhoVetor, int maiorDiferencaAltura)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        if (tamanhoVetor > 1)
        {
            if(i != 0)
            {
                int diferencaAltura = fabs(vetor[i] - vetor[i - 1]);

                if(diferencaAltura == maiorDiferencaAltura)
                    printf(" (%d %d)", i-1, i);
            }
        }
        else
            printf("IMPOSSIVEL");
    }
}