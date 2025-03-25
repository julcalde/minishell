/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_moar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:10:28 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/25 17:12:04 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check 'man strlcpy' */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/* Check 'man strlcat' */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	n;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	n = dstsize - dstlen - 1;
	if (n == 0)
		return (ft_strlen(src) + dstsize - 1);
	while (src[i] != '\0' && n != 0)
	{
		dst[dstlen + i] = src[i];
		i++;
		n--;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
