/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:31:03 by apestana          #+#    #+#             */
/*   Updated: 2023/09/15 12:35:46 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This functions returns the last node in the list*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	if (aux == NULL)
		return (aux);
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	return (aux);
}
