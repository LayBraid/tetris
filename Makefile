##
## EPITECH PROJECT, 2021
## MY_LS
## File description:
## No file there , just an epitech header example
##

SRC = $(wildcard src/*.c) \
	  $(wildcard src/utils/*.c) \
	  $(wildcard src/controls/*.c) \

OBJ = $(SRC:.c=.o)

NAME = tetris
SRC_LIB = -Llib -lmy
CFLAGS += -Wextra -Iinclude -g3

$(NAME): $(OBJ)
	cd lib/my && make
	gcc $(OBJ) $(SRC_LIB) -o./$(NAME) -g3 -lncurses

all: $(NAME)

fclean:
	cd lib/my && make fclean
	make clean
	rm -f $(NAME)
	rm -f u

clean:
	rm -f src/*.o
	rm -f src/controls/*.o
	rm -f src/utils/*.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.c.gcov

re:
	make fclean
	make
