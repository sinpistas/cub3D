/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:31:45 by apestana          #+#    #+#             */
/*   Updated: 2026/02/08 13:06:25 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_is_blank(char *line);
static int	cub_is_map_line(char *line);

/*
** Process one line from the .cub file.
**
** Dispatches the line to identifiers parsing or map storage,
** tracking when the map section starts.
**
** Returns 0 on success, 1 on error.
*/
int	cub_process_line(t_scene *sc, char *line, int *in_map)
{
	if (!*in_map && cub_is_blank(line))
		return (0);
	if (!*in_map && cub_is_map_line(line))
		*in_map = 1;
	if (!*in_map)
		return (cub_parse_id_line(sc, line));
	return (cub_map_push_line(sc, line));
}

/*
** Check if a line is empty or contains only whitespace.
**
** Returns 1 if blank, 0 otherwise.
*/
static int	cub_is_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\r'
			&& line[i] != '\v' && line[i] != '\f')
			return (0);
		i++;
	}
	return (1);
}

/*
** Check if a line can belong to the map section.
**
** Typically accepts lines containing only map characters and spaces.
** Returns 1 if it looks like a map line, 0 otherwise.
*/
static int	cub_is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	return (1);
}
