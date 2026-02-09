/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/09 13:58:26 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Return true if a map cell is walkable for the player.
*/
int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/*
** Move forward if the target cell is within bounds and walkable.
*/
void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	int		ix;
	int		iy;

	new_x = game->cam.pos_x + game->cam.dir_x * MOVE_SPEED;
	new_y = game->cam.pos_y + game->cam.dir_y * MOVE_SPEED;
	ix = (int)new_x;
	iy = (int)new_y;
	if (in_bounds(game, ix, iy) && is_walkable(game->scene.map[iy][ix]))
	{
		game->cam.pos_x = new_x;
		game->cam.pos_y = new_y;
	}
}

/*
** Move backward if the target cell is within bounds and walkable.
*/
void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	int		ix;
	int		iy;

	new_x = game->cam.pos_x - game->cam.dir_x * MOVE_SPEED;
	new_y = game->cam.pos_y - game->cam.dir_y * MOVE_SPEED;
	ix = (int)new_x;
	iy = (int)new_y;
	if (in_bounds(game, ix, iy)
		&& is_walkable(game->scene.map[(int)new_y][(int)new_x]))
	{
		game->cam.pos_x = new_x;
		game->cam.pos_y = new_y;
	}
}

/*
** Strafe left if the target cell is within bounds and walkable.
*/
void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	int		ix;
	int		iy;

	new_x = game->cam.pos_x - game->cam.plane_x * MOVE_SPEED;
	new_y = game->cam.pos_y - game->cam.plane_y * MOVE_SPEED;
	ix = (int)new_x;
	iy = (int)new_y;
	if (in_bounds(game, ix, iy)
		&& is_walkable(game->scene.map[(int)new_y][(int)new_x]))
	{
		game->cam.pos_x = new_x;
		game->cam.pos_y = new_y;
	}
}

/*
** Strafe right if the target cell is within bounds and walkable.
*/
void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	int		ix;
	int		iy;

	new_x = game->cam.pos_x + game->cam.plane_x * MOVE_SPEED;
	new_y = game->cam.pos_y + game->cam.plane_y * MOVE_SPEED;
	ix = (int)new_x;
	iy = (int)new_y;
	if (in_bounds(game, ix, iy)
		&& is_walkable(game->scene.map[(int)new_y][(int)new_x]))
	{
		game->cam.pos_x = new_x;
		game->cam.pos_y = new_y;
	}
}
