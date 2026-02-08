/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancanale <ancanale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/08 13:00:00 by ancanale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_movement_keys(t_game *game, int *moved)
{
	if (game->keys.w)
	{
		move_forward(game);
		*moved = 1;
	}
	if (game->keys.s)
	{
		move_backward(game);
		*moved = 1;
	}
	if (game->keys.a)
	{
		move_left(game);
		*moved = 1;
	}
	if (game->keys.d)
	{
		move_right(game);
		*moved = 1;
	}
}

void	handle_rotation_keys(t_game *game, int *moved)
{
	if (game->keys.left)
	{
		rotate_left(game);
		*moved = 1;
	}
	if (game->keys.right)
	{
		rotate_right(game);
		*moved = 1;
	}
}

int	update_game(t_game *game)
{
	int	moved;

	moved = 0;
	handle_movement_keys(game, &moved);
	handle_rotation_keys(game, &moved);
	if (moved)
		render_frame(game);
	return (0);
}
