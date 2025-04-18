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
	int i;
	t_env *prev;
	t_env *current;
	if (!ast || !ast->args)
	{
		perror("unset: No arguments provided");
		return (EXIT_FAILURE);
	}
	i = 1;
	while (ast->args[i])
	{
		current = env;
		prev = NULL;
		while (current)
		{
			if (strcmp(current->key, ast->args[i]) == 0)
			{
				if (prev)
					prev->next = current->next;
				else
					env = current->next;
				free(current->key);
				free(current->value);
				free(current);
				break;
			}
			prev = current;
			current = current->next;
		}
		i++;
	}


	return (EXIT_SUCCESS);
}

int ft_env(t_env *env)
{
	if (!env)
	{
		perror("env: No environment variables found");
		return (EXIT_FAILURE);
	}
	while (env)
	{
		if (env->key || (env->key && env->value))
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}