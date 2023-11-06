/* 
(BOCA:L5_6) Problema: Faça um programa para ler duas sequências de números
e armazena-las em dois vetores A e B. No final, o programa deverá dizer se todos os
itens de A estão em B, se somente parte deles está, ou se nenhum deles está.
 Entrada: um número inteiro N1 representando uma quantidade de números, seguido de N1
números inteiros, e um número N2 representando uma quantidade de números, seguido
de N2 números inteiros, todos separados por espaço e com cada sequência em uma linha.
 Saída: “TODOS” se todos os itens de A estiverem em B, “NENHUM” se nenhum item de A
estiver em B, “PARCIAL” se os itens de A estiverem parcialmente em B. Ver exemplo abaixo
da formatação de saída.
 Exemplo de Entrada:
1 41
1 40
2 56 54
4 2 56 54 10
4 2 56 54 10
2 56 54
3 2 56 54
3 56 54 10
3 2 54 54
3 56 54 10
 Exemplo de Saída:
NENHUM
TODOS
PARCIAL
PARCIAL
PARCIAL
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanhoVetor);
void verificaConjuntos(int vetorA[], int tamanhoVetorA, int vetorB[], int tamanhoVetorB);

int main()
{
    int qtdNumerosA, qtdNumerosB;
    
    scanf("%d", &qtdNumerosA);
    int vetorA[qtdNumerosA];
    preencheVetor(vetorA, qtdNumerosA);
    scanf("%d", &qtdNumerosB);
    int vetorB[qtdNumerosB];
    preencheVetor(vetorB, qtdNumerosB);

    verificaConjuntos(vetorA, qtdNumerosA, vetorB, qtdNumerosB);

    return 0;
}

void preencheVetor(int vetor[], int tamanhoVetor)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]); 
    }
}

void verificaConjuntos(int vetorA[], int tamanhoVetorA, int vetorB[], int tamanhoVetorB)
{
    int iA, iB;
    int qtdItensAemB = 0, qtdItensAFora = 0;

    for (iA = 0; iA < tamanhoVetorA; iA++)
    {
        int vItemAemB = 0;

        for (iB = 0; iB < tamanhoVetorB; iB++)
        {
            if(vetorA[iA] == vetorB[iB])
                vItemAemB = 1;
        }

        if(vItemAemB != 0)
            qtdItensAemB++;
        else
            qtdItensAFora++;
    }

    if (qtdItensAemB > 0 && qtdItensAFora == 0)
        printf("TODOS");
    else if (qtdItensAemB == 0 && qtdItensAFora > 0)
        printf("NENHUM");
    else
        printf("PARCIAL");
}