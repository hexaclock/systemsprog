#include "mylist.h"

/* pre: takes a t_node pointer representing where to start printing from. */
/* prints list of chars in format: (PREVELEM<-ELEM->NEXTELEM) */
/* in case of NULL, prints "NULL" in place of *ELEM value */
void debug_char(t_node *head)
{
  if (head == NULL)
    {
      my_str("The list is empty.\n");
    }
  while (head != NULL)
    {
      print_char(head);
      head = head->next;
    }
}
