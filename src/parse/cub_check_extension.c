/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:33:38 by apestana          #+#    #+#             */
/*   Updated: 2026/02/08 13:05:42 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Check that the given path has the expected ".cub" extension.
**
** Returns 0 if valid, 1 on error.
*/
int	cub_check_extension(const char *path)
{
	int	len;

	if (!path)
		return (1);
	len = ft_strlen(path);
	if (len < 5)
		return (1);
	if (path[len - 4] != '.'
		|| path[len - 3] != 'c'
		|| path[len - 2] != 'u'
		|| path[len - 1] != 'b')
		return (1);
	return (0);
}
