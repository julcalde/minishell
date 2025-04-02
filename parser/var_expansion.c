/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:58:40 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 22:36:00 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	extract_var_name(char *str)
{
	int		len;
	char	*name;

	len = 1;
	if (str[len] == '?')
		return (ft_strdup("?"));
	while (is_alnum(str[len]))
		len++;
	name = ft_substr(str, 1, len - 1);
	return (name);
}

static char	*get_var_value(char *var_name, t_env *env)
{
	t_env	*tmp;

	if (!ft_strcmp(var_name, "?"))
		return (ft_strdup("0)"));
	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, var_name))
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

/* Expands environment variables in a token. */
char	*expand_var(char *token, t_env *env)
{
	char	*result;
	char	*var_name;
	char	*var_value;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (token[i])
	{
		if (token[i] == '$' && (is_alnum(token[i + 1]) || token[i + 1] == '?'))
		{
			var_name = extract_var_name(&token[i]);
			var_value = get_var_value(var_name, env);
			result = ft_strjoin_free(result, var_value);
			i += ft_strlen(var_name) + 1;
			free(var_name);
			free(var_value);
		}
		else
			result = ft_append_char(result, token[i++]);
	}
	free(token);
	return (result);
}
