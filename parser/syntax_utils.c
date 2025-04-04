/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:44:08 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:34 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Returns 1 if the token type is a redirection, 0 otherwise */
int	is_redirect_type(t_token_type type)
{
	return (type == T_REDIRECT_IN || type == T_REDIRECT_OUT || \
			type == T_REDIRECT_APPEND);
}

/* Returns 1 if the token type is a pipe or a redirection, 0 otherwise */
int	is_operator_type(t_token_type type)
{
	return (type == T_PIPE || is_redirect_type(type));
}
