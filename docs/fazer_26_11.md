Precisamos que:


1 — Façamos com que:

void	execute_simple_command(char **tokens, int fd_in, int fd_out)

Receba um fd_in e um fd_out.
E que a entrada e saída de cada simple command sejam os file descriptors que lhe passamos.


2 — Depois executamos que:

int	execute_parse(char **parse)

abra os ficheiros descritos e os ligue entre si com pipe, para que:

int	execute_command(char **tokens, int fd_in, int fd_out)
crie os processos filhos e execute:

void	execute_simple_command(char **tokens, int fd_in, int fd_out);


---------------

implementar un itoa pasar de int a chat o STR

funciones internas tengan tokens

