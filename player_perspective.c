#include "header.h"

char *player_perspective(t_game game)
{
	int p_x;
	int p_y;
	char *perspective;

	p_x = (game.player.x + 1) / BLOCK_SIZE;
	p_y = (game.player.y + 1) / BLOCK_SIZE;
	perspective = (char *)malloc(sizeof(char) * 5);
	if (p_y <= 0)
		p_y = 1;
	if (p_x <= 0)
		p_x = 1;
	bzero(perspective, strlen(perspective));
	perspective[0] = game.platform.map[p_y][p_x + 1];
	perspective[1] = game.platform.map[p_y][p_x - 1];
	perspective[2] = game.platform.map[p_y + 1][p_x];
	perspective[3] = game.platform.map[p_y - 1][p_x];
	perspective[4] = '\0';
	return (perspective);
}