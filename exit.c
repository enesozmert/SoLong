#include "header.h"

int	close(int key_code, t_wlx *wlx)
{
	if (key_code == 53)
	{
		mlx_destroy_window(wlx->mlx, wlx->win);
		exit (0);
	}
	return (0);
}