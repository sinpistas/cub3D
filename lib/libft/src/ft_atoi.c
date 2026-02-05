/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:01:02 by apestana          #+#    #+#             */
/*   Updated: 2023/09/13 22:28:44 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, int *sign)
{
	int	state;

	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
	{
		state = 1;
	}
	else if (c == '-' || c == '+' )
	{
		state = 2;
		if (c == '-')
			*sign = (*sign) * (-1);
	}
	else if (c >= '0' && c <= '9')
		state = 3;
	else
		state = 4;
	return (state);
}

static int	add(int res, char c, int sign)
{
	int	sol;

	if (sign == -1)
		sol = res * 10 - (c - '0');
	else
		sol = res * 10 + c - '0';
	return (sol);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	state;
	int	sign;
	int	start;

	sign = 1;
	i = -1;
	res = 0;
	start = 0;
	while (str[++i] != '\0')
	{
		state = ft_check(str[i], &sign);
		if (start <= state && state != 4)
			start = state;
		else
			break ;
		if (start == 3)
			res = add(res, str[i], sign);
		if (start == 2)
			start = 3;
	}
	return (res);
}
