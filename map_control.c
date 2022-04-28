#include "header.h"

int map_error(t_platform platform)
{
	int x;
	int y;
	int *size;

	x = 1;
	y = 0;
	size = map_size(platform);
	while (platform.map[y])
	{
		x = 1;
		while (platform.map[y][x])
		{
			if (platform.map[0][x - 1] != '1') // up
				return (404);
			if (platform.map[y][0] != '1') // left
				return (403);
			if (platform.map[y][size[0] - 2] != '1') // right
				return (402);
			if (platform.map[size[1] - 2][x - 1] != '1') // down
				return (401);
			x++;
		}
		y++;
	}
	return (0);
}

int item_repeat_error(t_platform platform)
{
	char *singular_items;
	int i;

	singular_items = malloc(sizeof(char) * 3);
	singular_items = "EC";
	i = 0;
	while (singular_items[i])
	{
		//printf("count %d => %c\n", get_block_count(&platform, singular_items[i]), singular_items[i]);
		if (get_block_count(&platform, singular_items[i]) < 1)
			return (202);
		i++;
	}
	return (0);
}

int item_single_error(t_platform platform)
{
	// printf("P count P %d => %c\n",get_block_count(&platform,'P'),'P');
	if (get_block_count(&platform, 'P') != 1)
		return (204);
	return (0);
}

int item_wrong_error(t_platform platform)
{
	(void)platform;
	int i;
	int j;

	j = 0;
	i = 0;
	while (platform.map[i])
	{
		j = 0;
		while (platform.map[i][j])
		{
			if (!strchr("1PCE0X\n",platform.map[i][j]))
				return (102);
			j++;
		}
		i++;
	}
	return (0);
}

int file_error(t_platform platform)
{
	if (platform.fd < 0)
		return (504);
	if (strnstr(&platform.path[1], ".ber", strlen(&platform.path[1])) == NULL)
		return (502);
	return (0);
}