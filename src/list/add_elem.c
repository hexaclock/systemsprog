#include "mylist.h"

/*pre: takes a void* representing an elem, and a pointer to a pointer that points to the head of an existing list*/
/*post: constructs a new node with void *e as the elem, and adds it the front of the list*/
void add_elem(void *e, t_node **ph)
{
  if (e != NULL)
    {
      add_node( new_node(e,NULL,NULL) , ph );
    }
}
