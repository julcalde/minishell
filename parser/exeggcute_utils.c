/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeggcute_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:48:27 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/25 18:34:09 by julcalde         ###   ########.fr       */
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

/* Gets the path for execve. */
char	*get_path(char *cmd, t_env *env)
{
	char	*path;
	char	*dir;
	char	*full_path;
	char	*path_copy;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = ft_strdup(path);
	dir = ft_strtok(path_copy, ":");
	while (dir)
	{
		full_path = join_path(dir, cmd);
		if (is_executable(full_path))
			return (free(path_copy), full_path);
		free(full_path);
		dir = ft_strtok(NULL, ":");
	}
	free(path_copy);
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
