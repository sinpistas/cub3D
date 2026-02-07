/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:48:39 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 19:57:25 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_set_texture(char **dst, char *path);
static int	cub_parse_texture_line(t_scene *sc, char *line);

/*
** Parse a non-map identifier line.
**
** Handles texture and color identifiers and
** rejects unknown or malformed identifiers.
**
** Returns 0 on success, 1 on error.
*/
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
	if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
		return (cub_parse_color_line(sc, 'F', line));
	if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
		return (cub_parse_color_line(sc, 'C', line));
	return (1);
}

/*
** Skip leading spaces and tabs in a string.
**
** Returns a pointer to the first non-space character.
*/
char	*cub_skip_spaces(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

/*
** Duplicate an identifier argument without trailing newline.
**
** Trims leading spaces and removes a final '\n' if present.
**
** Returns a newly allocated string or NULL on error.
*/
char	*cub_dup_arg_no_nl(char *s)
{
	size_t	len;

	s = cub_skip_spaces(s);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		len--;
	return (ft_substr(s, 0, len));
}

/*
** Assign a texture path to a scene texture slot.
**
** Prevents duplicate definitions and duplicates
** the path string.
**
** Returns 0 on success, 1 on error.
*/
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

/*
** Parse a texture identifier line.
**
** Extracts the texture path and assigns it to the
** corresponding texture slot.
**
** Returns 0 on success, 1 on error.
*/
static int	cub_parse_texture_line(t_scene *sc, char *line)
{
	char	*arg;
	int		ret;

	arg = cub_dup_arg_no_nl(line + 2);
	if (!arg)
		return (1);
	if (line[0] == 'N' && line[1] == 'O')
		ret = cub_set_texture(&sc->textures.no, arg);
	else if (line[0] == 'S' && line[1] == 'O')
		ret = cub_set_texture(&sc->textures.so, arg);
	else if (line[0] == 'W' && line[1] == 'E')
		ret = cub_set_texture(&sc->textures.we, arg);
	else
		ret = cub_set_texture(&sc->textures.ea, arg);
	free(arg);
	return (ret);
}
