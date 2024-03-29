#include "linked_list.h"

/**
 * Initialize the list
 * Supply the head ptr address from the actual structure that is to be stored
 */
void ll_create_list(LL_Node * new_head_ptr)
{
  new_head_ptr->next = new_head_ptr;
  new_head_ptr->prev = new_head_ptr;
}

static void __ll_push_between(LL_Node * prev, LL_Node * next, LL_Node * new)
{
  prev->next = new;
  new->prev = prev;

  new->next = next;
  next->prev = new;
}
/*
 * Insert an element at the end of the list
 * Having a circular list makes sense since we don't have to \
 * traverse all the way to to end to insert an element
 */
void ll_push_back(LL_Node * head, LL_Node * new_node)
{
  __ll_push_between(head->prev, head, new_node);
}

void ll_push_front(LL_Node * head, LL_Node * new_node)
{
  __ll_push_between(head, head->next, new_node);
}

static void __ll_re_link(LL_Node * prev, LL_Node * next)
{
  prev->next = next;
  next->prev = prev;
}

static void __ll_nullify(LL_Node * node)
{
  node->next = NULL;
  node->prev = NULL;
}
void ll_delete(LL_Node * node)
{
  __ll_re_link(node->prev, node->next);
  __ll_nullify(node);
}

void ll_replace(LL_Node * old, LL_Node * new)
{
  __ll_re_link(old->prev, new);
  __ll_re_link(new, old->next);

  __ll_nullify(old);
}
