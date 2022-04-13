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
	//printf("%s\n", "w");
	player_move_up(game);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	fill_background_up(game);
	return (0);
}

int key_down(t_game *game)
{
	//printf("%s\n", "s");
	player_move_down(game);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	fill_background_down(game);
	return (0);
}

int key_left(t_game *game)
{
	//printf("%s\n", "a");
	player_move_left(game);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	fill_background_left(game);
	return (0);
}

int key_right(t_game *game)
{
	//printf("%s\n", "d");
	player_move_right(game);
	mlx_destroy_image(game->wlx.mlx, game->player.image.img);
	fill_background_right(game);
	return (0);
}

//13 up 0left 1down 2right