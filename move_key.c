#include "header.h"

int	key_up(int keycode, t_wlx *wlx)
{
	(void)keycode;
	(void)wlx;
	if (keycode == 13)
		return (1);
	else
		return (0);
}

int	key_down(int keycode, t_wlx *wlx)
{
	(void)keycode;
	(void)wlx;
	if (keycode == 1)
		return (1);
	else
		return (0);
}

int	key_left(int keycode, t_wlx *wlx)
{
	(void)keycode;
	(void)wlx;
	if (keycode == 0)
		return (1);
	else
		return (0);
}

int	key_right(int keycode, t_wlx *wlx)
{
	(void)keycode;
	(void)wlx;
	if (keycode == 2)
		return (1);
	else
		return (0);
}