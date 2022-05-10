/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:07:33 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/10 12:07:39 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

void	animator_coin(t_game *game, int x, int y)
{
	t_image	image;

	if (game->enemy.enemy_index >= 2)
		game->enemy.enemy_index = 0;
	image.wlx = game->wlx;
	image.x = x * BLOCK_SIZE;
	image.y = y * BLOCK_SIZE;
	if (game->enemy.enemy_index == 0)
	{
		image.relative_path = "./icons/maps/black/star1.xpm";
		put_image(image);
		image.relative_path = "./icons/maps/paving/block.xpm";
		put_image(image);
	}
	if (game->enemy.enemy_index == 1)
	{
		image.relative_path = "./icons/maps/black/star1.xpm";
		put_image(image);
		image.relative_path = "./icons/maps/paving/block_red.xpm";
		put_image(image);
	}
}

void	move_animation(t_game *game)
{
	int				i;
	int				j;

	i = 0;
	while (i < game->platform.height - 2)
	{
		j = 0;
		while (j < game->platform.width)
		{
			if (game->platform.map[i][j] == 'C')
				animator_coin(game, j, i);
			if (game->platform.map[i][j] == 'X')
				move_2(game, j, i);
			j++;
		}
		i++;
	}
	game->enemy.enemy_index++;
}

int	animation(t_game *game)
{
	game->enemy.enemy_speed++;
	if (game->enemy.enemy_speed >= 3000)
	{
		move_animation(game);
		game->enemy.enemy_speed = 0;
	}
	return (0);
}
