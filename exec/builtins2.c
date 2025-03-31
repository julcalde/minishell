/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 03:30:14 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/31 03:33:03 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int ft_unset(t_ast *ast, t_env *env)
{
	(void)ast;
	(void)env;
	printf("unset: not implemented yet\n");
	return (EXIT_SUCCESS);
}

int ft_env(t_env *env)
{
	(void)env;
	printf("env: not implemented yet\n");
	return (EXIT_SUCCESS);
}