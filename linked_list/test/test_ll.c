#include "../linked_list.h"
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
  LL_Node *temp, * ptr, * head = &list.node;
  
  ll_create_list(head);

  Entry * entry;

  for (int i = 0; i < 5; i++) {
    entry = (Entry *) malloc(sizeof(Entry));
    entry->name = "John";
    entry->val = i;

    ll_push_back(head, &(entry->node));
  }

  for (ptr = head->next; ptr != head; ptr = ptr->next) {
    entry = ll_get(ptr, Entry, node);
    printf("%s\t%d\n", entry->name, entry->val);
  }

  ll_foreach_safe(ptr, temp, head) {
    entry = ll_get(ptr, Entry, node);
    printf("%s\t%d\n", entry->name, entry->val);
    free(entry);
  }
}
