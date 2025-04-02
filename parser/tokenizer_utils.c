/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:22:50 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 21:04:14 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	handle_quoted_input(char **str, char quote)
{
	int	len;

	len = 1;
	while ((*str)[len] && (*str)[len] != quote)
		len++;
	if (!(*str)[len])
		return (-1);
	return (len + 1);
}

char	*get_next_token(char **input)
{
	int		len;
	char	*ptr;

	while (**input && is_whitespace(**input))
		(*input)++;
	if (!**input)
		return (NULL);
	ptr = *input;
	if (*ptr == '\'' || *ptr == '\"')
	{
		len = handle_quoted_input(&ptr, *ptr);
		if (len == -1)
			return (NULL);
	}
	else
	{
		len = 0;
		while (ptr[len] && !is_whitespace(ptr[len]) && !is_special(ptr[len]))
			len++;
	}
	return (ft_substr(*input, 0, len));
}
