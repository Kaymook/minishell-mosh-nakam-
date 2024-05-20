#include "minishell.h"

void    minishell(char **envp)
{
    char    *line;

    while (1)
    {
        line = readline("minishell$ ");
        if (line == NULL)
            break ;
        add_history(line);
        if (ft_strcmp(line, "exit") == 0)
            break ;
        if (ft_strcmp(line, "cd") == 0)
            chdir(line);

    }
}
int	main(int argc, char **argv, char **envp)
{

    (void)argc;
    (void)argv;

    return (0);
}

