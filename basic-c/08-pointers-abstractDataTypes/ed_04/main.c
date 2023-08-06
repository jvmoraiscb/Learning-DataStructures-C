/*
Implemente um TAD Lista Simplesmente Encadeada de Alunos, como explicado na última aula. Funcionalidades esperadas:
- inicialização da lista vazia;
- inserção de aluno na última posição;
- retirada de aluno por nome (chave de busca);
- liberação da memória alocada para a lista;

Neste exercício você tem a opção de definir o TAD Aluno separadamente (melhor!) OU no mesmo arquivo que a lista (para simplificar).

Implemente um cliente testador que teste todas as funcionalidades implementadas, inclusive, com 2 ou mais listas ativas na memória simultaneamente. 

Divirtam-se!!!!! :-)
*/
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

    Bruno = Constroi_aluno("Bruno", 3, 10, 10, 10);
    Insere_aluno(turma, Bruno);
    Imprime_aluno(turma);

    Retira_aluno(turma, "Bruno");
    Retira_aluno(turma, "Talles");
    Imprime_aluno(turma);
    
    Libera_sentinela(turma);

    return 0;
}