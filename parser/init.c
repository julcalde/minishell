/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:32:07 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/02 15:33:06 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* The init_env function initializes a linked list of environment variables by:
** parsing an array of strings into key-value pairs.
** dynamically allocating memory for each node.
*/
void	init_env(t_env **env, char **envp)
{
	t_env	*new_node;
	char	*key;
	char	*value;

	while (*envp)
	{
		key = ft_strtok(*envp, "=");
		value = ft_strtok(NULL, "=");
		new_node = malloc(sizeof(t_env));
		if (!new_node)
			perr_exit("malloc new_node failed");
		new_node->key = ft_strdup(key);
		new_node->value = ft_strdup(value);
		new_node->next = *env;
		*env = new_node;
		envp++;
	}
}
