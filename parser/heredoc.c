/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:02:17 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/03 20:02:02 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*generate_filename(void)
{
	static int	i;
	char		*num;
	char		*name;

	i = 0;
	num = ft_itoa(i++);
	name = ft_strjoin("/tmp/heredoc_file_", num);
	free(num);
	return (name);
}

static int	read_heredoc_input(int fd, char *delim, t_env *env)
{
	char	*line;
	char	*expanded;

	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, delim))
			break ;
		expanded = expand_var(line, env);
		write(fd, expanded, ft_strlen(expanded));
		write(fd, "\n", 1);
		free(line);
		free(expanded);
	}
	if (line)
		free(line);
	return (0);
}

int	handle_heredoc(char *delim, t_ast *ast, t_env *env)
{
	int		fd;
	char	*filename;

	filename = generate_filename();
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (free(filename), -1);
	if (read_heredoc_input(fd, delim, env) == -1)
		return (close(fd), free(filename), -1);
	close(fd);
	ast->heredoc_fd = open(filename, O_RDONLY);
	free(filename);
	return (fd);
}
