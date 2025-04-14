/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:22:50 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/14 22:15:43 by fileonar         ###   ########.fr       */
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

static int	get_operator_length(char *str)
{
	if (*str == '>' && *(str + 1) == '>')
		return (2);
	if (*str == '<' && *(str + 1) == '<')
		return (2);
	if (*str == '|' && *(str + 1) == '|')
		return (2);
	if (*str == '&' && *(str + 1) == '&')
		return (2);
	if (is_operator (*str))
		return (1);
	return (0);
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
		len = handle_quoted_input(&ptr, *ptr);
	else
	{
		len = get_operator_length(ptr);
		if (!len)
		{
			len = 0;
			while (ptr[len] && !is_whitespace(ptr[len]) && \
			!is_operator(ptr[len]))
				len++;
		}
	}
	*input += len;
	return (ft_substr(ptr, 0, len));
}
