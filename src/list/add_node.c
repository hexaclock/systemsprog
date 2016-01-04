#include "mylist.h"

/*pre: takes a t_node* representing the node to add, and t_node ** representing a pointer to a pointer that points to the head of the list*/
/*post: adds node to the front of the list, and rewrites the pointer to the header to the new node.*/
void add_node(t_node *n, t_node **ph)
{
  if (n != NULL && n->elem != NULL && ph != NULL && *ph != NULL)
    {
      n->prev = NULL;
      n->next = *ph;
      (*ph)->prev = n;
      *ph = n;
    }
  /* new list case */
  else if (n != NULL && n->elem != NULL && (ph == NULL || *ph == NULL))
    {
      n->prev = NULL;
      n->next = NULL;
      if (ph == NULL)
	ph = &n;
      if (*ph == NULL)
	*ph = n;
    }
}
