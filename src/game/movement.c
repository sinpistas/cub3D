/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancanale <ancanale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/08 13:00:00 by ancanale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cam.pos_x + game->cam.dir_x * MOVE_SPEED;
	new_y = game->cam.pos_y + game->cam.dir_y * MOVE_SPEED;
	if (is_walkable(game->scene.map[(int)new_y][(int)new_x]))
	{
		game->cam.pos_x = new_x;
		game->cam.pos_y = new_y;
	}
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cam.pos_x - game->cam.dir_x * MOVE_SPEED;
	new_y = game->cam.pos_y - game->cam.dir_y * MOVE_SPEED;
	if (is_walkable(game->scene.map[(int)new_y][(int)new_x]))
	{
		game->cam.pos_x = new_x;
		game->cam.pos_y = new_y;
	}
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cam.pos_x - game->cam.plane_x * MOVE_SPEED;
	new_y = game->cam.pos_y - game->cam.plane_y * MOVE_SPEED;
	if (is_walkable(game->scene.map[(int)new_y][(int)new_x]))
	{
		game->cam.pos_x = new_x;
		game->cam.pos_y = new_y;
	}
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cam.pos_x + game->cam.plane_x * MOVE_SPEED;
	new_y = game->cam.pos_y + game->cam.plane_y * MOVE_SPEED;
	if (is_walkable(game->scene.map[(int)new_y][(int)new_x]))
	{
		game->cam.pos_x = new_x;
		game->cam.pos_y = new_y;
	}
}
