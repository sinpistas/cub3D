/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:05:34 by apestana          #+#    #+#             */
/*   Updated: 2026/02/08 12:40:16 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/*
** Free a pointer and set it to NULL.
**
** This helper prevents double free and dangling pointers.
*/
void	cub_xfree(void **p)
{
	if (!p || !*p)
		return ;
	free(*p);
	*p = NULL;
}

/*
** Free a NULL-terminated array of strings and set it to NULL.
**
** Safely frees each entry, then the array itself.
*/
void	cub_free_strv(char ***p)
{
	int		i;
	char	**v;

	if (!p || !*p)
		return ;
	v = *p;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
	*p = NULL;
}
