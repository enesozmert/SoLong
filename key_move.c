#include "header.h"

int	key_hook(int keycode, t_game *game)
{
	int i;
	t_key_control key_control[5];

	i = 0;
	key_control[0] = (t_key_control){"W", 13, key_up};
	key_control[1] = (t_key_control){"S", 1, key_down};
	key_control[2] = (t_key_control){"A", 0, key_left};
	key_control[3] = (t_key_control){"D", 2, key_right};
	key_control[4] = (t_key_control){NULL, -1, NULL};
	while (key_control[i].name != NULL)
	{
		if (key_control[i].key_code == keycode)
		{
			key_control[i].f(game);
		}
		i++;
	}
	return (0);
}

int key_up(t_game *game)
{
	printf("%s\n", "w");
	game->player.image.y = image_move_up(game);
	game->player.image.x = game->player.x;
	game->player.wlx = game->wlx;
	game->player.relative_path = "./icons/character/rocket.xpm";
	game->player.image.img = put_image(game->player.image);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	t_image image1;
	image1.y = game->player.y + BLOCK_SIZE;
	image1.x = game->player.x;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
	return (0);
}

int key_down(t_game *game)
{
	printf("%s\n", "s");
	game->player.image.y = image_move_down(game);
	game->player.image.x = game->player.x;
	game->player.wlx = game->wlx;
	game->player.relative_path = "./icons/character/rocket.xpm";
	game->player.image.img = put_image(game->player.image);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	t_image image1;
	image1.y = game->player.y - BLOCK_SIZE;
	image1.x = game->player.x;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
	return (0);
}

int key_left(t_game *game)
{
	printf("%s\n", "a");
	game->player.image.x = image_move_left(game);
	game->player.image.y = game->player.y;
	game->player.wlx = game->wlx;
	game->player.relative_path = "./icons/character/rocket.xpm";
	game->player.image.img = put_image(game->player.image);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	t_image image1;
	image1.x = game->player.x + BLOCK_SIZE;
	image1.y = game->player.y;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
	return (0);
}

int key_right(t_game *game)
{
	printf("%s\n", "d");
	game->player.image.x = image_move_right(game);
	game->player.image.y = game->player.y;
	game->player.wlx = game->wlx;
	game->player.relative_path = "./icons/character/rocket.xpm";
	game->player.image.img = put_image(game->player.image);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	t_image image1;
	image1.x = game->player.x - BLOCK_SIZE;
	image1.y = game->player.y;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
	return (0);
}

//13 up 0left 1down 2right