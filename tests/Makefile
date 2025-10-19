# ======= Config =======

NAME_1 = prompt_test

CFLAGS = -Wall -Wextra -Werror -g

LDLIBS = -lreadline

CC = cc

# ======= Vars =======

obj_dir = build/

# ======= Prompt Vars =======

p_src = ../src/prompt/prompt.c \
		../src/utils/ft_strings_1.c \
		../src/utils/lens.c \
		../src/utils/ft_split.c \
		../src/utils/utils_matriz.c \
		../src/utils/utils_vec.c \
		../src/commands/env/env.c \
		prompt_test.c

tmp = $(notdir $(p_src))
p_obj = $(tmp:.c=.o)

# ======= Rules =======

all: $(NAME_1)

# ======= Prompt Rules =======

$(NAME_1): $(addprefix $(obj_dir), $(p_obj))
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

build/%.o : ../src/prompt/%.c | $(obj_dir)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o : ../src/commands/env/%.c | $(obj_dir)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o : %.c | $(obj_dir)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o : ../src/utils/%.c | $(obj_dir)
	$(CC) $(CFLAGS) -c $< -o $@

# ==============================

$(obj_dir):
	mkdir -p $@

clean:
	rm -rf $(obj_dir)

fclean: clean
	rm -f $(NAME_1)

re: fclean all

.PHONY: all prompt clean fclean re
