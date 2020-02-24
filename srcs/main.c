/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:50:10 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/13 14:04:46 by mbourand         ###   ########.fr       */
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
	if (!load_image(game->map.tex_s, &(game->tex_s), game->mlx_ptr))
		error("Sprite texture couldn't be load.");
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.res[0],
		game->map.res[1], "cub3d")))
		error("The window couldnt't be created..");
	if (!(game->img.img = mlx_new_image(game->mlx_ptr, game->map.res[0],
		game->map.res[1])))
		error("Image couldn't be created.");
	if (!(game->img.data = mlx_get_data_addr(game->img.img, &(game->img.bpp),
					&(game->img.size_line), &(game->img.endian))))
		error("Image data couldn't be converted to string.");
	mlx_do_key_autorepeatoff(game->mlx_ptr);
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
			if (s[i] == '2')
				ft_lstadd_back(&(game->spritecoords), point_lstnew(i, j));
			if (s[i] == 'S' || s[i] == 'E' || s[i] == 'W' || s[i] == 'N')
			{
				game->p.pos = point(i * CUBE_SIZE + CUBE_SIZE / 2,
					j * CUBE_SIZE + CUBE_SIZE / 2);
				game->p.cam_angle = get_char_angle(s[i]);
			}
		}
		j++;
		tmp = tmp->next;
	}
}

int			main(int argc, char **argv)
{
	t_game	game;
	int		screenshot;

	screenshot = 0;
	if (argc < 2 || argc > 3)
		error(ERR_ARG_COUNT);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", (ft_strlen(argv[2]) > 6 ? ft_strlen(argv[2]) : 6)))
		screenshot = 1;
	else if (argc == 3)
		error(ERR_ARG_SAVE);
	init_game(&game);
	parse_map(argv[1], &(game.map));
	if (!(game.p.rays = malloc(sizeof(t_ray) * game.map.res[0])))
		error(ERR_ALLOCATION);
	setup_mlx(&game);
	place_player(&game);
	game.p.proj_dist = fabs((game.map.res[0] / 2.0) /
			tan(to_radians(FOV / 2.0)));
	mlx_hook(game.win_ptr, 2, 1L << 0, &key_pressed, &game);
	mlx_hook(game.win_ptr, 3, 1L << 1, &key_released, &game);
	mlx_hook(game.win_ptr, 17, 1L << 0, &close_event, &game);
	mlx_loop_hook(game.mlx_ptr, &actions, &game);
	render(&game, screenshot);
	mlx_loop(game.mlx_ptr);
	reset_map(&(game.map));
}
