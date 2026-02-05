/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:52:50 by apestana          #+#    #+#             */
/*   Updated: 2023/09/14 21:07:25 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*To each character of the string 's', apply the function ’f’ giving as 
	parameters the index of each character within 's' and the address of
	itself character, which can be modified if necessary.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
