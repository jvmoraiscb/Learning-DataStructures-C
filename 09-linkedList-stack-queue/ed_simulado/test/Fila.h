
#ifndef FILA_H_
#define FILA_H_


/*Tipo que define a fila de strings (tipo opaco).
 * Esta fila NÃO tem limite de tamanho */
typedef struct fila Fila;

/*Cria uma fila vazia
* inputs: nenhum
* output: fila alocada e vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia */
Fila* criaFila();

/*Insere uma string na fila (lembre-se, fila e' FIFO).
* inputs: string a ser inserida na fila (do tipo char*) e a fila
* output: nenhum
* pre-condicao: a string deve ter sido alocada dinamicamente!
* pos-condicao: fila contém string na ultima posição */
void insereFila (Fila* f, char* string);

/*Retira uma string da fila (usando FIFO). Retorna NULL se vazia
* inputs: a fila
* output:a string do final (ou NULL, caso a fila esteja vazia)
* pre-condicao: fila não nula (porém pode ser vazia)
* pos-condicao: fila não contém string que estava na ultima posição */
char* retiraFila (Fila* f);

/*Verifica se a fila esta ou nao vazia
* inputs: a fila de strings
* output: 1 se estiver vazia e zero caso contrario
* pre-condicao: fila não eh nula
* pos-condicao: nenhuma */
int vaziaFila (Fila* f);

/*Imprime as strings da fila (do inicio ao fim da fila!).
* inputs: a fila de strings
* output: nenhum
* pre-condicao: fila não nula
* pos-condicao: strings são impressas na saida padrao
*/
void imprimeFila (Fila* f);

/*Libera toda a memoria alocada para a fila (use o valgrind)".
* inputs: a fila de strings (strings precisam ser alocadas dinamicamente)
* output: NULL
* pre-condicao: fila não nula
* pos-condicao: toda memoria alocada liberada (inclusive das strings)*/
Fila* liberaFila (Fila* f);

#endif /* FILA_H_ */
