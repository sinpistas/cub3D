/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:17:56 by apestana          #+#    #+#             */
/*   Updated: 2023/09/13 00:19:11 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function convert lowercase letters to uppercase*/
int	ft_toupper(int c)
{
	int	res;

	res = c;
	if (c >= 'a' && c <= 'z')
	{
		res = c - ('a' - 'A');
	}
	return (res);
}
