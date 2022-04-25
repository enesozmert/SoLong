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

int player_move_wall(t_game *game)
{
	(void)game;
	return (0);
}

void player_move_coin(t_game *game)
{
	int p_x;
	int p_y;

	p_x = game->player.x / BLOCK_SIZE;
	p_y = game->player.y / BLOCK_SIZE;
	if (game->platform.map[p_y][p_x] == 'C')
	{
		game->player.coin_count++;
		game->platform.map[p_y][p_x] = '0';
	}
}

void player_move_count(t_game *game)
{
	int p_x;
	int p_y;

	p_x = game->player.x / BLOCK_SIZE;
	p_y = game->player.y / BLOCK_SIZE;
	if (game->platform.map[p_y][p_x] != '1')
		game->player.move_count++;
}

void player_move_exit(t_game *game)
{
	int p_x;
	int p_y;
	//t_image image;

	p_x = game->player.x / BLOCK_SIZE;
	p_y = game->player.y / BLOCK_SIZE;
	if (game->player.coin_count == game->player.coin_size)
	{
		mlx_destroy_window(game->wlx.mlx, game->wlx.win);
		exit (0);
	}
	// else if (game->platform.map[p_y][p_x] != 'E' && game->player.coin_count != game->player.coin_size)
	// {
	// 	image.relative_path = "./icons/maps/paving/elevator1.xpm";
	// 	image.wlx = game->wlx;
	// 	image.x = get_location(&game->platform, 'E')[0] * BLOCK_SIZE;
	// 	image.y = get_location(&game->platform, 'E')[1] * BLOCK_SIZE;
	// 	image.img = put_image(image);
	// 	mlx_destroy_image(game->wlx.mlx, image.img);
	// }
}