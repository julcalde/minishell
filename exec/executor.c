/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:29 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/18 19:41:59 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* Check if a command is a built-in. */
int	is_builtin(char *command)
{
	if (!command)
		return (1);
	if (ft_strcmp(command, "echo") == 0 || ft_strcmp(command, "cd" ) == 0
		|| ft_strcmp(command, "pwd") == 0 || ft_strcmp(command, "export") == 0
		|| ft_strcmp(command, "unset") == 0 || ft_strcmp(command, "env" )== 0
		|| ft_strcmp(command, "exit") == 0)
		return (0);
	return (1);
}

/* Validate built-in syntax. */
int	validate_builtin(t_ast *ast)
{
	if (!ft_strcmp(ast->command, "echo"))
		return (1);
	if (!ft_strcmp(ast->command, "cd"))
		return (!ast->args[1] || !ast->args[2]);
	if (!ft_strcmp(ast->command, "pwd"))
		return (!ast->args[1]);
	if (!ft_strcmp(ast->command, "env"))
		return (!ast->args[1]);
	return (1);
}

/* Built-in execution. */
void	exec_builtin(t_ast *ast, t_env *env, char * path)
{
	(void) env;
	// printf("(valid built-in: %s)\n", ast->command);
	// Example with echo built-in:
	if (ft_strcmp(ast->command, "echo") == 0)
		ft_echo(ast);
	else if (ft_strcmp(ast->command, "cd") == 0)
		ft_cd(ast, path);
	else if (ft_strcmp(ast->command, "pwd") == 0)
		ft_pwd(ast);
	else if (ft_strcmp(ast->command, "export") == 0)
		ft_export(ast, env);
	else if (ft_strcmp(ast->command, "unset") == 0)
		ft_unset(ast, env);
	else if (ft_strcmp(ast->command, "env") == 0)
		ft_env(env);
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

	path = get_path(ast->command, env);
	if (!path)
	{
		write (2, "$fildirame$> ", 14);
		write (2, ast->command, ft_strlen(ast->command));
		write (2, " command not found\n", 20);
		return ;
	}
	env_array = env_to_array(env);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (execve(path, ast->args, env_array) == -1)
        {
			perror("execve");
			exit(EXIT_FAILURE);
        }
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		perror("fork");
	ft_free_array(env_array);
	free(path);
}

/* Main execution function. */
void	exec_cmd(t_ast *ast, t_env *env, char *path)
{
	if (!ast || !ast->command)
		return ;
	if (is_builtin(ast->command) == 0)
		exec_builtin(ast, env, path);
	else
		external_cmd_exe(ast, env);
}
