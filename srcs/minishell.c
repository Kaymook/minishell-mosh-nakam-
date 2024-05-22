#include "../includes/minishell.h"

void    minishell(char **envp)
{
	char    *line;
	(void)envp;

    while (1)
    {
        line = readline("minishell$ ");
        if (line == NULL)
            break ;
        add_history(line);
        if (ft_strncmp(line, "exit", 4) == 0)
            break ;
        if (ft_strncmp(line, "cd", 2) == 0)
            chdir(line);
    }
}
int	main(int argc, char **argv, char **envp)
{

    (void)argc;
    (void)argv;
	minishell(envp);

    return (0);
}


