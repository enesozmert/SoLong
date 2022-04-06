#include "header.h"

int image_move_left(t_player player, t_platform platform)
{
	static	int i = 0;
	i++;
	player.x -= i;
	if (player.x < platform.width)
		i = 0;
	return (player.x);
}

void image_move_right(int x, t_platform platform)
{
	static	int i = 0;
	i++;
	x -= i;
	if (x < platform.width)
		i = 0;
	return (x);
}

void image_move_up()
{
	static	int i = 0;
	i++;
	x -= i;
	if (x < platform.width)
		i = 0;
	return (x);
}

void image_move_down()
{
	
}
