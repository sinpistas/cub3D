/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancanale <antonioayr.94@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/08 17:10:12 by ancanale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_texture_color(t_img *texture, int x, int y)
{
	char	*pixel;

	if (x >= 0 && x < texture->width && y >= 0 && y < texture->height)
	{
		pixel = texture->addr + (y * texture->line_len
				+ x * (texture->bpp / 8));
		return (*(unsigned int *)pixel);
	}
	return (0);
}

t_img	*get_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&game->textures.east);
		else
			return (&game->textures.west);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (&game->textures.south);
		else
			return (&game->textures.north);
	}
}

void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	t_img	*texture;
	int		y;
	int		tex_y;
	int		color;

	texture = get_texture(game, ray);
	calc_texture_x(game, ray, texture);
	y = 0;
	while (y < ray->draw_start)
		put_pixel(&game->img, x, y++, game->ceiling_color);
	while (y < ray->draw_end)
	{
		tex_y = (int)ray->tex_pos & (texture->height - 1);
		ray->tex_pos += ray->step;
		color = get_texture_color(texture, ray->tex_x, tex_y);
		put_pixel(&game->img, x, y, color);
		y++;
	}
	while (y < WIN_HEIGHT)
		put_pixel(&game->img, x, y++, game->floor_color);
}
