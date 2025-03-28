/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:34:33 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/28 17:46:18 by fileonar         ###   ########.fr       */
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
	//check if it is echo or echo -n
	//check if there is printable characters in the string
	//if there is spaces, skip until the first character
	//print the string
	// printf("args: %s\n", ast);
	
	// while (ast == ' ')
	// 	i++;
	// if (ast == '-' && ast == 'n')
	// {
	// 	i += 2;
	// 	while (ast == ' ')
	// 		i++;
	// 	while (ast)
	// 	{
	// 		write(1, &ast, 1);
	// 		i++;
	// 	}
	// }
	printf("ast: %s\n", ast->args[1]);
	return (EXIT_SUCCESS);
}
