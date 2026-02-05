/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:30:53 by apestana          #+#    #+#             */
/*   Updated: 2023/09/15 15:09:01 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Delete and free the given 'lst' node and all
consecutive of that node, using the function
'del' and free(3). In the end, the pointer to 
the list must be NULL.*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (lst != NULL && del != NULL)
	{
		while (*lst != NULL)
		{
			aux = *lst;
			(*lst) = aux->next;
			ft_lstdelone(aux, del);
		}
	}
}
