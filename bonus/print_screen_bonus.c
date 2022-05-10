/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:10:15 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/10 12:43:37 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

void	print_map_string(t_game *game)
{
	char	*string;

	string = ft_itoa(game->player.move_count);
	mlx_string_put(game->wlx.mlx, game->wlx.win,
		(((game->platform.width) / 2) * BLOCK_SIZE),
		(game->platform.height * BLOCK_SIZE) - BLOCK_SIZE,
		rgb_hex(255, 255, 255), "Movements: ");
	mlx_string_put(game->wlx.mlx, game->wlx.win,
		(((game->platform.width) / 2) * BLOCK_SIZE) + 100,
		(game->platform.height * BLOCK_SIZE) - BLOCK_SIZE,
		rgb_hex(255, 255, 255), string);
	free(string);
	string = NULL;
	return ;
}
