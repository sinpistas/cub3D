/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:11:18 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 17:44:53 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This functions Reserves (with malloc) and returns a new string, formed 
by the concatenation of 's1' and 's2*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	len1;
	size_t	len2;
	char	*res_string;

	res_string = NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	size = len1 + len2;
	res_string = (char *)malloc((size + 1) * sizeof(char));
	if (res_string == NULL)
		return (res_string);
	res_string[0] = '\0';
	if (size > 0)
	{
		ft_strlcpy(res_string, s1, len1 + 1);
		ft_strlcat(res_string, s2, size + 1);
	}
	return (res_string);
}
