#include "header.h"

int main()
{
	t_wlx	wlx;
	t_platform	platform;

	platform.path = "./maps/map_1.ber";
	wlx.mlx = mlx_init();
	wlx.win = mlx_new_window(wlx.mlx, 2300, 600, "Ecole 42 eozmert");
	create_map(wlx, platform);
	mlx_key_hook(wlx.win, key_hook, &wlx);
	//int result;
	//result = key_up();
	//printf("%d",result);
	mlx_hook(wlx.win, ON_KEYDOWN, 1L<<0, game_exit, &wlx);
	mlx_loop(wlx.mlx);
}