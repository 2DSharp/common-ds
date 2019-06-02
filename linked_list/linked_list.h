#ifndef LLIST_H
#define LLIST_H

/* A generic-ish typed circular doubly linked list implementation
 * A part of the DSLIBC
 */
#include <stddef.h>

typedef struct ll_node_t 
{
  struct ll_node_t * next, * prev;
} LL_Node;

void ll_push_back(LL_Node * head, LL_Node * new_node);
void ll_flush_list(LL_Node * head);
void ll_create_list(LL_Node * new_head_ptr);

/*
 * Get the struct stored in that node location
 */
#define ll_get(node, struct_type, struct_member) \
  ((struct_type *)((char *)(node) - (unsigned long)(offsetof(struct_type, struct_member))))

#endif
