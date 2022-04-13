#include "header.h"

int main()
{
	t_wlx		wlx;
	t_game		game;

	wlx.mlx = mlx_init();
	wlx.win = mlx_new_window(wlx.mlx, 2600, 600, "Ecole 42 eozmert");
	game.wlx = wlx;
	
	//platform
	game.platform.path = "./maps/map_1.ber";
	game.platform.height = map_size(game.platform)[0];
	game.platform.width = map_size(game.platform)[1];

	printf("h: %d,w: %d", game.platform.height, game.platform.width);

	//create map
	create_map(wlx, game.platform);

	//player
	game.player.image.relative_path = "./icons/character/rocket.xpm";
	game.player.image.wlx = wlx;
	game.player.name = "player1";
	game.player.x = 9 * 64;
	game.player.y = 4 * 64;

	char *str = player_perspective(game);
	printf("%s\n", str);

	mlx_key_hook(wlx.win, key_hook, &game);
	mlx_hook(wlx.win, ON_KEYDOWN, 1L<<0, game_exit, &wlx);
	mlx_loop(wlx.mlx);
}