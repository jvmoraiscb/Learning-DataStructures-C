#include "../include/nodeList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell
{
  char *string;
  struct cell *next;
  struct cell *previous;
} Cell;

struct nodeList
{
  Cell *first;
  Cell *last;
};

static int CellCmpRecursive(Cell *cell1, Cell *cell2);
static void CellPrintRecursive(Cell *cell);
static Cell *CellFindRecursive(Cell *cell, char *string);
static void CellDestructorRecursive(Cell *cell);

List *ListConstructor()
{
  List *newList = malloc(sizeof(List));
  newList->first = NULL;
  newList->last = NULL;

  return newList;
}
void ListDestructor(List *list)
{
  CellDestructorRecursive(list->first);
  free(list);
}
void ListInsert(List *list, char *string)
{
  Cell *newCell = malloc(sizeof(Cell));
  newCell->string = strdup(string);
  newCell->next = NULL;

  if (list->first == NULL)
  {
    list->first = newCell;
    list->last = newCell;
    newCell->previous = NULL;
  }
  else
  {
    list->last->next = newCell;
    newCell->previous = list->last;
    list->last = newCell;
  }
}
void ListRemove(List *list, char *string)
{
  Cell *targetCell = CellFindRecursive(list->first, string);
  if (targetCell != NULL)
  {
    if (targetCell->next == NULL && targetCell->previous == NULL)
    {
      list->first = NULL;
      list->last = NULL;
    }
    else if (targetCell->previous == NULL)
    {
      targetCell->next->previous = NULL;
      list->first = list->first->next;
    }
    else if (targetCell->next == NULL)
    {
      targetCell->previous->next = NULL;
      list->last = list->last->previous;
    }
    else
    {
      targetCell->previous->next = targetCell->next;
      targetCell->next->previous = targetCell->previous;
    }
  }
  free(targetCell->string);
  free(targetCell);
}
void ListDisplay(List *list)
{
  CellPrintRecursive(list->first);
}
int ListCmp(List *list1, List *list2)
{
  return CellCmpRecursive(list1->first, list2->first);
}
static int CellCmpRecursive(Cell *cell1, Cell *cell2)
{
  if (cell1 != NULL && cell2 != NULL)
  {
    if (CellCmpRecursive(cell1->next, cell2->next))
    {
      if (!strcmp(cell1->string, cell2->string))
      {
        return 1;
      }
    }
  }
  if (cell1 == NULL && cell2 == NULL)
  {
    return 1;
  }
  return 0;
}
static void CellPrintRecursive(Cell *cell)
{
  if (cell != NULL)
  {
    printf("%s\n", cell->string);
    CellPrintRecursive(cell->next);
  }
}
static Cell *CellFindRecursive(Cell *cell, char *string)
{
  if (cell != NULL)
  {
    if (!strcmp(cell->string, string))
    {
      return cell;
    }
    else
    {
      return CellFindRecursive(cell->next, string);
    }
  }
  return NULL;
}
static void CellDestructorRecursive(Cell *cell)
{
  if (cell != NULL)
  {
    CellDestructorRecursive(cell->next);
    free(cell->string);
    free(cell);
  }
}
