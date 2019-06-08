#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../linked_list/linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define HT_MAGIC_SIZE 997

typedef struct bucket
{
  char * key;
  LL_Node ll_node;
} Bucket;

typedef struct hashtable
{
  Bucket ** buckets;
  unsigned int size;
} Hashtable;
  

void hashtable_init(Hashtable * hashtable, int size);
void hashtable_put(Hashtable * hashtable, char * key, Bucket * bucket);
int hashtable_key_exists(Hashtable * hashtable, char * key);
#define hashtable_get_value(bucket, struct_type, struct_member)		\
  ((struct_type *)((char *)(bucket) - (unsigned long)(offsetof(struct_type, struct_member))))

Bucket * hashtable_get_bucket(Hashtable * hashtable, char * key);

#define hashtable_get(hashtable, key, struct_type, struct_member)	\
  hashtable_get_value(hashtable_get_bucket(hashtable, key), struct_type, struct_member);

#endif
