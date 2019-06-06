#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../linked_list/linked_list.h"
#include <string.h>
#include <stddef.h>


#define HT_MAGIC_SIZE 997

typedef struct bucket_t
{
  char * key;
  LL_Node ll_node;
} Bucket;

Bucket * __hashtable[HT_MAGIC_SIZE];

void hashtable_put(char * key, Bucket * bucket);
#define hashtable_get_value(bucket, struct_type, struct_member) \
  ((struct_type *)((char *)(bucket) - (unsigned long)(offsetof(struct_type, struct_member))))
Bucket * hashtable_get_bucket(char * key);

#define hashtable_get(key, struct_type, struct_member)			\
  hashtable_get_value(hashtable_get_bucket(key), struct_type, struct_member);

#endif
