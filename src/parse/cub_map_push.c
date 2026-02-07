/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:11:45 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 17:30:22 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*cub_strdup_no_nl(char *line);

/*
** Store one map line during parsing.
**
** The line is duplicated without the trailing newline and added
** to a temporary linked list. No validation or resizing is done
** here; the final map is built later in cub_finalize_map.
**
** Returns 0 on success, 1 on error.
*/
int	cub_map_push_line(t_scene *sc, char *line)
{
	t_mline	*node;

	node = (t_mline *)malloc(sizeof(t_mline));
	if (!node)
		return (1);
	node->line = cub_strdup_no_nl(line);
	if (!node->line)
	{
		free(node);
		return (1);
	}
	node->next = NULL;
	if (sc->map_last)
		sc->map_last->next = node;
	else
		sc->map_lines = node;
	sc->map_last = node;
	sc->map_h++;
	return (0);
}

/*
** Duplicate a line without the trailing newline character.
**
** Used to clean get_next_line output before storing map lines.
*/
static char	*cub_strdup_no_nl(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (ft_substr(line, 0, len));
}
