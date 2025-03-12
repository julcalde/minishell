/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:08:59 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/12 23:24:26 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* tokenize_input
** tokenizes the input by splitting by space and special characters.
** Returns true if successful, false otherwise
** @line: The input string from user
** @tokens: Pointer to the s_tokens struct to store the tokens
** (error handling in case of missing space: TODO)
*/
static bool	tokenize_input(char *line, t_tokens *tokens)
{
	char	*token;
	int		i;

	i = 0;
	tokens->tokens = malloc(sizeof(char *) * 100);
	if (!tokens->tokens)
		return (false);
	token = strtok(line, " ");
	while (token)
	{
		tokens->tokens[i] = ft_strdup(token);
		if (!tokens->tokens[i])
		{
			free_tokens(tokens);
			return (false);
		}
		i++;
		token = strtok(NULL, " ");
	}
	tokens->tokens[i] = NULL;
	return (true);
}

/* execute_command
** Executes builtins or external commands
** @tokens: Pointer to the s_tokens struct containig tokens.
** (to improve for larger variety of commands)
*/
static void	execute_command(t_tokens *tokens)
{
	if (!tokens || !tokens->tokens || !tokens->tokens[0])
		return ;
	if (ft_strcmp(tokens->tokens[0], "echo") == 0)
	{
		while (*tokens->tokens)
		{
			printf("%s ", *tokens->tokens);
			if (*(tokens->tokens + 1))
				printf(" ");
			tokens->tokens++;
		}
		printf("\n");
	}
	else
		printf("Command not found: %s\n", tokens->tokens[0]);
}

/* free_tokens
** Frees the malloc for tokens
** @tokens: Pointer to the s_tokens struct containing the tokens
*/
static void	free_tokens(t_tokens *tokens)
{
	int	i;

	i = 0;
	if (!tokens || !tokens->tokens)
		return ;
	while (*tokens->tokens[i])
	{
		free(tokens->tokens[i]);
		i++;
	}
	free(tokens->tokens);
}

/* handle_input
** this funtion will care about parsing, tokenizing and executing the
** command from the user input
*/
void	handle_input(char *line)
{
	t_tokens	tokens;

	tokens.t_input = line;
	tokens.tokens = NULL;
	if (!tokenize_input(line, &tokens))
	{
		printf("Error while tokenizing input\n");
		return ;
	}
	execute_command(&tokens);
	free_tokens(&tokens);
}
