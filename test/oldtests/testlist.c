#include "mylist.h"

/* regarding the traverse and debug methods. It's up to them which one
they used for testing, though obviously debug_ is better to check for back
pointers. If they only used traverse_ when dealing with main data, take
-5 overall. They don't really need to test print_ methods as long as they 
call the debug_ methods.
Each debug_ and traverse_ method needs to be called at least once with
and empty list and with a non empty one */

int main()
{
  int arr[10] = {4, 65, 32, 1, 68, 23, 83, 12, 6, 82};
  char *str = "Hello!";
  char *str2 = "World!";
  t_node *head = NULL;
  unsigned int i;
  t_node *tmp = NULL;
  int n = 5;
  t_node **test = NULL;
  void *ret = NULL;

  /* new_node test */
  tmp = new_node(str, NULL, NULL);
  print_string(tmp); /* should print (N<-Hello!->N) */
  my_char('\n');
  print_char(tmp); /* should print (N<-H->N) */
  my_char('\n');
  free(tmp);
  tmp = new_node(NULL, NULL, NULL);
  if (tmp != NULL && tmp->elem == NULL)
    my_str("Node created with NULLs Galore\n");
  else
    my_panic("Didn't make node with NULLs\n", 1);
  
  /* add_node test */
  debug_int(head); /* should print The list is empty (or similar) */
  add_node(NULL, &head);
  debug_int(head); /* still empty */
  add_node(tmp, &head); 
  debug_int(head); /* still empty */
  tmp->elem = &n;
  add_node(tmp, NULL);
  debug_int(head); /* still empty */

  for (i = 0; i < 3; i++)
    {
      add_node(new_node(&arr[i], NULL, NULL), &head);
      debug_int(head);
      my_char('\n');
    }
  traverse_int(head); /* traverse_ should be tested at some point */
 /* technically adding 2 should be enough should test for adding to empty
    and adding to list with only one item. Only 2 cases where things could
    go wrong. They don't need to print after each insertion, one at the end
    would suffice.
 */
  empty_list(NULL); /* Shouldn't seg fault */
  empty_list(&head);
  debug_int(head); /* should print The list is empty */
  traverse_int(head); /* traverse_ should be tested at some point */
  debug_string(head); /* should print The list is empty */
  traverse_string(head); /* traverse_ should be tested at some point */
  debug_char(head); /* should print The list is empty */
  traverse_char(head); /* traverse_ should be tested at some point */

  /* add_elem test */
  add_elem(NULL, &head);
  debug_int(head); /* still empty */
  add_elem(&n, NULL);
  debug_int(head); /* still empty */
  for (i = 0; i < 3; i++)
    {
      add_elem(&arr[i], &head);
      debug_int(head);
      my_char('\n');
    }

  /* technically adding 2 should be enough should test for adding to empty
     and adding to list with only one item. Only 2 cases where things could
    go wrong. They don't need to print after each insertion, one at the end
    would suffice.
 */
  empty_list(&head);
  debug_int(head); /* should print The list is empty */

  /* append test */
  debug_int(head); /* should print The list is empty (or similar) */
  append(NULL, &head);
  debug_int(head); /* still empty */
  tmp->elem = NULL;
  append(tmp, &head); 
  debug_int(head); /* still empty */
  tmp->elem = &n;
  append(tmp, NULL);
  debug_int(head); /* still empty */
  for (i = 0; i < 3; i++)
    {
      append(new_node(&arr[i], NULL, NULL), &head);
      debug_int(head);
      my_char('\n');
    }
  /* same as usual, 2 insertions should suffice */
  empty_list(&head);
  debug_int(head);
  /* add_node_at */
  add_node_at(NULL, &head, 1);
  debug_int(head); /* still empty */
  tmp->elem = NULL;
  add_node_at(tmp, &head, 2);
  debug_int(head); /* still empty */
  tmp->elem = &n;
  add_node_at(tmp, NULL, 3);
  debug_int(head); /* still empty */
  /* I'm going overboard with these testing with indexes that are at the front and the back. 
I don't expect them to be as extreme. As long as they test 0 once, large number once, empty list once,
list with only one item once, and list with 2 or more items once, I'll be happy enough */
  for (i = 0; i < 3; i++)
    {
      add_node_at(new_node(&arr[i], NULL, NULL), &head, 0);
      debug_int(head);
      my_char('\n');
    }
  empty_list(&head);
  debug_int(head);
  for (i = 0; i < 3; i++)
    {
      add_node_at(new_node(&arr[i], NULL, NULL), &head, 438);
      debug_int(head);
      my_char('\n');
    }
  empty_list(&head);
  debug_int(head);
  /* putting all the ints in order to test the removes later on */
  for (i = 0; i < 10; i++)
    {
      add_node_at(new_node(&arr[i], NULL, NULL), &head, i);
      debug_int(head);
      my_char('\n');
    }
  add_node_at(tmp, &head, 2);
  debug_int(head);
  my_char('\n');

  /* testing count nodes. Technically all they need to do is call it at some point with an empty list
     and with an non-empty one */
  my_int(count_nodes(head)); /* should print 11 */
  my_char('\n');
  my_int(count_nodes(NULL)); /* should print 0 */
  my_char('\n');
  
  /* testing removes: gonna remove a few items with each method, then test each with NULLs and lists of one item only */
  ret = remove_node(&head);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  ret = remove_last(&head);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  ret = remove_node_at(&head, 0);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  ret = remove_node_at(&head, 243);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  ret = remove_node_at(&head, 3);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  empty_list(&head);
  debug_int(head);

  add_elem(&n, &head);
  debug_int(head);
  my_char('\n');
  ret = remove_node(&head);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  add_elem(&n, &head);
  debug_int(head);
  my_char('\n');
  ret = remove_last(&head);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  add_elem(&n, &head);
  debug_int(head);
  my_char('\n');
  ret = remove_node_at(&head, 0);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  add_elem(&n, &head);
  debug_int(head);
  my_char('\n');
  ret = remove_node_at(&head, 243);
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');

  if (remove_node(&head) == NULL)
    my_str("Passed remove_node from empty\n");
  else
    my_panic("Failed remove_node from empty\n",1);

  if (remove_last(&head) == NULL)
    my_str("Passed remove_last from empty\n");
  else
    my_panic("Failed remove_last from empty\n",1);

  if (remove_node_at(&head, 0) == NULL)
    my_str("Passed remove_node_at 0 from empty\n");
  else
    my_panic("Failed remove_node_at 0 from empty\n",1);

  if (remove_node_at(&head, 3) == NULL)
    my_str("Passed remove_node_at 3 from empty\n");
  else
    my_panic("Failed remove_node_at 3 from empty\n",1);

  if (remove_node(NULL) == NULL)
    my_str("Passed remove_node from NULL\n");
  else
    my_panic("Failed remove_node from NULL\n",1);

  if (remove_last(NULL) == NULL)
    my_str("Passed remove_last from NULL\n");
  else
    my_panic("Failed remove_last from NULL\n",1);

  if (remove_node_at(NULL, 0) == NULL)
    my_str("Passed remove_node_at 0 from NULL\n");
  else
    my_panic("Failed remove_node_at 0 from NULL\n",1);

  if (remove_node_at(NULL, 3) == NULL)
    my_str("Passed remove_node_at 3 from NULL\n");
  else
    my_panic("Failed remove_node_at 3 from NULL\n",1);

  /* testing node_at and elem_at with NULLs */
  if (node_at(NULL, 0) == NULL)
    my_str("Passed node_at 0 from empty\n");
  else
    my_panic("Failed node_at 0 from empty\n", 1);
  if (node_at(NULL, 2) == NULL)
    my_str("Passed node_at 2 from empty\n");
  else
    my_panic("Failed node_at 2 from empty\n", 1);
  if (elem_at(NULL, 0) == NULL)
    my_str("Passed elem_at 0 from empty\n");
  else
    my_panic("Failed elem_at 0 from empty\n", 1);
  if (elem_at(NULL, 2) == NULL)
    my_str("Passed elem_at 2 from empty\n");
  else
    my_panic("Failed elem_at 2 from empty\n", 1);

  /* adding strings to list to test these 2 methods and the last debug ones */
  add_elem(str2, &head);
  my_char('\n');
  add_elem(str, &head);
  my_char('\n');
  debug_string(head);
  my_char('\n');
  traverse_string(head);
  my_char('\n');
  debug_char(head);
  my_char('\n');
  traverse_char(head);
  my_char('\n');
  my_str((char*)elem_at(head, 0)); /* Hello */
  my_char('\n');
  my_str((char*)elem_at(head, 43)); /* World */
  my_char('\n');
  tmp = node_at(head, 0);
  print_string(tmp);
  my_char('\n');
  tmp = node_at(head, 43);
  print_string(tmp);
  my_char('\n');
  empty_list(&head);
  debug_string(head);
  /* this last one is mainly to clear memory */
  return 0;
}


