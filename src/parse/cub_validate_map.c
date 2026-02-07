/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:09:05 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 18:25:28 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_set_player(t_scene *sc, int y, int x, char c);

/*
** Validate the final map structure.
**
** Iterates through the map to ensure allowed characters,
** exactly one player, and a closed map.
**
** Returns 0 if valid, 1 on error.
*/
int	cub_validate_map(t_scene *sc)
{
	int		x;
	int		y;

	y = 0;
	while (y < sc->map_h)
	{
		x = 0;
		while (x < sc->map_w)
		{
			if (cub_validate_cell(sc, y, x) != 0)
				return (1);
			if (cub_set_player(sc, y, x, sc->map[y][x]) != 0)
				return (1);
			x++;
		}
		y++;
	}
	return (!sc->has_player);
}

/*
** Register the player position and direction.
**
** Ensures that only one player is defined in the map.
**
** Returns 0 on success, 1 if a player already exists.
*/
static int	cub_set_player(t_scene *sc, int y, int x, char c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	if (sc->has_player)
		return (1);
	sc->has_player = true;
	sc->player.x = x;
	sc->player.y = y;
	sc->player.dir = c;
	return (0);
}
