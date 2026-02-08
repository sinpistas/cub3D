/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:44:05 by apestana          #+#    #+#             */
/*   Updated: 2026/02/08 12:40:36 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* libft / gnl */
# include "libft.h"
# include "get_next_line.h"

/* minilibx */
# include "mlx.h"

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

/* Window */
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_TITLE "cub3D"

/* Raycasting */
# define FOV 60
# define ROT_SPEED 0.05
# define MOVE_SPEED 0.1

/* Key codes (Linux) */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/* MLX events */
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_DESTROY 17

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

/* Image for textures */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

/* Texture data */
typedef struct s_texture
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
}	t_texture;

/* Camera/Player for raycasting */
typedef struct s_cam
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_cam;

/* Key states for smooth movement */
typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

/* Raycasting ray data */
typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_ray;

/* Game structure */
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_scene		scene;
	t_texture	textures;
	t_cam		cam;
	t_keys		keys;
	int			floor_color;
	int			ceiling_color;
}	t_game;

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
void	cub_free_map_lines(t_mline *lst);
void	cub_xfree(void **p);
void	cub_free_strv(char ***p);

/* ------- game init ----------*/
int		game_init(t_game *game, t_scene *scene);
void	game_free(t_game *game);
int		load_textures(t_game *game);
void	init_camera(t_game *game);
int		rgb_to_int(t_rgb color);

/* ------- rendering ----------*/
void	render_frame(t_game *game);
void	raycast(t_game *game);

/* ------- raycasting utils ---*/
void	init_ray(t_game *game, t_ray *ray, int x);
void	set_step(t_game *game, t_ray *ray);
void	calc_wall_height(t_game *game, t_ray *ray);
void	calc_texture_x(t_game *game, t_ray *ray, t_img *texture);
void	perform_dda(t_game *game, t_ray *ray);

/* ------- raycasting draw ----*/
void	put_pixel(t_img *img, int x, int y, int color);
int		get_texture_color(t_img *texture, int x, int y);
void	draw_vertical_line(t_game *game, int x, t_ray *ray);
t_img	*get_texture(t_game *game, t_ray *ray);

/* ------- events -------------*/
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
int		handle_close(t_game *game);
int		update_game(t_game *game);
void	handle_movement_keys(t_game *game, int *moved);
void	handle_rotation_keys(t_game *game, int *moved);

/* ------- movement -----------*/
int		is_walkable(char c);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

/* ------- rotation -----------*/
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

#endif