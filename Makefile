FILE = get_next_line.c
OBJ = test_gnl
CFLAGS = -Wall -Werror -Wextra -g -I libft/includes -o

all : libft do

libft: 
	make -C libft/ re && make -C libft/ fclean

do:
	gcc  $(CFLAGS) get_next_line.o -c $(FILE)
	gcc  $(CFLAGS) main.o -c test.c
	gcc -o $(OBJ) -g main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	rm -f *.o

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
