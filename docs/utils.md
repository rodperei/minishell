# Documentação das Funções de Utils

##  Nome da função 
	int		cont_words(char *str, char C)

## Parâmetros  
- `char *str`: String a ser analisada.  
- `char C`: Caractere delimitador.  

## Função  
Conta quantas palavras existem em uma string, separadas pelo caractere `C`.  

## Retornos  
- Número de palavras encontradas.  

## Fluxo de trabalho e casos especiais  
1. Percorre a string pulando os caracteres iguais a `C`.  
2. Conta cada sequência de caracteres diferente de `C`.  
3. Continua até o final da string.  
- **Caso especial**: se `str` for nula, retorna `0`.  

---
##  Nome da função 
	int		cont_letter(char *str, char C)

## Parâmetros  
- `char *str`: String a ser analisada.  
- `char C`: Caractere delimitador.  

## Função  
Conta o tamanho de uma palavra até encontrar o delimitador `C` ou o fim da string.  

## Retornos  
- Quantidade de caracteres antes do próximo delimitador.  

## Fluxo de trabalho e casos especiais  
1. Inicia um contador em zero.  
2. Incrementa até achar `C` ou o fim.  
3. Retorna a contagem.  
- **Caso especial**: se `str` for nula, retorna `0`.  

---
##  Nome da função 
	char	**ft_split(char *str, char C)

##  Parâmetros  
- `char *str`: String a ser dividida.  
- `char C`: Caractere delimitador.  

##  Função  
Divide uma string em várias substrings, usando o caractere `C` como separador.  

##  Retornos  
- Um vetor (`char**`) contendo todas as substrings resultantes.  
- O vetor é finalizado com `NULL`.  

##  Fluxo de trabalho e casos especiais  
1. Conta a quantidade de palavras usando `cont_words`.  
2. Para cada palavra, calcula o tamanho com `cont_letter`.  
3. Copia cada palavra para um espaço novo de memória.  
4. Retorna o vetor de strings.  
- **Caso especial**: retorna `NULL` se não houver memória suficiente ou se `str` for nula.  

---
##  Nome da função 
	int		len(char *str)

##  Parâmetros  
- `char *str`: String a ser medida.  

##  Função  
Calcula o tamanho de uma string (quantidade de caracteres até `\0`).  

##  Retornos  
- Número inteiro com o tamanho da string.  

##  Fluxo de trabalho e casos especiais  
1. Percorre a string caracter por caracter.  
2. Para quando encontra `\0`.  
- **Caso especial**: se `str` for nula, retorna `0`.  

---
##  Nome da função 
	int		len_all(char **str)

##  Parâmetros  
- `char **str`: Vetor de strings (array de `char*`).  

##  Função  
Conta quantas strings válidas existem dentro de um vetor de strings.  

##  Retornos  
- Quantidade de strings encontradas.  

##  Fluxo de trabalho e casos especiais  
1. Percorre o vetor até encontrar `NULL` ou uma string vazia.  
2. Retorna o total.  
- **Caso especial**: se `str` for nulo, retorna `0`.  

---
##  Nome da função 
	int		equal(char *str, char *str1)

##  Parâmetros  
- `char *str`: Primeira string.  
- `char *str1`: Segunda string.  

##  Função  
Verifica se duas strings são iguais.  

##  Retornos  
- `1` se forem iguais.  
- `0` caso contrário.  

##  Fluxo de trabalho e casos especiais  
1. Compara caractere por caractere.  
2. Retorna falso ao encontrar diferença.  
- **Caso especial**: se ambas forem `NULL`, retorna verdadeiro.  

---
##  Nome da função 
	char	*copy_vec(char *str)

##  Parâmetros  
- `char *str`: String de entrada.  

##  Função  
Cria uma cópia simples de uma string, alocando nova memória.  

##  Retornos  
- Ponteiro para a nova string copiada.  

##  Fluxo de trabalho e casos especiais  
1. Calcula o tamanho da string.  
2. Aloca memória para cópia.  
3. Copia todos os caracteres até `\0`.  
- **Caso especial**: pode retornar `NULL` se `malloc` falhar.  

---

##  Nome da função  
	char	*z_maloc(int size)

##  Parâmetros  
- `int size`: Tamanho do vetor a ser alocado.  

##  Função  
Aloca um vetor de `char` com inicialização em zero (`\0`).  

##  Retornos  
- Ponteiro para o vetor alocado.  

##  Fluxo de trabalho e casos especiais  
1. Aloca memória do tamanho especificado + 1.  
2. Inicializa todos os índices com `\0`.  
- **Caso especial**: se `malloc` falhar, retorna `NULL`.  

---

##  Nome da função  
	char	*append(char *vec, int size_new, char *buff)

##  Parâmetros  
- `char *vec`: String original.  
- `int size_new`: Novo tamanho desejado.  
- `char *buff`: Buffer adicional a ser concatenado.  

##  Função  
Expande uma string já existente (`vec`) para um novo tamanho (`size_new`) e concatena o conteúdo de `buff`.  

##  Retornos  
- Ponteiro para a nova string expandida.  

##  Fluxo de trabalho e casos especiais  
1. Aloca espaço de memória suficiente para `vec + buff`.  
2. Copia o conteúdo original de `vec`.  
3. Copia os caracteres de `buff` após `vec`.  
4. Retorna a nova string.  
- **Caso especial**: retorna `NULL` se `malloc` falhar.  

---

##  Nome da função  
	void	free_all(char **map)

##  Parâmetros  
- `char **str`: Vetor de strings a ser liberado.  

##  Função  
Libera a memória de todas as strings dentro de um vetor, além do próprio vetor.  

##  Retornos  
- Não retorna valor (função `void`).  

##  Fluxo de trabalho e casos especiais  
1. Percorre o vetor de strings.  
2. Libera cada string com `free()`.  
3. Libera o vetor principal.  
- **Caso especial**: se `str` for nulo, não faz nada.  

## -> Nome da função  
	char	**read_file(int fd, char c);

## -> Parâmetros  
- `int fd`: File descriptor do arquivo a ser lido.  
- `char c`: Caractere delimitador usado para dividir o conteúdo.  

## -> Função  
Lê o conteúdo de um arquivo a partir de um file descriptor (`fd`), armazena em uma string dinâmica e depois divide esse conteúdo em várias substrings com base no delimitador `c`.  

## -> Retornos  
- Um vetor de strings (`char**`) contendo as partes do arquivo separadas pelo delimitador.  
- Retorna `NULL` em caso de falha na alocação de memória.  

## -> Fluxo de trabalho e casos especiais  
1. Aloca um buffer (`buf`) inicializado com zeros através de `z_maloc(SIZE_BUF)`.  
2. Inicializa `text` chamando `append` com `NULL`.  
3. Lê o arquivo em blocos de tamanho `SIZE_BUF` usando `read()`.  
4. A cada leitura (`bt_read`), concatena o conteúdo no `text` com `append`.  
5. Continua até `read()` retornar 0 (fim do arquivo).  
6. Fecha o arquivo com `close(fd)`.  
7. Libera o buffer temporário (`buf`).  
8. Divide `text` em substrings usando `ft_split(text, c)`.  
9. Libera `text` e retorna `text_split`.  

### Casos especiais  
- Se o arquivo estiver vazio, `ft_split` retornará apenas um vetor vazio (`NULL` no primeiro índice).  
- Se houver erro de alocação em `z_maloc` ou `append`, a função pode falhar retornando `NULL`.  
- O file descriptor (`fd`) é fechado dentro da função, o que significa que não poderá ser reutilizado fora dela.  

---

##  Nome da função  
	void	error_handle(int err, char	*str)
##  Parâmetros  
- `int err`: Código de erro a imprimir por **perror()**.
- `char *str`: String personalizada a imprimir.
##  Função  
Imprime erro através de `perror`, `strerror` ou `printf`, e sai de execução através de `exit`.
##  Fluxo de trabalho e casos especiais  
1. Se **err** é diferente de zero, imprime erro através de `strerror`;
2. Se **err** é zero, e **str** é diferente de zero, imprime erro através de `printf`;
3. Senão, imprime erro através de `perror`.
