/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:02:14 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/31 00:16:15 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_isdigit(int a)
{
	if (a > 9)
	{
		ft_isdigit(a / 10);
		ft_isdigit(a % 10);
	}
	return (a);
}

static int	ft_whitespaces(const char *c)
{
	int	i;

	i = 0;
	while (c[i] == 32 || c[i] == '\t' || c[i] == '\n'
		|| c[i] == '\v' || c[i] == '\f' || c[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nr;
	int	sign;

	nr = 0;
	i = ft_whitespaces(str);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nr = nr * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		nr = nr * -1;
	return (nr);
}
