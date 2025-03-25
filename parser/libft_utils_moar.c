/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_moar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:10:28 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/25 18:27:00 by julcalde         ###   ########.fr       */
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

/* Check 'man strjoin' */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;
	size_t	c1;
	size_t	c2;

	c1 = 0;
	c2 = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[c1])
		s3[c2++] = s1[c1++];
	c1 = 0;
	while (s2[c1])
		s3[c2++] = s2[c1++];
	s3[c2] = '\0';
	return (s3);
}
