/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:34:33 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/31 03:29:50 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no options */


int	ft_echo(t_ast *ast)
{

	ast->args++;
	if (ast->args && !ft_strcmp(ast->args[0], "-n"))
	{
		ast->args++;
		while (*ast->args != NULL)
		{
			if (ast->args[1] == NULL)
				printf("%s", ast->args[0]);
			else
				printf("%s ", ast->args[0]);
			ast->args++;
		}
	}
	else if (!ast->args[0])
		printf("\n");
	else
	{
		while (*ast->args)
		{
			printf("%s ", ast->args[0]);
			ast->args++;
		}
		printf("\n");
	}
	return (EXIT_SUCCESS);
}

int ft_cd(t_ast *ast, char *path)
{

	if (!ast->args[1])
	{
		chdir((const char *)path);
		return (EXIT_SUCCESS);
	}
	else
		path = ast->args[1];
	if (chdir(path) == -1)
	{
		printf("cd: %s: %s\n", path, strerror(errno));
		return (EXIT_FAILURE);
	}
	chdir(path);
	return (EXIT_SUCCESS);
}

int ft_exit(t_ast *ast)
{
	if (ast->args[1])
		{
			int nr;
			
			nr = ft_atoi ((const char *)ast->args[1]);
			if (!ft_isdigit(nr))
			{
				printf("exit: %s: numeric argument required\n", ast->args[1]);
				exit(2);
			}
			printf("exit\n");
			exit(nr);
		}
		else
		{
			printf("exit\n");
			exit(1);
		}
}

int ft_pwd(t_ast *ast)
{
	
	ast->command = getcwd(NULL, 0);
	if (!ast->command)
	{
		printf("error: %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	printf("%s\n", ast->command);
	free(ast->command);
	return (EXIT_SUCCESS);
}

void add_env_var(t_env *env, char *key, char *value)
{
	t_env *current;
	
	current  = env;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			return;
		}
		current = current->next;
	}

	t_env *new_node;

	new_node  = malloc(sizeof(t_env));
    if (!new_node)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    new_node->key = ft_strdup(key);
    new_node->value = ft_strdup(value);
	printf("new_node->key: %s\n", new_node->key);
	printf("new_node->value: %s\n", new_node->value);
    new_node->next = env;
    env = new_node;
	printf("env key : %s\n", env->key);
	printf("env value : %s\n", env->value); 
}

int ft_export(t_ast *ast, t_env *env)
{

	char *key;
	char *value;
	t_env *current;

	key = NULL;
	value = NULL;
	current = env;
	if (ast->args[1] == NULL)
	{
		while (current)
		{
			if (current->key && current->value)
			printf("declare -x %s=%s\n", current->key, current->value);
			current = current->next;
		}
	}
	else
	{
		while (ast->args[1])
		{
			key = ast->args[1];
			value = strchr(key, '=');
			if (value)
			{
				*value = '\0';
				value++;
				add_env_var(env, key, value);
			}
			else
				add_env_var(env, key, NULL);
			printf("env key: %s\n", env->key);
			ast->args++;
		}
	}
	return (EXIT_SUCCESS);
}
