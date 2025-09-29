# Vars
NAME = utils.a
OBJ = ft_split.o lens.o utils_vec.o utils_matriz.o ft_string.o
INC = -I.

PRE_COMP = cc -Wall -Wextra -Werror
COMP = ar rcs 

# Make reglas
MAKE = make --no-print-directory

# Reglas
%.o: %.c
	@$(PRE_COMP) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@$(COMP) $(NAME) $(OBJ) *.o
	@echo "($(NAME))--> Executable $(NAME) created."

clean:
	@rm -rf $(OBJ) *.o
	@echo "($(NAME))--> Object files cleaned."

fclean: clean
	@rm -rf $(NAME) *.o
	@echo "($(NAME))--> Object Executable remove."

all: $(NAME)
re: fclean all
.PHONY: all clean fclean re