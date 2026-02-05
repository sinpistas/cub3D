/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:45:03 by apestana          #+#    #+#             */
/*   Updated: 2023/09/15 12:21:13 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function adds a 'new' node at the beginning of 'lst'*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *(lst);
	*lst = new;
}
