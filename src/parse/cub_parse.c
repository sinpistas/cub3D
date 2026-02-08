/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:55:13 by apestana          #+#    #+#             */
/*   Updated: 2026/02/08 13:07:14 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_close_fd(int fd, int ret);
static int	cub_read_lines(t_scene *sc, int fd);
static int	cub_after_read(t_scene *sc);

/*
** Parse a .cub file into the scene structure.
**
** Opens the file, reads and processes all lines, then finalizes and
** validates the scene.
**
** Returns 0 on success, 1 on error.
*/
int	cub_parse_file(t_scene *sc, const char *path)
{
	int	fd;

	if (cub_check_extension(path) != 0)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (cub_read_lines(sc, fd) != 0)
		return (cub_close_fd(fd, 1));
	close(fd);
	return (cub_after_read(sc));
}

/*
** Close a file descriptor and return the provided status code.
**
** Used to centralize close() calls on success or error paths.
*/
static int	cub_close_fd(int fd, int ret)
{
	close(fd);
	return (ret);
}

/*
** Read and process all lines from the opened .cub file.
**
** Calls cub_process_line for each line and stops on the first error.
**
** Returns 0 on success, 1 on error.
*/
static int	cub_read_lines(t_scene *sc, int fd)
{
	char	*line;
	int		in_map;

	in_map = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		if (cub_process_line(sc, line, &in_map) != 0)
		{
			free(line);
			get_next_line(fd, 1);
			return (1);
		}
		free(line);
		line = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	return (0);
}

/*
** Run post-read steps after all lines have been processed.
**
** Builds the final map, then validates the full scene.
** Returns 0 on success, 1 on error.
*/
static int	cub_after_read(t_scene *sc)
{
	if (cub_finalize_map(sc) != 0)
		return (1);
	if (cub_validate_scene(sc) != 0)
		return (1);
	return (0);
}
