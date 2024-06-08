/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:57:54 by mosh              #+#    #+#             */
/*   Updated: 2024/06/08 17:54:24 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"


// #include "minishell.h"
// #include <stdio.h>

// void print_ast(t_ast_node *node, int level)
// {
//     if (node == NULL)
//         return;

//     for (int i = 0; i < level; i++)
//         printf("  ");

//     if (node->nodetype == NODE_COMMAND)
//         printf("Command: ");
//     else if (node->nodetype == NODE_PIPELINE)
//         printf("Pipeline: ");

//     if (node->args)
//     {
//         printf("Args: ");
//         for (int i = 0; node->args[i] != NULL; i++)
//             printf("'%s' ", node->args[i]);
//     }
//     printf("\n");

//     print_ast(node->left, level + 1);
//     print_ast(node->right, level + 1);
// }

// // void	set_envlist(t_envlist *new, char *env)
// // {
// // 	char	*var;
// // 	char	*value;
// // 	char	*where_equal;
// // 	size_t	key_len;

// // 	where_equal = ft_strchr(env, '=');
// // 	key_len = where_equal - env;
// // 	var = ft_substr(env, 0, key_len);
// // 	value = ft_substr(env, key_len + 1, ft_strlen(new->) - key_len - 1);
// // 	new->env_var = var;
// // 	new->value = value;
// // }

// // t_envlist *make_new_envlist(t_envlist *head, char *env)
// // {
// // 	t_envlist *new;
	
// // 	new = (t_envlist*)malloc(sizeof (*new));
// // 	set_envlist(new, env);
// // 	head->next = new;
// // 	return (new);
	
// // }

// // t_envlist *make_envlist(char **envp)
// // {
// // 	t_envlist *head;
// // 	t_envlist list;
// // 	int i;

// // 	head = &list;
// // 	i = 0;
// // 	if (envp[i] == NULL)
// // 		return (NULL);
// // 	while (envp[i])
// // 	{
// // 		head = make_new_envlist(head, envp[i++]);
// // 	}
// // 	return (list.next);
// // }

// void minishell(char **envp)
// {
//     char		*line;
//     t_token 	**tokens;
//     t_ast_node	*ast;
	
// 	// make_envlist(envp);
// 	(void)envp;
//     while (1)
//     {
//         line = readline("minishell$ ");
//         if (line == NULL)
//             break;
//         if (strlen(line) > 0)
//             add_history(line);
//         tokens = ft_lexer(line);
//         if (tokens == NULL)
//         {
//             free(line);
//             continue;
//         }
//         ast = parse_pipeline(tokens);
//         if (ast == NULL)
//         {
//             // free_tokens(tokens);
//             free(line);
//             continue;
//         }
		
// 		// ASTの内容を表示するためのコードを追加
//         printf("AST Structure:\n");
//         print_ast(ast, 0);  // ASTを表示する関数を呼び出し

//         // コマンドの実行（この部分はプレースホルダー、実際の実行関数を呼び出す）
//         // execute_ast(ast, envp);
//         // リソースの解放
//         // free_tokens(tokens);
//         // free_ast(ast);
//         free(line);
//     }
// }
// int	main(int argc, char **argv, char **envp)
// {

// 	(void)argc;
// 	(void)argv;
// 	minishell(envp);
// 	return (0);
// }
