/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:33:32 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/21 00:46:42 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_tokens
{
	char	*t_input;
	char	**tokens;
}	t_tokens;

char	*ft_strdup(const char *s1);
int	ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

//tokenaization julio
char	**tokenize_input(char *input);

void	execute_command(char	**tokens);
#endif

