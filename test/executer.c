#include "minishell.h"

void execute_command(char *command[]) {
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		handle_error("fork");
	}
	else if (pid == 0)
	{
		// 子プロセス
		if (execve(command[0], command, NULL) == -1)
		{
			handle_error("execve");
		}
	}
	else
	{
		// 親プロセス
		int status;
		waitpid(pid, &status, 0);
	}
}

