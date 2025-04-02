/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_moaar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:56:36 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 21:00:06 by julcalde         ###   ########.fr       */
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
