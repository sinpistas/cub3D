/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:26:53 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:44:25 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	finder(const char *haystack, const char *needle, int pos
	, size_t len)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (res == 0 && haystack[pos + i] != '\0' && (pos + i) < (int)len)
	{
		if (needle[i] == '\0')
			res = 1;
		else if (haystack[pos + i] != needle[i])
			res = -1;
		i++;
	}
	if (res == 0 && needle[i] == '\0')
		res = 1;
	return (res);
}

/*The strnstr() function locates the first occurrence of the null-
	terminated string little in the string big, where not more than
	len characters are searched.  Characters that appear after a 
	‘\0’ character are not searched.*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	char	*p;

	p = (char *)haystack;
	i = 0;
	if (*needle == '\0')
		return (p);
	else if (len == 0)
		return (NULL);
	else if ((int)len < 0)
		len = (size_t)ft_strlen(haystack);
	while (haystack[i] != '\0' && i < (int)len)
	{
		if (haystack[i] == needle[0])
		{
			if (finder(haystack, needle, i, len) == 1)
				return (p);
		}
		p++;
		i++;
	}
	return (0);
}
