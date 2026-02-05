/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:11:00 by apestana          #+#    #+#             */
/*   Updated: 2025/03/17 03:21:30 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_get_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_get_strlcpy(char *dst, const char *src, size_t dstsize)
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

char	*ft_get_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	real_len;

	real_len = ft_get_strlen(s);
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
	ft_get_strlcpy(p, s + start, len + 1);
	return (p);
}

/*This functions Reserves (with malloc) and returns a new string, formed 
by the concatenation of 's1' and 's2*/
char	*ft_get_strjoin(char *s1, char *s2)
{
	int		size;
	char	*res_string;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL)
	{
		s1 = malloc(1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	size = ft_get_strlen(s1) + ft_get_strlen(s2);
	res_string = (char *)malloc((size + 1) * sizeof(char));
	if (res_string == NULL)
		return (ft_get_memory_liberator(&s1));
	while (s1[++i] != '\0')
		res_string[i] = s1[i];
	free(s1);
	while (s2[++j] != '\0')
		res_string[i++] = s2[j];
	res_string[size] = '\0';
	return (res_string);
}

/*The  strchr() function returns a pointer to the first occurrence of the
       character c in the string s.*/
char	*ft_get_strchr(const char *s, int c)
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
