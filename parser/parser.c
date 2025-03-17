/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:39:47 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/17 17:41:17 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast	*parse_input(char **tokens)
{
	t_ast	*ast;

	ast = malloc(sizeof(t_ast));
	if (!ast)
		perr_exit("malloc ast failed\n");
}
