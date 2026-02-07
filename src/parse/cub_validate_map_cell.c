/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validate_map_cell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:18:24 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 18:25:51 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_is_allowed(char c);
static int	cub_is_walkable(char c);
static int	cub_cell_is_open(t_scene *sc, int y, int x);

/*
** Validate one map cell: allowed chars + open-to-void checks for walkable tiles.
** Returns 0 if OK, 1 if invalid.
*/
int	cub_validate_cell(t_scene *sc, int y, int x)
{
	char	c;

	c = sc->map[y][x];
	if (!cub_is_allowed(c))
		return (1);
	if (cub_is_walkable(c) && cub_cell_is_open(sc, y, x))
		return (1);
	return (0);
}

/*
** Check if a map character is allowed.
**
** Valid characters are spaces, walls, empty tiles,
** and player directions.
*/
static int	cub_is_allowed(char c)
{
	if (c == ' ' || c == '0' || c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
** Check if a map character represents a walkable tile.
**
** Walkable tiles include empty spaces and player positions.
*/
static int	cub_is_walkable(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
** Check if a walkable cell is open to the outside.
**
** A cell is considered open if it touches the map border
** or a space character.
*/
static int	cub_cell_is_open(t_scene *sc, int y, int x)
{
	if (y == 0 || x == 0 || y == sc->map_h - 1 || x == sc->map_w - 1)
		return (1);
	if (sc->map[y - 1][x] == ' ' || sc->map[y + 1][x] == ' ')
		return (1);
	if (sc->map[y][x - 1] == ' ' || sc->map[y][x + 1] == ' ')
		return (1);
	return (0);
}
