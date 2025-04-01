/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:58:22 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 00:04:03 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token_type	get_quote_type(char c)
{
	if (c == '\'')
		return (T_SQUOTE);
	if (c == '"')
		return (T_DQUOTE);
	return (T_WORD);
}

int	validate_quotes(char *input)
{
	int		i;
	char	open_quote;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			open_quote = input[i];
			while (input[++i] && input[i] != open_quote)
				;
			if (!input[i])
				return (0);
		}
	}
	return (1);
}
