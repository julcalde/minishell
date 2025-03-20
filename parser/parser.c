/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:39:47 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/20 20:02:50 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Parses tokens into an AST.*/
t_ast	*parse_input(char **tokens)
{
	t_ast	*ast;

	ast = malloc(sizeof(t_ast));
	if (!ast)
		perr_exit("malloc ast failed\n");
	ast->command = ft_strdup(tokens[0]);
	ast->args = tokens;
	ast->left = NULL;
	ast->right = NULL;
	return (ast);
}

/* Handles syntax errors in the parsed input. */
void	handle_err(t_ast *ast)
{
	if (!ast || !ast->command)
		perr_exit("parsing error\n");
}
