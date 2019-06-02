#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct entry_t {
  int val;
  char * name;
  LL_Node node;
  
} Entry;

int main()
{
  Entry list;
  LL_Node * pos, * head = &list.node;
  
  ll_create_list(head);

  Entry * tmp;

  for (int i = 0; i < 5; i++) {
    tmp = (Entry *) malloc(sizeof(Entry));
    tmp->name = "John";
    tmp->val = i;

    ll_push_back(head, &(tmp->node));
  }

  for (pos = head->next; pos != head; pos = pos->next) {
    tmp = ll_get(pos, Entry, node);
    printf("%s\t%d\n", tmp->name, tmp->val);
  }
}
