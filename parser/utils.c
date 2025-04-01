/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:39:52 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/01 23:45:11 by julcalde         ###   ########.fr       */
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

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_redirect(int type)
{
	return (type == T_REDIRECT_IN || type == T_REDIRECT_OUT || \
			type == T_REDIRECT_APPEND);
}
