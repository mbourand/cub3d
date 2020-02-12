#include "cub3d.h"

static void	write_int(unsigned char *str, int value)
{
	str[0] = (unsigned char)(value);
	str[1] = (unsigned char)(value >> 8);
	str[2] = (unsigned char)(value >> 16);
	str[3] = (unsigned char)(value >> 24);
}

static int	write_header(int fd, int size, t_game *game)
{
	int				index;
	unsigned char	header[54];

	index = 0;
	while (index < 54)
		header[index++] = (unsigned char)(0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	write_int(header + 2, size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	write_int(header + 18, game->map.res[0]);
	write_int(header + 22, game->map.res[1]);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

static int		write_data(int file, t_game *game)
{
	t_point	pos;
	int		color;

	pos.y = game->map.res[1];
	while (pos.y > 0)
	{
		pos.x = 0;
		while (pos.x < game->map.res[0])
		{
			color = image_get_color(game->img, pos.x, pos.y);
			if (write(file, &color, 3) < 0)
				return (0);
			pos.x++;
		}
		pos.y--;
	}
	return (1);
}

void	save_image(t_game *game)
{
	int fd;

	if (!(fd = open("screenshot.bmp", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP)))
		error(ERR_SCREEN_OPEN);
	if (!write_header(fd, 54 + ((int)game->map.res[0] * (int)game->map.res[1]), game))
		error(ERR_SCREEN_WRITE);
	if (!write_data(fd, game))
		error(ERR_SCREEN_WRITE);
	close(fd);
}