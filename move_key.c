#include "header.h"

int	key_up(int keycode, t_wlx *wlx)
{
	(void)keycode;
	(void)wlx;
	if (keycode == 126)
		return (1);
	else
		return (0);
}

int	key_down(int keycode, t_wlx *wlx)
{
	(void)keycode;
	(void)wlx;
	if (keycode == 125)
		return (1);
	else
		return (0);
}

int	key_left(int keycode, t_wlx *wlx)
{
	(void)keycode;
	(void)wlx;
	if (keycode == 123)
		return (1);
	else
		return (0);
}

int	key_right(int keycode, t_wlx *wlx)
{
	(void)keycode;
	(void)wlx;
	if (keycode == 124)
		return (1);
	else
		return (0);
}