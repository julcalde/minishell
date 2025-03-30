/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:34:33 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/31 00:23:01 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no options */


int	ft_echo(t_ast *ast)
{

	ast->args++;
	if (ast->args && !ft_strcmp(ast->args[0], "-n"))
	{
		ast->args++;
		while (*ast->args != NULL)
		{
			if (ast->args[1] == NULL)
				printf("%s", ast->args[0]);
			else
				printf("%s ", ast->args[0]);
			ast->args++;
		}
	}
	else if (!ast->args[0])
		printf("\n");
	else
	{
		while (*ast->args)
		{
			printf("%s ", ast->args[0]);
			ast->args++;
		}
		printf("\n");
	}
	return (EXIT_SUCCESS);
}
//I NEED ENV HOME OR ROOT TO SET THE ROOTPATH WHEN USER ONLY WRITE CD IN THE TERMINAL
int ft_cd(t_ast *ast)
{
	char *path;

	if (!ast->args[1])
		path = getenv("HOME");
	else
		path = ast->args[1];
	if (chdir(path) == -1)
	{
		printf("cd: %s: %s\n", path, strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int ft_exit(t_ast *ast)
{
	if (ast->args[1])
		{
			int nr;
			
			nr = ft_atoi ((const char *)ast->args[1]);
			if (!ft_isdigit(nr))
			{
				printf("exit: %s: numeric argument required\n", ast->args[1]);
				exit(1);
			}
			printf("exit\n");
			exit(nr);
		}
		else
		{
			printf("exit\n");
			exit(1);
		}
}