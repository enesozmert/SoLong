#include "header.h"

int check_door(t_game *game)
{
	if (game->player.perspective[game->player.direction] != 'E')
		return (1);
	else
	{
		player_move_exit(game);
		return (0);
	}
}

int check_wall(t_game *game)
{
	if (game->player.perspective[game->player.direction] != '1')
		return (1);
	else
		return (0);
}

int check_total_item(t_game *game)
{
	if (check_wall(game) == 1 && check_door(game) == 1)
		return (1);
	else
		return (0);
	return (0);
}