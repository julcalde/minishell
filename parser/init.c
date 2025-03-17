/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:32:07 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/17 16:33:05 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_env(t_env **env, char **envp)
{
	t_env	*new_node;
	char	*key;
	char	*value;

	while (*envp)
	{
		key = strtok(*envp, " ");
		value = strtok(NULL, " ");
		new_node = malloc(sizeof(t_env));
		if (!new_node)
			perr_exit("$fildirame$> malloc failed\n");
		new_node->key = ft_strdup(key);
		new_node->value = ft_strdup(value);
		new_node->next = *env;
		*env = new_node;
		envp++;
	}
}
