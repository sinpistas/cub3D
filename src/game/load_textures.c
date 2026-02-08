/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancanale <ancanale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/08 13:00:00 by ancanale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_texture_img(t_game *game, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (!img->img)
	{
		printf("Error\nFailed to load texture: %s\n", path);
		return (1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	return (0);
}

int	load_textures(t_game *game)
{
	if (load_texture_img(game, &game->textures.north,
			game->scene.textures.no) != 0)
		return (1);
	if (load_texture_img(game, &game->textures.south,
			game->scene.textures.so) != 0)
		return (1);
	if (load_texture_img(game, &game->textures.east,
			game->scene.textures.ea) != 0)
		return (1);
	if (load_texture_img(game, &game->textures.west,
			game->scene.textures.we) != 0)
		return (1);
	return (0);
}
