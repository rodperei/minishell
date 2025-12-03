# Documentação da Função `echo`

## -> Nome da função  
	int	ft_echo(char *text, int flag_n)

## -> Parâmetros  
- `char *text`: Texto a ser exibido na saída padrão.  
- `int flag_n`: Flag para el /n.

## -> Função  
Imita o comportamento básico do comando `echo` no shell, exibindo texto no terminal.  
Suporta o argumento `-n` para evitar a quebra de linha no final.  

## -> Retornos  
- Retorna **0** em caso de execução normal.  
- Pode encerrar o programa chamando `error(...)` em caso de argumentos inválidos.  

## -> Fluxo de trabalho e casos especiais  
1. Verifica se existem mais de 1 argumento em `args`.  
   - Se sim, gera erro: `"unknown arguments"`.  
2. Se houver exatamente 1 argumento e não for `"-n"`, gera erro: `"unknown arguments diff -n"`.  
3. Imprime o texto (`text`) na saída padrão.  
4. Caso não existam argumentos, imprime também uma quebra de linha.  

### Casos especiais  
- Se `args` contiver apenas `"-n"`, o texto é exibido **sem quebra de linha**.  
- Qualquer outro argumento além de `"-n"` gera erro.  
