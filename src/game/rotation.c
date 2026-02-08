/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancanale <antonioayr.94@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/08 17:10:21 by ancanale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->cam.dir_x;
	game->cam.dir_x = game->cam.dir_x * cos(-ROT_SPEED)
		- game->cam.dir_y * sin(-ROT_SPEED);
	game->cam.dir_y = old_dir_x * sin(-ROT_SPEED)
		+ game->cam.dir_y * cos(-ROT_SPEED);
	old_plane_x = game->cam.plane_x;
	game->cam.plane_x = game->cam.plane_x * cos(-ROT_SPEED)
		- game->cam.plane_y * sin(-ROT_SPEED);
	game->cam.plane_y = old_plane_x * sin(-ROT_SPEED)
		+ game->cam.plane_y * cos(-ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->cam.dir_x;
	game->cam.dir_x = game->cam.dir_x * cos(ROT_SPEED)
		- game->cam.dir_y * sin(ROT_SPEED);
	game->cam.dir_y = old_dir_x * sin(ROT_SPEED)
		+ game->cam.dir_y * cos(ROT_SPEED);
	old_plane_x = game->cam.plane_x;
	game->cam.plane_x = game->cam.plane_x * cos(ROT_SPEED)
		- game->cam.plane_y * sin(ROT_SPEED);
	game->cam.plane_y = old_plane_x * sin(ROT_SPEED)
		+ game->cam.plane_y * cos(ROT_SPEED);
}
