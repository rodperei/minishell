## NOME
tokenize - divide a string recebida em [tokens](https://www.gnu.org/software/bash/manual/bash.html#Definitions)
## SINOPSE
**#include "include/helper_functions.h"** [^1]

**char	\*\*tokenize(char \*input)**

[^1]: O diretório relativo é descrito a partir do diretório base **minishell**

## DESCRIÇÃO
**tokenize** recebe uma string guardada na heap, e separa-a em tokens, retornando um vetor de strings.
Caso a operação não tenha sucesso, ou a string recebida tenha aspas abertas, a função imprime o erro e termina a execussão através de **exit()**.
## VALOR DE RETORNO
Vetor de tokens. O vetor, tal como cada um dos seus elementos, está guardado na heap, necessitando cada um de ser liberto pela função **free()**.
