#include "header.h"

int *get_location(t_platform *platform, char block_name)
{
	int j;
	int i;
	int *location;

	i = 0;
	j = 0;
	location = malloc(sizeof(int) * 3);
	while (platform->map[i])
	{
		j = 0;
		while (platform->map[i][j])
		{
			if (platform->map[i][j] == block_name)
			{
				location[0] = i;
				location[1] = j;
			}
			j++;
		}
		i++;
	}
	return (location);
}