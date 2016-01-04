TEST1    = 
TEST2    = 
TEST3    = main
SRC1     = $(TEST1).c
SRC2     = $(TEST2).c
SRC3     = $(TEST3).c
OBJ1     = $(SRC1:.c=.o)
OBJ2     = $(SRC2:.c=.o)
OBJ3     = $(SRC3:.c=.o)
IPATH    = ../../include
CFLAGS  += -I$(IPATH)
LDFLAGS += -L../../lib
LDLIBS  += -lmy
RM       = rm -f

all: $(TEST1) $(TEST2) $(TEST3)
	mv $(TEST3) minishell

$(TEST1): $(OBJ1)

$(TEST2): $(OBJ2)

$(TEST3): $(OBJ3)

clean:
	-$(RM) *.o *~ \#*
	-$(RM) $(TEST1) $(TEST2) $(TEST3) minishell

fclean: clean

re: fclean all
