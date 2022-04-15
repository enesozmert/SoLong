#include "header.h"

int player_move_left(t_game *game)
{
	game->player.x -= BLOCK_SIZE;
	if (game->player.x <= 0)
		game->player.x = 0;
	game->player.image.x = game->player.x;
	game->player.image.y = game->player.y;
	game->player.wlx = game->wlx;
	game->player.relative_path = "./icons/character/rocket.xpm";
	game->player.image.img = put_image(game->player.image);
	printf("%s\n",player_perspective(*game));
	return (game->player.x);
}

int player_move_right(t_game *game)
{
	game->player.x += BLOCK_SIZE;
	if (game->player.x >= (game->platform.width - 1) * BLOCK_SIZE)
		game->player.x = (game->platform.width - 1) * BLOCK_SIZE;
	game->player.image.x = game->player.x;
	game->player.image.y = game->player.y;
	game->player.wlx = game->wlx;
	game->player.relative_path = "./icons/character/rocket.xpm";
	game->player.image.img = put_image(game->player.image);
	printf("%s\n",player_perspective(*game));
	return (game->player.x);
}

int player_move_up(t_game *game)
{
	game->player.y -= BLOCK_SIZE;
	if (game->player.y <= 0)
		game->player.y = 0;
	game->player.image.y = game->player.y;
	game->player.image.x = game->player.x;
	game->player.wlx = game->wlx;
	game->player.relative_path = "./icons/character/rocket.xpm";
	game->player.image.img = put_image(game->player.image);
	printf("%s\n",player_perspective(*game));
	return (game->player.y);
}

int player_move_down(t_game *game)
{
	game->player.y += BLOCK_SIZE;
	if (game->player.y >= (game->platform.height - 2) * BLOCK_SIZE)
		game->player.y = (game->platform.height - 2) * BLOCK_SIZE;
	game->player.image.y = game->player.y;
	game->player.image.x = game->player.x;
	game->player.wlx = game->wlx;
	game->player.relative_path = "./icons/character/rocket.xpm";
	game->player.image.img = put_image(game->player.image);
	printf("%s\n",player_perspective(*game));
	return (game->player.y);
}