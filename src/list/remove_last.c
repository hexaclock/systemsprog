#include "mylist.h"

/*pre: takes a pointer to a pointer that points to the head node*/
/*post: removes the last node in the list and returns its elem.*/
void *remove_last(t_node **ph)
{
	t_node *delidx;
	void  *delelem;
	if (ph != NULL && *ph != NULL)
	{
		delidx = *ph;
		/* 1 node list */
		if (delidx->next == NULL)
			return remove_node(ph);

		while (delidx->next != NULL)
			delidx = delidx->next;

		/* delidx is now at the tail */
		delidx->prev->next = NULL;
		delidx->prev = NULL;
		delelem = delidx->elem;
		free(delidx);
		delidx = NULL;
		return delelem;
	}
	return NULL;
}
