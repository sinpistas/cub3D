/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancanale <ancanale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/08 13:00:00 by ancanale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_game *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
