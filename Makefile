# Colors for output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Configuration
NAME := malloc
C := cc
CFLAGS := -g -Wextra -Wall -Werror -pthread -pedantic

# Directories
SRC_DIR := ./srcs
OBJ_DIR := ./objs

SRCS := $(SRC_DIR)/malloc.c

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Mandatory part
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Created objects directory$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$(CYAN)Compiled: $(notdir $<)$(RESET)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)$(NAME) built successfully!$(RESET)"

# Clean rules
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Clean completed!$(RESET)"

fclean: clean
	@echo "$(RED)Full clean...$(RESET)"
	@rm -rf $(NAME)
	@echo "$(RED)Full clean completed!$(RESET)"

re: fclean all
