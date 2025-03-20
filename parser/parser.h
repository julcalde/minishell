/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:32:15 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/20 20:19:04 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
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


// INIT.C: Initializes the shell environment.

void	init_env(t_env **env, char **envp);


// INPUT.C: Functions for reading and handling user input.

char	*read_input(void);
void	add_to_history(char *input);


// LOOP.C: Core minishell loop.

void	shell_loop(t_env *env);


// PARSER.C: Parses tokens into an Abstract Syntax Tree (AST)

t_ast	*parse_input(char **tokens);
void	handle_err(t_ast *ast);


// SIGNALS.C: Functions for handling signals.

void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	set_sigs(void);


// TOKENIZER.C: Functions for tokenizing user input.

char	**tokenize_input(char *input);


// UTILS.C: Utility functions.

void	perr_exit(char *err_msg);
void	ft_free_array(char **array);


/* Helper functions libft_utils.c */

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);

#endif