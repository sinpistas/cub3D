/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:18:38 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 21:24:17 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Send the character 'c' to the file descriptor
specified.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
