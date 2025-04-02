/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:22:47 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 22:44:35 by julcalde         ###   ########.fr       */
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

/* Returns 1 if the character is an alphanumeric character, 0 otherwise */
int	is_alnum(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || \
			(c >= '0' && c <= '9'));
}
