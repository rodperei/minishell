## NOME
create\_prompt - cria um prompt similar ao bash

## SINOPSE
**#include "include/prompt.h"** [^1]

**char \*create_prompt(void)**

[^1]: O diretório relativo é descrito a partir do diretório base **minishell**

## DESCRIÇÃO
**create_prompt** cria um prompt no formato `user@hostname:cwd$ `.

***user*** é obtido da variável de ambiente `USER`, e caso a variável não exista, o prompt é criado com `user = ""`.

***hostname*** é obtido a partir do ficheiro `/etc/hostname`, e caso não seja possível abrir ou lê-lo, o erro é impresso no terminal e o prompt é criado com `hostname = ""`.

***cwd*** refere-se ao *current working directory*, e este é obtido a partir da função **getcwd**(3). Caso esta não consiga obter com sucesso o diretório, o erro é impresso no terminal e `cwd = ""`.

## VALOR DE RETORNO
**create_prompt** retorna a string do prompt. O valor é alocado na memória, e o utilizador deve usar **free**(3) para o libertar.
