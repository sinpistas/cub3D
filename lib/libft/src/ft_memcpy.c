/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:34:18 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:42:18 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p_dst;
	const char	*p_src;
	size_t		i;

	if (dst == src || n == 0)
		return (dst);
	p_dst = (char *)dst;
	p_src = (const char *)src;
	i = 0;
	while (i < n)
	{
		*(p_dst) = *(p_src);
		p_dst++;
		p_src++;
		i++;
	}
	return (dst);
}
