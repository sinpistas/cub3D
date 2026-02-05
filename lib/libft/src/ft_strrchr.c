/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:03:29 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:43:17 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strrchr() function returns a pointer to the last  occurrence  of  the
    character c in the string s.*/
char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	const char	*last;
	char		found;

	c = c % 256;
	p = s;
	found = 0;
	while (*p != '\0')
	{
		if (*p == c)
		{
			last = p;
			found = 1;
		}
		p++;
	}
	if (found == 1)
		return ((char *)last);
	if (c != '\0' && *p == '\0')
		return (NULL);
	return ((char *)p);
}
