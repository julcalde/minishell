/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:33:32 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/31 03:30:55 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

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
# include <limits.h>
# include "../parser/parser.h"

/* s_token
** @t_input: input string
** @tokens: array of tokens
*/
typedef struct s_tokens
{
	char	*t_input;
	char	**tokens;
}	t_tokens;

//LIBFT UTILS
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int a);
int		ft_atoi(const char *str);

// EXEGGCUTE_UTILS.C: Utility functions for executing commands.

int		is_executable(char *path);
char	*join_path(char *dir, char *cmd);
char	*get_path(char *cmd, t_env *env);
char	**env_to_array(t_env *env);


// EXEGGUTOR.C: Functions for executing commands.

int		is_builtin(char *command);
int		validate_builtin(t_ast *ast);
void	exec_builtin(t_ast *ast, t_env *env, char *path);
void	external_cmd_exe(t_ast *ast, t_env *env);
void	exec_cmd(t_ast *ast, t_env *env, char *path);


void	execute_command(char	**tokens);


//BUILTINS.C: Built-in functions.
int ft_echo(t_ast *ast);
int ft_cd(t_ast *ast,char *path);
int ft_exit(t_ast *ast);
int ft_pwd(t_ast *ast);
int ft_export(t_ast *ast, t_env *env);
int ft_unset(t_ast *ast, t_env *env);
int ft_env(t_env *env);
#endif

