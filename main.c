/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:13:02 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/12 21:26:34 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_input(char *line)
{
	char		**tokens;
	int			i;

	i = 0;
	tokens[i] = strtok(line, " ");
	while (tokens[i++])
		tokens[i] = strtok(NULL, " ");
	if (tokens[0])
		exe_cmd(tokens);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	while (1)
	{
		line = readline("$fildirame$> ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line)
			add_history(line);
		handle_input(line);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
