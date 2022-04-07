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
	t_image image;
	image.y = image_move_up(game);
	image.x = game->player.x;
	image.wlx = game->wlx;
	image.relative_path = "./icons/character/rocket.xpm";
	image.img = put_image(image);
	mlx_destroy_image(game->wlx.mlx, image.img);
	return (0);
}

int key_down(t_game *game)
{
	printf("%s\n", "s");
	t_image image;
	image.y = image_move_down(game);
	image.x = game->player.x;
	image.wlx = game->wlx;
	image.relative_path = "./icons/character/rocket.xpm";
	image.img = put_image(image);
	mlx_destroy_image(game->wlx.mlx, image.img);
	return (0);
}

int key_left(t_game *game)
{
	printf("%s\n", "a");
	t_image image;
	image.x = image_move_left(game);
	image.y = game->player.y;
	image.wlx = game->wlx;
	image.relative_path = "./icons/character/rocket.xpm";
	image.img = put_image(image);
	mlx_destroy_image(game->wlx.mlx, image.img);
	return (0);
}

int key_right(t_game *game)
{
	printf("%s\n", "d");
	t_image image;
	image.x = image_move_right(game);
	image.y = game->player.y;
	image.wlx = game->wlx;
	image.relative_path = "./icons/character/rocket.xpm";
	image.img = put_image(image);
	mlx_destroy_image(game->wlx.mlx, image.img);
	return (0);
}

//13 up 0left 1down 2right