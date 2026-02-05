/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:45:47 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:42:28 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strdup() function allocates sufficient memory for a copy 
	of the string s1, does the copy, and returns a pointer to it.
	The pointer may subsequently be used as an argument to the 
    function free().If insufficient memory is available, NULL 
	is returned and errno is set to ENOMEM.*/
char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	len = ft_strlen(s1) + 1;
	p = (char *)malloc(len);
	if (p != NULL)
	{
		ft_strlcpy(p, s1, len);
	}
	else
		errno = ENOMEM;
	return (p);
}
