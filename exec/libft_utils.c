/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:46:23 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/21 00:46:33 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dupe;
	int		c;
	size_t	i;

	c = 0;
	i = ft_strlen(s1);
	dupe = malloc(sizeof(char) * (i + 1));
	if (!dupe)
		return (NULL);
	while (s1[c])
	{
		dupe[c] = s1[c];
		c++;
	}
	dupe[c] = '\0';
	return (dupe);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*s3;

	n = 0;
	i = 0;
	s3 = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		s3[i] = s2[n];
		n++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}