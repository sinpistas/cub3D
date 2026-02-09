/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by ancanale          #+#    #+#             */
/*   Updated: 2026/02/09 13:58:23 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Apply movement keys (WASD). Sets moved if the player position changed.
*/
void	handle_movement_keys(t_game *game, int *moved)
{
	double	old_x;
	double	old_y;

	if (game->keys.w || game->keys.s || game->keys.a || game->keys.d)
	{
		old_x = game->cam.pos_x;
		old_y = game->cam.pos_y;
		if (game->keys.w)
			move_forward(game);
		if (game->keys.s)
			move_backward(game);
		if (game->keys.a)
			move_left(game);
		if (game->keys.d)
			move_right(game);
		if (game->cam.pos_x != old_x || game->cam.pos_y != old_y)
			*moved = 1;
	}
}

/*
** Apply rotation keys (left/right). Sets moved if the view changed.
*/
void	handle_rotation_keys(t_game *game, int *moved)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	if (game->keys.left || game->keys.right)
	{
		old_dir_x = game->cam.dir_x;
		old_dir_y = game->cam.dir_y;
		old_plane_x = game->cam.plane_x;
		old_plane_y = game->cam.plane_y;
		if (game->keys.left)
			rotate_left(game);
		if (game->keys.right)
			rotate_right(game);
		if (game->cam.dir_x != old_dir_x || game->cam.dir_y != old_dir_y
			|| game->cam.plane_x != old_plane_x
			|| game->cam.plane_y != old_plane_y)
			*moved = 1;
	}
}

/*
** Main loop hook: update movement/rotation and re-render only when needed.
*/
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
