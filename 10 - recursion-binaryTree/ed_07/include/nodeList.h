#if !defined(NODELIST_H)
#define NODELIST_H

typedef struct nodeList List;

List *ListConstructor();
void ListDestructor(List *list);
void ListInsert(List *list, char *string);
void ListRemove(List *list, char *string);
void ListDisplay(List *list);
int ListCmp(List *list1, List *list2);

#endif // NODELIST_H
