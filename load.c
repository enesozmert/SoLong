#include "header.h"

int main()
{
	t_wlx		wlx;
	t_game		game;

	wlx.mlx = mlx_init();
	wlx.win = mlx_new_window(wlx.mlx, 2600, 600, "Ecole 42 eozmert");
	game.platform.path = "./maps/map_1.ber";
	game.wlx = wlx;
	create_map(wlx, game.platform);
	mlx_key_hook(wlx.win, key_hook, &game);
	//player
	game.player.image.relative_path = "./icons/character/rocket.xpm";
	game.player.image.wlx = wlx;
	game.player.name = "player1";

	//char **str = create_map_matris(game.platform);
	//printf("%c",str[2][1]);

	mlx_hook(wlx.win, ON_KEYDOWN, 1L<<0, game_exit, &wlx);
	mlx_loop(wlx.mlx);
}