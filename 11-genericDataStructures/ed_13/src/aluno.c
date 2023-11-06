#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/aluno.h"

struct aluno
{
    char *nome;
    int matricula;
};

Aluno *Constroi_aluno(char *nome, int matricula)
{
    Aluno *aluno = malloc(sizeof(Aluno));
    aluno->matricula = matricula;
    aluno->nome = malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(aluno->nome, nome);

    return aluno;
}

void Libera_aluno(Aluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}
char *Retorna_nome_aluno(Aluno *aluno)
{
    return aluno->nome;
}

int Retorna_matricula_aluno(Aluno *aluno)
{
    return aluno->matricula;
}
