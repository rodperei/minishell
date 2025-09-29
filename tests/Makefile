# ======= Config =======

NAME_1 = prompt_test

CFLAGS = -Wall -Wextra -Werror -g

LDLIBS = -lreadline

CC = cc

# ======= Vars =======

obj_dir = build/

# ======= Prompt Vars =======

p_src = ../src/prompt/prompt.c \
		../src/prompt/utils/ft_string.c \
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

build/%.o : %.c | $(obj_dir)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o : ../src/prompt/utils/%.c | $(obj_dir)
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
