/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:58:36 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/05 15:15:02 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	validate_operator(t_token **tokens, int i)
{
	if (!tokens[i] || !tokens[i + 1])
		return (0);
	if (tokens[i]->type == T_PIPE && (i == 0 || tokens[i + 1]->type == T_PIPE))
		return (0);
	if (is_redirect_type(tokens[i]->type) && tokens[i + 1]->type != T_WORD)
		return (0);
	return (1);
}


int	validate_syntax(t_token **tokens)
{
	int	i;

	if (!tokens || !*tokens)
		return (0);
	i = -1;
	while (tokens[++i])
	{
		if (!validate_token_quotes(tokens[i]))
			return (0);
		if (is_operator_type(tokens[i]->type) && !validate_operator(tokens, i))
		{
			handle_err(NULL);
			return (0);
		}
	}
	return (1);
}
