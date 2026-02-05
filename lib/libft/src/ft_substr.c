/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:58:59 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:44:37 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function has 3 cases:
	1: start is bigger than s size
	2: the bytes to copy from s are less than len
	3: len are smaller than s size - start
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	real_len;

	real_len = ft_strlen(s);
	if (start > real_len)
		p = malloc(sizeof(char) * 1);
	else if (real_len - start < (unsigned int)len)
	{
		p = malloc(sizeof(char) * (real_len - start + 1));
		len = (size_t)(real_len - start);
	}
	else
		p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	else if (len == 0 || start > real_len)
	{
		p[0] = '\0';
		return (p);
	}
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
