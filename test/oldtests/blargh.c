#include "my.h"

/*tests functions assigned in assignment 2*/
/*returns 0 if all functions have passed.*/
/*some manual output inspection may be required*/
int main()
{
  char *sp;
  unsigned int maxpos = -1;
  char *dst = "YELLOW SUBMARINE";
  char *dst2 = (char *)xmalloc(17*sizeof(char));
  char *dst3 = (char *)xmalloc(17*sizeof(char));
  char *dst4 = (char *)xmalloc(17*sizeof(char));
  char *xtrabuf = (char *)xmalloc(50*sizeof(char));
  unsigned char status = 0;
  int sc;

  /**************my_strcmp tests***********************/
  if (my_strcmp(dst,dst) != 0)
    {
      my_str("Problem with first my_strcmp test");
      status = 1;
    }
  if (my_strcmp("","") != 0)
    {
      my_str("Problem with second my_strcmp test");
      status = 1;
    }
  if (my_strcmp(NULL,"") >= 0)
    {
      my_str("Problem with third my_strcmp test");
      status = 1;
    }
  if (my_strcmp(NULL,NULL) != 0)
    {
      my_str("Problem with fourth my_strcmp test");
      status = 1;
    }
  if (my_strcmp("abc","abcd") >= 0)
    {
      my_str("Problem with fifth my_strcmp test");
      status = 1;
    }
  if (my_strcmp("hi","bye") <= 0)
    {
      my_str("Problem with sixth my_strcmp test");
      status = 1;
    }

  my_strcpy(dst3,"abc");
  my_strcpy(dst3,"LED ZEPPELIN");
  if (my_strcmp(dst3,"LED ZEPPELIN") != 0)
    {
      my_str("Problem with seventh my_strcmp test (includes my_strcpy test).");
      status = 1;
    }
  /***********end my_strcmp tests***********************/

  /**************my_strncmp tests***********************/

  if (my_strncmp("TESTING","TEST",4) != 0)
    {
      my_str("Problem with first my_strncmp test");
      status = 1;
    }
  if (my_strncmp("TESTING","TEST",20) <= 0)
    {
      my_str("Problem with second my_strncmp test");
      my_int(my_strncmp("TESTING","TEST",20));
      status = 1;
    }
  if (my_strncmp("hi","bye",1) <= 0)
    {
      my_str("Problem with third my_strncmp test");
      status = 1;
    }
  if (my_strncmp("abc","xyz",3) >= 0)
    {
      my_str("Problem with fourth my_strncmp test");
      status = 1;
    }
  if (my_strncmp("abc","",3) <= 0)
    {
      my_str("Problem with fifth my_strncmp test");
      status = 1;
    }
  if (my_strncmp(NULL,"",26) >= 0)
    {
      my_str("Problem with sixth my_strncmp test");
      status = 1;
    }
  if (my_strncmp(NULL,NULL,1) != 0)
    {
      my_str("Problem with seventh my_strncmp test");
      status = 1;
    }
  if (my_strncmp("hi","bye",0) != 0)
    {
      my_str("Problem with eighth my_strncmp test");
      status = 1;
    }
  if (my_strncmp("","",10) != 0)
    {
      my_str("Problem with ninth my_strncmp test");
      status = 1;
    }
  if (my_strncmp("TESTING","TESTING",25) != 0)
    {
      my_str("Problem with tenth my_strncmp test");
      status = 1;
    }

  /***************end my_strncmp tests*********************/

  /****************my_strfind tests************************/

  sp = my_strfind("YELLOW SUBMARINE",'L');
  if (*sp != 'L' && *(sp+1) != 'O')
    {
      my_str("Problem with first my_strfind test");
      status = 1;
    }
  
  sp = my_strfind("YELLOW SUBMARINE",'f');
  if (sp != NULL)
    {
      my_str("Problem with second my_strfind test");
      status = 1;
    }
  
  sp = my_strfind("",'x');
  if (sp != NULL)
    {
      my_str("Problem with third my_strfind test");
      status = 1;
    }
  
  sp = my_strfind(NULL,'A');
  if (sp != NULL)
    {
      my_str("Problem with fourth my_strfind test");
      status = 1;
    }
  /***************end my_strfind tests*********************/

  /****************my_strrfind tests************************/

  sp = my_strrfind("YELLOW SUBMARINE",'L');
  if (*sp != 'L' && *(sp+1) != 'W')
    {
      my_str("Problem with first my_strrfind test");
      status = 1;
    }
  
  sp = my_strrfind("YELLOW SUBMARINE",'f');
  if (sp != NULL)
    {
      my_str("Problem with second my_strrfind test");
      status = 1;
    }
  
  sp = my_strrfind("",'x');
  if (sp != NULL)
    {
      my_str("Problem with third my_strrfind test");
      status = 1;
    }
  
  sp = my_strrfind(NULL,'A');
  if (sp != NULL)
    {
      my_str("Problem with fourth my_strrfind test");
      status = 1;
    }

  /***************end my_strrfind tests*********************/

  /****************my_strdup testing******************/
  /* First test */
  sp = my_strdup(NULL);
  if (sp != NULL)
    {
      my_str("Problem with first my_strdup test");
      status = 1;
    }
  
  /* Second test */
  sp = my_strdup("");
  if (my_strlen(sp) != 0)
    {
      my_str("Problem with second my_strdup test");
      status = 1;
    }

  /* Third test */
  sp = my_strdup("a string");
  if (my_strcmp(sp,"a string") != 0)
    {
      my_str("Problem with third my_strdup test");
      status = 1;
    }

  if (my_strlen(sp) != 8)
    {
      my_str("Problem with fourth my_strdup test");
      status = 1;
    }
  /*****************end my_strdup testing****************/

  /*****************my_strcpy testing*********************/
  sp = my_strcpy(dst2,"PURPLE");
  if (my_strcmp(sp,"PURPLE SUBMARINE") == 0)
    {
      my_str("Problem with first my_strcpy test\n");
      my_str(sp);
      status = 1;
    }
  
  sp = my_strcpy(NULL,"hi");
  sp = my_strcpy(dst2,NULL);

  if (my_strcmp(sp,"PURPLE SUBMARINE") == 0)
    {
      my_str("Problem with second my_strcpy test\n");
      my_str(sp);
      status = 1;
    }

  sp = my_strcpy(dst2,"");

  if (my_strcmp(sp,"PURPLE SUBMARINE") == 0)
    {
      my_str("Problem with third my_strcpy test\n");
      my_str(sp);
      status = 1;
    }

  /******************end my_strcpy testing******************/

  /******************my_strncpy testing*********************/
  
  sp = my_strncpy(dst4,"BLACK", 3);
  if (my_strcmp(dst,"BLAPLE SUBMARINE") != 0)
    {
      my_str("Problem with first my_strncpy test");
      status = 1;
    }

  my_str("my_strncpy test 1 passed.\n");

  sp = my_strncpy(dst4, "YELLOW", maxpos);
  if (my_strcmp(dst4,"YELLOW SUBMARINE") != 0)
    {
      my_str("Problem with second my_strncpy test");
      status = 1;
    }

  my_str("my_strncpy test 2 passed.\n");

  sp = my_strncpy(dst4, "RED", 0);
  if (my_strcmp(sp,"YELLOW SUBMARINE") != 0)
    {
      my_str("Problem with third my_strncpy test");
      status = 1;
    }

  my_str("my_strncpy test 3 passed.\n");

  sp = my_strncpy(NULL, NULL, 5);
  sp = my_strncpy(NULL, dst4, 25);
  sp = my_strncpy(dst4, NULL, 25);
  if (my_strcmp(sp,"YELLOW SUBMARINE") != 0)
    {
      my_str("Problem with fourth my_strncpy test");
      status = 1;
    }

  my_str("my_strncpy test four passed.\n");

  sp = my_strncpy(dst4, "", 5);
  if (my_strcmp(sp,"YELLOW SUBMARINE") != 0)
    {
      my_str("Problem with fifth my_strncpy test");
      status = 1;
    }

  my_str("my_strncpy test five passed.\n");

  /**************end my_strncpy tests******************/

  /****************my_strconcat tests*********************/
  sp = my_strconcat(NULL,"Hello");
  my_str("this part works\n");
  if (my_strcmp(sp,"Hello") != 0)
    {
      my_str("Problem with first my_strconcat test");
      status = 1;
    }

  my_str("first my_strconcat test passed.\n");

  sp = my_strconcat("Hello",NULL);
  if (my_strcmp(sp,"Hello") != 0)
    {
      my_str("Problem with second my_strconcat test");
      status = 1;
    }

  sp = my_strconcat(NULL,NULL);
  if (sp != NULL)
    {
      my_str("Problem with third my_strconcat test");
      status = 1;
    }

  sp = my_strconcat("","");
  if (my_strcmp(sp,"") != 0)
    {
      my_str("Problem with fourth my_strconcat test");
      status = 1;
    }

  char *spx = my_strconcat("Hi","Bye");
  if (my_strcmp(spx,"HiBye") != 0)
    {
      my_str("Problem with fifth my_strconcat test\n");
      my_str(spx);
      status = 1;
    }

  /***************end my_strconcat tests******************/

  /****************my_strnconcat tests*********************/

  sp = my_strnconcat(NULL,"Hello",4);
  if (my_strcmp(sp,"Hell") != 0)
    {
      my_str("Problem with first my_strnconcat test");
      status = 1;
    }

  sp = my_strnconcat("Hello",NULL,4);
  if (my_strcmp(sp,"Hello") != 0)
    {
      my_str("Problem with second my_strnconcat test");
      status = 1;
    }

  sp = my_strnconcat(NULL,NULL,20);
  if (sp != NULL)
    {
      my_str("Problem with third my_strnconcat test");
      status = 1;
    }

  sp = my_strnconcat("","",5);
  if (my_strcmp(sp,"") != 0)
    {
      my_str("Problem with fourth my_strnconcat test");
      status = 1;
    }

  sp = my_strnconcat("Hi","Bye",2);
  if (my_strcmp(sp,"HiBy") != 0)
    {
      my_str("Problem with fifth my_strnconcat test");
      status = 1;
    }
  
  sp = my_strnconcat("Giga","byte",0);
  if (my_strcmp(sp,"Giga") != 0)
    {
      my_str("Problem with sixth my_strnconcat test");
      status = 1;
    }

  sp = my_strnconcat("Test","ing",90);
  if (my_strcmp(sp,"Testing") != 0)
    {
      my_str("Problem with seventh my_strnconcat test");
      status = 1;
    }
  /***************end my_strnconcat tests******************/

  /****************my_strcat tests************************/
  sp = my_strcat(xtrabuf," Compiler");
  if (my_strlen(sp) != 9)
    {
      my_str("Problem with first my_strcat test");
      status = 1;
    }
  
  sp = my_strcat(xtrabuf,NULL);
  if (my_strcmp(sp," Compiler") != 0)
    {
      my_str("Problem with second my_strcat test");
      status = 1;
    }

  sp = my_strcat(xtrabuf," testing");
  if (my_strcmp(sp," Compiler testing") != 0)
    {
      my_str("Problem with third my_strcat test");
      status = 1;
    }

  sp = my_strcat(NULL,NULL);
  if (sp != NULL)
    {
      my_str("Problem with fourth my_strcat test");
      status = 1;
    }
  my_panic("Done with tests!",status);
  /***************end my_strcat tests*********************/

#if 0
  /*Need to run test main twice, and select 1 my_panic case to test*/
  my_panic(NULL,status);
  /*****************************************************************/
#endif
  return status;
}
