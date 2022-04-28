#include "./../header.h"

void player_main_b(t_game *game)
{
	game->player.image.relative_path = "./icons/character/rocketu.xpm";
	game->player.image.wlx = game->wlx;
	game->player.name = "player1";
	game->player.coin_size = get_block_count(&game->platform, 'C');
	game->player.coin_count = 0;
	game->player.move_count = 0;
	game->player.x = 1 * 64;
	game->player.y = 4 * 64;
	game->player.perspective = player_perspective(*game);
}

void load_main_b(t_game *game, t_wlx *wlx)
{
	int window_w;
	int window_h;

	window_w = (game->platform.width - 1) * BLOCK_SIZE;
	window_h = (game->platform.height - 1) * BLOCK_SIZE;
	wlx->mlx = mlx_init();
	wlx->win = mlx_new_window(wlx->mlx, window_w,window_h, "Ecole 42 eozmert");
	game->wlx = *wlx;
	game->platform.map = create_map_matris(game->platform);
	
}

void control_main_b(t_game *game, char **av, int ac)
{

	if (ac != 2)
		exit(printf("Error Arg Two Many\n"));
	game->platform.path = av[1];
	game->platform.fd = open(game->platform.path, O_RDONLY);
	if (game->platform.fd < 0)
		exit(printf("Error Map Not Found\n"));	
	game->platform.width = map_size(game->platform)[0];
	game->platform.height = map_size(game->platform)[1];
}

int main(int ac, char **av)
{
	t_wlx		wlx;
	t_game		game;

	control_main_b(&game, av, ac);
	load_main_b(&game, &wlx);
	exception_handler(game.platform);
	create_map(wlx, game.platform);
	player_main_b(&game);
	mlx_key_hook(wlx.win, key_hook, &game);
	mlx_hook(wlx.win, ON_DESTROY, 1L << 2, game_exit, &game);
	mlx_hook(wlx.win, ON_KEYDOWN, 1L << 0, game_exit, &wlx);
	mlx_loop_hook(game.wlx.mlx, animation, &game);
	mlx_loop(wlx.mlx);
}