all:
	cd src/my; make
	cd src/minitalk; make
#	cd src/pipes; make
#	cd src/list; make
#	cd src/minishell; make
	cd src/minitalk; make
	cd test; make

clean:
	cd src/my; make clean
	cd src/minitalk; make clean
#	cd src/pipes; make clean
#	cd src/list; make clean
#	cd src/minishell; make clean
	cd test; make clean

minishell:
	cd src/my; make re
	cd src/minishell; make re

test:
	cd src/my; make re
	cd test; make re

minitalk:
	cd src/my; make
	cd src/minitalk; make

fclean:
	cd src/my; make fclean
	cd src/minitalk; make fclean
#	cd src/pipes; make fclean
#	cd src/list; make fclean
#	cd src/minishell; make fclean
	cd test; make fclean

re: fclean all
