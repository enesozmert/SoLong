#include "header.h"

int main()
{
	t_wlx	wlx;
	t_platform	platform;

	platform.path = "./maps/map_1.ber";
	wlx.mlx = mlx_init();
	wlx.win = mlx_new_window(wlx.mlx, 3840, 2160, "Ecole 42 eozmert");
	create_map(wlx, platform);
	mlx_hook(wlx.win, ON_KEYDOWN, 1L<<0, game_exit, &wlx);
	mlx_loop(wlx.mlx);
}