#include "hashtable.h"

int hashtable_init(Hashtable * ht, int size)
{
  if ((ht->buckets = (Bucket **) calloc (size, sizeof(Bucket *))) == NULL)
    return HT_INIT_FAILURE;
  ht->size = size;
  
  for (int i = 0; i < size; i++)
    ht->buckets[i] = NULL;

  return HT_INIT_SUCCESS;
}

unsigned long __hash_sdbm(char *str)
{
  unsigned long hash = 0;
  int c;
  
  while ((c = *str++))
    hash = c + (hash << 6) + (hash << 16) - hash;
  
  return hash;
}
int __key_matches(char * source, char * target)
{
  return (strcmp(source, target) == 0);
}

void __insert_bucket(Hashtable * hashtable, int index, Bucket * bucket)
{
  if (hashtable->buckets[index] == NULL) {
    
    LL_Node * head = &bucket->ll_node;  
    ll_create_list(head);
    hashtable->buckets[index] = bucket;
  }
  else {

    LL_Node * head = &(hashtable->buckets[index]->ll_node);
    LL_Node * ptr = head;
    int head_key_matches = (__key_matches(bucket->key,
					  hashtable->buckets[index]->key));
    
    Bucket * search_bucket;
    
    ll_foreach(ptr, head) { 
      search_bucket = ll_get(ptr, Bucket, ll_node); 
      if (head_key_matches || __key_matches(bucket->key, search_bucket->key)) { 
     	ll_replace(ptr, &bucket->ll_node); 
	return; 
      }     
    }
    ll_push_front(head, &(bucket->ll_node));
  }
}
    
  /* else { */
  /*   Bucket * search_bucket = hashtable_get_bucket(bucket->key); */
  /*   if (search_bucket == NULL) */
  /*     ll_push_back(&(__hashtable[index]->ll_node), &(bucket->ll_node)); */
  /*   else { */
  /*     // replace bucket */
  /*     __replace_bucket(search_bucket, bucket); */
  /*   } */
  /* } */

void hashtable_put(Hashtable * ht, char * key, Bucket * bucket)
{
  int index = __hash_sdbm(key) % ht->size;
  bucket->key = key;
  __insert_bucket(ht, index, bucket);
}

Bucket * __hashtable_get_bucket(Hashtable * hashtable, char * key)
{
  int index = __hash_sdbm(key) % hashtable->size;  

  if (hashtable->buckets[index] == NULL)
    return NULL;

  Bucket * bucket = hashtable->buckets[index];
  
  if (__key_matches(bucket->key, key)) {
    return bucket;
  }

  else {
    LL_Node * ptr;
    LL_Node * head = &(hashtable->buckets[index]->ll_node);
  
    ll_foreach(ptr, head) {
      bucket = ll_get(ptr, Bucket, ll_node);
      if (__key_matches(key, bucket->key)) {
	return bucket;
      }
    }
    return NULL;
  }
}

int hashtable_key_exists(Hashtable * ht, char * key)
{
  return (__hashtable_get_bucket(ht, key) == NULL);
}

void hashtable_close(Hashtable *ht)
{
  free(ht->buckets);
  ht->size = 0;
}
