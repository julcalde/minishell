/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:46:23 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/28 15:53:21 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check 'man strlen' */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* Check 'man strdup' */
char	*ft_strdup(const char *s1)
{
	char	*dupe;
	int		c;
	size_t	i;

	if (!s1)
		return (NULL);
	c = 0;
	i = ft_strlen(s1);
	dupe = malloc(sizeof(char) * (i + 1));
	if (!dupe)
		perr_exit("duplication failed");
	while (s1[c])
	{
		dupe[c] = s1[c];
		c++;
	}
	dupe[c] = '\0';
	return (dupe);
}

/* Check 'man strcmp' */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

/* Check 'man strchr' */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}

/* Check 'man strtok' */
char	*ft_strtok(char *str, const char *delim)
{
	static char	*save_p;
	char		*start;
	char		*end;

	if (str)
		save_p = str;
	if (!save_p || !*save_p)
		return (NULL);
	start = save_p;
	while (*start && ft_strchr(delim, *start))
		start++;
	if (!*start)
		return (save_p = NULL, NULL);
	end = start;
	while (*end && !ft_strchr(delim, *end))
		end++;
	if (*end)
	{
		*end = '\0';
		save_p = end + 1;
	}
	else
		save_p = end;
	return (start);
}
