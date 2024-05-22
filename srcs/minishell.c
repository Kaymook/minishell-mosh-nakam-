/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:57:54 by mosh              #+#    #+#             */
/*   Updated: 2024/05/22 19:02:26 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_envlist(t_envlist *new, char *env)
{
	char	*var;
	char	*value;
	char	*where_equal;
	size_t	key_len;

	where_equal = ft_strchr(env, '=');
	key_len = where_equal - env;
	var = ft_substr(env, 0, key_len);
	value = ft_substr(env, key_len + 1, ft_strlen(new) - key_len - 1);
	new->env_var = var;
	new->value = value;
}

t_envlist *make_new_envlist(t_envlist *head, char *env)
{
	t_envlist *new;
	
	new = (t_envlist*)malloc(sizeof (*new));
	set_envlist(new, env);
	head->next = new;
	return (new);
	
}

t_envlist *make_envlist(char **envp)
{
	t_envlist *head;
	t_envlist list;
	int i;

	head = &list;
	i = 0;
	if (envp[i] == NULL)
		return (NULL);
	while (envp[i])
	{
		head = make_new_envlist(head, envp[i++]);
	}
	return (list.next);
}

void minishell(char **envp)
{
	char 		*line;
	t_envlist	*list;

	list = make_envlist(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			break;
		add_history(line);
		// if (ft_strcmp(line, "exit") == 0)
		// 	break;
		// if (ft_strcmp(line, "cd") == 0)
		// 	chdir(line);
	}
}

int	main(int argc, char **argv, char **envp)
{

	(void)argc;
	(void)argv;
	minishell(envp);
	return (0);
}
