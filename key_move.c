#include "header.h"

int	key_hook(int keycode, t_wlx *wlx)
{
	(void)wlx;
	t_key_control key_control[5];
	key_control[0] = (t_key_control){"W", 13, key_up};
	key_control[1] = (t_key_control){"S", 1, key_down};
	key_control[2] = (t_key_control){"A", 0, key_left};
	key_control[3] = (t_key_control){"D", 2, key_right};
	key_control[4] = (t_key_control){NULL, -1, NULL};

	int i;
	i = 0;
	while (key_control[i].name != NULL)
	{
		if (key_control[i].key_code == keycode)
		{
			key_control[i].f(wlx);
		}
		i++;
	}
	return (0);
}

int key_up(t_wlx *wlx)
{
	printf("%s\n", "w");
	static int left = 0;
	left += 32;
	t_image image;
	image.x = left;
	image.y = 0;
	image.wlx = *wlx;
	image.relative_path = "./icons/maps/black/black.xpm";
	put_image(image);
	return (0);
}

int key_down(t_wlx *wlx)
{
	(void)wlx;
	printf("%s\n", "s");
	return (0);
}

int key_left(t_wlx *wlx)
{
	(void)wlx;
	printf("%s\n", "a");
	return (0);
}

int key_right(t_wlx *wlx)
{
	(void)wlx;
	printf("%s\n", "d");
	return (0);
}

//13 up 0left 1down 2right