/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:19:21 by eozmert           #+#    #+#             */
/*   Updated: 2022/05/09 16:19:32 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	game_exit(int key_code, t_wlx *wlx)
{
	if (key_code == 53)
	{
		mlx_destroy_window(wlx->mlx, wlx->win);
		exit (0);
	}
	return (0);
}
