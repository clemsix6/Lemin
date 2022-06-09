##
## EPITECH PROJECT, 2022
## tetris
## File description:
## Makefile
##

SRC = $(wildcard cly_string/*.c cly_linked_list/*.c cly_io/*.c cly_lib/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Werror -Wextra -I../../include

TARGET = libcly.a

all: $(TARGET)
	@echo "\033[1;36m[ LIB COMPILED ] \033[0m"

$(TARGET): $(OBJ)
	@ar rc $(TARGET) $(OBJ)

clean:
	@ rm -f $(OBJ)
	@ echo "\033[3;31mRemoving CLY LIB\033[0m"

fclean: clean
	@ rm -f $(TARGET)

re : fclean all

%.o:	%.c
		@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS)