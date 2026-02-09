/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/09 13:58:24 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Convert RGB components to a packed 0xRRGGBB integer.
*/
int	rgb_to_int(t_rgb color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

/*
** Initialize MLX context, create window and backbuffer image.
*/
static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->win)
		return (1);
	game->img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img.img)
		return (1);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	game->img.width = WIN_WIDTH;
	game->img.height = WIN_HEIGHT;
	return (0);
}

/*
** Initialize game runtime from parsed scene (mlx, textures, camera, keys).
*/
int	game_init(t_game *game, t_scene *scene)
{
	ft_memset(game, 0, sizeof(t_game));
	game->scene = *scene;
	game->floor_color = rgb_to_int(scene->floor);
	game->ceiling_color = rgb_to_int(scene->ceiling);
	if (init_mlx(game) != 0)
	{
		printf("Error\nFailed to initialize MLX\n");
		return (1);
	}
	if (load_textures(game) != 0)
	{
		printf("Error\nFailed to load textures\n");
		game_free(game);
		return (1);
	}
	init_camera(game);
	ft_bzero(&game->keys, sizeof(t_keys));
	return (0);
}

/*
** Free MLX images/window/display allocated by the game.
*/
void	game_free(t_game *game)
{
	if (game->textures.north.img)
		mlx_destroy_image(game->mlx, game->textures.north.img);
	if (game->textures.south.img)
		mlx_destroy_image(game->mlx, game->textures.south.img);
	if (game->textures.east.img)
		mlx_destroy_image(game->mlx, game->textures.east.img);
	if (game->textures.west.img)
		mlx_destroy_image(game->mlx, game->textures.west.img);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
