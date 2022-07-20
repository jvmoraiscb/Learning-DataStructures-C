
#if !defined(LISTA_GENERICA_H)
#define LISTA_GENERICA_H

typedef struct lista Lista;

Lista* Constroi_lista();
void Destroi_lista(Lista* lista);

void Insere_item_lista(Lista* lista, void* item);
int Retira_item_lista(Lista* lista, int(*Cmp)(void*, void*), void* chave);
void Percorre_lista(Lista* lista, void(*fix_it)(void*));

#endif // LISTA_H