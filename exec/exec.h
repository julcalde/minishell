/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:33:32 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/14 18:47:46 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_tokens
{
	char	*t_input;
	char	**tokens;
}	t_tokens;


bool	tokenize_input(char *line, t_tokens *tokens);
void	execute_command(t_tokens *tokens);
#endif