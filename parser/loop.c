/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:23:08 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/20 20:17:19 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Core minishell loop:
** calls set_sigs() to configure signal handlers.
** calls read_input() to get user input and exits when Ctrl+D is received.
** calls add_history() to store non-empty input in the command history.
** calls tokenize_input() to split input into tokens.
** calls parse_input() to create an AST from the tokens.
** calls handle_err() to check for syntax errors in the parsed input.
** (executes the commands represented in the AST.)
** (frees input, tokens and AST after command execution.)*/
void	shell_loop(t_env *env)
{
	char	*input;
	char	**tokens;
	t_ast	*ast;

	set_sigs();
	while (1)
	{
		input = read_input();
		if (!input)
			break ;
		if (*input)
			add_to_history(input);
		tokens = tokenize_input(input);
		ast = parse_input(tokens);
		handle_err(ast);
		exec_cmd(ast, env);
		free(input);
		free(tokens);
		cleanup(env, ast);
	}
}
