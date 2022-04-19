#include "header.h"

int main()
{
	t_wlx		wlx;
	t_game		game;

	//platform
	game.platform.path = "./maps/map_1.ber";
	game.platform.width = map_size(game.platform)[0];
	game.platform.height = map_size(game.platform)[1];

	wlx.mlx = mlx_init();
	wlx.win = mlx_new_window(wlx.mlx, game.platform.width * BLOCK_SIZE, 600, "Ecole 42 eozmert");
	game.wlx = wlx;

	//platform matris
	game.platform.map = create_map_matris(game.platform);
	printf("w: %d,h: %d\n", game.platform.width, game.platform.height);

	//create map
	create_map(wlx, game.platform);

	//player
	game.player.image.relative_path = "./icons/character/rocketu.xpm";
	game.player.image.wlx = wlx;
	game.player.name = "player1";
	game.player.coin_size = get_block_count(&game.platform, 'C');
	printf("coin count : %d", game.player.coin_size);
	game.player.x = 1 * 64;
	game.player.y = 4 * 64;
	game.player.perspective = player_perspective(game);

	// char **matris = create_map_matris(game.platform);
	// int i;
	// int j;

	// i = 0;
	// j = 0;
	// printf("\n");
	// while (matris[i])
	// {
	// 	j = 0;
	// 	while (matris[i][j])
	// 	{
	// 		printf("%c",matris[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }

	mlx_key_hook(wlx.win, key_hook, &game);
	mlx_hook(wlx.win, ON_KEYDOWN, 1L<<0, game_exit, &wlx);
	mlx_loop(wlx.mlx);
}