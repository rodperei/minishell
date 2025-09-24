# Vars
NAME		= echo.out
OBJ			= ./echo/echo.o
INC			= -I.

PRE_COMP	= cc -Wall -Wextra -Werror
COMP		= cc -Wall -Wextra -Werror
#COMP		= ar rcs 

# Dependencia
UTILS_PATH	= ./utils/
UTILS		= $(UTILS_PATH)utils.a

# Make reglas
MAKE = make --no-print-directory

# Reglas
%.o: %.c
	@$(PRE_COMP) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C $(UTILS_PATH)
	@$(COMP) $(INC) $(OBJ) $(UTILS) -o $(NAME)
	@chmod +x $(NAME)
	@echo "($(NAME))--> Executable $(NAME) created."

clean:
	@$(MAKE) clean -C $(UTILS_PATH)
	@rm -rf $(OBJ)
	@echo "($(NAME))--> Object files cleaned."

fclean: clean
	@$(MAKE) fclean -C $(UTILS_PATH)
	@rm -rf $(NAME)
	@echo "($(NAME))--> Object Executable remove."

all: $(NAME)
re: fclean all
.PHONY: all clean fclean re