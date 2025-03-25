/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:29 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/25 16:06:11 by julcalde         ###   ########.fr       */
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

static void	exec_builtin(t_ast *ast, t_env *env)
{
	(void) env;
	printf("(valid built-in: %s)\n", ast->command);

	// Actual implementation of built-in commands goes here or other file(s).
}

static void	external_cmd_exe(t_ast *ast)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execvp(ast->command, ast->args);
		perr_exit("execvp"); // to modify after test with "$fildirame$"
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		write (2, "fork", 5); // to modify after test with "$fildirame$"
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
