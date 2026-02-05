/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:12:43 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:42:31 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Find the end of dst and adjust bytes left but don't go past end.
   Use: dstsize need to be size + 1 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*p_dst;
	const char	*p_src;
	size_t		n;
	size_t		dlen;

	p_dst = dst;
	p_src = src;
	n = 0;
	while (n++ < dstsize && *p_dst != '\0')
		p_dst++;
	dlen = p_dst - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(p_src));
	while (*p_src != '\0')
	{
		if (n != 1)
		{
			*p_dst++ = *p_src;
			n--;
		}
		p_src++;
	}
	*p_dst = '\0';
	return (dlen + (p_src - src));
}
