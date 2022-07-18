/* 
Problema: (BOCA: P2_2018_Q3_a) Faça um programa para exibir o índice da turma
com a maior e a menor quantidade de alunos aprovados. O programa deverá exibir
também, para cada turma, a lista dos nomes dos aprovados. O índice da turma é
dado pela sua ordem de leitura, por exemplo, a primeira turma é a turma 1, a
segunda é a turma 2, etc. Um aluno é considerado aprovado, quando sua média é
maior ou igual a 70. O cálculo da média final de um aluno considera todas as suas
notas, exceto a nota mais baixa. Se o aluno só tiver uma nota, então ela será a média
final do aluno. As notas vão de 0 a 100.
• Entrada: um número inteiro n representando a quantidade de turmas a serem analisadas
seguido (na linha seguinte) das informações sobre as turmas. Cada turma será descrita por
um número inteiro a representando o número de alunos da turma seguido (na linha
seguinte) dos alunos da turma (um por linha). As informações de cada aluno serão dadas
em uma linha contendo o “nome” (representado por 2 caracteres) e as notas daquele
aluno. As notas serão dadas entre colchetes e separadas por espaço. Ver formatação nos
exemplos abaixo.
• Saída: para cada turma, o programa deverá imprimir “TURMA:#1” (em que #1 representa o
índice da turma) seguido das primeiras letras dos “nomes” dos alunos aprovados daquela
turma (sendo um em cada linha), ou seja, dos alunos com nota final maior ou igual a 70. Ao
final o programa deverá imprimir uma linha "MAIOR:TURMA #2 MENOR:TURMA #3", em
que #2 e #3 são respectivamente os índices da primeira ocorrência da turma com maior, e
menor, quantidade de alunos aprovados. Ver formato da saída nos exemplos abaixo.
O programa deve estar modularizado, para isso crie:
a) Uma função que leia as notas de um aluno e retorne a média daquele aluno
considerando o exposto acima (ou seja, desconsiderando a menor nota se for o
caso). Assuma que a função será chamada no início da leitura das notas (ou seja,
logo antes de ler a abertura do par de colchetes com as notas) e deve retornar após
consumir os caracteres que fecham o par de colchetes e fazem a quebra de linha.
Cabeçalho: double LeNotasECalculaMediaAluno ();
b) Uma função que leia as informações de uma turma e retorne a quantidade de seus
alunos aprovados. Assuma que a função será chamada no início da leitura das
informações de uma turma, ou seja, logo antes de ler o valor a representando o
número de alunos da turma. A função retornará após ler as informações do último
aluno da turma em questão. Adicionalmente, essa função deverá imprimir o nome
de cada aluno aprovados da turma sendo processada (um nome em cada linha).
Cabeçalho: int ContaAlunosAprovadosTurma ();
• Exemplos de Entradas:
4
4
AB[80 70 30 90 85 75]
BC[100 7]
CB[50]
DB[7 100]
1
DN[80 80 80]
2
FG[20 50 60]
HG[0 80]
1
UT[50 50 70]
2
4
FG[20 50 60]
HG[0 80]
TU[100]
UT[50 50 70]
4
AB[80 70 30 90 85 75]
BC[80 7]
CB[50]
DB[7 90]
• Exemplos de Saídas:
TURMA:1
A
B
D
TURMA:2
D
TURMA:3
H
TURMA:4
MAIOR:TURMA 1 MENOR:TURMA 4
TURMA:1
H
T
TURMA:2
A
B
D
MAIOR:TURMA 2 MENOR:TURMA 1
*/

#include <stdio.h>

int ContaAlunosAprovadosTurma();
double LeNotasECalculaMediaAluno();

void main()
{
    int turma, numTurmas, maiorTurma, menorTurma, numAprovados, maiorNumAprovados = -32000, menorNumAprovados = 32000;

    scanf("%d%*c", &numTurmas);
    for(turma = 1; turma <= numTurmas; turma++)
    {
        printf("TURMA:%d\n", turma);
        numAprovados = ContaAlunosAprovadosTurma();
        
        if (numAprovados > maiorNumAprovados){
            maiorNumAprovados = numAprovados;
            maiorTurma = turma;
        }
        if (numAprovados < menorNumAprovados){
            menorNumAprovados = numAprovados;
            menorTurma = turma;
        }
    }
    printf("MAIOR:TURMA %d MENOR:TURMA %d\n", maiorTurma, menorTurma);
}

int ContaAlunosAprovadosTurma()
{
    int aluno, numAlunos, numAprovados = 0; double mediaAluno; char nomeAluno;

    scanf("%d%*c", &numAlunos);
    for (aluno = 1; aluno <= numAlunos; aluno++)
    {
        scanf("%c%*c", &nomeAluno);
        mediaAluno = LeNotasECalculaMediaAluno();
        if (mediaAluno >= 70)
        {
            printf("%c\n", nomeAluno);
            numAprovados++;
        }
    }

    return numAprovados;
}

double LeNotasECalculaMediaAluno()
{
    int nota, somaNotas = 0, numNotas = 0, menorNota = 101;
    double media;
    char espacoOuColchete;

    scanf("%*c");
    while (1)
    {
        scanf("%d%c", &nota, &espacoOuColchete);
        if (nota < menorNota)
            menorNota = nota;
        somaNotas += nota;
        numNotas++;
        if (espacoOuColchete == ']')
            break;
    }
    scanf("%*c");
    if (numNotas <= 1)
        media = somaNotas;
    else
        media = (somaNotas - menorNota) / (numNotas - 1);
    
    return media;
}