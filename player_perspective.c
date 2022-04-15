#include "header.h"

char *player_perspective(t_game game)
{
	int p_x;
	int p_y;
	char *perspective;

	p_x = 0;
	p_y = 0;
	perspective = (char *)malloc(sizeof(char) * 5);
	while (game.platform.map[p_y])
	{
		p_x = 0;
		while (game.platform.map[p_y][p_x])
		{
			if (game.player.x / BLOCK_SIZE == p_x && game.player.y / BLOCK_SIZE == p_y && (p_x != 0 || p_y != 0))
			{
				perspective[0] = game.platform.map[p_y][p_x - 1];
				perspective[1] = game.platform.map[p_y][p_x + 1];
				perspective[2] = game.platform.map[p_y - 1][p_x];
				perspective[3] = game.platform.map[p_y + 1][p_x];
				break;
			}
			p_x++;
		}
		p_y++;
	}
	perspective[4] = '\0';
	return (perspective);
}