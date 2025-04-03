/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:44:08 by julcalde          #+#    #+#             */
/*   Updated: 2025/04/03 15:56:44 by julcalde         ###   ########.fr       */
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
	return (type == T_PIPE || is_redirect(type));
}
