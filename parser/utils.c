/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:39:52 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/25 16:33:28 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Handles custom error messages and exits using EXIT_FAILURE */
void	perr_exit(char *err_msg)
{
	write (2, "Error: ", 8); // to update later
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

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}
