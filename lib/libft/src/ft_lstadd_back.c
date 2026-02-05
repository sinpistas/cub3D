/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:55:01 by apestana          #+#    #+#             */
/*   Updated: 2023/09/15 13:16:10 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function adds a 'new' node at the end of 'lst'*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = *lst;
	if (*lst == NULL)
		*lst = new;
	else if (new != NULL)
	{
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = new;
	}
}
