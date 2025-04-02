/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:58:40 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 21:33:05 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*expand_var(char *token, t_env *env)
{
	char	*result;
	char	*tmp;
	int		i;

	result = ft_strdup("");
	i = -1;
	while (token[++i])
	{
		if (token[i] == '$' && (is_alnum(token[i + 1]) || token[i + 1] == '?'))
		{
			tmp = get_var
		}
	}
}
