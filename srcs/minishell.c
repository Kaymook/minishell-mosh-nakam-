/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:57:54 by mosh              #+#    #+#             */
/*   Updated: 2024/06/08 19:07:24 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void minishell(char **envp)
{
    char		*line;
    t_token 	**tokens;
	
	// make_envlist(envp);
	(void)envp;
    while (1)
    {
        line = readline("minishell$ ");
        if (line == NULL)
            break;
        if (strlen(line) > 0)
            add_history(line);
        tokens = ft_lexer(line);
        print_tokens(tokens);
        if (tokens == NULL)
        {
            free(line);
            continue;
        }
        free(line);
    }
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	minishell(envp);
	return (0);
}
