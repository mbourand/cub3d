/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:38:05 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/25 17:14:12 by mbourand         ###   ########.fr       */
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
# define TRANSPARENT_COLOR 0x000000
# define MAX_WIDTH 2560
# define MAX_HEIGHT	1400
# define ERR_ARG_COUNT "Invalid number of arguments. Use ./cub3d <map> [--save]"
# define ERR_ARG_SAVE "Invalid second argument. Use ./cub3d <map> [--save]"
# define ERR_ALLOCATION "An allocation error has occured."
# define ERR_UNDEF_PARAM "Undefined parameter in the given file."
# define ERR_MISSING_PARAM "Missing parameters in the given file"
# define ERR_RESOLUTION "Incorrect resolution in the given file."
# define ERR_TEXTURE "Incorrect texture in the given file."
# define ERR_COLOR "Incorrect color in the given file."
# define ERR_MAP "Incorrect map description in the given file."
# define ERR_FILE_READ "Unable to read the given file."
# define ERR_FILE_OPEN "Unable to open the given file."
# define ERR_NOT_CUB "The given file is not a .cub file."
# define ERR_SCREEN_OPEN "The screenshot file couldn't be opened."
# define ERR_SCREEN_WRITE "The screenshot file couldn't be written."

# define K_UP 13
# define K_DOWN 1
# define K_LEFT 0
# define K_RIGHT 2
# define K_CAMUP 126
# define K_CAMDOWN 125
# define K_CAMLEFT 123
# define K_CAMRIGHT 124
# define K_ESC 53
# define K_SCREENSHOT 39

# define CUBE_SIZE 1920
# define PLAYER_SIZE 100
# define MOVE_SPEED 240
# define CAM_SPEED 2.33
# define CAM_SPEED_V 10
# define FOV 60
# define MINIMAP_SIZE 200
# define SCOPE_OFFSET 5
# define MAX_STAMINA 200

typedef struct		s_map
{
	t_list			*map_d;
	char			*tex_no;
	char			*tex_so;
	char			*tex_we;
	char			*tex_ea;
	char			*tex_s;
	int				res[2];
	int				col_f;
	int				col_c;
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
	double			angle;
	double			distance;
	double			wall;
	int				face;
}					t_ray;

typedef struct		s_player
{
	t_point			pos;
	double			cam_angle;
	double			proj_dist;
	t_ray			*rays;
}					t_player;

typedef struct		s_game
{
	t_player		p;
	t_image			img;
	t_image			tex_no;
	t_image			tex_so;
	t_image			tex_we;
	t_image			tex_ea;
	t_image			tex_s;
	double			floor_coef;
	t_list			*spritecoords;
	t_map			map;
	void			*mlx_ptr;
	void			*win_ptr;
	int				keys[8];
}					t_game;

t_image				get_texture_face(t_game *game, int face);
t_point				point(double x, double y);
t_list				*point_lstnew(double x, double y);
double				distance(t_point p, t_point p2);
double				atan2(double y, double x);
double				to_radians(double angle);
double				get_angle(int key);
double				get_char_angle(char c);
double				min(double d, double e);
double				constrain(double d, double min, double max);
double				cast(t_game *game, t_ray *ray);
void				render_scope(t_game *game);
void				render_minimap(t_game *game);
void				render_hud(t_game *game);
void				render_sprites(t_game *game);
void				render_wall(t_game *game, t_ray *ray, int x);
void				reset_map(t_map *map);
void				init_game(t_game *game);
void				image_set_pixel(t_image *img, int x, int y, int color);
void				quit(t_game *game);
void				error(char *message);
void				save_image(t_image img);
void				set_tile_at(t_point point, char val, t_list *map_d);
void				set_tile_at_grid(t_point point, char val, t_list *map_d);
void				swap(t_point *p1, t_point *p2);
int					key_released(int key, void *param);
int					get_tile_at(t_point point, t_list *map_d);
int					get_tile_at_grid(t_point point, t_list *map_d);
int					image_get_color(t_image img, int x, int y);
int					get_key_index(int key);
int					check_map(t_list *map);
int					format_description(t_map *map);
int					parse_resolution(char *line, t_map *map);
int					parse_texture(char *line, t_map *map);
int					parse_color(char *line, t_map *map);
int					is_filled(t_map map);
int					parse_map(char *filename, t_map *map);
int					key_pressed(int key, void *param);
int					rgbtoint(int rgb[3]);
int					close_event(void *param);
int					actions(void *param);
int					render(t_game *game, int save);
int					load_image(char *file, t_image *img, void *mlx_ptr);

#endif
