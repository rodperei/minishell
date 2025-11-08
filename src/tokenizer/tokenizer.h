/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:12:59 by rodperei          #+#    #+#             */
/*   Updated: 2025/10/25 15:49:26 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

//	token_utils.c

# define META 4
# define SQUOTE 1
# define DQUOTE 2

void	compute_quotes_mask(char input, char *flg);
void	is_meta(char c, char *flg);
void	parse_redirect(char **bgn, char *oprt, int *i, char c);
void	read_token(char **end, char *flg);
char	**resize_tokens(char **list, char *new_token);

//	process_input.c

char	*clear_input(char *input);

//	save_utils.c

char	*save_word(char **bgn, char *end, char **tokens);
int		save_operator(char **bgn, char *end, char *oprt);

#endif // !TOKEN_UTILS_H
