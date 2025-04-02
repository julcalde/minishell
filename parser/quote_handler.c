/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:58:22 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 23:07:17 by julcalde         ###   ########.fr       */
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

// Validate that the token has a matching quote
int	validate_token_quotes(t_token *token)
{
	char	*str;
	int		len;

	if (token->type != T_SQUOTE && token->type != T_DQUOTE)
		return (1);
	str = token->value;
	len = ft_strlen(str);
	return (len >= 2 && str[0] == str[len - 1]);
}
