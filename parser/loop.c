/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:23:08 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/01 23:27:50 by julcalde         ###   ########.fr       */
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
	while (g_shell_state == SHELL_RUNNING)
	{
		input = read_input();
		if (!input || g_shell_state == SHELL_TERMINATE)
			break ;
		if (*input)
			add_to_history(input);
		tokens = tokenize_input(input);
		ast = parse_input(tokens);
		if (ast && ast->command)
			exec_cmd(ast, env);
		free(input);
		cleanup(NULL, ast, (t_token **)tokens);
		if (g_shell_state == SHELL_INTERRUPT)
			g_shell_state = SHELL_RUNNING;
	}
}
