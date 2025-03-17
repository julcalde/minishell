/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:32:15 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/17 18:36:02 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

/* Environment variable structure
** key: stores the name of the environment variable (e.g. "PATH").
** value: stores the value of the env variable (e.g. "/usr/bin:/bin").
** next: pointer to the next node in the linked list.
*/
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/* AST node structure
** command: stores the command to execute (e.g. "ls").
** args: stores the arguments for the command in an array (e.g. ["ls", "-l"]).
** left: points to left child node in AST. Used for pipelining or redirecting.
** right: points to right child node in AST. Used for pipelining or redirecting.
*/
typedef struct s_ast
{
	char			*command;
	char			**args;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;


// INIT.C: Functions for initializing the shell.
/* The init_env function initializes a linked list of environment variables by:
** parsing an array of strings into key-value pairs.
** dynamically allocating memory for each node.
*/
void	init_env(t_env **env, char **envp);


// INPUT.C: Functions for reading and handling user input.
/* Reads input from the user using readline and handles EOF */
char	*read_input(void);
/* Adds non-empty input to the command history */
void	add_history(char *input);


// TOKENIZER.C: Functions for tokenizing user input.
/* Splits user input into tokens.
** tokens_counter: counts the number of tokens in the input.
** tokens_allocer: allocates memory for the tokens array based on token count.
** tokens_filler: fills the tokens array with actual tokens.
** tokenize_input: calls the above functions to tokenize the input.
*/
char	**tokenize_input(char *input);


// PARSER.C: Parses tokens into an Abstract Syntax Tree (AST)
/* Parses tokens into an AST.*/
t_ast	*parse_input(char **tokens);
/* Handles syntax errors in the parsed input.*/
void	handle_err(t_ast *ast);


// UTILS.C: Utility functions.
/* Handles custom error messages and exit using EXIT_FAILURE */
void	perr_exit(char *err_msg);


/* Helper functions libft_utils.c */

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);

#endif