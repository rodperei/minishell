# ======= Config =======

NAME_1 = minishell

CFLAGS = -Wall -Wextra -Werror -g

LDLIBS = -lreadline

CC = cc

INC			= -I ../include/.

# ======= Vars =======

obj_dir = build/

src = ../src/commands/cd.c \
		../src/commands/echo.c \
		../src/commands/env.c \
		../src/commands/exit.c \
		../src/commands/export.c \
		../src/commands/pwd.c \
		../src/commands/unset.c \
		../src/commands/traductor.c \
		\
		../src/prompt/prompt.c \
		\
		../src/utils/error.c \
		../src/utils/ft_itoa.c \
		../src/utils/ft_memmove.c \
		../src/utils/ft_split.c \
		../src/utils/ft_strings_1.c \
		../src/utils/ft_strings_2.c \
		../src/utils/ft_strings_3.c \
		../src/utils/lens.c \
		../src/utils/utils_matriz.c \
		../src/utils/utils_vec.c \
		../src/utils/ft_path.c \
		../src/utils/ft_split_custom.c \
		\
		../src/tokenizer/process_input.c \
		../src/tokenizer/save_utils.c \
		../src/tokenizer/token_utils.c \
		../src/tokenizer/tokenizer.c \
		\
		../src/parse/parse.c \
		\
		../src/redirections/redirections.c \
		../src/redirections/redir_utils.c \
		\
		../src/signal/signal.c \
		\
		../src/expansions/expansions.c \
		../src/expansions/hdoc_utils.c \
		../src/expansions/expansion_utils.c \
		\
		../src/execute/simple_command.c \
		\
		../src/pipe/pipe.c \
		\
		./redir_test.c

tmp = $(notdir $(src))
obj = $(tmp:.c=.o)

# ======= Rules =======

all: $(NAME_1)

# ======= Prompt Rules =======

$(NAME_1): $(addprefix $(obj_dir), $(obj))
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

build/%.o : ../src/*/%.c | $(obj_dir)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

build/%.o : %.c | $(obj_dir)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


# ==============================

$(obj_dir):
	mkdir -p $@

clean:
	rm -rf $(obj_dir)

fclean: clean
	rm -f $(NAME_1)

re: fclean all

.PHONY: all prompt clean fclean re
