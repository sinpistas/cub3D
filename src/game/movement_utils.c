/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:07:24 by apestana          #+#    #+#             */
/*   Updated: 2026/02/09 13:58:26 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Check if a (x, y) tile coordinate is inside the map dimensions.
*/
int	in_bounds(t_game *g, int x, int y)
{
	if (y < 0 || y >= g->scene.map_h)
		return (0);
	if (x < 0 || x >= g->scene.map_w)
		return (0);
	return (1);
}
