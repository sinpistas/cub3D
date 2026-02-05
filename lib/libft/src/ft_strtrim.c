/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:46:30 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 18:46:35 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_limits(char const *s1, char const *set, int *start, int *end)
{
	int	i;

	i = -1;
	*start = 0;
	*end = ft_strlen(s1) - 1;
	while (s1[++i] != '\0')
	{
		if (ft_strchr(set, s1[i]) != NULL)
			(*start)++;
		else
			break ;
	}
	i = *end;
	while (i >= 0 && i > *start)
	{
		if (ft_strchr(set, s1[i]) != NULL)
			(*end)--;
		else
			break ;
		i--;
	}
}

/*This function removes all characters from the string 'set' from 
	the beginning and from the end of 's1', until it finds a 
	character not belonging to 'set'. The resulting string is 
	returned with a reservation of malloc.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*final;
	int		start;
	int		end;
	int		j;

	if (set == NULL || *set == '\0')
		return (ft_strdup(s1));
	p = malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (p == NULL)
		return (p);
	ft_limits(s1, set, &start, &end);
	j = 0;
	while (start + j <= end)
	{
		p[j] = s1[start + j];
		j++;
	}
	p[j] = '\0';
	final = ft_strdup((const char *)p);
	free(p);
	return (final);
}
