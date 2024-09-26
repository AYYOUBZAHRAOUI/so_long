#this is a makefile for the get_next_line project

# Name of the executable
NAME = get_next_line.a

# Compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror

# Source files
SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

# Object files
OBJ = $(SRC:.c=.o)

# Header files
HEADER = get_next_line_bonus.h

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "get_next_line.a created"

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re