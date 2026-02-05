/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:37:47 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:33:12 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This functions copy src on dst. Always ends up setting 0 at the end 
  of the string. 
  Use: always set len+1 in dstsize so the the string is saved correctly. */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	else if (dstsize > 0)
	{
		dst[i - 1] = '\0';
	}
	while (src[j] != '\0')
		j++;
	return (j);
}
