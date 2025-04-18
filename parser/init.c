/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:32:07 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/04 15:35:24 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* The init_env function initializes a linked list of environment variables. */
// void	init_env(t_env **env, char **envp)
// {
// 	t_env	*new_node;
// 	char	*key;
// 	char	*dup;

// 	while (*envp)
// 	{
// 		dup = ft_strdup(*envp);
// 		key = ft_strtok(dup, "=");
// 		if (key)
// 		{
// 			new_node = malloc(sizeof(t_env));
// 			if (!new_node)
// 				perr_exit("malloc new_node failed");
// 			new_node->key = key;
// 			new_node->value = ft_strtok(NULL, "=");
// 			new_node->next = *env;
// 			*env = new_node;
// 		}
// 		free(dup);
// 		envp++;
// 	}
// }

/* The init_env function initializes a linked list of environment variables. */
void	init_env(t_env **env, char **envp)
{
    t_env	*new_node;
    char	*key;
    char	*value;
    char	*equal_sign;

    while (*envp)
    {
        equal_sign = strchr(*envp, '=');
        if (equal_sign)
        {
            key = strndup(*envp, equal_sign - *envp);
            value = strdup(equal_sign + 1);
            new_node = malloc(sizeof(t_env));
            if (!new_node || !key || !value)
                perr_exit("malloc failed");
            new_node->key = key;
            new_node->value = value;
            new_node->next = *env;
            *env = new_node;
        }
        envp++;
    }
}