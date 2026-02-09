/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/09 13:58:22 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Configure camera direction/plane for a North-facing player.
*/
static void	set_camera_north(t_game *game)
{
	game->cam.dir_x = 0;
	game->cam.dir_y = -1;
	game->cam.plane_x = 0.66;
	game->cam.plane_y = 0;
}

/*
** Configure camera direction/plane for a South-facing player.
*/
static void	set_camera_south(t_game *game)
{
	game->cam.dir_x = 0;
	game->cam.dir_y = 1;
	game->cam.plane_x = -0.66;
	game->cam.plane_y = 0;
}

/*
** Configure camera direction/plane for an East-facing player.
*/
static void	set_camera_east(t_game *game)
{
	game->cam.dir_x = 1;
	game->cam.dir_y = 0;
	game->cam.plane_x = 0;
	game->cam.plane_y = 0.66;
}

/*
** Configure camera direction/plane for a West-facing player.
*/
static void	set_camera_west(t_game *game)
{
	game->cam.dir_x = -1;
	game->cam.dir_y = 0;
	game->cam.plane_x = 0;
	game->cam.plane_y = -0.66;
}

/*
** Initialize camera position and orientation from the parsed scene player.
** Player grid coords are centered in the tile by adding 0.5.
*/
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
