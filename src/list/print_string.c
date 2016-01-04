#include "mylist.h"

/*pre: takes a t_node* (pointer to t_node) that represents the node to be printed.*/
/*post: prints node from string list in the form: (PREVELEM<-ELEM->NEXTELEM)*/
void print_string(t_node *ph)
{
  if (ph != NULL)
    {
      my_char('(');
      
      /*print prev*/
      if (ph->prev != NULL && ph->prev->elem != NULL)
	my_str((char*)ph->prev->elem);
      else
	my_str("N");
     
      my_str("<-");
      
      /*print current*/
      if (ph->elem != NULL)
	my_str((char*)ph->elem);

      my_str("->");

      /*print next*/
      if (ph->next != NULL && ph->next->elem != NULL)
	my_str((char*)ph->next->elem);
      else
	my_str("N");

      my_char(')');
    }
}
