/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:22:47 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 20:41:02 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Returns 1 if the character is a whitespace character, 0 otherwise */
int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/* Returns 1 if the character is a special character, 0 otherwise */
int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '$' || c == '\''
		|| c == '\"');
}

/* Returns 1 if the token type is a redirection, 0 otherwise */
int	is_redirect(int type)
{
	return (type == T_REDIRECT_IN || type == T_REDIRECT_OUT || \
			type == T_REDIRECT_APPEND);
}
