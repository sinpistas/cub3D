/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:31:26 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 23:54:23 by apestana         ###   ########.fr       */
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

/*Put the number n to the file descriptor fd*/
void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[11];
	long long int	ln;
	int				i;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		i = 0;
		ln = n;
		if (ln < 0)
			ln = -ln;
		if (ln == 0)
			buffer[i++] = '0';
		while (ln != 0)
		{
			buffer[i++] = (ln % 10) + '0';
			ln = ln / 10;
		}
		if (n < 0)
			buffer[i++] = '-';
		buffer[i] = '\0';
		ft_reverse(buffer, i);
		ft_putstr_fd(buffer, fd);
	}
}
