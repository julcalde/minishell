/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:29 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/31 00:29:32 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* Check if a command is a built-in. */
int	is_builtin(char *command)
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
int	validate_builtin(t_ast *ast)
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
void	exec_builtin(t_ast *ast, t_env *env)
{
	(void) env;
	// printf("(valid built-in: %s)\n", ast->command);
	// Example with echo built-in:
	if (ft_strcmp(ast->command, "echo") == 0)
		ft_echo(ast);
	else if (ft_strcmp(ast->command, "cd") == 0)
		ft_cd(ast);
	else if (ft_strcmp(ast->command, "pwd") == 0)
		ft_pwd(ast);
	// else if (ft_strcmp(ast->command, "export") == 0)
	// 	ft_export(ast, env);
	// else if (ft_strcmp(ast->command, "unset") == 0)
	// 	ft_unset(ast, env);
	// else if (ft_strcmp(ast->command, "env") == 0)
	// 	ft_env(env);
	else if (ft_strcmp(ast->command, "exit") == 0)
	{
		ft_exit(ast);
	}
	
}

/* Executes external commands. */
void	external_cmd_exe(t_ast *ast, t_env *env)
{
	pid_t	pid;
	char	*path;
	char	**env_array;

	(void)env;
	path = get_path(ast->command, env);
	if (!path)
	{
		write (2, "$fildirame$> ", 14);
		write (2, ast->command, ft_strlen(ast->command));
		write (2, "command not found\n", 19);
		return ;
	}
	env_array = env_to_array(env);
	pid = fork();
	if (pid == 0)
	{
		execve(path, ast->args, env_array);
		perr_exit("execvp failed");
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		write (2, "$fildirame$> fork failed\n", 26);
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
		external_cmd_exe(ast, env);
}
