/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:39:52 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/14 22:45:44 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Handles custom error messages and exits using EXIT_FAILURE */
void	perr_exit(char *err_msg)
{
	write (2, "$fildirame$> ", 14);
	write (2, err_msg, ft_strlen(err_msg));
	write (2, "\n", 1);
	exit(EXIT_FAILURE);
}

/* Frees a dynamically allocated array of strings:
** if array is NULL, just returns immediately.
** otherwise, iterates through array and frees each string
** finally, frees the array itself and sets it to NULL*/
void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_free_tokens(t_token **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	if (*tokens)
		free(*tokens);
}

