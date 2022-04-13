#include "header.h"

char	*player_perspective(t_game game)
{
	char	*perspective;
	char	**map_matris;
	int		p_x;
	int		p_y;
	
	p_x = 0;
	p_y = 0;
	int len = 0;
	map_matris = create_map_matris(game.platform);
	perspective = (char *)malloc(sizeof(char) * 5);
	while (map_matris[p_y])
	{
		len++;
		p_x = 0;
		while (map_matris[p_y][p_x])
		{
			
			if (game.player.x / BLOCK_SIZE == p_x && game.player.y / BLOCK_SIZE == p_y)
			{
				perspective[0] = map_matris[p_y][p_x - 1];
				perspective[1] = map_matris[p_y + 1][p_x];
				perspective[2] = map_matris[p_y][p_x + 1];
				perspective[3] = map_matris[p_y - 1][p_x];
				break;
			}
			p_x++;
		}
		p_y++;
	}
	return (perspective);
}
