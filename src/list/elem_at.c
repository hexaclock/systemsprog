#include "mylist.h"

/* pre: takes a t_node pointer representing index 0, and a desired index. */
/* post: returns the elem (as a void*) of the node at index. 
   if the index is greater than the amount of nodes in the list, returns the elem of the last one.
*/
void *elem_at(t_node *head, unsigned int index)
{
  unsigned int j;
  
  if (head==NULL)
    return NULL;

  for(j=0; j<index; ++j)
    {
      if (head->next == NULL)
	break;
      head = head->next;
    }
  if (head->elem != NULL)
    return head->elem;
  else
    return NULL;
}
