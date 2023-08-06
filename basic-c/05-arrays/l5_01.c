/*
(BOCA:L5_1) Problema: Faça um programa que lê notas (de 0 a 100) de N
participantes de um concurso. O programa deverá calcular e imprimir: a menor
nota, a maior nota, a nota média, o desvio padrão, em que N é o
número de participantes, 𝑥𝑖 é uma nota e 𝑥 é a média das notas), a quantidade de
alunos acima da média do concurso, e o número de participantes reprovados (nota
inferior a 70).
 Entrada: 1 número inteiro N representando a o número de participantes, seguido de N
notas separadas por espaço.
 Saída: Um inteiro representando a menor nota, um inteiro representando a maior nota, um
decimal com 2 casas de precisão representando a nota média, um decimal com 2 casas de
precisão representando o desvio padrão, um inteiro representando a quantidade de alunos
acima da média do concurso, e um inteiro representando o número de participantes
reprovados. Olhe os exemplos de saída para ver formatações adicionais.
 Exemplo de Entrada:
1 41
2 56 54
5 5 31 32 62 10
10 21 93 4 48 0 68 40 54 76 88
 Exemplo de Saída:
MENOR:41, MAIOR:41, MEDIA:41.00, STD:0.00, ACIMA_MEDIA_CONC:0, REPROV:1
MENOR:54, MAIOR:56, MEDIA:55.00, STD:1.00, ACIMA_MEDIA_CONC:1, REPROV:2
MENOR:5, MAIOR:62, MEDIA:28.00, STD:20.17, ACIMA_MEDIA_CONC:3, REPROV:5
MENOR:0, MAIOR:93, MEDIA:49.20, STD:31.41, ACIMA_MEDIA_CONC:5, REPROV:7
*/
#include <stdio.h>
#include <math.h>

float recebeNotas(int numAlunos, int nota[], float armazenaValores[]);
void defineNumAprovadosReprovados(int numAlunos, int nota[], float notaMedia, float armazenaValores[]);
void calculaDesvioPadrao(int numAlunos, int nota[], float notaMedia, float armazenaValores[]);
void imprimeValores(float armazenaValores[]);

int main ()
{
    float armazenaValores[6]; //MENOR, MAIOR, MEDIA, STD, ACIMA_MEDIA_CON, REPROV

    int aluno, numAlunos; float notaMedia;

    scanf("%d", &numAlunos);
    int nota[numAlunos];

    notaMedia = recebeNotas(numAlunos, nota, armazenaValores); //armazena MENOR, MAIOR, MEDIA
    calculaDesvioPadrao(numAlunos, nota, notaMedia, armazenaValores); //armazena STD
    defineNumAprovadosReprovados(numAlunos, nota, notaMedia, armazenaValores); //armazena ACIMA_MEDIA_CON, REPROV
    imprimeValores(armazenaValores);

    return 0;
}

float recebeNotas(int numAlunos, int nota[], float armazenaValores[])
{
    int aluno, maiorNota, menorNota;
    float notaMedia = 0;

    for (aluno = 0; aluno < numAlunos; aluno++)
    {
        scanf("%d", &nota[aluno]);

        if (aluno == 0)
        {
            menorNota = nota[aluno];
            maiorNota = nota[aluno];
        }
        else
        {
            if (nota[aluno] > maiorNota)
                maiorNota = nota[aluno];
            if (nota[aluno] < menorNota)
                menorNota = nota[aluno];
        }
        
        notaMedia += nota[aluno];
    }
    notaMedia = notaMedia / numAlunos;

    armazenaValores[0] = menorNota;
    armazenaValores[1] = maiorNota;
    armazenaValores[2] = notaMedia;
    
    return notaMedia;
}

void calculaDesvioPadrao(int numAlunos, int nota[], float notaMedia, float armazenaValores[])
{
    int i;
    float desvioPadrao, somaDesvio = 0;

    for (i = 0; i < numAlunos; i++)
    {
        somaDesvio += pow( (nota[i] - notaMedia), 2 );
    }
    desvioPadrao = sqrt( somaDesvio / numAlunos );

    armazenaValores[3] = desvioPadrao;
}

void defineNumAprovadosReprovados(int numAlunos, int nota[], float notaMedia, float armazenaValores[])
{
    int notaAtual, numAcimaDaMedia = 0, numReprovados = 0;

    for (notaAtual = 0; notaAtual < numAlunos; notaAtual++)
    {
        if (nota[notaAtual] > notaMedia)
            numAcimaDaMedia++;
        if (nota[notaAtual] < 70)
            numReprovados++;
    }

    armazenaValores[4] = numAcimaDaMedia;
    armazenaValores[5] = numReprovados;
}

void imprimeValores(float armazenaValores[])
{
    printf("MENOR:%.0f, MAIOR:%.0f, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%.0f, REPROV:%.0f", armazenaValores[0], armazenaValores[1], armazenaValores[2], armazenaValores[3], armazenaValores[4], armazenaValores[5]);
}