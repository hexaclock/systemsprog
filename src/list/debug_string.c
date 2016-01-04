#include "mylist.h"

/* pre: takes a t_node pointer representing where to start printing from. */
/* prints list of strings in format: (PREVELEM<-ELEM->NEXTELEM) */
/* in case of NULL, prints "NULL" in place of *ELEM value */
void debug_string(t_node *head)
{
  if (head == NULL)
    {
      my_str("The list is empty.\n");
    }
  while (head != NULL)
    {
      print_string(head);
      head = head->next;
    }
}
