SERVER   = server
CLIENT   = client
SRC1     = $(SERVER).c
SRC2     = $(CLIENT).c
OBJ1     = $(SRC1:.c=.o)
OBJ2     = $(SRC2:.c=.o)
IPATH    = ../../include
CFLAGS  += -I$(IPATH)
LDFLAGS += -L../../lib
LDLIBS  += -lmy
RM       = rm -f

all: libmy $(SERVER) $(CLIENT)

$(SERVER): $(OBJ1)

$(CLIENT): $(OBJ2)

libmy:
	cd ../my; make

clean:
	-$(RM) *.o *~ \#*
	-$(RM) $(SERVER) $(CLIENT)

fclean: clean
	cd ../my; make fclean

re: fclean all
