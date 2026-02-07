/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:05:34 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 17:31:00 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*
** Free the temporary linked list used to store map lines.
**
** Releases both the strings and the list nodes.
*/
void	cub_free_map_lines(t_mline *lst)
{
	t_mline	*next;

	while (lst)
	{
		next = lst->next;
		free(lst->line);
		free(lst);
		lst = next;
	}
}
