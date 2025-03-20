/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:37:05 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/21 00:12:16 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int main(int argc, char **argv)
{
	int i;
	char **tokens;
	
	i = 0;
	if (argc < 2)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	tokens = tokenize_input(argv[1]);
	if (tokens == NULL)
	{
		write(2, "Error: failed to tokenize input\n", 33);
		return (1);
	}
	execute_command(tokens);
	
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (0);
}