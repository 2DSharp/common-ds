#ifndef LLIST_H
#define LLIST_H

/* A generic-ish typed circular doubly linked list implementation
 * A part of the DSLIBC
 * This is loosely based on the Linux kernel's list.h
 */
#include <stddef.h>

typedef struct ll_node 
{
  struct ll_node * next, * prev;
} LL_Node;

void ll_push_back(LL_Node * head, LL_Node * new_node);
void ll_push_front(LL_Node * head, LL_Node * new_node);
void ll_delete(LL_Node * node);
void ll_replace(LL_Node * old, LL_Node * new);
void ll_create_list(LL_Node * new_head_ptr);

/*
 * Get the struct stored in that node location
 * A neat trick that gets the address of the struct housing the \
 * LL_Node
 */
#define ll_get(node, struct_type, struct_member)			\
  ((struct_type *)((char *)(node) - (unsigned long)(offsetof(struct_type, struct_member))))

/*
 * Iterate over the list
 */
#define ll_foreach(ptr, head)			\
  for (ptr = (head)->next; ptr != head;		\
       ptr = ptr->next)

/*
 * Iterate backwards
 */
#define ll_foreach_back(ptr, head)		\
  for (ptr = (head)->prev; ptr != head;		\
       ptr = ptr->prev)
/*
 * Iterate over each item safely 
 * Allows for freeing of objects without any errors
 */
#define ll_foreach_safe(ptr, temp, head)			\
  for (ptr = (head)->next, temp = ptr->next; ptr != head;	\
       ptr = temp, temp = ptr->next)

#endif
