/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:23:08 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/28 19:19:35 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	(void)env;
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
		exec_cmd(ast, env); // this function is not yet implemented
		free(input);
		free(tokens);
		// cleanup(env, ast);
	}
}
