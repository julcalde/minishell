/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:08:06 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/30 16:54:39 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Actual function to free the t_env struct. */
void	cleaner_env(t_env *env)
{
	t_env	*cur_env;
	t_env	*next_env;

	cur_env = env;
	while (cur_env)
	{
		next_env = cur_env->next;
		free(cur_env->key);
		free(cur_env->value);
		free(cur_env);
		cur_env = next_env;
	}
}

/* Actual function to free the t_ast struct. */
void	cleaner_ast(t_ast *ast)
{
	int	i;

	if (ast)
	{
		free(ast->command);
		if (ast->args)
		{
			i = 0;
			while (ast->args[i])
			{
				free(ast->args[i]);
				i++;
			}
			free(ast->args);
		}
	}
	if (ast->left)
		cleanup(NULL, ast->left);
	if (ast->right)
		cleanup(NULL, ast->right);
	free(ast);
}

/* Main cleanup function that frees t_env and t_ast structs. */
void	cleanup(t_env *env, t_ast *ast)
{
	cleaner_env(env);
	cleaner_ast(ast);
}
