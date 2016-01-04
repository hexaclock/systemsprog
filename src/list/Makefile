NAME     = libmylist.a
SRC      = add_elem.c add_node.c add_node_at.c append.c \
	   count_nodes.c debug_char.c debug_int.c debug_string.c \
	   elem_at.c empty_list.c new_node.c node_at.c print_char.c \
	   print_int.c print_string.c remove_last.c remove_node.c \
	   remove_node_at.c traverse_char.c traverse_int.c traverse_string.c
OBJ      = $(SRC:.c=.o);
RM       = rm -f
INCLPATH = ../../include
LIBPATH  = ../../lib
CFLAGS  += -I$(INCLPATH) -g

all: $(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)
clean:
	-$(RM) *~ *.o *.core *.swp \#*

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all

