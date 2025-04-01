/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggcute_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:48:27 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/01 22:45:19 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check if file exists and is executable. */
int	is_executable(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

/* Joins directory and command with '/'. */
char	*join_path(char *dir, char *cmd)
{
	char	*path;
	int		len;

	len = ft_strlen(dir) + ft_strlen(cmd) + 2;
	path = malloc(len);
	if (!path)
		return (NULL);
	ft_strlcpy(path, dir, len);
	ft_strlcat(path, "/", len);
	ft_strlcat(path, cmd, len);
	return (path);
}

/* Gets the value of an environment variable. */
char	*get_env_value(char *key, t_env *env)
{
	if (!key || !env)
		return (NULL);
	while (env)
	{
		if (!ft_strcmp(key, env->key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

/* Gets the path for execve. */
char	*get_path(char *cmd, t_env *env)
{
	char	*path;
	char	*dir;
	char	*full_path;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path = get_env_value("PATH", env);
	if (!path)
		return (NULL);
	dir = ft_strtok(path, ":");
	while (dir)
	{
		full_path = join_path(dir, cmd);
		if (is_executable(full_path))
			return (full_path);
		free(full_path);
		dir = ft_strtok(NULL, ":");
	}
	return (NULL);
}

/* Converts the env list to an array of char for the execve function. */
char	**env_to_array(t_env *env)
{
	int		c;
	char	**array;
	t_env	*tmp;

	c = 0;
	tmp = env;
	while (tmp && ++c)
		tmp = tmp->next;
	array = malloc(sizeof(char *) * (c + 1));
	if (!array)
		return (NULL);
	c = 0;
	tmp = env;
	while (tmp)
	{
		array[c] = ft_strjoin(tmp->key, "=");
		array[c] = ft_strjoin(array[c], tmp->value);
		tmp = tmp->next;
		c++;
	}
	array[c] = NULL;
	return (array);
}
