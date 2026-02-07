/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:24:16 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 20:07:29 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_usage(void)
{
	printf("Usage: ./cub3D <map.cub>\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_scene	sc;

	if (argc != 2)
		return (cub_usage());
	cub_scene_init(&sc);
	if (cub_parse_file(&sc, argv[1]) != 0)
	{
		printf("Error\n");
		cub_scene_free(&sc);
		return (1);
	}
	printf("OK\n");
	cub_scene_free(&sc);
	return (0);
}
