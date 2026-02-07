/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:53:37 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 17:26:51 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_scene_init(t_scene *sc)
{
	if (!sc)
		return ;
	sc->textures.no = NULL;
	sc->textures.so = NULL;
	sc->textures.we = NULL;
	sc->textures.ea = NULL;
	sc->floor.r = 0;
	sc->floor.g = 0;
	sc->floor.b = 0;
	sc->ceiling.r = 0;
	sc->ceiling.g = 0;
	sc->ceiling.b = 0;
	sc->map = NULL;
	sc->map_h = 0;
	sc->map_w = 0;
	sc->player.x = -1;
	sc->player.y = -1;
	sc->player.dir = 0;
	sc->has_floor = false;
	sc->has_ceiling = false;
	sc->has_player = false;
	sc->map_lines = NULL;
	sc->map_last = NULL;
}

void	cub_scene_free(t_scene *sc)
{
	if (!sc)
		return ;
	free(sc->textures.no);
	free(sc->textures.so);
	free(sc->textures.we);
	free(sc->textures.ea);
	ft_free_split(sc->map);
	cub_free_map_lines(sc->map_lines);
	sc->map_lines = NULL;
	sc->map_last = NULL;
	cub_scene_init(sc);
}
