/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:34:33 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/29 05:45:03 by fileonar         ###   ########.fr       */
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
