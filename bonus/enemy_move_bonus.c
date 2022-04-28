#include "./../header.h"

void	update2(t_game *game, int x, int y)
{
	t_image	image;

	image.relative_path = "./icons/maps/black/star1.xpm";
	image.wlx = game->wlx;
	image.x = x;
	image.y = y;
	put_image(image);
}

void	move_2(t_game *game, int x, int y)
{
	t_image	image;

	image.wlx = game->wlx;
	image.relative_path = "./icons/character/enemy.xpm";
	if (x * BLOCK_SIZE == game->player.x && y * BLOCK_SIZE == game->player.y)
		printf("The dead cannot speak\n");
	if (game->platform.map[y][x - 1] != '1')
	{
		update2(game, (x * BLOCK_SIZE), y * BLOCK_SIZE);
		game->platform.map[y][x] = '0';
		game->platform.map[y][x - 1] = 'X';
		image.x = y * BLOCK_SIZE;
		image.y = (x * BLOCK_SIZE) - BLOCK_SIZE;
		put_image(image);
	}
	else if (game->platform.map[y][x + 1] == '0')
		move_4(game, x, y);
}

void	move_4(t_game *game, int x, int y)
{
	t_image	image;

	image.wlx = game->wlx;
	image.relative_path = "./icons/character/enemy.xpm";
	while (game->platform.map[y][x + 1] != '1')
	{
		update2(game, (x * BLOCK_SIZE), y * BLOCK_SIZE);
		game->platform.map[y][x] = '0';
		game->platform.map[y][x + 1] = 'X';
		image.x = y * BLOCK_SIZE;
		image.y = (x * BLOCK_SIZE) + BLOCK_SIZE;
		put_image(image);
		x++;
	}	
}