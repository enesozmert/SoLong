#include "header.h"

void fill_background_up(t_game *game)
{
	t_image image1;
	image1.y = game->player.y + BLOCK_SIZE;
	image1.x = game->player.x;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
}

void fill_background_down(t_game *game)
{
	t_image image1;
	image1.y = game->player.y - BLOCK_SIZE;
	image1.x = game->player.x;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
}

void fill_background_left(t_game *game)
{
	t_image image1;
	image1.x = game->player.x + BLOCK_SIZE;
	image1.y = game->player.y;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
}

void fill_background_right(t_game *game)
{
	t_image image1;
	image1.x = game->player.x - BLOCK_SIZE;
	image1.y = game->player.y;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
}
