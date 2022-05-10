/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:48:19 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/10 11:48:51 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_background_base(t_game *game, int x, int y)
{
	t_image	image1;

	image1.x = game->player.x + x;
	image1.y = game->player.y + y;
	image1.wlx = game->wlx;
	image1.relative_path = "./icons/maps/black/star1.xpm";
	image1.img = put_image(image1);
	mlx_destroy_image(game->wlx.mlx, image1.img);
}
