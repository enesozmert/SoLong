#include "header.h"

int player_move_left(t_game *game)
{
	game->player.direction = 1;
	if (check_total_item(game) == 1)
	{
		game->player.x -= BLOCK_SIZE;
		fill_background_base(game, BLOCK_SIZE,0);
	}
	game->player.image.relative_path = "./icons/character/rocketl.xpm";
	player_move_base(game);
	return (game->player.x);
}

int player_move_right(t_game *game)
{
	game->player.direction = 0;
	if (check_total_item(game) == 1)
	{
		game->player.x += BLOCK_SIZE;
		fill_background_base(game, -BLOCK_SIZE,0);
	}
	game->player.image.relative_path = "./icons/character/rocketr.xpm";
	player_move_base(game);
	return (game->player.x);
}

int player_move_up(t_game *game)
{
	game->player.direction = 3;
	if (check_total_item(game) == 1)
	{
		game->player.y -= BLOCK_SIZE;
		fill_background_base(game, 0,+BLOCK_SIZE);
	}
	game->player.image.relative_path = "./icons/character/rocketu.xpm";
	player_move_base(game);
	return (game->player.y);
}

int player_move_down(t_game *game)
{
	game->player.direction = 2;
	if (check_total_item(game) == 1)
	{
		game->player.y += BLOCK_SIZE;
		fill_background_base(game, 0, -BLOCK_SIZE);
		//fill_background_down(game);
	}
	game->player.image.relative_path = "./icons/character/rocketd.xpm";
	player_move_base(game);
	return (game->player.y);
}

int player_move(t_game *game, int x, int y)
{
	if (check_total_item(game) == 1)
	{
		game->player.x -= x;
		game->player.y -= y;
		fill_background_base(game, x, y);
	}
	game->player.image.relative_path = "./icons/character/rocketd.xpm";
	player_move_base(game);
	return (game->player.y);
}

void player_move_base(t_game *game)
{
	//player_move_exit(game);
	player_move_area(game);
	player_move_coin(game);
	player_move_count(game);
	game->player.image.y = game->player.y;
	game->player.image.x = game->player.x;
	game->player.wlx = game->wlx;
	game->player.image.img = put_image(game->player.image);
	game->player.perspective = player_perspective(*game);
	printf("coin count :%d \n",game->player.coin_count);
	printf("move count :%d \n",game->player.move_count);
	//printf("%s\n", game->player.perspective);
}