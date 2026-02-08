/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancanale <antonioayr.94@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/08 17:09:32 by ancanale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_camera_north(t_game *game)
{
	game->cam.dir_x = 0;
	game->cam.dir_y = -1;
	game->cam.plane_x = 0.66;
	game->cam.plane_y = 0;
}

static void	set_camera_south(t_game *game)
{
	game->cam.dir_x = 0;
	game->cam.dir_y = 1;
	game->cam.plane_x = -0.66;
	game->cam.plane_y = 0;
}

static void	set_camera_east(t_game *game)
{
	game->cam.dir_x = 1;
	game->cam.dir_y = 0;
	game->cam.plane_x = 0;
	game->cam.plane_y = 0.66;
}

static void	set_camera_west(t_game *game)
{
	game->cam.dir_x = -1;
	game->cam.dir_y = 0;
	game->cam.plane_x = 0;
	game->cam.plane_y = -0.66;
}

void	init_camera(t_game *game)
{
	game->cam.pos_x = game->scene.player.x + 0.5;
	game->cam.pos_y = game->scene.player.y + 0.5;
	if (game->scene.player.dir == 'N')
		set_camera_north(game);
	else if (game->scene.player.dir == 'S')
		set_camera_south(game);
	else if (game->scene.player.dir == 'E')
		set_camera_east(game);
	else if (game->scene.player.dir == 'W')
		set_camera_west(game);
}
