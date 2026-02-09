/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/09 13:09:42 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = game->cam.dir_x + game->cam.plane_x * ray->camera_x;
	ray->ray_dir_y = game->cam.dir_y + game->cam.plane_y * ray->camera_x;
	ray->map_x = (int)game->cam.pos_x;
	ray->map_y = (int)game->cam.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	set_step(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->cam.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->cam.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->cam.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->cam.pos_y)
			* ray->delta_dist_y;
	}
}

void	calc_wall_height(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->cam.pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->cam.pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	if (ray->perp_wall_dist < 1e-6)
		ray->perp_wall_dist = 1e-6;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	if (ray->line_height < 1)
		ray->line_height = 1;
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_start >= WIN_HEIGHT)
		ray->draw_start = WIN_HEIGHT - 1;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end < 0)
		ray->draw_end = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	calc_texture_x(t_game *game, t_ray *ray, t_img *texture)
{
	if (ray->side == 0)
		ray->wall_x = game->cam.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->cam.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
	ray->step = 1.0 * texture->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * ray->step;
}

void	perform_dda(t_game *game, t_ray *ray)
{
	int	guard;

	guard = game->scene.map_h * game->scene.map_w + 1;
	while (ray->hit == 0 && guard-- > 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= game->scene.map_h
			|| ray->map_x < 0 || ray->map_x >= game->scene.map_w)
			break ;
		if (game->scene.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->hit == 0)
		ray->hit = 1;
}
