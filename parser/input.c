/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:07:51 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/20 20:17:04 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Reads input from the user:
** displays prompt and read input.
** handles EOF (Ctrl+D).
** Exits gracefully. */
char	*read_input(void)
{
	char	*input;

	input = readline("$fildirame$> ");
	if (!input)
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	return (input);
}

/* Adds non-empty input to the command history */
void	add_to_history(char *input)
{
	if (input && *input)
		add_history(input);
}
