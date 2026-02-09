/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/09 13:58:29 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Rotate view to the left by ROT_SPEED (direction and camera plane).
*/
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

/*
** Rotate view to the right by ROT_SPEED (direction and camera plane).
*/
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
