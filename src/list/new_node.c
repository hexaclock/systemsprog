#include "mylist.h"

/*pre: takes an void* representing the element, a t_node pointer to the next node, and a t_node pointer to the previous node*/
/*post: returns pointer to newly constructed node (t_node*) from supplied params*/
t_node *new_node(void *e, t_node *n, t_node *p)
{
  t_node *ret;
  /*  if (e == NULL)
    return NULL;
  */
  ret = (t_node*)xmalloc(sizeof(t_node));
  ret->elem = e;
  ret->next = n;
  ret->prev = p;
  return ret;
}
