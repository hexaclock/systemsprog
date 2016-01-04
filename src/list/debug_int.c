#include "mylist.h"

/* pre: takes a t_node pointer representing where to start printing from. */
/* prints list of ints in format: (PREVELEM<-ELEM->NEXTELEM) */
/* in case of NULL, prints "NULL" in place of *ELEM value */
void debug_int(t_node *head)
{
  if (head == NULL)
    {
      my_str("The list is empty.\n");
    }
  while (head != NULL)
    {
      print_int(head);
      head = head->next;
    }
}
