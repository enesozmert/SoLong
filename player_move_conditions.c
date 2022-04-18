#include "header.h"

void player_move_area(t_game *game)
{
	if (game->player.x <= 0)
		game->player.x = 0;
	else if (game->player.x >= (game->platform.width - 2) * BLOCK_SIZE)
		game->player.x = (game->platform.width - 2) * BLOCK_SIZE;
	if (game->player.y <= 0)
		game->player.y = 0;
	else if (game->player.y >= (game->platform.height - 2) * BLOCK_SIZE)
		game->player.y = (game->platform.height - 2) * BLOCK_SIZE;
}
void player_move_wall(t_game *game)
{
	char *perspective;
	
	perspective = game->player.perspective;
	// if (perspective[0] == game->player.x + 1 && perspective[0] != '\0')
	// 	game->player.x -= 1;
	// else if (perspective[1] == game->player.x - 1 && perspective[1] != '\0')
	// 	game->player.x += 1;
	// else if (perspective[2] == game->player.y - 1 && perspective[2] != '\0')
	// 	game->player.y -= 1;
	// else if (perspective[3] == game->player.y + 1 && perspective[3] != '\0')
	// 	game->player.y += 1;
}