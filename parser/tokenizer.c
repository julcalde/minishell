/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:23:41 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/01 23:40:30 by julcalde         ###   ########.fr       */
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
	token = ft_strtok(tmp, " \t\n");
	while (token && ++count)
		token = ft_strtok(NULL, " \t\n");
	free(tmp);
	return (count);
}

static char	**tokens_allocer(int count)
{
	char	**tokens;

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		perr_exit("malloc failed");
	return (tokens);
}

static void	tokens_filler(char **tokens, char *input)
{
	char	*token;
	int		i;

	i = 0;
	token = ft_strtok(input, " \t\n");
	while (token)
	{
		tokens[i++] = ft_strdup(token);
		token = ft_strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
}

/* Splits user input into tokens via static functions:
** tokens_counter: counts the number of tokens in the input.
** tokens_allocer: allocates memory for the tokens array based on token count.
** tokens_filler: fills the tokens array with actual tokens.
** tokenize_input: calls the above functions to tokenize the input.
*/
char	**tokenize_input(char *input)
{
	int		tok_count;
	char	**tokens;

	if (!input || !*input)
		return (NULL);
	tok_count = tokens_counter(input);
	tokens = tokens_allocer(tok_count);
	tokens_filler(tokens, input);
	return (tokens);
}
