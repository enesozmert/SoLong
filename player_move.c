#include "header.h"

int player_move_left(t_game *game)
{
	if (game->player.perspective[1] != '1')
	{
		game->player.x -= BLOCK_SIZE;
		fill_background_left(game);
	}
	game->player.image.relative_path = "./icons/character/rocketl.xpm";
	player_move_base(game);
	return (game->player.x);
}

int player_move_right(t_game *game)
{
	if (game->player.perspective[0] != '1')
	{
		game->player.x += BLOCK_SIZE;
		fill_background_right(game);
	}
	game->player.image.relative_path = "./icons/character/rocketr.xpm";
	player_move_base(game);
	return (game->player.x);
}

int player_move_up(t_game *game)
{
	if (game->player.perspective[3] != '1')
	{
		game->player.y -= BLOCK_SIZE;
		fill_background_up(game);
	}
	game->player.image.relative_path = "./icons/character/rocketu.xpm";
	player_move_base(game);
	return (game->player.y);
}

int player_move_down(t_game *game)
{
	if (game->player.perspective[2] != '1')
	{
		game->player.y += BLOCK_SIZE;
		fill_background_down(game);
	}
	game->player.image.relative_path = "./icons/character/rocketd.xpm";
	player_move_base(game);
	return (game->player.y);
}

void player_move_base(t_game *game)
{
	player_move_area(game);
	player_move_coin(game);
	player_move_count(game);
	game->player.image.y = game->player.y;
	game->player.image.x = game->player.x;
	game->player.wlx = game->wlx;
	game->player.image.img = put_image(game->player.image);
	game->player.perspective = player_perspective(*game);
	printf("path %s \n",game->player.relative_path);
	printf("coin count :%d \n",game->player.coin_count);
	printf("move count :%d \n",game->player.move_count);
	//printf("%s\n", game->player.perspective);
}