#include "./../header.h"

void print_map_string(t_game *game)
{
	char *string;

	string = ft_itoa(game->player.move_count);
	mlx_string_put(game->wlx.mlx, game->wlx.win,
				   (((game->platform.width) / 2) * BLOCK_SIZE),
				   (game->platform.height * BLOCK_SIZE) - BLOCK_SIZE, rgb_hex(255,255,255), "Movements: ");
	mlx_string_put(game->wlx.mlx, game->wlx.win,
				   (((game->platform.width) / 2) * BLOCK_SIZE) + 100,
				   (game->platform.height * BLOCK_SIZE) - BLOCK_SIZE, rgb_hex(255, 255, 255), string);
	free(string);
	string = NULL;
	return;
}