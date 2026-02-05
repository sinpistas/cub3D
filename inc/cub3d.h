/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:44:05 by apestana          #+#    #+#             */
/*   Updated: 2026/02/05 12:05:19 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* libft / gnl */
# include "libft.h"
# include "get_next_line.h"

/* system */
# include <stdio.h>
# include <math.h>

/* ------- constants ----------*/
# define CUB_EXT ".cub"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_tex;

typedef struct s_scene
{
	t_tex	textures;
	t_rgb	floor;
	t_rgb	ceiling;
	char	**map;
	int		map_h;
	int		map_w;
}	t_scene;

/* ------- parsing ---------- */
int		cub_parse_file(t_scene *sc, const char *path);
void	cub_scene_init(t_scene *sc);
void	cub_scene_free(t_scene *sc);

/* ------- aux ----------------*/
void	ft_free_split(char **split);

#endif