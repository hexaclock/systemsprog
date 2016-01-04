SERVER   = server
CLIENT   = client
SRC1     = $(SERVER).c
SRC2     = $(CLIENT).c
OBJ1     = $(SRC1:.c=.o)
OBJ2     = $(SRC2:.c=.o)
IPATH    = ../../include
CFLAGS  += -I$(IPATH) -pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12
LDFLAGS += -L../../lib
LDLIBS  += -lmy -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo -lpango-1.0 -lfreetype -lfontconfig -lgobject-2.0 -lglib-2.0
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
