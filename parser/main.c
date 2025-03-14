/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:26:09 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/14 16:31:08 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = NULL;
	(void)argc;
	(void)argv;
	init_env(&env, envp);
	shell_loop(env);
	cleanup(env, NULL);
	return (0);
}
