/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:46:23 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/17 17:14:50 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
		perr_exit("malloc failed\n");
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
