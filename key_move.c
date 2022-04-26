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
			key_control[i].f(game);
		i++;
	}
	return (0);
}

int key_up(t_game *game)
{
	game->player.direction = 3;
	if (check_total_item(game) == 1)
		game->player.image.relative_path = "./icons/character/rocketu.xpm";
	player_move(game, 0, BLOCK_SIZE);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	return (0);
}

int key_down(t_game *game)
{
	game->player.direction = 2;
	if (check_total_item(game) == 1)
		game->player.image.relative_path = "./icons/character/rocketd.xpm";
	player_move(game, 0, -BLOCK_SIZE);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	return (0);
}

int key_left(t_game *game)
{
	game->player.direction = 1;
	if (check_total_item(game) == 1)
		game->player.image.relative_path = "./icons/character/rocketl.xpm";
	player_move(game, BLOCK_SIZE, 0);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	return (0);
}

int key_right(t_game *game)
{
	game->player.direction = 0;
	if (check_total_item(game) == 1)
		game->player.image.relative_path = "./icons/character/rocketr.xpm";
	player_move(game, -BLOCK_SIZE, 0);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	return (0);
}

//13 up 0left 1down 2right