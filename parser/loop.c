/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:23:08 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 21:12:47 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Core minishell loop */
void	shell_loop(t_env *env)
{
	char	*input;
	char	**tokens;
	t_ast	*ast;

	set_sigs();
	while (g_shell_state == SHELL_RUNNING)
	{
		input = read_input();
		if (!*input || g_shell_state == SHELL_TERMINATE)
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
