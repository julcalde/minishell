/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggutor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:29 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/05 14:50:49 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check if a command is a built-in. */
int	is_builtin(char *command)
{
	if (!command)
		return (0);
	if (!ft_strcmp(command, "echo") || !ft_strcmp(command, "cd")
		|| !ft_strcmp(command, "pwd") || !ft_strcmp(command, "export")
		|| !ft_strcmp(command, "unset") || !ft_strcmp(command, "env")
		|| !ft_strcmp(command, "exit"))
		return (1);
	return (0);
}

// /* Validate built-in syntax. */
// int	validate_builtin(t_ast *ast)
// {
// 	if (!ft_strcmp(ast->command, "echo"))
// 		return (1);
// 	if (!ft_strcmp(ast->command, "cd"))
// 		return (!ast->args[1] || !ast->args[2]);
// 	if (!ft_strcmp(ast->command, "pwd"))
// 		return (!ast->args[1]);
// 	if (!ft_strcmp(ast->command, "env"))
// 		return (!ast->args[1]);
// 	return (1);
// }

/* Built-in execution. */
void	exec_builtin(t_ast *ast, t_env *env)
{
	(void)env;
	(void)ast;
	printf("HELLO\n");
	// if (!ft_strcmp(ast->command, "echo"))
	// 	ft_echo(ast->args);
	// else if (!ft_strcmp(ast->command, "cd"))
	// 	ft_cd(ast->args[1], env);
	// else if (!ft_strcmp(ast->command, "pwd"))
	// 	ft_pwd();
	// else if (!ft_strcmp(ast->command, "export"))
	// 	ft_export(ast->args, env);
	// else if (!ft_strcmp(ast->command, "unset"))
	// 	ft_unset(ast->args, env);
	// else if (!ft_strcmp(ast->command, "env"))
	// 	ft_env(env);
	// else if (!ft_strcmp(ast->command, "exit"))
	// 	ft_exit(ast->args);
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
		write (2, "command not found\n", 19);
		return ;
	}
	env_array = env_to_array(env);
	pid = fork();
	if (pid == 0)
		execve(path, ast->args, env_array);
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	ft_free_array(env_array);
	free(path);
}

/* Main execution function. */
void	exec_cmd(t_ast *ast, t_env *env)
{
	if (!ast || !ast->command)
		return ;
	if (is_builtin(ast->command))
		exec_builtin(ast, env);
	else
		external_cmd_exe(ast, env);
}
