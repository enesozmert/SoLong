
#include "header.h"

int get_block_count(t_platform *platform, char block_name)
{
	int j;
	int i;
	int result;

	i = 0;
	j = 0;
	result = 0;
	while (platform->map[i])
	{
		j = 0;
		while (platform->map[i][j])
		{
			if (platform->map[i][j] == block_name)
				result++;
			j++;
		}
		i++;
	}
	return (result);
}