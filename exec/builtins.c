/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:34:33 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/28 17:57:34 by fileonar         ###   ########.fr       */
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
	if (ast->args[1] && !ft_strcmp(ast->args[1], "-n"))
	{
		while (*ast->args != NULL)
		{
			printf("%s ", ast->args[1]);
			ast->args++;
		}
	}
	else if (!ast->args[1])
		printf("\n");
	else
	{
		while (*ast->args != NULL)
		{
			printf("%s ", ast->args[1]);
			ast->args++;
		}
		printf("\n");
	}
	return (EXIT_SUCCESS);
}
