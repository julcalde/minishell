/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:50 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/12 23:43:01 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <errno.h>

/* s_env
** @envp: Environment variables
** @exit_status: Exit status of the last command
** @sigint_detected: flag for (ctrl + c)
*/
typedef struct s_env
{
	char	**envp;
	int		exit_status;
	bool	sigint_detected;
}	t_env;

/* s_token
** @t_input: input string
** @tokens: array of tokens
*/
typedef struct s_tokens
{
	char	*t_input;
	char	**tokens;
}	t_tokens;

/*
** Global variable to hold shell's state
*/
extern t_env	g_shell;

// handle_input.c
bool	tokenize_input(char *line, t_tokens *tokens);
void	execute_command(t_tokens *tokens);
void	free_tokens(t_tokens *tokens);
void	handle_input(char *line);

/* tmp ft from libft coz lazy*/
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);

#endif