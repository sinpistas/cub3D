/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:49:55 by apestana          #+#    #+#             */
/*   Updated: 2025/02/05 02:04:57 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns the word len*/
static int	ft_strlen_word(int pos, const char *str, char c)
{
	int	i;

	i = 0;
	while (str[pos] != '\0' && str[pos] != c)
	{
		pos++;
		i++;
	}
	return (i);
}

/*This function count words*/
static int	ft_count_words(const char *str, char c)
{
	int	res;
	int	i;
	int	counting;

	i = 0;
	counting = 1;
	res = 0;
	while (str[i] != '\0')
	{
		if (counting == 1 && str[i] != c)
		{
			counting = 0;
			res++;
		}
		else if (counting == 0 && str[i] == c)
			counting = 1;
		i++;
	}
	return (res);
}

/*This function writes a word using malloc*/
static char	*ft_write_word(const char *str, char c, int *pos)
{
	char	*word;
	int		len;
	int		i;

	len = ft_strlen_word(*pos, str, c);
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[*pos + i];
		i++;
	}
	word[len] = '\0';
	*pos = *pos + i;
	return (word);
}

/*This function free memory in case malloc fails*/
static char	**ft_erase(char **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		words;
	int		j;

	i = 0;
	j = 0;
	words = ft_count_words(s, c);
	p = (char **)malloc((words +1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			p[j] = ft_write_word(s, c, &i);
			if (p[j] == NULL)
				return (ft_erase(p, j));
			j++;
		}
		else
			i++;
	}
	p[j] = NULL;
	return (p);
}
