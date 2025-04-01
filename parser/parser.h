/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:32:15 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/01 22:46:33 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

typedef enum e_shell_state
{
	SHELL_RUNNING,
	SHELL_INTERRUPT,
	SHELL_TERMINATE
}	t_shell_state;

extern volatile sig_atomic_t	g_shell_state;

/* Token types */
typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIRECT_IN,
	T_REDIRECT_OUT,
	T_REDIRECT_APPEND,
	T_SQUOTE,
	T_DQUOTE,
	T_VAR,
	T_EOF
}	t_token_type;

/* Token structure */
typedef struct s_token
{
	char			*value;
	t_token_type	type;
}	t_token;

/* Environment variable structure */
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/* AST node type */
typedef enum e_node_type
{
	N_CMD,
	N_PIPE,
	N_REDIR
}	t_node_type;

/* AST node structure */
typedef struct s_ast
{
	char			*command;
	char			**args;
	struct s_ast	*left;
	struct s_ast	*right;
	char			*redir_file;
	int				redir_fd;
}	t_ast;


/* --------------------------- Parsing Functions --------------------------- */

// CLEANER.C: clean-up function for freeing memory at the end.

void	cleanup(t_env *env, t_ast *ast, t_token **tokens);
void	cleaner_env(t_env *env);
void	cleaner_ast(t_ast *ast);


// EXEGGCUTE_UTILS.C: Utility functions for executing commands.

int		is_executable(char *path);
char	*join_path(char *dir, char *cmd);
char	*get_env_value(char *key, t_env *env);
char	*get_path(char *cmd, t_env *env);
char	**env_to_array(t_env *env);


// EXEGGUTOR.C: Functions for executing commands.

int		is_builtin(char *command);
int		validate_builtin(t_ast *ast);
void	exec_builtin(t_ast *ast, t_env *env);
void	external_cmd_exe(t_ast *ast, t_env *env);
void	exec_cmd(t_ast *ast, t_env *env);


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


/* Helper functions libft_utils.c and libft_utils_moar.c */

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strtok(char *str, const char *delim);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);

#endif