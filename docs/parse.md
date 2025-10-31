## 🧩 Nome
**parse**

---

## 📘 Função principal
A função `parse` recebe uma lista de *tokens* previamente divididos (geralmente o resultado de um *split* da linha de comando inserida pelo utilizador) e constrói uma nova matriz que representa a estrutura sintática do comando.  
Durante este processo:
- Verifica erros de sintaxe, como operadores consecutivos (`>>`, `|`, etc.) sem argumentos válidos entre eles.
- Insere separadores de nova linha (`"\n"`) para delimitar blocos lógicos de comandos (como *pipes* ou redirecionamentos).
- Retorna uma nova matriz de *strings* representando a sequência processada e validada de comandos.

---

## 📤 Dados de saída
Retorna um **array de `char **`** contendo:
- Tokens processados e validados.
- Quebras de linha (`"\n"`) nos pontos onde há operadores (`|`, `>`, `<`, `>>`, `<<`), permitindo que etapas posteriores da *mini-shell* identifiquem cada comando individualmente.

Caso o argumento `tokens` seja `NULL`, retorna `NULL`.

---

## ⚠️ Erros / Terminações possíveis
A função pode terminar o programa através de chamadas indiretas de:
- `error_handle(0, "syntax error near unexpected token")` — quando é encontrado um operador inválido ou mal posicionado.
- Funções internas chamadas como `append_matriz`, `len_all`, `equal` ou `print_matriz_vec` podem também provocar terminação caso falhem internamente (ex: falta de memória).

Não utiliza `exit()` diretamente, mas delega o tratamento de erros para `error_handle`.

---

## 🔧 Funções auxiliares utilizadas
- `shear_error()` — valida a sequência de tokens e verifica combinações ilegais.
- `case_split()` — insere delimitadores de nova linha quando encontra operadores.
- `append_matriz()` — adiciona novos elementos à matriz de saída.
- `print_matriz_vec()` — imprime a matriz de entrada e saída para debug.
- `len_all()` e `equal()` — funções utilitárias para medir comprimento e comparar *strings*.

---
