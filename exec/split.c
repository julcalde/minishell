/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:30:53 by fefo              #+#    #+#             */
/*   Updated: 2025/04/18 19:31:32 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	ft_free(char **s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		free(s2[i]);
		i++;
	}
	free(s2);
}

static char	**ft_arrayi(char const *s, char c, char **s2)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			s2[j] = malloc(i - start +1);
			if (s2[j] == NULL)
				return (ft_free(s2), NULL);
			s2[j] = ft_memcpy(s2[j], s + start, i - start);
			s2[j][i - start] = '\0';
			j++;
		}
	}
	s2[j] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		counter;
	char	**s2;

	i = 0;
	counter = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (i > 0 && s[i - 1] != c)
				counter++;
		}
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		counter++;
	s2 = (char **)malloc(sizeof(char *) * (counter + 1));
	if (s2 == NULL)
		return (NULL);
	return (ft_arrayi(s, c, s2));
}