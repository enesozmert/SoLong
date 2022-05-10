/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_conditions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:02:57 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/10 12:03:42 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_move_area(t_game *game)
{
	if (game->player.x <= 0)
		game->player.x = 0;
	else if (game->player.x >= (game->platform.width - 2) * BLOCK_SIZE)
		game->player.x = (game->platform.width - 2) * BLOCK_SIZE;
	if (game->player.y <= 0)
		game->player.y = 0;
	else if (game->player.y >= (game->platform.height - 2) * BLOCK_SIZE)
		game->player.y = (game->platform.height - 2) * BLOCK_SIZE;
}

int	player_move_wall(t_game *game)
{
	(void)game;
	return (0);
}

void	player_move_coin(t_game *game)
{
	int	p_x;
	int	p_y;

	p_x = game->player.x / BLOCK_SIZE;
	p_y = game->player.y / BLOCK_SIZE;
	if (game->platform.map[p_y][p_x] == 'C')
	{
		game->player.coin_count++;
		game->platform.map[p_y][p_x] = '0';
	}
}

void	player_move_count(t_game *game)
{
	int	p_x;
	int	p_y;

	p_x = game->player.x / BLOCK_SIZE;
	p_y = game->player.y / BLOCK_SIZE;
	if (game->platform.map[p_y][p_x] != '1')
		game->player.move_count++;
	print_map_string(game);
}

void	player_move_exit(t_game *game)
{
	int	p_x;
	int	p_y;

	p_x = game->player.x / BLOCK_SIZE;
	p_y = game->player.y / BLOCK_SIZE;
	if (game->player.coin_count == game->player.coin_size)
	{
		mlx_destroy_window(game->wlx.mlx, game->wlx.win);
		exit (0);
	}
}
