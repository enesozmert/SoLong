#include "header.h"

int image_move_left(t_game *game)
{
	game->player.x -= BLOCK_SIZE;
	// if (game->player.x >= game->platform.width)
	// 	game->player.x = game->platform.width / BLOCK_SIZE;
	return (game->player.x);
}

int image_move_right(t_game *game)
{
	game->player.x += BLOCK_SIZE;
	// if (game->player.x <= 0)
	// 	game->player.x = 0;
	return (game->player.x);
}

int image_move_up(t_game *game)
{
	game->player.y -= BLOCK_SIZE;
	// if (game->player.y >= game->platform.height)
	// 	game->player.y = game->platform.height / BLOCK_SIZE;
	return (game->player.y);
}

int image_move_down(t_game *game)
{
	game->player.y += BLOCK_SIZE;
	// if (game->player.y <= 0)
	// 	game->player.y = game->platform.height / BLOCK_SIZE;
	return (game->player.y);
}
