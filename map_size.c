#include "header.h"

int *map_size(t_platform platform)
{
	char **map_matris;
	int *size;
	int w;
	int h;
	int start_w;

	w = 0;
	h = 0;
	size = (int *)malloc(sizeof(int) * 3);
	map_matris = create_map_matris(platform);
	while (map_matris[h])
	{
		w = 0;
		while (map_matris[h][w])
			w++;
		if (h == 0)
			start_w = w;
		h++;
	}
	size[0] = start_w;
	size[1] = h;
	return (size);
}

int map_line_count(t_platform platform)
{
	int i;
	int fd;
	int byte;
	char area;

	fd = open(platform.path, O_RDONLY);
	i = 0;
	byte = 1;
	while (byte != 0)
	{
		byte = read(fd, &area, 1);
		if (area == '\0')
			break;
		if (area == '\n')
			i++;
	}
	close(fd);
	return (i);
}