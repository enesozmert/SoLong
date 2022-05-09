#include "header.h"

int player_move(t_game *game, int x, int y)
{
	if (check_total_item(game) == 1)
	{
		game->player.x += -1 * x;
		game->player.y += -1 * y;
		fill_background_base(game, x, y);
		player_move_count(game);
	}
	player_move_base(game);
	return (game->player.y);
}

void player_move_base(t_game *game)
{
	player_move_area(game);
	player_move_coin(game);
	game->player.image.y = game->player.y;
	game->player.image.x = game->player.x;
	game->player.wlx = game->wlx;
	game->player.image.img = put_image(game->player.image);
	game->player.perspective = player_perspective(*game);
	printf("coin count :%d \n",game->player.coin_count);
	printf("move count :%d \n",game->player.move_count);
}