/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:50 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/12 19:43:41 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

/* s_env
** envp: Environment variables
** exit_status: Exit status of the last command
** sigint_detected: flag for (ctrl + c)
*/
typedef struct s_env
{
	char	**envp;
	int		exit_status;
	bool	sigint_detected;
}	t_env;

/* s_token
** t_input: input string
** tokens: array of tokens
*/
typedef struct s_tokens
{
	char	*t_input;
	char	**tokens;
}	t_tokens;

#endif