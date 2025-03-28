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

	env = NULL;
	(void)argc;
	(void)argv;
	init_env(&env, envp);
	shell_loop(env);
	// cleanup(env, NULL);
	return (0);
}
