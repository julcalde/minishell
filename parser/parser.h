/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:32:15 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/17 17:48:09 by julcalde         ###   ########.fr       */
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

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_ast
{
	char			*command;
	char			**args;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

// Functions init.c
/* The init_env function initializes a linked list of environment variables by:
** parsing an array of strings into key-value pairs.
** dynamically allocating memory for each node.
*/
void	init_env(t_env **env, char **envp);


// Functions input.c
char	*read_input(void);
void	add_history(char *input);

// Functions tokenizer.c
char	**tokenize_input(char *input);

// Functions parser.c
t_ast	*parse_input(char **tokens);
void	handle_err(t_ast *ast);

// Functions libft_utils.c
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);

// Functions utils.c
void	perr_exit(char *err_msg);

#endif