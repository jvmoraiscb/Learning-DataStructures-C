#include <stdio.h>
#include "aluno.h"
#include "lista.h"

int main(){
    Aluno* Joao = Constroi_aluno("Joao", 1, 10, 10, 10);
    Aluno* Talles = Constroi_aluno("Talles", 2, 1.5, 0, 0);
    Aluno* Bruno = Constroi_aluno("Bruno", 3, 10, 10, 10);
    Aluno* Celso = Constroi_aluno("Celso", 4, 10, 10, 10);

    Sentinela* turma = Constroi_sentinela();
    Insere_aluno(turma, Joao);
    Insere_aluno(turma, Talles);
    Insere_aluno(turma, Bruno);
    Insere_aluno(turma, Celso);
    Imprime_aluno(turma);

    Retira_aluno(turma, "Joao");
    Retira_aluno(turma, "Bruno");
    Retira_aluno(turma, "Celso");
    Imprime_aluno(turma);

    Insere_aluno(turma, Bruno);
    Imprime_aluno(turma);
    
    Libera_sentinela(turma);

    return 0;
}