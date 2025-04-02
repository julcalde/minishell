/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:23:41 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 21:25:07 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	tokens_counter(char *input)
{
	int		count;
	char	*tmp;
	char	*token;

	count = 0;
	tmp = ft_strdup(input);
	token = get_next_token(&tmp);
	while (token && ++count)
	{
		free(token);
		token = get_next_token(&tmp);
	}
	free(tmp);
	return (count);
}

char	**tokenize_input(char *input)
{
	char	**tokens;
	char	*tmp;
	char	*token;
	int		i;

	if (!validate_quotes(input))
		return (NULL);
	tokens = malloc(sizeof(char *) * (tokens_counter(input) + 1));
	if (!tokens)
		return (NULL);
	tmp = ft_strdup(input);
	i = 0;
	token = get_next_token(&tmp);
	while (token)
	{
		tokens[i++] = token;
		token = get_next_token(&tmp);
	}
	tokens[i] = NULL;
	free(tmp);
	return (tokens);
}
