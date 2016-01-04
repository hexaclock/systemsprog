#include "mylist.h"

/*pre: takes a t_node* as the node to add, a pointer to a pointer that points to the head node, and an u_int i that represents the index to add the node at*/
/*post: inserts the node into the list at the index i (rewrites adjacent pointers as necessary to preserve doubly-linked list data structure)*/
void add_node_at(t_node *n, t_node **ph, unsigned int i)
{
  t_node *head;
  unsigned int j;
  if (n != NULL && n->elem != NULL && (ph == NULL || *ph == NULL))
    {
      add_node(n,ph);
      return;
    }
  if (n != NULL && n->elem != NULL && ph != NULL && *ph != NULL)
    {
      head = *ph;
      for(j=0; j<i; ++j)
	{
	  if ((*ph)->next == NULL)
	    break;
	  *ph = (*ph)->next;
	}
      /* add to front of list */
      if (i==0)
	{
	  add_node(n,ph);
	}
      /* add to index 1 when there is only 1 node in the list and the requested index is greater than 0*/
      /* use append logic */
      else if (j==0 && i>0)
	{
	  (*ph)->next = n;
	  n->prev = *ph;
	  n->next = NULL;
	  *ph = head;
	}
      /*reached end of list, just use append logic*/
      else if ( (*ph)->next == NULL && j != i )
	{
	  (*ph)->next = n;
	  n->prev = *ph;
	  n->next = NULL;
	  *ph = head;
	}
      /* a "regular" case */
      else
	{
	  n->prev = (*ph)->prev;
	  n->next = *ph;
	  (*ph)->prev->next = n;
	  (*ph)->prev = n;
	  *ph = head;
	  (*ph)->prev = NULL;
	}
      
    }
}
