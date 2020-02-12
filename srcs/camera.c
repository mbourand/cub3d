#include "cub3d.h"

double	get_angle(int key)
{
	if (key == K_UP)
		return (180);
	if (key == K_DOWN)
		return (0);
	if (key == K_LEFT)
		return (90);
	if (key == K_RIGHT)
		return (270);
	return (0);
}

double	get_char_angle(char c)
{
	if (c == 'N')
		return (90);
	if (c == 'S')
		return (270);
	if (c == 'W')
		return (180);
	if (c == 'E')
		return (0.0001);
	return (0);
}