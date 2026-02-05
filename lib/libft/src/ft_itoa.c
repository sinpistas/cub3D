/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:48:08 by apestana          #+#    #+#             */
/*   Updated: 2023/09/15 17:58:01 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse(char	*buff, int len)
{
	int		i;
	char	aux;

	i = 0;
	while (i < len / 2)
	{
		aux = buff[len - 1 - i];
		buff[len - 1 - i] = buff[i];
		buff[i] = aux;
		i++;
	}
}

/*This function converts an interger to string*/
char	*ft_itoa(int n)
{
	char			buffer[12];
	long long int	ln;
	int				i;

	i = 0;
	ln = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (ln < 0)
		ln = -ln;
	if (ln == 0)
		buffer[i++] = '0';
	while (ln != 0)
	{
		buffer[i] = (ln % 10) + '0';
		ln = ln / 10;
		i++;
	}
	if (n < 0)
		buffer[i++] = '-';
	buffer[i] = '\0';
	ft_reverse(buffer, i);
	return (ft_strdup((const char *)buffer));
}
