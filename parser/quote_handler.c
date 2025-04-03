/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:58:22 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/03 18:56:59 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// // might not need this function
// t_token_type	get_quote_type(char c) // in case remove from header
// {
// 	if (c == '\'')
// 		return (T_SQUOTE);
// 	if (c == '"')
// 		return (T_DQUOTE);
// 	return (T_WORD);
// }

// Validate that the input has matching quotes
int	validate_quotes(char *input)
{
	int		i;
	char	quote;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\\' && input[i + 1])
			i++;
		else if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i];
			while (input[++i] && input[i] != quote)
				if (quote == '"' && input[i] == '\\' && input[i + 1])
					i++;
			if (!input[i])
				return (0);
		}
	}
	return (1);
}

// Validate that the token has a matching quote
int	validate_token_quotes(t_token *token)
{
	char	*str;
	int		len;

	if (token->type != T_SQUOTE && token->type != T_DQUOTE)
		return (1);
	str = token->value;
	len = ft_strlen(str);
	if (len < 2 || str[0] != str[len - 1])
		return (0);
	return (1);
}
