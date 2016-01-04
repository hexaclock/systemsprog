#include "mylist.h"

/*pre: takes a pointer to a pointer that points to the head node, and a desired index*/
/*post: removes the node at 'index' in the list and returns its elem.*/
void *remove_node_at(t_node **ph, unsigned int index)
{
	t_node *delidx;
	void   *delelem;
	if (ph != NULL && *ph != NULL)
	{
		delidx = *ph;
		/* head removal case */
		if (index == 0 || delidx->next == NULL)
			return remove_node(ph);
		
		while(delidx->next != NULL && index>0)
		{
			--index;
			delidx = delidx->next;
		}
		/* tail removal case */
		if (delidx->next == NULL)
		{
			delelem = delidx->elem;
			delidx->prev->next = NULL;
			delidx->prev = NULL;
			free(delidx);
			delidx = NULL;
			return delelem;
		}
		/* somewhere in between head and tail */
		if (delidx->next != NULL)
		{
			delelem = delidx->elem;
			delidx->prev->next = delidx->next;
			delidx->next->prev = delidx->prev;
			delidx->prev = NULL;
			delidx->next = NULL;
			free(delidx);
			delidx = NULL;
			return delelem;
		}
	}
	return NULL;
}
