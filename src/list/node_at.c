#include "mylist.h"

/*pre: takes a t_node* representing index 0, and a desired index.*/
/*post: returns pointer to the node (t_node*) at the desired index. if index is greater than the amount of nodes, returns pointer to last node*/
t_node *node_at(t_node *head, unsigned int index)
{
  unsigned int j;

  if (head == NULL)
    return NULL;

  for(j=0; j<index; ++j)
    {
      if (head->next == NULL)
	break;
      head = head->next;
    }

  return head;
}
