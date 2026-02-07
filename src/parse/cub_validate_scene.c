/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validate_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:57:17 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 19:39:51 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_has_all_textures(t_scene *sc);

/*
** Validate the parsed scene before execution.
**
** Checks that required elements are present and
** triggers map validation.
**
** Returns 0 if valid, 1 on error.
*/
int	cub_validate_scene(t_scene *sc)
{
	if (!sc)
		return (1);
	if (!cub_has_all_textures(sc))
		return (1);
	if (!sc->map || sc->map_h <= 0 || sc->map_w <= 0)
		return (1);
	if (cub_validate_map(sc) != 0)
		return (1);
	if (!sc->has_floor || !sc->has_ceiling)
		return (1);
	return (0);
}

/*
** Check that all required texture paths are present.
**
** Returns 1 if all textures are set, 0 otherwise.
*/
static int	cub_has_all_textures(t_scene *sc)
{
	if (!sc->textures.no || !sc->textures.so)
		return (0);
	if (!sc->textures.we || !sc->textures.ea)
		return (0);
	return (1);
}
