/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:25:47 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:42:15 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  strchr() function returns a pointer to the first occurrence of the
       character c in the string s.*/
char	*ft_strchr(const char *s, int c)
{
	const char	*p;

	c = c % 256;
	p = s;
	while (*p != c && *p != '\0')
		p++;
	if (c != '\0' && *p == '\0')
		return (NULL);
	return ((char *)p);
}
