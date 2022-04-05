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
			//printf("%s\n", key_control[i].name);
			key_control[i].f(1);
		}
		else
			key_control[i].f(0);
		i++;
	}
	return (0);
}

int key_up(__attribute__((unused))int booleaner)
{
	return (booleaner);
}

int key_down(__attribute__((unused))int booleaner)
{
	return (booleaner);
}

int key_left(__attribute__((unused))int booleaner)
{
	return (booleaner);
}

int key_right(__attribute__((unused))int booleaner)
{
	return (booleaner);
}

//13 up 0left 1down 2right