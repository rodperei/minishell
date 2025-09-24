# Vars
NAME = ft_printf.a
OBJ = main.o utils.o print_hexs.o print_nums.o
INC = -I.

PRE_COMP = cc -Wall -Wextra -Werror
COMP = ar rcs 

# Reglas
%.o: %.c
	@$(PRE_COMP) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@$(COMP) $(NAME) $(OBJ)
	@echo "($(NAME))--> Executable $(NAME) created."

clean:
	@rm -rf $(OBJ)
	@echo "($(NAME))--> Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "($(NAME))--> Object Executable remove."

all: $(NAME)
re: fclean all
.PHONY: all clean fclean re