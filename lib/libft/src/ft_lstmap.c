/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:53:04 by apestana          #+#    #+#             */
/*   Updated: 2023/09/15 18:15:07 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_pre_clear(t_list *lst, void (*del)(void *), void *data)
{
	del(data);
	ft_lstclear(&lst, del);
	return (NULL);
}

/*Iterates the list 'lst' and applies the function 'f' to it
content of each node. Create a resulting list
of the correct and successive application of the function
'f' over each node. The 'del' function is used
to delete the contents of a node, if you do lack.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_aux;
	t_list	*aux;
	void	*data;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	aux = lst;
	data = f(aux->content);
	new_lst = ft_lstnew(data);
	if (new_lst == NULL)
		return (ft_pre_clear(new_lst, del, data));
	new_aux = new_lst;
	while (aux->next != NULL)
	{
		data = f(aux->next->content);
		new_aux->next = ft_lstnew(data);
		if (new_aux->next == NULL)
		{
			return (ft_pre_clear(new_lst, del, data));
		}
		new_aux = new_aux->next;
		aux = aux->next;
	}
	return (new_lst);
}
