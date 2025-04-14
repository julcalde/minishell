/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:08:06 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/14 22:50:07 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Actual function to free environment list. */
void	cleaner_env(t_env *env)
{
	t_env	*tmp_env;

	while (env)
	{
		tmp_env = env;
		env = env->next;
		free(tmp_env->key);
		free(tmp_env->value);
		free(tmp_env);
	}
}

/* Actual function to free AST (if exists). */
void	cleaner_ast(t_ast *ast)
{
	int	i;

	if (!ast)
		return ;
	free(ast->command);
	if (ast->args)
	{
		i = 0;
		while (ast->args[i])
			free(ast->args[i++]);
		free(ast->args);
	}
	if (ast->heredoc_fd > 2)
		close(ast->heredoc_fd);
	if (ast->left)
		cleaner_ast(ast->left);
	if (ast->right)
		cleaner_ast(ast->right);
	free(ast);
}

/* Main cleanup function that frees t_env, t_ast and t_token structs. */
void	cleanup(t_env *env, t_ast *ast, t_token **tokens)
{
	if (env)
		cleaner_env(env);
	if (ast)
		cleaner_ast(ast);
	if (*tokens)
		ft_free_tokens(tokens);
}
