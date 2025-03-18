/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:42:31 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/18 19:28:08 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	handle_sigint(int sig)
{
	(void)sig;
	printf("\n");
}

void	handle_sigquit(int sig)
{
	(void)sig;
	printf("Quit: %d\n", sig);
}

void	set_sigs(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
}
