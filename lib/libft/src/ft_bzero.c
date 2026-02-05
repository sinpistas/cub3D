/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:29:50 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:34:42 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  bzero() function erases the data in the n bytes of the memory start‐
       ing at the location pointed to by s, by writing zeros  (bytes  containing
       '\0') to that area.*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		*p = 0;
		p++;
		i++;
	}
}
