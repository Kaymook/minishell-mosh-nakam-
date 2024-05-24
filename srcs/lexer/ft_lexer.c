/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:25:51 by shonakam          #+#    #+#             */
/*   Updated: 2024/05/24 19:40:24 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(TokenType type, const char *line, size_t pos, size_t size)
{
	 t_token	*t;

	t = (t_token *)malloc(sizeof(t_token));
	if (!t)
		return (NULL);
	t->type = type;
	t->word	= ft_substr(line, pos, size);
	return (t);
}

static TokenType identify_metachar(const char *input, size_t pos)
{
	if (ft_strncmp(&input[pos], ">>", 2) == 0)
		return METACHAR_APPEND_REDIRECT;
	if (ft_strncmp(&input[pos], "<<", 2) == 0)
		return METACHAR_HEREDOC;
	if (ft_strncmp(&input[pos], "|", 1) == 0)
		return METACHAR_PIPE;
	if (ft_strncmp(&input[pos], "<",1) == 0)
		return METACHAR_INPUT_REDIRECT;
	if (ft_strncmp(&input[pos], ">", 1) == 0)
		return METACHAR_OUTPUT_REDIRECT;
	if (ft_strncmp(&input[pos], "'", 1) == 0)
		return METACHAR_SINGLE_QUOTE;
	if (ft_strncmp(&input[pos], "\"", 1) == 0)
		return METACHAR_DOUBLE_QUOTE;
	if (ft_strncmp(&input[pos], "$?", 2) == 0)
		return METACHAR_EXIT_STATUS;
	if (ft_strncmp(&input[pos], "$", 1) == 0)
		return METACHAR_DOLLAR;
	return METACHAR_NONE;
}

size_t	get_token_size(const char *line, size_t posision, int flag)
{
	size_t	end;

	end = posision;
	while (flag == 0 && line[end] && !ft_isspace(line[end]))
		end++;
	while (flag == 1 && line[end] && line[end] != '\'')
		end++;
	while (flag == 2 && line[end] && line[end] != '"')
		end++;
	return (end - posision);
}

void	extract_token(const char *line, t_token **toks, size_t pos, size_t c)
{	
	TokenType	type;
	size_t		token_size;

	while (line[pos] && ft_isspace(line[pos]))
		pos++;
	if (line[pos] == '\0')
	{
		toks[c] = NULL;
		return ;
	}
	type = identify_metachar(line, pos);
	if (type == METACHAR_SINGLE_QUOTE)
		token_size = (2 + get_token_size(line, (pos + 1), 1));
	else if (type == METACHAR_DOUBLE_QUOTE)
		token_size = (2 + get_token_size(line, (pos + 1), 2));
	else
		token_size = get_token_size(line, pos, 0);
	toks[c] = create_token(type, line, pos, token_size);
	pos += token_size;
	extract_token(line, toks, pos, ++c);
}

t_token	**ft_lexer(char *line)
{
	t_token	**tokens;
	
	tokens = (t_token **)malloc(ARGUMENT_SIZE * sizeof(t_token *));
	if (!tokens)
		return (NULL);
	extract_token(line, tokens, 0, 0);
	return (tokens);
}
