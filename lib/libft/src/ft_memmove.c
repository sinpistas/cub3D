/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:54:52 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:42:17 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The functions moves blocks of memory. We have here 4 cases:
 - case 1: The two pointers are the same pointer or len is zero.
 - case 2: (overlap) dst is greater in the memory struct than src and the 
  distance is less than len. We have to copy in reverse order to avoid overlap.
 - case 3: (overlap) src is greater in the memory struct than dst and the
  distance is less than len. We have to copy forwards to avoid overlap.
 - case 4: the distance is greater than len. We use case 3.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*s_end;
	char		*d_end;

	d = dst;
	s = src;
	if (dst == src || len == 0)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		s_end = (char *)s + (len - 1);
		d_end = d + (len - 1);
		while (len--)
			*d_end-- = *s_end--;
	}
	return (dst);
}
