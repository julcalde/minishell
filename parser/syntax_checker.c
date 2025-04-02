/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:58:36 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 23:22:06 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Returns 1 if the token type is a redirection, 0 otherwise
static int	validate_operator(t_token **tokens, int i)
{
	if (tokens[i] == T_PIPE && (i == 0 || !tokens[i + 1]))
		return (0);
	if (is_redirect(tokens[i]->type) && \
	(!tokens[i + 1] || tokens[i + 1]->type != T_WORD))
		return (0);
	return (1);
}

// Validate that the token has a matching quote
int	validate_syntax(t_token **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
	{
		if (!validate_operator(tokens, i) || !validate_token_quotes(tokens[i]))
			return (0);
	}
	return (1);
}
