/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:37:05 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/21 00:51:47 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int main(int argc, char **argv)
{
	int i;
	char **tokens;
	char *str;
	
	i = 1;
	str = argv[1];
	if (argc < 2)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	//take everything after the ./exec and make it a string so it s easier to manipulate?
	while (i < argc)
	{
		str = ft_strjoin(str, " ");
		if (argv[i + 1] != NULL)
			str = ft_strjoin(str, argv[++i]);
		i++;
	}
	tokens = tokenize_input(str);
	if (tokens == NULL)
	{
		write(2, "Error: failed to tokenize input\n", 33);
		return (1);
	}
	execute_command(tokens);
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (0);
}