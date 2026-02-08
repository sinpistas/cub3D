/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancanale <ancanale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:24:16 by apestana          #+#    #+#             */
/*   Updated: 2026/02/08 13:00:00 by ancanale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_usage(void)
{
	printf("Usage: ./cub3D <map.cub>\n");
	printf("       ./cub3D --test <map.cub>  (parse only, for testing)\n");
	return (1);
}

static int	parse_arguments(int *argc, char **argv, int *test_mode)
{
	if (*argc == 3 && ft_strncmp(argv[1], "--test", 7) == 0)
	{
		*test_mode = 1;
		*argc = 2;
		argv[1] = argv[2];
	}
	if (*argc != 2)
		return (cub_usage());
	return (0);
}

static int	parse_scene(t_scene *sc, char *file)
{
	cub_scene_init(sc);
	if (cub_parse_file(sc, file) != 0)
	{
		printf("Error\n");
		cub_scene_free(sc);
		return (1);
	}
	return (0);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, EVENT_KEY_PRESS, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, EVENT_KEY_RELEASE, 1L << 1, handle_keyrelease, game);
	mlx_hook(game->win, EVENT_DESTROY, 1L << 17, handle_close, game);
	mlx_loop_hook(game->mlx, update_game, game);
}

int	main(int argc, char **argv)
{
	t_scene	sc;
	t_game	game;
	int		test_mode;

	test_mode = 0;
	if (parse_arguments(&argc, argv, &test_mode) != 0)
		return (1);
	if (parse_scene(&sc, argv[1]) != 0)
		return (1);
	if (test_mode)
	{
		printf("OK\n");
		cub_scene_free(&sc);
		return (0);
	}
	if (game_init(&game, &sc) != 0)
	{
		cub_scene_free(&sc);
		return (1);
	}
	render_frame(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
