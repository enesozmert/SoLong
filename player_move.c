#include "header.h"

int player_move_left(t_game *game)
{
	game->player.x -= BLOCK_SIZE;
	game->player.relative_path = "./icons/character/rocket.xpm";
	player_move_base(game);
	return (game->player.x);
}

int player_move_right(t_game *game)
{
	game->player.x += BLOCK_SIZE;
	game->player.relative_path = "./icons/character/rocket.xpm";
	player_move_base(game);
	return (game->player.x);
}

int player_move_up(t_game *game)
{
	game->player.y -= BLOCK_SIZE;
	game->player.relative_path = "./icons/character/rocket.xpm";
	player_move_base(game);
	return (game->player.y);
}

int player_move_down(t_game *game)
{
	game->player.y += BLOCK_SIZE;
	game->player.relative_path = "./icons/character/rocket.xpm";
	player_move_base(game);
	return (game->player.y);
}

void player_move_base(t_game *game)
{
	player_move_area(game);
	player_move_wall(game);
	game->player.image.y = game->player.y;
	game->player.image.x = game->player.x;
	game->player.wlx = game->wlx;
	game->player.image.img = put_image(game->player.image);
	game->player.perspective = player_perspective(*game);
	printf("%s\n", player_perspective(*game));
}