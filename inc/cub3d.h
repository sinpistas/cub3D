/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:44:05 by apestana          #+#    #+#             */
/*   Updated: 2026/02/07 19:57:33 by apestana         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

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

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

/* Parser's use only */
typedef struct s_mline
{
	char			*line;
	struct s_mline	*next;
}	t_mline;

typedef struct s_scene
{
	t_tex		textures;
	t_rgb		floor;
	t_rgb		ceiling;
	char		**map;
	int			map_h;
	int			map_w;
	t_player	player;
	bool		has_floor;
	bool		has_ceiling;
	bool		has_player;
	t_mline		*map_lines;
	t_mline		*map_last;
}	t_scene;

/* ------- parsing ---------- */
int		cub_parse_file(t_scene *sc, const char *path);
void	cub_scene_init(t_scene *sc);
void	cub_scene_free(t_scene *sc);
/* ------- helpers parsing ---*/
int		cub_process_line(t_scene *sc, char *line, int *in_map);
int		cub_check_extension(const char *path);
int		cub_parse_id_line(t_scene *sc, char *line);
int		cub_parse_color_line(t_scene *sc, char id, char *line);
int		cub_parse_rgb(char *line, t_rgb *rgb);
int		cub_map_push_line(t_scene *sc, char *line);
int		cub_finalize_map(t_scene *sc);
int		cub_validate_scene(t_scene *sc);
int		cub_validate_map(t_scene *sc);
int		cub_validate_cell(t_scene *sc, int y, int x);
char	*cub_skip_spaces(char *s);
char	*cub_dup_arg_no_nl(char *s);

/* ------- aux ----------------*/
void	ft_free_split(char **split);
void	cub_free_map_lines(t_mline *lst);

#endif