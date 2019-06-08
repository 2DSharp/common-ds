#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct entry_t {
  int val;
  Bucket bucket;  
} Entry;

int main()
{
  Hashtable hashtable;
  Hashtable * ht = &hashtable;
  
  hashtable_init(ht, 10);
  
  Entry * entry = (Entry *) malloc(sizeof(Entry));
  entry->val = 10;
  
  hashtable_put(ht, "john", &(entry->bucket));

  Entry * res;

  Entry * entry2 = (Entry *) malloc(sizeof(Entry));
  entry2->val = 12;
  
  hashtable_put(ht, "pan", &(entry2->bucket));

  Entry * entry3 = (Entry *) malloc(sizeof(Entry));
  entry3->val = 15;
  
  hashtable_put(ht, "tran", &(entry3->bucket));

  res = hashtable_get(ht, "john", Entry, bucket);
  printf("%d\n", res->val);
  
  res = hashtable_get(ht, "pan", Entry, bucket);
  printf("%d\n", res->val);

  res = hashtable_get(ht, "tran", Entry, bucket);
  printf("%d\n", res->val);

  Entry * entry4 = (Entry *) malloc(sizeof(Entry));
  entry4->val = 100;
  
  hashtable_put(ht, "pan", &(entry4->bucket));

  res = hashtable_get(ht, "john", Entry, bucket);
  printf("Replaced\n%d\n", res->val);
  
  res = hashtable_get(ht, "pan", Entry, bucket);
  printf("%d\n", res->val);

  res = hashtable_get(ht, "tran", Entry, bucket);
  printf("%d\n", res->val);
  
  res = hashtable_get(ht, "trans", Entry, bucket);
  if (res == NULL) {
    printf("Doesn't exist");
  }
  else printf("%d\n", res->val);  
}
