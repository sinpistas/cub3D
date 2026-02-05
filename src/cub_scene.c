/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:53:37 by apestana          #+#    #+#             */
/*   Updated: 2026/02/05 11:55:57 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_scene_init(t_scene *sc)
{
	ft_bzero(sc, sizeof(*sc));
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
	cub_scene_init(sc);
}
