#include "mylist.h"

/*pre: takes a t_node** representing a pointer to a pointer to the head node.*/
/*post: calls remove_node on each node in the list (effectively makes memory that list took up available for use again).*/
void empty_list(t_node **ph)
{
  if (ph == NULL || *ph == NULL)
    return;
  while (*ph != NULL)
    {
      remove_node(ph);
      /*ph = &((*ph)->next);*/
    }
}
