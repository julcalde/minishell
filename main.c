/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:13:02 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/13 14:12:45 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	g_shell;

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	g_shell.envp = env;
	g_shell.exit_status = 0;
	g_shell.sigint_detected = false;
	while (1)
	{
		line = readline("$fildirame$> ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line)
		{
			add_history(line);
			handle_input(line);
		}
		free(line);
	}
	return (0);
}
