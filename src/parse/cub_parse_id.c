/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:48:39 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 16:51:09 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_set_texture(char **dst, char *path);
static char	*cub_skip_spaces(char *s);
static int	cub_parse_texture_line(t_scene *sc, char *line);

int	cub_parse_id_line(t_scene *sc, char *line)
{
	line = cub_skip_spaces(line);
	if (line[0] == 'N' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\t'))
		return (cub_parse_texture_line(sc, line));
	if (line[0] == 'S' && line[1] == 'O'
		&& (line[2] == ' ' || line[2] == '\t'))
		return (cub_parse_texture_line(sc, line));
	if (line[0] == 'W' && line[1] == 'E'
		&& (line[2] == ' ' || line[2] == '\t'))
		return (cub_parse_texture_line(sc, line));
	if (line[0] == 'E' && line[1] == 'A'
		&& (line[2] == ' ' || line[2] == '\t'))
		return (cub_parse_texture_line(sc, line));
	return (0);
}

static int	cub_set_texture(char **dst, char *path)
{
	if (*dst != NULL)
		return (1);
	if (!path || *path == '\0')
		return (1);
	*dst = ft_strdup(path);
	if (*dst == NULL)
		return (1);
	return (0);
}

static char	*cub_skip_spaces(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

static int	cub_parse_texture_line(t_scene *sc, char *line)
{
	char	*path;

	path = cub_skip_spaces(line + 2);
	if (*path == '\0')
		return (1);
	if (*path == '\n')
		return (1);
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = '\0';
	if (line[0] == 'N' && line[1] == 'O')
		return (cub_set_texture(&sc->textures.no, path));
	if (line[0] == 'S' && line[1] == 'O')
		return (cub_set_texture(&sc->textures.so, path));
	if (line[0] == 'W' && line[1] == 'E')
		return (cub_set_texture(&sc->textures.we, path));
	if (line[0] == 'E' && line[1] == 'A')
		return (cub_set_texture(&sc->textures.ea, path));
	return (1);
}
