/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:42:31 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/20 20:01:30 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Handle SIGINT signal:
** prints a newline
** clears current input line (rl_replace_line)
** moves cursor to a new line (rl_on_new_line)
** redisplays the prompt (rl_redisplay) */
void	handle_sigint(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/* Handles SIGQUIT signal:
** prints "Quit: <signal_number>" */
void	handle_sigquit(int sig)
{
	(void)sig;
	printf("Quit: %d\n", sig);
}

/* Sets up signal handlers:
** uses (sigaction) to setup SIGINT to call handle_sigint
** uses (sigaction) to setup SIGQUIT to be ignored (SIG_IGN)
** interrupted system calls are restarted with (SA_RESTART) */
void	set_sigs(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sa_int.sa_handler = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = SIG_IGN;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa_quit, NULL);
}
