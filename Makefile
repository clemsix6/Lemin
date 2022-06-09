##
## EPITECH PROJECT, 2022
## Minishell1
## File description:
## Makefile
##

CFLAGS =	-W -Wextra -Wall -Werror -I include/ -g3

LDFLAGS =	-L./lib/cly\
			-lcly\

SRC =	$(wildcard src/*.c)

OBJ =	$(SRC:.c=.o)

BIN_NAME	=	lem_in

all: make_lib $(BIN_NAME) $(OBJ)

make_lib:
	@ make -C lib/cly

$(BIN_NAME): $(OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34mLem-in \033[0m"
	@ $(CC) -o $(BIN_NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)
	@ echo "\033[1;32m[ SUCCESS ] \033[0m\033[1;34mBinary :\033[1;32m Lem-ib \033[1;34m created sucesfully.\033[0m"

clean:
	@ rm -f $(OBJ)
	@ make clean -C lib/cly

fclean: clean
	@ rm -f $(BIN_NAME)
	@ make fclean -C lib/cly

re: fclean all