/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:25:19 by apestana          #+#    #+#             */
/*   Updated: 2023/09/15 12:46:43 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function counts the number of nodes in a list*/
int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*aux;

	res = 0;
	aux = lst;
	while (aux != NULL)
	{
		aux = aux->next;
		res++;
	}
	return (res);
}
