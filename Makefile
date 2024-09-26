# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

# Directories
SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
GETNEXTLINE_DIR = get_next_line
OBJ_DIR = obj

# Source files # you need to edit this line after adding new files
SRC_FILES =	$(wildcard $(SRC_DIR)/*.c)
SRC_FILES += $(wildcard $(SRC_DIR)/parsing/*.c)
SRC_FILES += $(wildcard $(SRC_DIR)/rendring/*.c)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
# patsubst : https://www.gnu.org/software/make/manual/html_node/Text-Functions.html

# Executable name
NAME = so_long

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Get_next_line
GETNEXTLINE = $(GETNEXTLINE_DIR)/get_next_line.a

MLX = libmlx42.a -ldl -lglfw -pthread -lm

# Targets
all: $(LIBFT) $(GETNEXTLINE) $(NAME)

# Rule o create libft.a
$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "Libft has been created."

# Rule to create get_next_line.a
$(GETNEXTLINE):
	@make -C $(GETNEXTLINE_DIR)
	@echo "Get_next_line has been created."

# Rule to create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/rendring
	@$(CC) $(CFLAGS)  -I $(INC_DIR) -c $< -o $@
# -I $(LIBFT_DIR) : specify the directory where the header files are located

# Rule to create executable
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INC_DIR)  $(OBJ_FILES) $(LIBFT) $(GETNEXTLINE) $(MLX) -o $(NAME)
# -I $(LIBFT_DIR) : specify the directory where the header files are located

# Rule to clean object files
clean:
# @rm *.o
	@rm -rf $(OBJ_DIR)
	@make -C libft clean
	@make -C get_next_line clean
	@echo "Object files have been removed."

# Rule to clean object files and executable
fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@make -C get_next_line fclean
	@echo "Executable and libraries have been removed."

# Rule to recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re