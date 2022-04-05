#include "header.h"

t_block set_block(char name)
{
	t_block maps[6];
	int i;

	maps[0] = (t_block){"1", "./icons/maps/paving/paving2.xpm"};
	maps[1] = (t_block){"0", "./icons/maps/black/star.xpm"};
	maps[2] = (t_block){"C", "./icons/maps/paving/block.xpm"};
	maps[3] = (t_block){"P", "./icons/character/rocket.xpm"};
	maps[4] = (t_block){"E", "./icons/maps/paving/elevator1.xpm"};
	maps[5] = (t_block){NULL, NULL};

	i = 0;
	while (maps[i].name != NULL)
	{
		if (maps[i].name[0] == name)
		{
			return (maps[i]);
			break;
		}
		i++;
	}
	return (maps[0]);
}

void create_line(char *area, t_wlx wlx, int *i)
{
	int		j;
	t_block map;
	t_image	image;

	image.wlx = wlx;
	j = 0;
	while (area[j])
	{
		map = set_block(area[j]);
		image.x = j * BLOCK_SIZE;
		image.y = *i * BLOCK_SIZE;
		image.relative_path = map.relative_path;
		put_image(image);
		j++;
	}
}

void create_map(t_wlx wlx, t_platform platform)
{
	int		fd;
	char 	*area;
	int		i;

	fd = open(platform.path, O_RDONLY);
	i = 0;
	while (i < 1000)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break;
		line_by_line(area, wlx, &i);
		i++;
	}
}