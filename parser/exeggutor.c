/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:29 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/25 16:46:10 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check if a command is a built-in. */
static int	is_builtin(char *command)
{
	if (!ft_strcmp(command, "echo"))
		return (1);
	if (!ft_strcmp(command, "cd"))
		return (1);
	if (!ft_strcmp(command, "pwd"))
		return (1);
	if (!ft_strcmp(command, "export"))
		return (1);
	if (!ft_strcmp(command, "unset"))
		return (1);
	if (!ft_strcmp(command, "env"))
		return (1);
	if (!ft_strcmp(command, "exit"))
		return (1);
	return (0);
}

/* Validate built-in syntax.
** echo: validate option -n and arguments.
** cd: must have 0 or 1 arguments.
** pwd: no args allowed.
** export: arguments allowed (key value pairs).
** unset: arguments allowed (variable names).
** env: no options or arguments allowed.
** exit: no options allowed. */
static int	validate_builtin(t_ast *ast)
{
	if (!ft_strcmp(ast->command, "echo"))
		return (1);
	if (!ft_strcmp(ast->command, "cd"))
		return (!ast->args[1] || !ast->args[2]);
	if (!ft_strcmp(ast->command, "pwd"))
		return (!ast->args[1]);
	if (!ft_strcmp(ast->command, "export"))
		return (1);
	if (!ft_strcmp(ast->command, "unset"))
		return (1);
	if (!ft_strcmp(ast->command, "env"))
		return (!ast->args[1]);
	if (!ft_strcmp(ast->command, "exit"))
		return (1);
	return (0);
}

/* Built-in execution. */
static void	exec_builtin(t_ast *ast, t_env *env)
{
	(void) env;
	printf("(valid built-in: %s)\n", ast->command);
	// Example with echo built-in:
	// if (ft_strcmp(ast->command, "echo") == 0)
		// ft_echo(ast);
}

static void	external_cmd_exe(t_ast *ast, t_env *env)
{
	pid_t	pid;
	char	*path;
	char	**env_array;

	path = get_path(ast->command, env); // todo: implement get_path
	if (!path)
	{
		write (2, "command not found\n", 19);
		return ;
	}
	env_array = env_to_array(env); // todo: implement env_to_array
	pid = fork();
	if (pid == 0)
	{
		execvp(ast->command, ast->args);
		perr_exit("execvp");
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		write (2, "fork\n", 6);
	free(path);
	ft_free_array(env_array);
}

/* Main execution function. */
void	exec_cmd(t_ast *ast, t_env *env)
{
	if (!ast || !ast->command)
		return ;
	if (is_builtin(ast->command))
	{
		if (validate_builtin(ast))
			exec_builtin(ast, env);
		else
			write (2, "invalid arguments\n", 19);
	}
	else
		external_cmd_exe(ast);
}
