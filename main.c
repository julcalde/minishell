/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:26:09 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/28 16:26:57 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* The main function initializes the shell environment in t_env *env
* and enters the shell loop.
* The shell loop sets the signals handlers, reads user input, parses it into
* an AST, and executes it until the user exits the shell.
* The shell environment is cleaned up with cleanup() before exiting.
*/
int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void)argc;
	(void)argv;
	if (!isatty(STDIN_FILENO))
		perr_exit("Not a terminal.");
	env = NULL;
	g_shell_state = SHELL_RUNNING;
	init_env(&env, envp);
	shell_loop(env);
	cleanup(env, NULL, NULL);
	if (g_shell_state == SHELL_TERMINATE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}