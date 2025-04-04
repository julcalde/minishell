/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:35:49 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/21 00:30:52 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	tokens_counter(char *input)
{
	int		count;
	char	*tmp;
	char	*token;

	count = 0;
	tmp = ft_strdup(input);
	token = strtok(tmp, " \t\r\n\a");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\r\n\a");
	}
	free(tmp);
	return (count);
}

static char	**tokens_allocer(int count)
{
	char	**tokens;

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	return (tokens);
}

static void	tokens_filler(char **tokens, char *input)
{
	char	*token;
	int		i;

	i = 0;
	token = strtok(input, " \t\r\n\a");
	while (token)
	{
		tokens[i++] = ft_strdup(token);
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
}

char	**tokenize_input(char *input)
{
	int		count_tokens;
	char	**tokens;
	if (!input || !*input)
		return (NULL);
	count_tokens = tokens_counter(input);
	tokens = tokens_allocer(count_tokens);
	tokens_filler(tokens, input);
	return (tokens);
}
