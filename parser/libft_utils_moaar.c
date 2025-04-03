/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_moaar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:56:36 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/03 19:43:49 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check 'man substr' */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	max_len;

	if (!s)
		return (NULL);
	max_len = ft_strlen(s);
	if (start >= max_len)
		len = max_len;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	return (sub);
}

char	*ft_itoa(int n)
{
	char	buf[12];
	int		i;
	int		sign;

	sign = (n < 0);
	i = 11;
	buf[i--] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		if (sign)
			buf[i--] = '0' - (n % 10) * -1;
		else
			buf[i--] = '0' + (n % 10);
		n /= 10;
	}
	if (sign)
		buf[i--] = '-';
	return (ft_strdup(buf + i + 1));
}
