/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_finalize_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:40:29 by apestana          #+#    #+#             */
/*   Updated: 2026/02/08 12:38:11 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_compute_map_width(t_mline *lst);
static char	*cub_build_map_row(char *src, int width);
static int	cub_fill_map_from_lines(t_scene *sc);

/*
** Build the final rectangular map from stored map lines.
** Computes dimensions, fills missing spaces and frees
** the temporary list.
*/
int	cub_finalize_map(t_scene *sc)
{
	if (!sc->map_lines || sc->map_h <= 0)
		return (1);
	sc->map_w = cub_compute_map_width(sc->map_lines);
	sc->map = (char **)malloc(sizeof(char *) * (sc->map_h + 1));
	if (!sc->map)
		return (1);
	if (cub_fill_map_from_lines(sc) != 0)
		return (1);
	cub_free_map_lines(sc->map_lines);
	sc->map_lines = NULL;
	sc->map_last = NULL;
	return (0);
}

/*
** Compute the maximum width of the map.
** Iterates through all stored map lines and returns
** the length of the longest one.
*/
static int	cub_compute_map_width(t_mline *lst)
{
	int	max;
	int	len;

	max = 0;
	while (lst)
	{
		len = ft_strlen(lst->line);
		if (len > max)
			max = len;
		lst = lst->next;
	}
	return (max);
}

/*
** Build one rectangular map row.
** Copies the original line and fills the remaining
** cells with spaces to match the map width.
*/
static char	*cub_build_map_row(char *src, int width)
{
	char	*row;
	int		i;

	row = (char *)malloc(sizeof(char) * (width + 1));
	if (!row)
		return (NULL);
	i = 0;
	while (src[i])
	{
		row[i] = src[i];
		i++;
	}
	while (i < width)
	{
		row[i] = ' ';
		i++;
	}
	row[i] = '\0';
	return (row);
}

/*
** Fill the final map array from the temporary map lines list.
** Allocates each row and keeps the map NULL-terminated during filling.
** Returns 0 on success, 1 on error.
*/
static int	cub_fill_map_from_lines(t_scene *sc)
{
	t_mline	*lst;
	int		i;

	lst = sc->map_lines;
	i = 0;
	sc->map[0] = NULL;
	while (lst)
	{
		sc->map[i] = cub_build_map_row(lst->line, sc->map_w);
		if (!sc->map[i])
			return (1);
		sc->map[i + 1] = NULL;
		lst = lst->next;
		i++;
	}
	return (0);
}
