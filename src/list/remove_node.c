#include "mylist.h"

/*pre: takes a pointer to a pointer that points to the head node*/
/*post: removes the first node in the list and returns its elem.*/
void *remove_node(t_node **ph)
{
	t_node *nodeb;
	void   *delelem;
	if (ph != NULL && *ph != NULL)
	{
		/*1 node list case*/
		if ((*ph)->next == NULL)
		{
			delelem = (*ph)->elem;
			free(*ph);
			*ph = NULL;
			return delelem;
		}
		/* 2+ node list */
		else
		{
			nodeb = (*ph)->next;
			(*ph)->next->prev = NULL;
			(*ph)->next = NULL;
			(*ph)->prev = NULL;
			delelem = (*ph)->elem;
			free(*ph);
			*ph = nodeb;
			return delelem;
		}
	}
	return NULL;
}
