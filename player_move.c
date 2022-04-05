#include "header.h"

void player_move(t_player player)
{
	t_image image;
	image.relative_path = player.relative_path;
	image.wlx = player.wlx;
	put_image(image);
}