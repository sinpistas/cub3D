/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:23:19 by apestana          #+#    #+#             */
/*   Updated: 2023/09/13 00:19:07 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function converts uppercase letters to lowercase*/
int	ft_tolower(int c)
{
	int	res;

	res = c;
	if (c >= 'A' && c <= 'Z')
	{
		res = c + ('a' - 'A');
	}
	return (res);
}
