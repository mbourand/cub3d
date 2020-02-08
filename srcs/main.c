/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:50:10 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/08 17:19:35 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "string.h"

static void	setup_mlx(t_game *game)
{
	if (!(game->mlx_ptr = mlx_init()))
		error("Minilibx initialisation failed.");
	if (!load_image(game->map.tex_no, &(game->tex_no), game->mlx_ptr))
		error("North texture couldn't be load.");
	if (!load_image(game->map.tex_so, &(game->tex_so), game->mlx_ptr))
		error("South texture couldn't be load.");
	if (!load_image(game->map.tex_ea, &(game->tex_ea), game->mlx_ptr))
		error("East texture couldn't be load.");
	if (!load_image(game->map.tex_we, &(game->tex_we), game->mlx_ptr))
		error("West texture couldn't be load.");
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.res[0],
		game->map.res[1], "cub3d")))
		error("The window couldnt't be created..");
	if (!(game->img.img = mlx_new_image(game->mlx_ptr, game->map.res[0],
		game->map.res[1])))
		error("Image couldn't be created.");
	if (!(game->img.data = mlx_get_data_addr(game->img.img, &(game->img.bpp),
					&(game->img.size_line), &(game->img.endian))))
		error("Image data couldn't be converted to string.");
	game->img.w = game->map.res[0];
	game->img.h = game->map.res[1];
}

static void		place_player(t_game *game)
{
	t_list	*tmp;
	char	*s;
	int		i;
	int		j;
	
	tmp = game->map.map_d;
	j = 0;
	while (tmp)
	{
		s = (char*)tmp->content;
		i = -1;
		while (s[++i])
		{
			if (s[i] == 'S' || s[i] == 'E' || s[i] == 'W' || s[i] == 'N')
			{
				game->p.pos.x = (i / 2) * CUBE_SIZE + (CUBE_SIZE / 2);
				game->p.pos.y = j * CUBE_SIZE + (CUBE_SIZE / 2);
				game->p.cam_angle = get_char_angle(s[i]);
				return ;
			}
		}
		j++;
		tmp = tmp->next;
	}
}

int			main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error("Invalid number of arguments.");
	init_game(&game);
	parse_map(argv[1], &(game.map));
	setup_mlx(&game);
	place_player(&game);
	game.p.proj_dist = fabs((game.map.res[0] / 2.0) /
			tan(to_radians(FOV / 2.0)));
	mlx_hook(game.win_ptr, 2, 1L << 0, &key_pressed, &game);
	mlx_hook(game.win_ptr, 17, 1L << 0, &close_event, &game);
	render(&game);
	mlx_loop(game.mlx_ptr);
	reset_map(&(game.map));
}
