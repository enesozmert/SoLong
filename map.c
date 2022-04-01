#include "header.h"

t_block set_block(char name)
{
	t_block maps[6];
	maps[0] = (t_block){"1", "./icons/map/"};
	maps[1] = (t_block){"0", "./icons/map/"};
	maps[2] = (t_block){"C", "./icons/map/"};
	maps[3] = (t_block){"P", "./icons/map/"};
	maps[4] = (t_block){"E", "./icons/map/"};
	maps[5] = (t_block){NULL, NULL};

	int i;
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

void create_map(t_wlx wlx, t_platform platform)
{
	int		fd;
	char 	*area;
	int		i;
	int		j;
	t_block	map;
	t_image	image;


	image.wlx = wlx;
	image.img = NULL;
	image.img_height = 0;
	image.img_width = 0;
	fd = open(platform.path, O_RDONLY);
	i = 0;
	j = 0;
	area = get_next_line(fd);
	while (area[i])
	{
		j = 0;
		while (area[j])
		{
			map = set_block(area[j]);
			image.x = i * image.img_height;
			image.y = i * image.img_width;
			image.relative_path = put_image(image);
			j++;
		}
		area = get_next_line(fd);
		i++;
	}
}