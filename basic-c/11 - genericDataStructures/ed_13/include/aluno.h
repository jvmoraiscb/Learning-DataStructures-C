#if !defined(ALUNO_H)
#define ALUNO_H

typedef struct aluno Aluno;

Aluno *Constroi_aluno(char *nome, int matricula);
void Libera_aluno(Aluno *aluno);
char *Retorna_nome_aluno(Aluno *aluno);
int Retorna_matricula_aluno(Aluno *aluno);

#endif // ALUNO_H