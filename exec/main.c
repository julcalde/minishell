/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:37:05 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/14 18:37:25 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int main(int argc, char **argv)
{
	t_tokens	tokens;

	if (argc != 2)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	tokenize_input(argv[1], &tokens);
	execute_command(&tokens);
	return (0);
}