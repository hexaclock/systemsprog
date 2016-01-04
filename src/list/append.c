#include "mylist.h"

/*pre: takes a t_node* to append, and a pointer to a pointer that points to the head node of a list*/
/*post: inserts the node at the end of list. updates adjacent pointers as necessary*/
void append(t_node *n, t_node **ph)
{
  t_node *head;
   /* no head */
  if (n != NULL && n->elem != NULL && (ph == NULL || *ph == NULL))
    {
      add_node(n,ph);
    }
  else if (n != NULL && n->elem != NULL && ph != NULL && *ph != NULL)
    {
      head = *ph;
      /* find last/tail node */
      while ((*ph)->next != NULL)
	*ph = (*ph)->next;
      (*ph)->next = n;
      n->prev = *ph;
      n->next = NULL;
      /*reset head ptr to node 0*/
      *ph = head;
    }
}
