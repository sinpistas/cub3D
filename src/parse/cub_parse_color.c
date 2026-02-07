/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:38:25 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 19:52:10 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_parse_u8(char **s, int *out);

/*
** Parse "r,g,b" into t_rgb. Spaces around numbers/commas are allowed.
** Returns 0 on success, 1 on error.
*/
int	cub_parse_rgb(char *line, t_rgb *rgb)
{
	char	*s;

	s = cub_skip_spaces(line);
	if (cub_parse_u8(&s, &rgb->r) != 0)
		return (1);
	s = cub_skip_spaces(s);
	if (*s++ != ',')
		return (1);
	if (cub_parse_u8(&s, &rgb->g) != 0)
		return (1);
	s = cub_skip_spaces(s);
	if (*s++ != ',')
		return (1);
	if (cub_parse_u8(&s, &rgb->b) != 0)
		return (1);
	s = cub_skip_spaces(s);
	if (*s != '\0')
		return (1);
	return (0);
}

/*
** Parse an unsigned 8-bit integer from a string.
**
** Accepts values in range [0..255] and advances
** the string pointer.
**
** Returns 0 on success, 1 on error.
*/
static int	cub_parse_u8(char **s, int *out)
{
	int	n;

	*s = cub_skip_spaces(*s);
	if (!ft_isdigit(**s))
		return (1);
	n = 0;
	while (ft_isdigit(**s))
	{
		n = n * 10 + (**s - '0');
		(*s)++;
	}
	if (n < 0 || n > 255)
		return (1);
	*out = n;
	return (0);
}
