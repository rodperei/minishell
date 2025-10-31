## Explicação simples das funções de redirecionamento

Estas três funções fazem a parte responsável por lidar com as redireções de entrada e saída no *mini-shell*. O objetivo principal é validar ficheiros e preparar o conteúdo quando existe um `<<` (*here-document*).

---

### ✅ `case_redirection`

**O que faz:**  
Detecta redireções `>`, `>>` e `<`. De acordo com o tipo, tenta abrir o ficheiro correspondente.

- `>`  → escreve no ficheiro, sobrescrevendo se já existir  
- `>>` → escreve no final do ficheiro (*append*)  
- `<`  → lê de um ficheiro  

**Para que serve:**  
Apenas verifica se o ficheiro pode ser aberto corretamente.  
Depois de abrir, fecha-o imediatamente (ainda não é a redireção real, só validação).

---

### ✅ `case_read_term`

**O que faz:**  
Trata do `<<`, conhecido como *here-document*.

- Lê do terminal até o utilizador escrever a palavra delimitadora
- Tudo o que o utilizador escreve vai sendo concatenado num *buffer*
- Substitui esse parâmetro do comando pelo conteúdo digitado

**Exemplo:**  
```

cat << END
ola
mundo
END

```

O conteúdo `"ola\nmundo\n"` fica guardado e depois é passado como entrada para o próximo processo.

---

### ✅ `redirection`

**O que faz:**  
Percorre a matriz `parse` e chama as duas funções anteriores para cada token.

Passos:
1. Percorre todos os elementos do comando  
2. Chama `case_redirection` (validação de ficheiros para `> >> <`)  
3. Chama `case_read_term` (gestão do `<<`)  
4. Imprime a matriz final processada para depuração  

Devolve a matriz modificada.

---

### 📌 Resumo

| Função | Responsabilidade |
|--------|------------------|
`case_redirection()` | Validar ficheiros para `>`, `>>`, `<` |
`case_read_term()` | Ler texto para `<<` e armazenar |
`redirection()` | Controlar as duas funções e processar toda a matriz |

---

Isto é apenas um rascunho da lógica real: no Bash é usado *file descriptor*, aqui só verificamos ficheiros e preparamos o conteúdo para testes futuros.
