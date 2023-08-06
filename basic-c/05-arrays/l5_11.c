/* 
(BOCA:L5_11) Problema: Faça um programa para ler duas sequências de números
e armazena-las em dois vetores A e B. Ordene em ordem crescente os dois vetores
individualmente. No final, imprima a sequência de retiradas dos vetores A e B,
intercaladamente e do menor para o maior, que será necessária para gerar uma
nova sequência de números contendo os elementos de A e B, e ainda ordenada. Em
caso de empate, o vetor A terá prioridade. Exemplo: A= 1, 3, 4, 5; e B=2, 3, 6; gerará a
sequência: ABABAAB, pois a nova sequência de números seria 1,2,3,3,4,5,6, sendo
que o 1 vem de A, 2 vem de B, 3 vem de A, 3 vem de B, 4 vem de A, 5 vem de A, e 6
vem de B.
 Entrada: um número inteiro N1 representando uma quantidade de números, seguido de N1
números inteiros, e um número N2 representando uma quantidade de números, seguido
de N2 números inteiros, todos separados por espaço e com cada sequência em uma linha.
 Saída: Sequência de retiradas mostrando o vetor de origem de cada uma delas.
 Exemplo de Entrada:
1 41
1 40
2 56 54
4 2 56 54 10
4 2 56 54 10
2 56 54
3 2 56 54
3 56 54 10
3 2 5 4
3 56 54 10
3 2 54 54
1 54
 Exemplo de Saída:
BA
BBABAB
AAABAB
ABABAB
AAABBB
AAAB
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanhoVetor);
void imprimeOrdemAouB(int vetor[], int tamanhoVetor, int vetor2[], int tamanhoVetor2);
void ordenaCrescente(int vetor[], int tamanhoVetor);
int encontraMenorInteiro(int vetor[], int tamanhoVetor, int i);

int main()
{
    int qtdNumeros, qtdNumeros2;
    scanf("%d", &qtdNumeros);
    int vetorNumero[qtdNumeros];
    preencheVetor(vetorNumero, qtdNumeros);
    scanf("%d", &qtdNumeros2);
    int vetorNumero2[qtdNumeros2];
    preencheVetor(vetorNumero2, qtdNumeros2);

    ordenaCrescente(vetorNumero, qtdNumeros);
    ordenaCrescente(vetorNumero2, qtdNumeros2);

    imprimeOrdemAouB(vetorNumero, qtdNumeros, vetorNumero2, qtdNumeros2);

    return 0;
}

void ordenaCrescente(int vetor[], int tamanhoVetor)
{
   int i, iMenorInteiro, inteiroFlutuante;

    for (i = 0; i < tamanhoVetor; i++)
    {
        iMenorInteiro = encontraMenorInteiro(vetor, tamanhoVetor, i);
        inteiroFlutuante = vetor[i];
        vetor[i] = vetor[iMenorInteiro];
        vetor[iMenorInteiro] = inteiroFlutuante;
    } 
}

void preencheVetor(int vetor[], int tamanhoVetor)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        scanf("%d", &vetor[i]); 
    }
}

void imprimeOrdemAouB(int vetor[], int tamanhoVetor, int vetor2[], int tamanhoVetor2)
{
    int i, i1 = 0, i2 = 0;

    int vetorSomado[tamanhoVetor + tamanhoVetor2];
    for (i = 0; i < tamanhoVetor + tamanhoVetor2; i++)
    {
        if(vetor[i1] <= vetor2[i2] && i1 < tamanhoVetor)
        {
            vetorSomado[i] = vetor[i1];
            i1++;
            printf("A");
        }
        else if (i2 < tamanhoVetor2)
        {
            vetorSomado[i] = vetor[i2];
            i2++;
            printf("B");
        }
    }
}

int encontraMenorInteiro(int vetor[], int tamanhoVetor, int i)
{
    int i2, menorInteiro, iMenorInteiro;

    for (i2 = i; i2 < tamanhoVetor; i2++)
    {
        if (i2 == i)
        {
            menorInteiro = vetor[i2];
            iMenorInteiro = i2;
        }
        else if(vetor[i2] < menorInteiro)
        {
            menorInteiro = vetor[i2];
            iMenorInteiro = i2;
        }
    }

    return iMenorInteiro;
}