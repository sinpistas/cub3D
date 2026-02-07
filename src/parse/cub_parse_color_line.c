/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_color_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:44:06 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 19:54:46 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_parse_floor(t_scene *sc, char *arg);
static int	cub_parse_ceiling(t_scene *sc, char *arg);

/*
** Parse a floor or ceiling color identifier line.
**
** Dispatches the parsing depending on the identifier
** ('F' or 'C').
**
** Returns 0 on success, 1 on error.
*/
int	cub_parse_color_line(t_scene *sc, char id, char *line)
{
	char	*arg;
	int		ret;

	arg = cub_dup_arg_no_nl(line + 1);
	if (!arg)
		return (1);
	if (id == 'F')
		ret = cub_parse_floor(sc, arg);
	else
		ret = cub_parse_ceiling(sc, arg);
	free(arg);
	return (ret);
}

/*
** Parse and store the floor color.
**
** Prevents duplicate definitions and sets the
** floor RGB values.
**
** Returns 0 on success, 1 on error.
*/
static int	cub_parse_floor(t_scene *sc, char *arg)
{
	int	ret;

	if (sc->has_floor)
		return (1);
	ret = cub_parse_rgb(arg, &sc->floor);
	if (ret == 0)
		sc->has_floor = true;
	return (ret);
}

/*
** Parse and store the ceiling color.
**
** Prevents duplicate definitions and sets the
** ceiling RGB values.
**
** Returns 0 on success, 1 on error.
*/
static int	cub_parse_ceiling(t_scene *sc, char *arg)
{
	int	ret;

	if (sc->has_ceiling)
		return (1);
	ret = cub_parse_rgb(arg, &sc->ceiling);
	if (ret == 0)
		sc->has_ceiling = true;
	return (ret);
}
