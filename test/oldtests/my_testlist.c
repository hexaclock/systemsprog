#include "mylist.h"

int main()
{
  t_node *head;
  t_node *tail;
  t_node *numh;
  t_node *strh;
  t_node *atth;
  t_node *temp;

  /*head = new_node(NULL,NULL,NULL);*/
  /* Creating new nodes  */
  head = new_node("Hello",NULL,NULL);

  tail = new_node("Goodbye",NULL,head);

  if (new_node(NULL,NULL,NULL) != NULL)
    my_str("Problem with new_node(NULL,NULL,NULL) test");
  if (my_strcmp(head->elem,"Hello") != 0)
    my_str("Problem with line 18 test.\n");
  if (my_strcmp(tail->prev->elem,"Hello") != 0)
    my_str("Problem with line 20 test.\n");

  /* Adding nodes to existing list */
  add_node(tail,&head);
  add_node(NULL,&head);
  /*add_node(tail,NULL);*/
  add_node(NULL,NULL);
  /* Creating and adding node */
  add_elem("!",&head);
  add_elem("Newlist",NULL);
  add_elem(NULL,NULL);
  /*add_elem(NULL,&head);*/
  /*  add_node_at(new_node("Insertion",NULL,NULL),&(tail->prev),1);*/
  append(new_node("Append",NULL,NULL),&head);
  append(new_node("Append2",NULL,NULL),&head);
  append(new_node("Append3",NULL,NULL),&head);
  traverse_string(head);
  my_char('\n');
  debug_string(head);

  my_char('\n');

  int x = 0;
  /* Test append and int list */
  numh = new_node(&x,NULL,NULL);
  int y = 1;
  append(new_node(&y,numh,numh),&numh);
  append(NULL,&numh);
  int z = 56;
  t_node *ret = new_node(&z,NULL,NULL);
  append(ret,NULL);
  /*  my_str("segfault?\n"); */
  int a = 42;
  append(new_node(&a,NULL,numh),&numh);
  append(NULL,NULL);
  
  /* should print 0,1,42 */
  debug_int(numh);
  my_char('\n');
  traverse_int(numh);
  my_char('\n');
  remove_node(&head);
  debug_string(head);
  my_char('\n');

  remove_node_at(&head,2);
  debug_string(head);
  my_char('\n');

  remove_last(&head);
  debug_string(head);
  my_char('\n');
  
  remove_last(&head);
  remove_last(&head);
  debug_string(head);
  my_char('\n');

  remove_last(&head);
  remove_node(NULL);
  /*  remove_last(&head);*/
  debug_string(head);
  my_char('\n');



  /* test odd new_node case */
  /*new_node('a',numh,numh);*/
  /* should have 0,1,42 now */
  int b = 2;
  int c = 3;
  int d = 4;
  add_node_at(new_node(&b,NULL,NULL),&numh,1);
  add_node_at(NULL,NULL,55);
  add_node_at(NULL,&numh,60);
  add_node_at(new_node(&c,NULL,NULL),&numh,60);
  add_node_at(new_node(&d,NULL,NULL),NULL,89);
  /* we should have a new list at this point */
  /* should have 0,2,1,42,3 now */
  debug_int(numh);
  empty_list(&numh);
  my_char('\n');
  my_char('\n');
  my_str("Print of empty list:\n");
  debug_int(numh);

  /*Node removal tests*/
  remove_node(NULL);
  
  t_node *blargh = NULL;
  add_node(new_node("This",NULL,NULL),&blargh);
  append(new_node(" is",NULL,NULL),&blargh);
  append(new_node(" a",NULL,NULL),&blargh);
  append(new_node(" list.",NULL,NULL),&blargh);
  remove_node_at(NULL,50);
  
  remove_node_at(&blargh,60);
  my_char('\n');
  debug_string(blargh);
  
  remove_node_at(&blargh,1);
  my_char('\n');
  debug_string(blargh);

  remove_node_at(&blargh,0);
  my_char('\n');  
  debug_string(blargh);

  //free(head);
  //free(tail);
  //free(numh);
  head = NULL;
  tail = NULL;
  numh = NULL;
  /*************************/

  /*More removal tests, counting nodes tests*/
  char A = 'A';
  char B = 'B';
  char C = 'C';
  char D = 'D';
  char E = 'E';
  char X = 'x';
  head = new_node(&A,NULL,NULL);
  add_node_at( new_node(&B,NULL,NULL), &head, 1 );
  add_node_at(new_node(&C,NULL,NULL),&head,2);
  add_node_at(new_node(&D,NULL,NULL),&head,3);
  add_node_at(new_node(&E,NULL,NULL),&head,4);
  
  remove_last(NULL);
  remove_last(&head);
  remove_last(&numh);

  free(numh);
  numh = new_node(&X,NULL,NULL);

  if(count_nodes(NULL) != 0)
    my_str("Problem with count nodes 1.\n");
  if(count_nodes(numh) != 1)
    my_str("Problem with count nodes 2.\n");
  if(count_nodes(head) != 4)
    my_str("Problem with count nodes 3.\n");

  empty_list(NULL);
  empty_list(&head);
  
  atth = new_node(&A,NULL,NULL);
  add_node_at(new_node(&B,NULL,NULL),&atth,1);
  add_node_at(new_node(&C,NULL,NULL),&atth,2);
  add_node_at(new_node(&D,NULL,NULL),&atth,3);
  add_node_at(new_node(&E,NULL,NULL),&atth,4);

  /*************************************************/

  /**************node_at testing*******************/
  /*should return 2nd node w/ elem=C*/
  temp = node_at(atth,2);
  if ( *( (char *)(temp->elem) ) != 'C')
    my_str("Problem with node_at test 1.\n");
  /*test null*/
  temp = node_at(NULL,50);
  /*test out of bounds*/
  temp = node_at(atth,67);
  /************************************************/

  /***************elem_at testing********************/
  my_char( *((char *)(elem_at(atth,0))) );
  if( *((char *)(elem_at(atth,3))) != 'D')
    my_str("Problem with elem_at test 1\n");
  /* bounds test */
  if ( *((char *)(elem_at(atth,4))) != 'E')
    my_str("Problem with elem_at test 2\n");

  /* out of bounds test */
  if ( *((char *)(elem_at(atth,25))) != 'E')
    my_str("Problem with elem_at test 3\n");
  /**************************************************/
  my_char('\n');

  empty_list(&head);
  free(head);
  /*list traversal printing tets*/
  head = new_node(&A,NULL,NULL);
  add_node_at(new_node(&B,NULL,NULL),&head,1);
  add_node_at(new_node(&C,NULL,NULL),&head,2);
  add_node_at(new_node(&D,NULL,NULL),&head,3);
  add_node_at(new_node(&E,NULL,NULL),&head,3);  

  /*should print ABCED*/
  traverse_char(head);
  my_char('\n');

  remove_node_at(&head,0);
  /*should print BCED*/
  debug_char(head);
  my_char('\n');
  
  /******************print tests ***********************/
  print_char(NULL);
  print_string(NULL);
  print_int(NULL);

  /*****************************************************/

  /******************debug tests************************/
  debug_string(NULL);
  debug_int(NULL);
  debug_char(NULL);

  /*****************end tests***************************/
  /*exit test main*/
#if 0
#endif
  return 0;
}
