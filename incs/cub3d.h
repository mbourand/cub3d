/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:38:05 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/08 20:36:36 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define PI 3.1415926535
# define FACE_NORTH 0
# define FACE_SOUTH 1
# define FACE_WEST 2
# define FACE_EAST 3

# define K_UP 122
# define K_DOWN 115
# define K_LEFT 113
# define K_RIGHT 100
# define K_CAMLEFT 65361
# define K_CAMRIGHT 65363

# define CUBE_SIZE 1920
# define PLAYER_SIZE 100
# define MOVE_SPEED 450
# define CAM_SPEED 3.13
# define FOV 60

typedef struct		s_map
{
	int				res[2];
	char			*tex_no;
	char			*tex_so;
	char			*tex_we;
	char			*tex_ea;
	char			*tex_s;
	int				col_f;
	int				col_c;
	t_list			*map_d;
}					t_map;

typedef struct		s_image
{
	void			*img;
	char			*data;
	int				size_line;
	int				bpp;
	int				w;
	int				h;
	int				endian;
}					t_image;


typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_ray
{
	double			wall;
	double			distance;
	double			angle;
	int				face;
}					t_ray;

typedef struct		s_player
{
	t_point			pos;
	double			cam_angle;
	t_ray			ray;
	double			proj_dist;
}					t_player;

typedef struct		s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				keys[6];
	t_image			img;
	t_image	tex_no;
	t_image	tex_so;
	t_image	tex_we;
	t_image	tex_ea;
	t_map			map;
	t_player		p;
}					t_game;

int					get_tile_at(t_point point, t_list *map_d);
void				render_wall(t_game *game, int x);
void				image_set_pixel(t_image *img, int x, int y, int color);
int					image_get_color(t_image img, int x, int y);
void				move_player(t_player *p, t_map map);
double				get_angle(int key);
int					get_key_index(int key);
double				cast(t_game *game, t_ray *ray);
int					check_map(t_list *map);
int					parse_resolution(char *line, t_map *map);
int					parse_texture(char *line, t_map *map);
int					parse_color(char *line, t_map *map);
int					is_filled(t_map map);
int					parse_map(char *filename, t_map *map);
void				error(char *message);
void				reset_map(t_map *map);
void				init_game(t_game *game);
double				min(double d, double e);
double				constrain(double d, double min, double max);
int					key_pressed(int key, void *param);
int					rgbtoint(int rgb[3]);
int					close_event(void *param);
int					render(t_game *game);
double				to_radians(double angle);
int					load_image(char *file, t_image *img, void *mlx_ptr);
double				get_char_angle(char c);
t_image				get_texture_face(t_game *game, int face);
void				quit(t_game *game);

#endif
