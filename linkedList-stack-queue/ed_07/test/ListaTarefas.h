#ifndef LISTATAREFAS_H_
#define LISTATAREFAS_H_

/*Tipo que define a Tarefa (tipo opaco)
 * Uma tarefa deve ter um nome e uma fila de procedimentos (fila sem limite de tamanho)
 * O fila.h a ser implementada também é fornecido
 * */
typedef struct tarefa Tarefa;


/*Tipo que define a Lista de Tarefas (tipo opaco)
 * Defina uma lista encadeada
 * */
typedef struct listatarefas ListaTarefas;


/*------------ funcoes relacionadas a tarefa e procedimentos -----------*/

/*Cria uma tarefa vazia, com uma fila de procedimentos vazia
* inputs: nome da tarefa (char*). Esta função deve alocar dinamicamente o nome da tarefa.
* output: tarefa alocada e vazia, com fila de procedimentos ainda vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia,  */
Tarefa* criaTarefa(char* nome);

/*Insere um procedimento na fila de procedimentos de uma tarefa
* inputs: Endereço da tarefa e a string que define o procedimento. Esta função deve alocar dinamicamente esta string.
* output: nao tem
* pre-condicao:tarefa e procedimento nao nulos
* pos-condicao: procedimento inserido na ultima posicao da fila de procedimentos desta tarefa */
void insereProcedimentoTarefa (Tarefa* tarefa, char* procedimento);



/*------------ funcoes relacionadas a lista de tarefas -----------*/

/* Cria uma lista de tarefas vazia
* inputs: nenhum
* output: lista vazia
* pre-condicao: nao tem
* pos-condicao: lista alocada e vazia,  */
ListaTarefas* criaListaTarefas ();

/* Insere uma tarefa na PRIMEIRA posicao da lista de tarefas.
* inputs: a lista de tarefas e a tarefa a ser inserida
* output: nao tem
* pre-condicao: lista e tarefa nao nulas
* pos-condicao: tarefa incluida na primeira posicao da lista*/
void insereTarefaLista (ListaTarefas* lista, Tarefa* tarefa);


/* Retira uma determinada tarefa da lista de tarefas e a retorna.
* inputs: a lista de tarefas e o nome da tarefa a ser retirada
* output: Endereco da tarefa retirada
* pre-condicao: lista e nome nao nulos
* pos-condicao: tarefa retirada da lista e ponteiros da lista ficam consistentes */
Tarefa* retiraTarefaLista (ListaTarefas* lista, char* nome);

/* Imprime a lista de tarefas e todos os procedimentos de cada tarefa.
 * (Formato: Nome da Tarefa: EstudarProvaED.
 *           Procedimentos: Pegar material no site
 *                           Baixar os slides
 *                           Refazer todos os labs
 * )
* inputs: a lista de tarefas
* output: nao tem
* pre-condicao: lista nao nula
* pos-condicao: tarefas e procedimentos impressos na saida padrao */
void imprimeListaTarefas (ListaTarefas* lista);

/* Libera toda a memoria alocada (use valgrind)!
* inputs: a lista de tarefas
* output: NULL
* pre-condicao: lista nao nula
* pos-condicao: toda a memoria eh liberada, inclusive das strings e dos procedimentos. */
ListaTarefas* liberaListaTarefas(ListaTarefas* lista);

#endif /* LISTATAREFAS_H_ */
