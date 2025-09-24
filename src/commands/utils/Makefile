# Vars
NAME = utils.a
OBJ = ft_split.o lens.o utils_vec.o
INC = -I.

PRE_COMP = cc -Wall -Wextra -Werror
COMP = ar rcs 

# Dependencia
PRINTF_DIR	= printf/
PRINTF		= $(PRINTF_DIR)ft_printf.a

# Make reglas
MAKE = make --no-print-directory

# Reglas
%.o: %.c
	@$(PRE_COMP) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR)
	@ar x $(PRINTF)
	@$(COMP) $(NAME) $(OBJ) *.o
	@echo "($(NAME))--> Executable $(NAME) created."

clean:
	@$(MAKE) clean -C $(PRINTF_DIR)
	@rm -rf $(OBJ) *.o
	@echo "($(NAME))--> Object files cleaned."

fclean: clean
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@rm -rf $(NAME) *.o
	@echo "($(NAME))--> Object Executable remove."

all: $(NAME)
re: fclean all
.PHONY: all clean fclean re