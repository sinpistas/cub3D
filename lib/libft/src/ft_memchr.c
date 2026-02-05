/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:55:18 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:42:21 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  memchr()  function  scans  the  initial  n  bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the bytes of the
       memory area pointed to by s are interpreted as unsigned char.*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		i++;
		p++;
	}
	return (NULL);
}
