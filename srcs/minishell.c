/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:57:54 by mosh              #+#    #+#             */
/*   Updated: 2024/05/24 19:30:50 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	set_envlist(t_envlist *new, char *env)
// {
// 	char	*var;
// 	char	*value;
// 	char	*where_equal;
// 	size_t	key_len;

// 	where_equal = ft_strchr(env, '=');
// 	key_len = where_equal - env;
// 	var = ft_substr(env, 0, key_len);
// 	value = ft_substr(env, key_len + 1, ft_strlen(new) - key_len - 1);
// 	new->env_var = var;
// 	new->value = value;
// }

// t_envlist *make_new_envlist(t_envlist *head, char *env)
// {
// 	t_envlist *new;
	
// 	new = (t_envlist*)malloc(sizeof (*new));
// 	set_envlist(new, env);
// 	head->next = new;
// 	return (new);
	
// }

// t_envlist *make_envlist(char **envp)
// {
// 	t_envlist *head;
// 	t_envlist list;
// 	int i;

// 	head = &list;
// 	i = 0;
// 	if (envp[i] == NULL)
// 		return (NULL);
// 	while (envp[i])
// 	{
// 		head = make_new_envlist(head, envp[i++]);
// 	}
// 	return (list.next);
// }

void minishell(char **envp)
{
	char 		*line;
	t_envlist	*list;

	(void)envp;
	(void)list;
	// list = make_envlist(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			break;
		add_history(line);
		t_token **t = ft_lexer(line);
		for (size_t i=0; t[i]; i++) {
			printf("count: %zu | type is: %u | word is: %s\n",i, t[i]->type, t[i]->word);
		}


		if (ft_strncmp(line, "exit", 4) == 0)
			break;
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
