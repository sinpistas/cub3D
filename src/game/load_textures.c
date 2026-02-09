/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:11:35 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/09 13:58:25 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Load an XPM file into an MLX image and fetch its pixel buffer.
*/
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

/*
** Load all scene textures (NO/SO/EA/WE) into MLX images.
*/
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
