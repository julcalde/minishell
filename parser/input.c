/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:07:51 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/17 16:21:54 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void	add_history(char *input)
{
	if (input && *input)
		add_history(input);
}
