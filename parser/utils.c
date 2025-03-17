/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:39:52 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/17 16:32:48 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	perr_exit(char *err_msg)
{
	write (2, "Error: ", 7);
	perror(err_msg);
	exit(EXIT_FAILURE);
}
