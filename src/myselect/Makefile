NAME     = myselect
CC       = gcc
SRC      = init_terminal.c restore_terminal.c term_get_cap.c init_caps.c my_termprint.c \
	  term_clear.c term_vi.c term_ve.c check_character.c get_win_size.c show_elems.c \
	  refreshin.c refreshout.c moveup.c movedown.c moveleft.c moveright.c doselect.c \
	  getout.c setup_elems.c term_move_to_item.c term_underline.c \
	  term_standout.c term_standend.c term_underend.c myselect.c
OBJ      = $(SRC:.c=.o)
IPATH    = ../../include
CFLAGS  += -I$(IPATH)
LDFLAGS += -L../../lib
LDLIBS  += -lmy -ltermcap
RM       = rm -f

all: libmy $(NAME)

$(NAME): $(OBJ)

libmy:
	cd ../my; make

clean:
	-$(RM) $(OBJ) $(NAME) *~ \#*

fclean: clean
	cd ../my; make fclean

re: fclean all
